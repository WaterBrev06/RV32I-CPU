# 32-Bit 5-Stage Pipelined RISC-V (RV32I) Processor Core

A 32-bit, 5-stage pipelined RISC-V processor written in SystemVerilog. It implements every RV32I computational, control-flow and load/store instruction (all except `fence`, `ecall` and `ebreak`), with full hazard handling: forwarding, load-use stalls, branch/jump flushes and a register-file write-through bypass. It runs C programs compiled with GCC, and is verified with self-checking directed tests in Verilator, with pipeline valid bits and performance counters to measure IPC.

---

## Key Metrics

* **Pipeline depth:** 5 stages (`IF`, `ID`, `EX`, `MEM`, `WB`)
* **Branch/jump resolution:** EX stage, 2-cycle penalty for a taken branch or jump
* **Load-use penalty:** 1 stall cycle
* **ALU:** 10 operations (`ADD`, `SUB`, `AND`, `OR`, `XOR`, `SLL`, `SRL`, `SRA`, `SLT`, `SLTU`), operand A selectable between rs1, PC and zero
* **Register file:** 32 x 32-bit, dual asynchronous read / synchronous write, write-through bypass, `x0` hardwired to 0
* **Memories:** 1 KB instruction memory, 1 KB data memory with byte enables (Harvard architecture)
* **Target clock:** 50 MHz (testbench clock; FPGA timing not yet closed)
* **Measured IPC** (retired instructions / cycles, including the 4-cycle pipeline fill):

| Program | Retired | Cycles | IPC |
| --- | --- | --- | --- |
| C: bubble sort of 8 values (GCC `-O1`) | 553 | 730 | 0.76 |
| 0: ALU, forwarding, load/store | 6 | 10 | 0.60 |
| 1: All branch types | 11 | 21 | 0.52 |
| 2: JAL / JALR | 7 | 15 | 0.47 |
| 3: LUI / AUIPC | 8 | 12 | 0.67 |
| 4: Byte and halfword loads/stores | 15 | 19 | 0.79 |

The C program is the representative number. The directed tests are short, so the pipeline fill and taken-branch bubbles dominate them. In the bubble sort, the lost cycles are mostly taken loop branches (2 cycles each, about one per inner iteration) plus load-use stalls (1 cycle each).

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
| System | `fence`, `ecall`, `ebreak` | Not yet |

Misaligned halfword and word accesses are not supported; the RISC-V specification allows a core to trap on them instead.

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
     instr_mem        regfile             alu            data_mem          regfile
         |            immgen          branch_unit       (byte enables,     (write)
         |         control_unit       alu_control        sign/zero ext.)
         |                                 |
         +------ branch / jump target ------+
                                           ^
                                    FORWARDING UNIT  (from EX/MEM and MEM/WB)
```

### Pipeline Breakdown

1. **Instruction Fetch (IF):** Selects PC + 4 or the branch/jump target from EX, and fetches the instruction from `instr_mem.sv`.
2. **Instruction Decode (ID):** Decodes the opcode in `control_unit.sv`, reads `regfile.sv` and builds the immediate in `immgen.sv`. Control signals are decoded once here and travel down the pipeline with the instruction.
3. **Execute (EX):** The ALU's operand A is the forwarded rs1, the PC (`auipc`) or zero (`lui`); operand B is the forwarded rs2 or the immediate. `branch_unit.sv` evaluates all six branch conditions on the forwarded register values. Branch and JAL targets are `PC + imm`; the JALR target is `(rs1 + imm) & ~1`. A taken branch or any jump redirects the PC and flushes IF/ID and ID/EX. Jumps compute their write-back value (PC + 4) here, so every forwarding path sees the final result.
4. **Memory (MEM):** `data_mem.sv` uses `funct3` and the low address bits to write only the enabled bytes on stores, and to select and sign- or zero-extend the byte or halfword on loads.
5. **Write-Back (WB):** Selects the loaded data or the EX result and writes it to the register file.

### Hazard Handling

| Hazard | Mechanism |
| --- | --- |
| RAW, producer 1 instruction ahead | Forward from EX/MEM (`forward = 2'b10`) |
| RAW, producer 2 instructions ahead | Forward from MEM/WB (`forward = 2'b01`) |
| RAW, producer 3 instructions ahead | Register-file write-through bypass (WB writes and ID reads the same register in one cycle) |
| Load-use | Stall PC and IF/ID for one cycle, insert a bubble into ID/EX |
| Taken branch / jump | Resolve in EX, flush IF/ID and ID/EX (2 bubbles) |

The hazard and forwarding units compare the rs1/rs2 fields of every instruction, including those (such as `lui`) whose fields are really immediate bits. This can cause a harmless forward, or an unnecessary one-cycle stall; neither affects correctness.

### Valid Bits and Performance Counters

A `valid` bit travels through every pipeline register. It is set when an instruction is fetched and cleared on reset, flush or bubble insertion. The testbench counts cycles and retired instructions (`wb_valid`) until each program ends, which gives the IPC figures above.

---

## Project Structure

| File | Type | Description |
| --- | --- | --- |
| `riscv_core.sv` | Top module | Integrates the 5 stages, pipeline registers and control units |
| `instr_mem.sv` | Design | 1 KB instruction ROM; loads a hex file with `+HEX=file`, or a built-in test with `+TEST=N` |
| `data_mem.sv` | Design | 1 KB data RAM: byte-enable writes, byte/halfword/word reads with sign or zero extension |
| `regfile.sv` | Design | 32 x 32-bit register file with write-through bypass and hardwired `x0` |
| `alu.sv` | Design | 32-bit, 10-operation ALU |
| `alu_control.sv` | Design | Decodes `alu_op`, `funct3`, `funct7` into ALU control |
| `branch_unit.sv` | Design | Evaluates BEQ/BNE/BLT/BGE/BLTU/BGEU on forwarded operands |
| `control_unit.sv` | Design | Main decoder, including `jump`, `jalr` and the ALU operand-A select |
| `immgen.sv` | Design | Immediate generator for I, S, B, U and J formats |
| `if_id_reg.sv` | Pipeline reg | IF/ID with stall, flush and valid bit |
| `id_ex_reg.sv` | Pipeline reg | ID/EX with flush (bubble insertion) and valid bit |
| `ex_mem_reg.sv` | Pipeline reg | EX/MEM, carries `funct3` to the data memory, valid bit |
| `mem_wb_reg.sv` | Pipeline reg | MEM/WB with valid bit |
| `forwarding_unit.sv` | Control | EX/MEM and MEM/WB bypass selection |
| `hazard_unit.sv` | Control | Load-use stall and branch/jump flush |
| `tb_riscv_core.sv` | Testbench | Self-checking integration tests, C program mode, IPC counters |
| `tb_alu.sv`, `tb_regfile.sv`, `tb_imm_gen.sv` | Testbench | Unit tests |
| `run_all.sh` | Script | Builds once, runs every built-in test, compiles and runs the C program |
| `sw/crt0.S` | Software | Startup: sets the stack pointer, calls `main`, stores the result and a done flag |
| `sw/link.ld` | Software | Places code at address 0; refuses global data (separate instruction and data memories) |
| `sw/prog.c` | Software | Bubble sort test program |
| `sw/bin2hex.py` | Software | Converts the binary into one 32-bit word per line for `$readmemh` |

---

## Running the Tests

Requires [Verilator](https://verilator.org) 5.x and a RISC-V GCC (`brew install verilator riscv64-elf-gcc` on macOS).

```bash
./run_all.sh                                                  # every built-in test plus the C program
./obj_dir/Vtb_riscv_core +TEST=4                              # one built-in test
./obj_dir/Vtb_riscv_core +HEX=sw/prog.hex +EXPECT=01234567    # a compiled program and its expected result
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

Lint:

```bash
verilator --lint-only -Wall riscv_core.sv *_reg.sv alu*.sv control_unit.sv immgen.sv \
  regfile.sv instr_mem.sv data_mem.sv forwarding_unit.sv hazard_unit.sv branch_unit.sv
```

Address bits that the 1 KB memories do not use are routed into signals named `unused_*`, so lint still flags any other unused bit.

---

## Verification

| Test | Covers |
| --- | --- |
| `+TEST=0` | ALU immediates, EX/MEM and MEM/WB forwarding into an `add`, forwarding store data, store then load |
| `+TEST=1` | Every branch type taken and not taken, signed vs unsigned comparison with a negative operand, forwarding into branch operands |
| `+TEST=2` | JAL and JALR redirect and flush, link register = PC + 4, forwarding into the JALR base register |
| `+TEST=3` | LUI and AUIPC, building a 32-bit constant with LUI + ADDI. The registers named by LUI's rs1 bits are preloaded with non-zero values, so a missing operand-A mux cannot pass by accident |
| `+TEST=4` | LB/LBU/LH/LHU/LW with values whose top bit is set (sign extension) and clear, SB and SH into the same word so only their bytes may change |
| `+HEX=sw/prog.hex` | Compiled C: function call and return, stack, nested loops, signed compares, shifts, loads and stores. 553 instructions |

Each built-in program ends with `addi x6, x0, 7`, which marks the end for the IPC counters and is checked as the last test. The C program ends with the done flag instead, because compiled code is free to use `x6` (`t1`).

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

---

## Corrections to Earlier Claims

Earlier versions of this README and my resume made claims the repository did not support. This is where each one stands now.

**"Full RV32I ISA compliance."** This was not true. At the time, `jal`/`jalr` were decoded but not connected, every branch behaved like `beq`, and `lui`, `auipc`, sub-word loads and stores and the system instructions were missing. All of these except `fence`, `ecall` and `ebreak` are now implemented and tested. Compliance means passing the official `riscv-tests` suite, which has not been run yet, so the core is described as implementing RV32I except the system instructions.

**"Sustained IPC of 0.88."** This number was not measured: the design had no counters, and the only test program was 5 instructions long. Measuring IPC properly needed a valid bit in every pipeline register. That work also showed how easily IPC is misreported: counting until the end of a padded simulation gave 0.95, because the NOPs after the program retire one per cycle. The measured figure on compiled code is 0.76.

**"10 µs testbenches running compiled C workloads."** This was not true then: the tests were short hand-encoded programs. It is true now: the core runs a GCC-compiled bubble sort (553 instructions, about 15 µs of simulated time).

**"Operating at 50 MHz."** 50 MHz is the testbench clock; timing has not been closed on an FPGA.

---

## Use of AI

I used AI assistants during this project, and I want to be clear about how.

* **Original design:** I used AI to help bridge pipelining theory and RTL while writing the pipelined datapath, and to generate the original testbenches. Those tests passed but shared the design's blind spots: they never exercised the cases where the bugs were.
* **Review:** I later had a different AI model review the design. It flagged the stale register read, the incomplete branch flush, the stall/branch conflict, and the unsupported claims above.
* **Fixes and new features:** I confirmed each bug with a directed test that failed, then implemented the fixes and the new features: `branch_unit`, valid bits and counters, JAL/JALR, LUI/AUIPC and byte/halfword memory access. The AI acted as a tutor: it explained concepts, gave scaffolds and hints, reviewed my code, and helped me debug from test results and waveforms.
* **What the AI wrote:** the machine code for the hand-encoded test programs, the `+TEST`/`+HEX` selection, `run_all.sh`, the software flow in `sw/` (`crt0.S`, `link.ld`, `prog.c`, `bin2hex.py`), and drafts of this README.
* **Verification:** every change was checked by simulation and regression in Verilator, and every IPC figure was predicted by hand before being measured.

The main lesson: when the same source helps write the design and its tests, the tests inherit its assumptions. Independent review, and directed tests that are able to fail, are what found these problems.

---

## Next Steps

* Run the official `riscv-tests` suite, with a test environment that reports pass/fail through a memory write instead of `ecall`
* `fence`, `ecall` and `ebreak`
* Only check source registers an instruction actually uses (removes unnecessary load-use stalls after `lui`, `auipc` and `jal`)
* Load initialized data into the data memory as well, so C programs can use global variables
* Synthesize on an FPGA (Real Digital Boolean board, Spartan-7) and close timing
