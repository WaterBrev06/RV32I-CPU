#!/bin/bash
verilator --binary --timing --assert -Wno-fatal --top-module tb_riscv_core \
  tb_riscv_core.sv riscv_core.sv *_reg.sv alu.sv alu_control.sv control_unit.sv \
  immgen.sv regfile.sv instr_mem.sv data_mem.sv forwarding_unit.sv hazard_unit.sv \
  branch_unit.sv csr_unit.sv lsu.sv soc_sim.sv || exit 1

T=../riscv-tests/isa
OUT=build_tests; mkdir -p $OUT
pass=0; fail=0
ENV=${ENV:-custom}
if [ "$ENV" = official ]; then
  INC="-I ../riscv-tests/env/p -I ../riscv-tests/env"; LD=sw/tests_official.ld
  MARCH=rv32i_zicsr; EXTRA=+TOHOST
else
  INC="-I sw/env"; LD=sw/tests.ld; MARCH=rv32i; EXTRA=
fi
for src in $T/rv32ui/*.S; do
  name=$(basename $src .S)
  case $name in fence_i|ma_data) continue;; esac     # need fence.i / misaligned access: not supported
  riscv64-elf-gcc -march=$MARCH -mabi=ilp32 -nostdlib -nostartfiles -T $LD \
      $INC -I $T/macros/scalar $src -o $OUT/$name.elf || { echo "BUILD FAIL  $name"; fail=$((fail+1)); continue; }
  riscv64-elf-objcopy -O binary -j .text $OUT/$name.elf $OUT/$name.text.bin
  riscv64-elf-objcopy -O binary -j .data $OUT/$name.elf $OUT/$name.data.bin
  python3 sw/bin2hex.py $OUT/$name.text.bin $OUT/$name.text.hex
  args="+HEX=$OUT/$name.text.hex +EXPECT=1 $EXTRA"
  if [ -s $OUT/$name.data.bin ]; then
    python3 sw/bin2hex.py $OUT/$name.data.bin $OUT/$name.data.hex
    args="$args +DHEX=$OUT/$name.data.hex"
  fi
  result=$(./obj_dir/Vtb_riscv_core $args)
  if echo "$result" | grep -q "^SUCCESS"; then
    echo "PASS  $name"; pass=$((pass+1))
  else
    echo "FAIL  $name: $(echo "$result" | grep -m1 FAIL)"; fail=$((fail+1))
  fi
done
echo "[$ENV environment] $pass passed, $fail failed"
