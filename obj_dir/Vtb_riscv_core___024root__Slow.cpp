// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vtb_riscv_core.h for the primary calling header

#include "Vtb_riscv_core__pch.h"

void Vtb_riscv_core___024root___ctor_var_reset(Vtb_riscv_core___024root* vlSelf);

void Vtb_riscv_core___024root__ctor(Vtb_riscv_core___024root* vlSelf, Vtb_riscv_core__Syms* symsp, const char* namep) {
    vlSelf->vlSymsp = symsp;
    vlSelf->vlNamep = strdup(namep);
    // Construct members
    VL_INPLACE_CONSTRUCT(vlSelf->__Vnontrivs.__Vtask_tb_riscv_core__DOT__check_reg__test_desc_2);
    VL_INPLACE_CONSTRUCT(vlSelf->__Vnontrivs.__Vtask_tb_riscv_core__DOT__check_reg__test_desc_5);
    VL_INPLACE_CONSTRUCT(vlSelf->__Vnontrivs.__Vtask_tb_riscv_core__DOT__check_reg__test_desc_8);
    VL_INPLACE_CONSTRUCT(vlSelf->__Vnontrivs.__Vtask_tb_riscv_core__DOT__check_reg__test_desc_11);
    VL_INPLACE_CONSTRUCT(vlSelf->__Vnontrivs.__Vtask_tb_riscv_core__DOT__check_reg__test_desc_14);
    VL_INPLACE_CONSTRUCT(vlSelf->__Vnontrivs.__Vtask_tb_riscv_core__DOT__check_reg__test_desc_17);
    VL_INPLACE_CONSTRUCT(vlSelf->__Vnontrivs.__VdlySched, *vlSelf->vlSymsp->_vm_contextp__);
    // Reset structure values
    Vtb_riscv_core___024root___ctor_var_reset(vlSelf);
}

Vtb_riscv_core___024root::Vtb_riscv_core___024root(Vtb_riscv_core__Syms* symsp, const char* namep) {
    Vtb_riscv_core___024root__ctor(this, symsp, namep);
}

void Vtb_riscv_core___024root__dtor(Vtb_riscv_core___024root* vlSelf) {
    // Destroy members
    VL_INPLACE_DESTRUCT(vlSelf->__Vnontrivs.__VdlySched);
    VL_INPLACE_DESTRUCT(vlSelf->__Vnontrivs.__Vtask_tb_riscv_core__DOT__check_reg__test_desc_17);
    VL_INPLACE_DESTRUCT(vlSelf->__Vnontrivs.__Vtask_tb_riscv_core__DOT__check_reg__test_desc_14);
    VL_INPLACE_DESTRUCT(vlSelf->__Vnontrivs.__Vtask_tb_riscv_core__DOT__check_reg__test_desc_11);
    VL_INPLACE_DESTRUCT(vlSelf->__Vnontrivs.__Vtask_tb_riscv_core__DOT__check_reg__test_desc_8);
    VL_INPLACE_DESTRUCT(vlSelf->__Vnontrivs.__Vtask_tb_riscv_core__DOT__check_reg__test_desc_5);
    VL_INPLACE_DESTRUCT(vlSelf->__Vnontrivs.__Vtask_tb_riscv_core__DOT__check_reg__test_desc_2);
    VL_DO_DANGLING(std::free(const_cast<char*>(vlSelf->vlNamep)), vlSelf->vlNamep);
}

Vtb_riscv_core___024root::~Vtb_riscv_core___024root() {
    Vtb_riscv_core___024root__dtor(this);
}
