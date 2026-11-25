#!/bin/bash
verilator --binary --timing --assert --trace -Wno-fatal --top-module tb_riscv_core \
  tb_riscv_core.sv riscv_core.sv *_reg.sv alu.sv alu_control.sv control_unit.sv \
  immgen.sv regfile.sv instr_mem.sv data_mem.sv forwarding_unit.sv hazard_unit.sv \
  branch_unit.sv csr_unit.sv lsu.sv soc_sim.sv|| exit 1

for t in 0 1 2 3 4 5 6 7; do
  echo "===== TEST $t ====="
  ./obj_dir/Vtb_riscv_core +TEST=$t | grep -E "FAIL|SUCCESS|FAILURE|IPC"
done

echo "===== C: bubble sort ====="
(cd sw && riscv64-elf-gcc -march=rv32i -mabi=ilp32 -O1 -nostdlib -ffreestanding -T link.ld crt0.S prog.c -o prog.elf \
  && riscv64-elf-objcopy -O binary prog.elf prog.bin && python3 bin2hex.py prog.bin prog.hex) || exit 1
./obj_dir/Vtb_riscv_core +HEX=sw/prog.hex +EXPECT=01234567 | grep -E "FAIL|SUCCESS|FAILURE|IPC"
