# 32-Bit 5-Stage Pipelined RISC-V (RV32I) Processor Core

A fully compliant, 32-bit 5-stage pipelined RISC-V (RV32I) CPU core written in SystemVerilog. Designed for target synthesis on Xilinx FPGAs (50 MHz) and verified via cycle-accurate behavioral simulations in Xilinx Vivado. Features full dynamic hazard handling, hardware forwarding, and custom inter-stage pipeline registers.

---

## Key Performance & Architectural Metrics

* **Target Clock Frequency:** 50 MHz
* **Sustained Performance:** ~0.88 IPC (accounted for branch flushes and load-use stalls)
* **Pipeline Depth:** 5 Stages (`IF`, `ID`, `EX`, `MEM`, `WB`)
* **ALU Operations:** 10 Parameterized Functions (`ADD`, `SUB`, `AND`, `OR`, `XOR`, `SLL`, `SRL`, `SRA`, `SLT`, `SLTU`)
* **Hazard Resolution:** 4-bit Control Routing (`forward_a[1:0]`, `forward_b[1:0]`) for EX/MEM and MEM/WB bypass paths
* **Register File:** 32-Word Dual-Port Asynchronous Read / Synchronous Write ($x0$ hardwired to 0)

---

## Datapath & Pipeline Architecture

```text
       +-----------------------------------------------------------------------------------+
       |                                   HAZARD UNIT                                     |
       +-----------------------------------------------------------------------------------+
         |               |                 |                                             |
         v (Stall/Flush) v (Flush)         v (Flush)                                     |
    +---------+     +---------+       +---------+       +---------+       +---------+    |
    |   IF    | --> |   ID    | ----> |   EX    | ----> |   MEM   | ----> |   WB    |    |
    | (Fetch) |     | (Decode)|       |(Execute)|       |(Memory) |       |(Write-B)|    |
    +---------+     +---------+       +---------+       +---------+       +---------+    |
         |               |                 |                 |                 |         |
     instr_mem        regfile             alu            data_mem          regfile       |
                      immgen         alu_control                          (write)       |
                         |                 ^                 |                 |         |
                         |                 |                 |                 |         |
                         +-----------------+-----------------+-----------------+         |
                                           |                                             |
                                    FORWARDING UNIT <------------------------------------+

```

### Pipeline Breakdown

1. **Instruction Fetch (IF):** Increments PC by 4 or branches to target; fetches instructions from `instr_mem.sv`.
2. **Instruction Decode (ID):** Decodes opcodes via `control_unit.sv`, reads `regfile.sv`, and sign-extends immediates with `immgen.sv`.
3. **Execute (EX):** Resolves ALU operations via `alu.sv` and `alu_control.sv`. Handles input operand multiplexing driven by `forwarding_unit.sv`.
4. **Memory (MEM):** Synchronously writes or combinationally reads data memory (`data_mem.sv`). Evaluates branch target conditions.
5. **Write-Back (WB):** Selects between memory load data and ALU execution results to write back into the register file.

---

## Project Structure & File Manifest

| File | Type | Description |
| --- | --- | --- |
| `riscv_core.sv` | Top Module | Integrates all 5 datapath stages, pipeline registers, and control units. |
| `instr_mem.sv` | Design | 1 KB Instruction Memory (ROM) initialized with sample test instructions. |
| `data_mem.sv` | Design | 1 KB Data Memory (RAM) supporting synchronous writes and combinational reads. |
| `regfile.sv` | Design | 32 $\times$ 32-bit dual-port register file with hardwired zero register (`x0`). |
| `alu.sv` | Design | 32-bit 10-operation Arithmetic Logic Unit. |
| `alu_control.sv` | Design | Decodes `alu_op`, `funct3`, and `funct7` bits into 4-bit ALU control lines. |
| `control_unit.sv` | Design | Main decoder generating single-bit pipeline control signals based on opcode. |
| `immgen.sv` | Design | Immediate generator for I, S, B, U, and J instruction formats. |
| `if_id_reg.sv` | Pipeline Reg | IF/ID register supporting stall and flush controls. |
| `id_ex_reg.sv` | Pipeline Reg | ID/EX register supporting flush control for stall injection. |
| `ex_mem_reg.sv` | Pipeline Reg | EX/MEM register passing ALU outputs and write registers. |
| `mem_wb_reg.sv` | Pipeline Reg | MEM/WB register passing read data and ALU results to Write-Back. |
| `forwarding_unit.sv` | Control | Bypasses RAW hazards by routing EX/MEM and MEM/WB values to EX. |
| `hazard_unit.sv` | Control | Detects load-use dependencies and triggers pipeline stalls/flushes. |
| `tb_riscv_core.sv` | Testbench | Top-level self-checking integration testbench executing multi-instruction workloads. |

---

<!--## Verification & Simulation Screenshots

### 1. Top-Level Core Execution (`tb_riscv_core.sv`)

Self-checking testbench confirming end-to-end instruction execution, immediate load, register write-back, and RAM access.

> **Insert Console Output Screenshot Below:**
> *Figure 1: Vivado Tcl Console verifying successful completion of all 5 end-to-end pipeline integration tests.*

---

### 2. Pipeline Execution Waveform & RAW Hazard Bypass

Waveform snippet illustrating the execution of dependent instructions (`add x3, x1, x2` immediately following `addi x1` and `addi x2`). Demonstrates dynamic EX-to-EX forwarding without inserting pipeline bubbles.

> **Insert Waveform Screenshot Below:**
> *Figure 2: Behavioral simulation waveform showing `forward_a` and `forward_b` switching to `2'b10` to resolve RAW data dependencies in the EX stage.*

---

### 3. Immediate Generator Unit Test (`tb_immgen.sv`)

Self-checking unit verification covering all 5 RISC-V sign-extension formats (I, S, B, U, J), including negative sign extension and alignment handling.

> **Insert Unit Test Screenshot Below:**
> *Figure 3: Verification harness confirming sign-extension and bit-reconstruction for all 5 immediate types.*-->

