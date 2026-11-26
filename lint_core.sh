#!/bin/bash
verilator --lint-only -Wall --top-module riscv_core riscv_core.sv *_reg.sv alu*.sv \
  control_unit.sv immgen.sv regfile.sv forwarding_unit.sv hazard_unit.sv \
  branch_unit.sv csr_unit.sv lsu.sv && echo "Core lint clean"
