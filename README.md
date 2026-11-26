# 32-Bit 5-Stage Pipelined RISC-V (RV32I) Processor Core

A 32-bit, 5-stage pipelined RISC-V processor written in SystemVerilog. It implements RV32I plus the Zicsr extension, with machine-mode traps (`ecall`, `ebreak`, `mret`) and full hazard handling: forwarding, load-use stalls, branch/jump flushes and a register-file write-through bypass. It passes all 40 applicable tests of the official [`riscv-tests`](https://github.com/riscv-software-src/riscv-tests) rv32ui suite in the suite's standard, unmodified test environment, runs C programs compiled with GCC, and is verified with self-checking directed tests in Verilator, with pipeline valid bits and performance counters to measure IPC.

The core has also been taken from RTL to a GDSII layout in the SkyWater 130 nm process with the open-source [LibreLane](https://github.com/librelane/librelane) flow. Setup and hold timing are met at 50 MHz across all 9 process/voltage/temperature and wiring corners, and the layout passes DRC, LVS and antenna checks (see [ASIC Implementation](#asic-implementation-rtl-to-gdsii)).

---

## Key Metrics

* **Pipeline depth:** 5 stages (`IF`, `ID`, `EX`, `MEM`, `WB`)
* **Branch/jump resolution:** EX stage, 2-cycle penalty for a taken branch or jump
* **Load-use penalty:** 1 stall cycle
* **ALU:** 10 operations (`ADD`, `SUB`, `AND`, `OR`, `XOR`, `SLL`, `SRL`, `SRA`, `SLT`, `SLTU`), operand A selectable between rs1, PC and zero
* **Register file:** 32 x 32-bit, dual asynchronous read / synchronous write, write-through bypass, `x0` hardwired to 0
* **Memories:** outside the core, connected through instruction and data memory ports (Harvard architecture). The simulation models are 16 KB each; the data port has byte enables
* **Compliance:** 40 / 40 applicable `riscv-tests` rv32ui tests pass, in both the official environment (real `ecall` traps) and a simplified one
* **Privileged:** machine mode only; CSRs `mstatus`, `misa`, `mtvec` (direct), `mscratch`, `mepc`, `mcause`, `mtval`, `mhartid`
* **Clock:** 50 MHz, timing met in SkyWater 130 nm at all 9 corners (worst-case setup slack +3.63 ns). FPGA timing not yet closed
* **ASIC size:** 17.6k standard cells, 0.14 mm² of cell area (Sky130 `sky130_fd_sc_hd`)
* **Measured IPC** (retired instructions / cycles, including the 4-cycle pipeline fill):

| Program | Retired | Cycles | IPC |
| --- | --- | --- | --- |
| C: bubble sort of 8 values (GCC `-O1`) | 553 | 730 | 0.76 |
| 0: ALU, forwarding, load/store | 6 | 10 | 0.60 |
| 1: All branch types | 11 | 21 | 0.52 |
| 2: JAL / JALR | 7 | 15 | 0.47 |
| 3: LUI / AUIPC | 8 | 12 | 0.67 |
| 4: Byte and halfword loads/stores | 15 | 19 | 0.79 |
| 5: No false load-use stalls | 5 | 9 | 0.56 |
| 6: Required store-data load-use stall | 5 | 10 | 0.50 |
| 7: ECALL / EBREAK trap handler | 24 | 36 | 0.67 |

The C program is the representative number. The directed tests are short, so the pipeline fill and taken-branch bubbles dominate them. In the bubble sort, the lost cycles are mostly taken loop branches (2 cycles each, about one per inner iteration) plus load-use stalls (1 cycle each). None of the timing-closure changes described below changed a single cycle count.

---

## Supported Instructions

| Class | Instructions | Status |
| --- | --- | --- |
| R-type ALU | `add sub and or xor sll srl sra slt sltu` | Supported |
| I-type ALU | `addi andi ori xori slli srli srai slti sltiu` | Supported |
| Upper immediates | `lui`, `auipc` | Supported |
| Loads | `lb lh lw lbu lhu` | Supported (aligned) |
| Stores | `sb sh sw` | Supported (aligned) |
| Branches | `beq bne blt bge bltu bgeu` | Supported |
| Jumps | `jal`, `jalr` | Supported |
| Ordering | `fence` | Supported (no-op: single in-order core, no caches) |
| System | `ecall`, `ebreak`, `mret` | Supported (machine-mode trap) |
| CSR (Zicsr) | `csrrw csrrs csrrc csrrwi csrrsi csrrci` | Supported |
| Not implemented | `fence.i`, `wfi`, interrupts, user/supervisor modes | |

Misaligned halfword and word accesses are not supported and do not trap; the RISC-V specification allows a core to trap on them instead. Assertions in `soc_sim.sv` flag any misaligned access in simulation.

---

## Datapath & Pipeline Architecture

```text
       +-----------------------------------------------------------------------------------+
       |                                   HAZARD UNIT                                     |
       +-----------------------------------------------------------------------------------+
         |               |                 |
         v (Stall)       v (Stall/Flush)   v (Flush)
    +---------+     +---------+       +---------+       +---------+       +---------+
    |   IF    | --> |   ID    | ----> |   EX    | ----> |   MEM   | ----> |   WB    |
    | (Fetch) |     | (Decode)|       |(Execute)|       |(Memory) |       |(Write-B)|
    +---------+     +---------+       +---------+       +---------+       +---------+
         ^               |                 |                 |                 |
     imem port        regfile             alu               lsu            regfile
         |            immgen          branch_unit       (byte enables,     (write)
         |         control_unit       alu_control        sign/zero ext.)
         |       FORWARDING UNIT        csr_unit         dmem port
         |     (selects computed here)     |
         +------ branch / jump target ------+
```

The instruction and data memories are outside `riscv_core`. In simulation, `soc_sim.sv` connects the core to behavioural memories; in the ASIC flow only the core is hardened, and the memory ports become pins of the block.

### Pipeline Breakdown

1. **Instruction Fetch (IF):** Selects PC + 4 or the branch/jump target from EX, drives the PC onto the instruction memory port, and takes the instruction from it.
2. **Instruction Decode (ID):** Decodes the opcode in `control_unit.sv`, reads `regfile.sv` and builds the immediate in `immgen.sv`. Control signals are decoded once here and travel down the pipeline with the instruction. The forwarding unit also runs here, one stage early (see Hazard Handling).
3. **Execute (EX):** The ALU's operand A is the forwarded rs1, the PC (`auipc`) or zero (`lui`); operand B is the forwarded rs2 or the immediate. `branch_unit.sv` evaluates all six branch conditions on the forwarded register values. Branch and JAL targets are `PC + imm`; the JALR target is `(rs1 + imm) & ~1`. A taken branch or any jump redirects the PC and flushes IF/ID and ID/EX. Jumps compute their write-back value (PC + 4) here, so every forwarding path sees the final result. `csr_unit.sv` also lives in EX: it reads and writes CSRs, and on `ecall`/`ebreak` it saves the PC in `mepc` and the cause in `mcause` and redirects to `mtvec`; `mret` redirects to `mepc`. Traps reuse the branch/jump redirect and its two-instruction flush. CSR writes are safe in EX because nothing can cancel an instruction once it reaches EX: redirects only come from EX and only flush younger instructions.
4. **Memory (MEM):** `lsu.sv` turns `funct3` and the low address bits into byte enables and replicated write data for stores, and selects and sign- or zero-extends the byte or halfword for loads. The data memory itself sits behind the data port.
5. **Write-Back (WB):** Selects the loaded data or the EX result and writes it to the register file.

### Hazard Handling

| Hazard | Mechanism |
| --- | --- |
| RAW, producer 1 instruction ahead | Forward from EX/MEM (`forward[1]`) |
| RAW, producer 2 instructions ahead | Forward from MEM/WB (`forward[0]`) |
| RAW, producer 3 instructions ahead | Register-file write-through bypass (WB writes and ID reads the same register in one cycle) |
| Load-use | Stall PC and IF/ID for one cycle, insert a bubble into ID/EX |
| Taken branch / jump / trap / `mret` | Resolve in EX, flush IF/ID and ID/EX (2 bubbles) |

The control unit flags which source registers each instruction actually reads (`uses_rs1`, `uses_rs2`), and the hazard unit only stalls for those. This removes unnecessary load-use stalls after instructions such as `lui` and `addi`, whose rs1/rs2 fields hold immediate bits. The forwarding unit still compares all fields; a forward into an unused operand is harmless and costs no cycles.

**Forwarding selects are computed one stage early.** The forwarding unit compares the instruction in ID against the instructions in EX and MEM, which are exactly the ones that will be in MEM and WB one cycle later, and the result is registered in ID/EX. EX therefore starts each cycle with the mux selects already settled, instead of computing them from register-address compares first. The selects are one-hot (`10` = EX/MEM, `01` = MEM/WB, `00` = register file; `11` never occurs because EX/MEM has priority), so the EX muxes test single bits. An assertion in `soc_sim.sv` checks that `11` never appears. Both changes came from the ASIC timing work.

### Valid Bits and Performance Counters

A `valid` bit travels through every pipeline register. It is set when an instruction is fetched and cleared on reset, flush or bubble insertion. The testbench counts cycles and retired instructions (`wb_valid`) until each program ends, which gives the IPC figures above.

Flushes only clear what has side effects: the ID/EX flush clears the valid bit and the control bits that write state (register write, memory read/write, branch, jump, system), and the IF/ID flush clears only the valid bit, which forces the decoder's opcode to zero. Data fields such as the immediate and register values pass through unflushed, since an invalid instruction can never use them. This also came from the ASIC work: it removes the flush signal from many datapath flip-flops.

---

## Project Structure

| File | Type | Description |
| --- | --- | --- |
| `riscv_core.sv` | Top module | The synthesizable core: 5 stages, pipeline registers, control units, instruction and data memory ports |
| `soc_sim.sv` | Simulation top | Connects the core to the behavioural memories; alignment and one-hot forwarding assertions |
| `instr_mem.sv` | Simulation model | 16 KB instruction ROM; loads a hex file with `+HEX=file`, or a built-in test with `+TEST=N` |
| `data_mem.sv` | Simulation model | 16 KB data RAM with byte-enable writes; loads a data image at `0x2000` with `+DHEX=file` |
| `lsu.sv` | Design | Load/store unit: store byte enables and data, load byte/halfword select with sign or zero extension |
| `regfile.sv` | Design | 32 x 32-bit register file with write-through bypass and hardwired `x0` |
| `alu.sv` | Design | 32-bit, 10-operation ALU |
| `alu_control.sv` | Design | Decodes `alu_op`, `funct3`, `funct7` into ALU control |
| `branch_unit.sv` | Design | Evaluates BEQ/BNE/BLT/BGE/BLTU/BGEU on forwarded operands |
| `control_unit.sv` | Design | Main decoder, including `jump`, `jalr`, `system`, the ALU operand-A select and `uses_rs1`/`uses_rs2` |
| `csr_unit.sv` | Design | Machine-mode CSRs, CSR read/modify/write, `ecall`/`ebreak` traps and `mret` |
| `immgen.sv` | Design | Immediate generator for I, S, B, U and J formats |
| `if_id_reg.sv` | Pipeline reg | IF/ID with stall; flush clears only the valid bit |
| `id_ex_reg.sv` | Pipeline reg | ID/EX; flush clears the valid and side-effect control bits; carries the precomputed forwarding selects |
| `ex_mem_reg.sv` | Pipeline reg | EX/MEM, carries `funct3` to the load/store unit, valid bit |
| `mem_wb_reg.sv` | Pipeline reg | MEM/WB with valid bit |
| `forwarding_unit.sv` | Control | EX/MEM and MEM/WB bypass selection (evaluated in ID) |
| `hazard_unit.sv` | Control | Load-use stall and branch/jump flush |
| `tb_riscv_core.sv` | Testbench | Self-checking integration tests, C program mode, `tohost` mode, IPC counters |
| `tb_alu.sv`, `tb_regfile.sv`, `tb_imm_gen.sv` | Testbench | Unit tests |
| `run_all.sh` | Script | Builds once, runs every built-in test, compiles and runs the C program |
| `run_riscv_tests.sh` | Script | Rebuilds the simulator, then builds and runs every applicable rv32ui test; `ENV=official` uses the suite's standard environment |
| `lint_core.sh` | Script | Verilator `-Wall` lint of the synthesizable core only |
| `sw/crt0.S` | Software | Startup: sets the stack pointer, calls `main`, stores the result and a done flag |
| `sw/link.ld` | Software | Places code at address 0; refuses global data (separate instruction and data memories) |
| `sw/prog.c` | Software | Bubble sort test program |
| `sw/bin2hex.py` | Software | Converts the binary into one 32-bit word per line for `$readmemh` |
| `sw/env/riscv_test.h` | Software | Test environment for `riscv-tests`: reports pass/fail through memory instead of `ecall` |
| `sw/tests.ld` | Software | Linker script for `riscv-tests`: code at `0x0`, test data at `0x2000` |
| `sw/tests_official.ld` | Software | The same, plus the official environment's `tohost` result word at `0x3000` |
| `asic/config.json` | ASIC | LibreLane configuration for hardening `riscv_core` in Sky130 |
| `asic/report.sh` | ASIC | Summarizes the latest run: setup/hold slack per corner, slew/cap violations, cell count, area, critical path start and end registers |
| `asic/trace.py` | ASIC | Traces a net in the final netlist back through inserted buffers to the RTL signal that drives it |

---

## Running the Tests

Requires [Verilator](https://verilator.org) 5.x and a RISC-V GCC (`brew install verilator riscv64-elf-gcc` on macOS). For the compliance suite, clone `riscv-tests` next to this repository with its environment submodule: `git clone --recursive https://github.com/riscv-software-src/riscv-tests ../riscv-tests`.

```bash
ENV=official ./run_riscv_tests.sh                             # rv32ui suite, standard environment (ecall traps, tohost)
./run_riscv_tests.sh                                          # rv32ui suite, simplified environment
./run_all.sh                                                  # every built-in test plus the C program
./obj_dir/Vtb_riscv_core +TEST=4                              # one built-in test
./obj_dir/Vtb_riscv_core +HEX=sw/prog.hex +EXPECT=01234567    # a compiled program and its expected result
./lint_core.sh                                                # lint the synthesizable core
```

Building a C program by hand:

```bash
cd sw
riscv64-elf-gcc -march=rv32i -mabi=ilp32 -O1 -nostdlib -ffreestanding -T link.ld crt0.S prog.c -o prog.elf
riscv64-elf-objcopy -O binary prog.elf prog.bin
python3 bin2hex.py prog.bin prog.hex
riscv64-elf-objdump -d prog.elf          # disassembly, useful alongside the waveform
```

`crt0.S` stores `main`'s return value at data address `0x3F8` and then writes `1` to `0x3FC`. The testbench waits for that flag and checks the result against `+EXPECT`. Programs must not use global or static data, because the instruction and data memories are separate; the linker script fails the build if they do. RV32I has no multiply or divide, so programs avoid `*` and `/`.

Each run writes `wave.vcd`, which opens in [Surfer](https://surfer-project.org) (`surfer wave.vcd`) or GTKWave.

---

## Verification

| Test | Covers |
| --- | --- |
| `+TEST=0` | ALU immediates, EX/MEM and MEM/WB forwarding into an `add`, forwarding store data, store then load |
| `+TEST=1` | Every branch type taken and not taken, signed vs unsigned comparison with a negative operand, forwarding into branch operands |
| `+TEST=2` | JAL and JALR redirect and flush, link register = PC + 4, forwarding into the JALR base register |
| `+TEST=3` | LUI and AUIPC, building a 32-bit constant with LUI + ADDI. The registers named by LUI's rs1 bits are preloaded with non-zero values, so a missing operand-A mux cannot pass by accident |
| `+TEST=4` | LB/LBU/LH/LHU/LW with values whose top bit is set (sign extension) and clear, SB and SH into the same word so only their bytes may change |
| `+TEST=5` | Loads followed by `lui` and `addi` whose immediate bits match the load's destination: no stall (9 cycles, not 11) |
| `+TEST=6` | A load followed immediately by a store of the loaded value: the stall must happen (10 cycles) |
| `+TEST=7` | A trap handler: `mtvec` setup, `ecall` and `ebreak`, `mcause` and `mepc`, `mret` back past the trap, a CSR written in the handler and read after it, forwarding into and out of CSR instructions |
| `+HEX=sw/prog.hex` | Compiled C: function call and return, stack, nested loops, signed compares, shifts, loads and stores. 553 instructions |

Each built-in program ends with `addi x6, x0, 7`, which marks the end for the IPC counters and is checked as the last test. The C program ends with the done flag instead, because compiled code is free to use `x6` (`t1`).

Every RTL change made for timing closure was followed by the full regression (`run_all.sh` and both `riscv-tests` environments), with identical results and identical cycle counts.

### Compliance: `riscv-tests`

The official [`riscv-tests`](https://github.com/riscv-software-src/riscv-tests) suite has one test program per instruction, each running dozens of cases: every forwarding distance, negative operands, shifts by 0 and 31, `x0` as a destination. **All 40 applicable rv32ui tests pass.**

| Group | Tests | Result |
| --- | --- | --- |
| Arithmetic and logic | `add addi sub and andi or ori xor xori` | Pass |
| Shifts | `sll slli srl srli sra srai` | Pass |
| Compares | `slt slti sltu sltiu` | Pass |
| Upper immediates | `lui auipc` | Pass |
| Branches | `beq bne blt bge bltu bgeu` | Pass |
| Jumps | `jal jalr` | Pass |
| Loads | `lb lbu lh lhu lw` | Pass |
| Stores | `sb sh sw` | Pass |
| Mixed | `ld_st st_ld simple` | Pass |
| Not run | `fence_i` (needs `fence.i` and self-modifying code), `ma_data` (misaligned access) | Excluded |

The suite runs in two environments, and all 40 tests pass in both:
* **Official environment** (`ENV=official`). The suite's own `env/p` environment, unmodified. Each test writes several CSRs and enters through `mret`, and ends with an `ecall` that traps to the environment's handler, which reads `mcause` and writes the result to `tohost` (placed at `0x3000`): `1` for pass, or `(case << 1) | 1` for a failure. Every test therefore also exercises the trap path. CSRs the environment touches that this core does not implement (such as `satp`, `pmpaddr0`, `medeleg`, `mideleg`, `mie`) read as zero and ignore writes; none of them affect a single-hart, machine-mode core without virtual memory or interrupts.
* **Simplified environment** (default). `sw/env/riscv_test.h` replaces the reporting macros so each test writes `1` or the failing case number to `0x3F8` without using CSRs or traps. It was used before the trap mechanism existed and still isolates the base instructions from the trap logic.
* **Code and data images.** Each test is linked with code at `0x0` and its data tables at `0x2000`, then split into two hex files: one for the instruction memory, one for the data memory. The tests reach their data with `la` (AUIPC + ADDI), so the PC-relative addresses resolve correctly.
* **Checking the checker.** With arithmetic right shift deliberately broken (`>>` instead of `>>>`), `sra` and `srai` failed at case 3, the first case that shifts a negative number, and `lui` failed too, because its test checks the upper bits through an `sra`. With the store-data load-use stall removed, the individual store tests still passed but `ld_st` failed, along with directed test 6. Restoring each change returned all 40 to passing.

This is the `riscv-tests` suite, not the formal RISC-V architecture certification tests (`riscv-arch-test`).

### Bugs Found and Fixed

| Bug | How it was found | Fix |
| --- | --- | --- |
| A dependency exactly 3 instructions apart read a stale register (WB writes at the edge while ID reads in the same cycle; the producer has left the forwarding window) | Design review, confirmed by a directed distance-3 test that failed | Write-through bypass in the register file |
| A taken branch flushed only 2 of the 3 wrong-path instructions (branches resolved in MEM) | Design review, confirmed by a taken-branch test | Branches resolve in EX, matching the 2-stage flush |
| A load-use stall in the same cycle as a taken branch could drop the branch target | Design review | Removed by resolving branches in EX (a branch and a load can no longer both be in EX) |
| JAL/JALR decoded but never redirected the PC | Verilator lint: unused `jump` signal | Implemented jumps |
| Performance counter reported 8 retired instructions for a 6-instruction program | IPC prediction did not match measurement; traced in the waveform | The valid bit was combinational in EX/MEM and MEM/WB; now registered |
| JAL treated as JALR | Jump test: the JAL target never executed | The JAL/JALR select was taken from an inverted opcode bit; now decoded as a `jalr` signal in the control unit |
| AUIPC wrote the immediate instead of PC + immediate, while LUI appeared to pass | Test 3 failed for AUIPC; analysis showed LUI only passed because the registers named by its rs1 bits held zero | Added the missing operand-A mux; strengthened the test so LUI cannot pass by coincidence |
| Every load and store behaved as a signed byte access | Test 4: seven failures traced to a single cause, `funct3 = 000` at the data memory | The data memory's new `funct3` port was not connected in the core |
| Removing false stalls also removed required ones | The bubble sort returned a wrong result and retired 454 instead of 553 instructions (a different path), and five load tests failed at their first zero-NOP bypass case | The `uses_rs1`/`uses_rs2` flags were paired with the wrong source registers; added test 6 for the store-data case |
| `if (rst \|\| flush)` inside an asynchronously reset `always_ff` simulated correctly but was rejected by synthesis ("multiple edge sensitive events") | Yosys, on the first ASIC run | Asynchronous reset tested on its own (`if (rst) ... else if (flush) ...`) |

---

## ASIC Implementation (RTL to GDSII)

`riscv_core` was hardened into a GDSII layout with [LibreLane](https://github.com/librelane/librelane) 3.0.17 (Classic flow: Yosys synthesis, OpenROAD floorplan, placement, clock tree synthesis, routing and static timing analysis, Magic/KLayout and Netgen signoff), in the SkyWater 130 nm process with the `sky130_fd_sc_hd` standard-cell library, run through Docker on an Apple M2.

**Scope.** Only the core is hardened. The instruction and data memories stay outside the block, behind its memory ports; in a full chip they would be SRAM macros. The 32 x 32 register file is built from flip-flops (about 1,600 flip-flops in total). Clock and I/O constraints use LibreLane's generic SDC: a 20 ns clock on `clk`, with default input/output delays.

### Results (final run)

| Metric | Result |
| --- | --- |
| Clock | 50 MHz (20 ns) |
| Setup slack, worst slow corner (ss, 100 °C, 1.60 V) | **+3.63 ns** (met) |
| Setup slack, typical corner (tt, 25 °C, 1.80 V) | +10.71 ns (data path about 9.3 ns) |
| Hold slack, worst fast corner (ff, −40 °C, 1.95 V) | +0.09 ns (met) |
| Corners checked | 3 PVT corners x 3 wiring (RC) corners = 9, setup and hold met in all |
| DRC / LVS / antenna | Clean |
| Standard cells | 17,575 (including 5,666 buffers inserted by design repair) |
| Cell area | 139,628 µm² (0.14 mm²) |
| Max slew violations (ss) | 1,277 (see Remaining Issues) |
| Max capacitance violations (ss) | 3 |

```bash
python3 -m venv ~/librelane-venv && source ~/librelane-venv/bin/activate
pip install librelane
python3 -m librelane --dockerized --pdk-root $HOME/.ciel asic/config.json   # about 10 minutes
./asic/report.sh                                                           # summary of the latest run
```

Runs go to `asic/runs/` (ignored by git, about 1 GB each). The final layout is in `asic/runs/<run>/final/gds/`.

### Timing closure

The first full run missed timing at the slow corner by almost 4 ns. Each later run changed one thing, so the effect of each change could be measured. Worst-case setup slack at the slow corner, at 20 ns unless noted:

| Run | Change | ss setup slack | Slew violations (ss) | Kept? |
| --- | --- | --- | --- | --- |
| 1 | First complete run | −3.96 ns | | |
| 2 | ID/EX flush clears only side-effect control bits | −3.62 ns | | Yes |
| 3 | Clock relaxed to 25 ns | −4.95 ns | | No: slower, not faster |
| 4 | Post-global-routing repair and timing optimization enabled | −2.75 ns | | Yes |
| 5 | IF/ID flush through the valid bit only | −3.23 ns | | Yes (within run-to-run noise; simpler logic) |
| 6 | Forwarding selects computed in ID and registered | −1.82 ns | 2,807 | Yes |
| 7 | Core utilization 40% → 50% | −1.75 ns | 3,159 | No: more slew and cap violations |
| 8 | Maximum wire length 300 µm during repair | −1.83 ns | 2,384 | Yes |
| 9 | One-hot forwarding mux | −2.93 ns | 2,467 | Yes, see below |
| 10 | Synthesis strategy `AREA 0` → `DELAY 1` | **+1.36 ns** | 2,946 | Yes |
| 11 | Delay cells excluded from buffering | +2.55 ns | 3,447 | Yes |
| 12 | Repair margins 40% / 30% | **+3.63 ns** | **1,277** | Yes (final) |
| 13 | Repair margins 60% / 50% | Crashed in OpenROAD's repair step | | No |

Run-to-run variation from placement is about ±0.5 ns, so small differences such as runs 5 and 7 are noise.

**How the critical paths were found.** For each run, `asic/report.sh` reads the static timing report and maps the critical path's start and end flip-flops back to RTL register names. Reading the per-cell delays of the path then showed where the time went:

* **Runs 1–6: forwarding control in EX.** The early critical paths started at EX/MEM and MEM/WB registers (destination register address, write-back select) and ended at the PC or IF/ID. In EX, the register-address compares, the forwarding mux, the ALU or branch compare and the PC select were all in series. Computing the forwarding selects in ID removed the compares from EX entirely (run 6, the best result up to that point).
* **Runs 7–9: the branch-to-PC path.** The per-cell breakdown of the run 9 path showed about 4.9 ns of buffers distributing the forwarding select to 32 mux bits, 6.6 ns in a chain of four `or4` gates (the 32-bit equality compare built as a chain rather than a tree), and 3.5 ns distributing `branch_taken` to the 32-bit PC mux.
* **Run 10: synthesis for delay.** The default synthesis script optimizes for area, which produced the `or4` chain. `DELAY 1` builds shallower logic, at about 7% more area. This was the largest single gain (+4.3 ns), and it moved the critical path off the branch-to-PC path onto an ordinary ALU path.
* **Run 11: no delay cells as buffers.** The buffer trees on the critical paths were built partly from `clkdlybuf4s*` cells, which are deliberately slow cells intended for hold fixing. Excluding them (`EXTRA_EXCLUDED_CELLS`) gained another 1.2 ns and reduced area. Hold timing stayed met without them.

The one-hot mux (run 9) measured worse on its own. It removes a decode gate from the mux select, but the select's buffering dominated that path either way, so it was kept; it was not re-measured on its own after run 10.

**Slew violations.** The trace through the netlist (`asic/trace.py`) showed that the violating nets are not high-fanout signals in the RTL: each violating buffer drove only 5–7 loads, but over long wires with a weak `buf_1` cell. Counting violations after each step of the flow located the cause:

| STA step | Slew violations (typical corner) |
| --- | --- |
| After synthesis (no buffering yet) | 5,632 |
| After global placement (real distances) | 9,355 |
| After design repair | 30 |
| After post-global-routing repair | **0** |
| After detailed routing and parasitic extraction | **688** |

The repair steps fix every violation according to their own estimate of the wiring, but the real routed wires carry more capacitance than estimated, and no repair runs after detailed routing. Making the repair aim below the limit (`DESIGN_REPAIR_MAX_SLEW_PCT` 40, `GRT_DESIGN_REPAIR_MAX_SLEW_PCT` 30, and the same for capacitance) absorbs part of that error: slow-corner slew violations fell by 63% and capacitance violations from 31 to 3, and setup slack improved as well, because the faster edges also speed up the paths.

### Configuration

```json
{
  "DESIGN_NAME": "riscv_core",
  "VERILOG_FILES": ["dir::../riscv_core.sv", "dir::../if_id_reg.sv", "...", "dir::../lsu.sv"],
  "CLOCK_PORT": "clk",
  "CLOCK_PERIOD": 20,
  "FP_CORE_UTIL": 40,
  "SYNTH_STRATEGY": "DELAY 1",
  "EXTRA_EXCLUDED_CELLS": [
    "sky130_fd_sc_hd__clkdlybuf4s*",
    "sky130_fd_sc_hd__dlygate4sd*",
    "sky130_fd_sc_hd__dlymetal6s*"
  ],
  "DESIGN_REPAIR_MAX_WIRE_LENGTH": 300,
  "GRT_DESIGN_REPAIR_MAX_WIRE_LENGTH": 300,
  "DESIGN_REPAIR_MAX_SLEW_PCT": 40,
  "DESIGN_REPAIR_MAX_CAP_PCT": 40,
  "GRT_DESIGN_REPAIR_MAX_SLEW_PCT": 30,
  "GRT_DESIGN_REPAIR_MAX_CAP_PCT": 30,
  "RUN_POST_GRT_DESIGN_REPAIR": true,
  "RUN_POST_GRT_RESIZER_TIMING": true
}
```

### Remaining issues

* **1,277 max-slew violations at the slow corner** (and 3 capacitance violations) remain after routing. They do not break timing: static timing analysis includes the slow edges in its delays, and setup still has 3.6 ns of margin. They are still design-rule violations, so the layout is timing-clean and DRC/LVS-clean but not fully signoff-clean. Further steps would be a repair pass after detailed routing, or tuning the wire-length limit: OpenROAD reported that a limit below about 6,000 µm adds wire delay, so 300 µm may buffer more nets than necessary.
* **Generic constraints.** The input/output delays come from LibreLane's default SDC, not from a real chip's memory interface. With real SRAM macros, the memory paths would need their own constraints.
* **Hold margin is thin** (+0.09 ns at the fast corner) and would need re-checking after any change.

---

## Corrections to Earlier Claims

Earlier versions of this README and my resume made claims the repository did not support. This is where each one stands now.

**"Full RV32I ISA compliance."** This was not true. At the time, `jal`/`jalr` were decoded but not connected, every branch behaved like `beq`, `lui`, `auipc`, sub-word loads and stores and the system instructions were missing, and the official test suite had never been run. All of these are now implemented, and the core passes all 40 applicable rv32ui tests of the official `riscv-tests` suite in its standard environment (see Compliance). The accurate description is "passes the rv32ui `riscv-tests`"; formal compliance would mean the `riscv-arch-test` certification suite, which has not been run.

**"Sustained IPC of 0.88."** This number was not measured: the design had no counters, and the only test program was 5 instructions long. Measuring IPC properly needed a valid bit in every pipeline register. That work also showed how easily IPC is misreported: counting until the end of a padded simulation gave 0.95, because the NOPs after the program retire one per cycle. The measured figure on compiled code is 0.76.

**"10 µs testbenches running compiled C workloads."** This was not true then: the tests were short hand-encoded programs. It is true now: the core runs a GCC-compiled bubble sort (553 instructions, about 15 µs of simulated time).

**"Operating at 50 MHz."** At the time, 50 MHz was only the testbench clock. It is now backed by static timing analysis: the core meets timing at 50 MHz across all 9 corners in SkyWater 130 nm (see ASIC Implementation). It has not yet been run on an FPGA.

---

## Use of AI

I used AI assistants during this project, and I want to be clear about how.

* **Original design:** I used AI to help bridge pipelining theory and RTL while writing the pipelined datapath, and to generate the original testbenches. Those tests passed but shared the design's blind spots: they never exercised the cases where the bugs were.
* **Review:** I later had a different AI model review the design. It flagged the stale register read, the incomplete branch flush, the stall/branch conflict, and the unsupported claims above.
* **Fixes and new features:** I confirmed each bug with a directed test that failed, then implemented the fixes and the new features: `branch_unit`, valid bits and counters, JAL/JALR, LUI/AUIPC, byte/halfword memory access, the larger memories with data-image loading, the `uses_rs1`/`uses_rs2` hazard fix, and the CSR unit with traps (scaffolded by the AI, completed and wired in by me). The AI acted as a tutor: it explained concepts, gave scaffolds and hints, reviewed my code, and helped me debug from test results and waveforms.
* **ASIC flow:** I ran every LibreLane run and made the RTL and configuration changes. The AI explained the flow and the reports, proposed what to try next, and wrote the restructured pipeline registers (`if_id_reg.sv`, `id_ex_reg.sv`), `lsu.sv`, `soc_sim.sv` and the analysis scripts (`asic/report.sh`, `asic/trace.py`). Several of its predictions were wrong when measured, for example that relaxing the clock would help, that higher utilization would help, and that the slew violations came from the corner used for repair. The table above records the measured results, not the predictions.
* **What the AI wrote:** the machine code for the hand-encoded test programs, the `+TEST`/`+HEX` selection, `run_all.sh`, the software flow in `sw/` (`crt0.S`, `link.ld`, `prog.c`, `bin2hex.py`), the `riscv-tests` environments and flow (`sw/env/riscv_test.h`, `sw/tests.ld`, `sw/tests_official.ld`, `run_riscv_tests.sh`, the testbench's `tohost` mode), the files listed under ASIC flow, and drafts of this README.
* **Verification:** every change was checked by simulation and regression in Verilator, every IPC figure was predicted by hand before being measured, and every timing change was measured with a full flow run.

The main lesson: when the same source helps write the design and its tests, the tests inherit its assumptions. Independent review, directed tests that are able to fail, and measuring each change on its own are what found these problems.

---

## Next Steps

* Clear the remaining slew violations (post-route repair, wire-length tuning)
* Misaligned-access and illegal-instruction exceptions
* Run the formal `riscv-arch-test` suite
* Use the data-image loading built for `riscv-tests` so C programs can have global variables
* Synthesize on an FPGA (Real Digital Boolean board, Spartan-7) and close timing
