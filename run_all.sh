#!/bin/bash
verilator --binary --timing --trace -Wno-fatal --top-module tb_riscv_core \
  tb_riscv_core.sv riscv_core.sv *_reg.sv alu.sv alu_control.sv control_unit.sv \
  immgen.sv regfile.sv instr_mem.sv data_mem.sv forwarding_unit.sv hazard_unit.sv \
  branch_unit.sv || exit 1

for t in 0 1 2 3 4; do
  echo "===== TEST $t ====="
  ./obj_dir/Vtb_riscv_core +TEST=$t | grep -E "FAIL|SUCCESS|FAILURE|IPC"
done
