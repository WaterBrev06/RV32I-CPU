// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design internal header
// See Vtb_riscv_core.h for the primary calling header

#ifndef VERILATED_VTB_RISCV_CORE___024ROOT_H_
#define VERILATED_VTB_RISCV_CORE___024ROOT_H_  // guard

#include "verilated.h"
#include "verilated_timing.h"


class Vtb_riscv_core__Syms;

class alignas(VL_CACHE_LINE_BYTES) Vtb_riscv_core___024root final {
  public:

    // TRIVIALLY CONSTRUCTIBLE STATE
    // Anonymous structures to workaround compiler member-count bugs
    struct {
        ::CData/*0:0*/ tb_riscv_core__DOT__clk;
        ::CData/*0:0*/ tb_riscv_core__DOT__rst;
        ::CData/*0:0*/ tb_riscv_core__DOT__done;
        ::CData/*0:0*/ tb_riscv_core__DOT__uut__DOT__pc_stall;
        ::CData/*0:0*/ tb_riscv_core__DOT__uut__DOT__if_id_flush;
        ::CData/*0:0*/ tb_riscv_core__DOT__uut__DOT__id_ex_flush;
        ::CData/*1:0*/ tb_riscv_core__DOT__uut__DOT__forward_a;
        ::CData/*1:0*/ tb_riscv_core__DOT__uut__DOT__forward_b;
        ::CData/*0:0*/ tb_riscv_core__DOT__uut__DOT__mem_wb__DOT__valid_out;
        ::CData/*0:0*/ tb_riscv_core__DOT__uut__DOT__mem_wb__DOT__reg_write_out;
        ::CData/*0:0*/ tb_riscv_core__DOT__uut__DOT__mem_wb__DOT__mem_to_reg_out;
        ::CData/*4:0*/ tb_riscv_core__DOT__uut__DOT__mem_wb__DOT__rd_addr_out;
        ::CData/*0:0*/ tb_riscv_core__DOT__uut__DOT__ex_mem__DOT__valid_out;
        ::CData/*0:0*/ tb_riscv_core__DOT__uut__DOT__ex_mem__DOT__reg_write_out;
        ::CData/*0:0*/ tb_riscv_core__DOT__uut__DOT__ex_mem__DOT__mem_to_reg_out;
        ::CData/*0:0*/ tb_riscv_core__DOT__uut__DOT__ex_mem__DOT__mem_read_out;
        ::CData/*0:0*/ tb_riscv_core__DOT__uut__DOT__ex_mem__DOT__mem_write_out;
        ::CData/*0:0*/ tb_riscv_core__DOT__uut__DOT__ex_mem__DOT__branch_out;
        ::CData/*0:0*/ tb_riscv_core__DOT__uut__DOT__ex_mem__DOT__zero_out;
        ::CData/*4:0*/ tb_riscv_core__DOT__uut__DOT__ex_mem__DOT__rd_addr_out;
        ::CData/*0:0*/ tb_riscv_core__DOT__uut__DOT__id_ex__DOT__valid_out;
        ::CData/*0:0*/ tb_riscv_core__DOT__uut__DOT__id_ex__DOT__jump_out;
        ::CData/*0:0*/ tb_riscv_core__DOT__uut__DOT__id_ex__DOT__jalr_out;
        ::CData/*0:0*/ tb_riscv_core__DOT__uut__DOT__id_ex__DOT__reg_write_out;
        ::CData/*0:0*/ tb_riscv_core__DOT__uut__DOT__id_ex__DOT__mem_to_reg_out;
        ::CData/*0:0*/ tb_riscv_core__DOT__uut__DOT__id_ex__DOT__mem_read_out;
        ::CData/*0:0*/ tb_riscv_core__DOT__uut__DOT__id_ex__DOT__mem_write_out;
        ::CData/*0:0*/ tb_riscv_core__DOT__uut__DOT__id_ex__DOT__branch_out;
        ::CData/*0:0*/ tb_riscv_core__DOT__uut__DOT__id_ex__DOT__alu_src_out;
        ::CData/*1:0*/ tb_riscv_core__DOT__uut__DOT__id_ex__DOT__alu_op_out;
        ::CData/*2:0*/ tb_riscv_core__DOT__uut__DOT__id_ex__DOT__funct3_out;
        ::CData/*0:0*/ tb_riscv_core__DOT__uut__DOT__id_ex__DOT__funct7_5_out;
        ::CData/*0:0*/ tb_riscv_core__DOT__uut__DOT__id_ex__DOT__op_bit5_out;
        ::CData/*4:0*/ tb_riscv_core__DOT__uut__DOT__id_ex__DOT__rs1_addr_out;
        ::CData/*4:0*/ tb_riscv_core__DOT__uut__DOT__id_ex__DOT__rs2_addr_out;
        ::CData/*4:0*/ tb_riscv_core__DOT__uut__DOT__id_ex__DOT__rd_addr_out;
        ::CData/*0:0*/ tb_riscv_core__DOT__uut__DOT__if_id__DOT__valid_out;
        ::CData/*7:0*/ __Vdly_Dim0__tb_riscv_core__DOT__uut__DOT__dmem__DOT__mem_42;
        ::CData/*0:0*/ __Vdly_Set__tb_riscv_core__DOT__uut__DOT__dmem__DOT__mem_43;
        ::CData/*4:0*/ __Vdly_Dim0__tb_riscv_core__DOT__uut__DOT__u_regfile__DOT__rf_45;
        ::CData/*0:0*/ __Vdly_Set__tb_riscv_core__DOT__uut__DOT__u_regfile__DOT__rf_46;
        ::CData/*0:0*/ __Vtrigprevexpr___TOP__tb_riscv_core__DOT__clk__0;
        ::CData/*0:0*/ __Vtrigprevexpr___TOP__tb_riscv_core__DOT__rst__0;
        ::SData/*9:0*/ __Vdfg_Regularize_273;
        ::IData/*31:0*/ tb_riscv_core__DOT__wb_result;
        ::IData/*31:0*/ tb_riscv_core__DOT__error_count;
        ::IData/*31:0*/ tb_riscv_core__DOT__test_count;
        ::IData/*31:0*/ tb_riscv_core__DOT__cycles;
        ::IData/*31:0*/ tb_riscv_core__DOT__retired;
        ::IData/*31:0*/ tb_riscv_core__DOT__test;
        ::IData/*31:0*/ tb_riscv_core__DOT__uut__DOT__pc;
        ::IData/*31:0*/ tb_riscv_core__DOT__uut__DOT__next_pc;
        ::IData/*31:0*/ tb_riscv_core__DOT__uut__DOT__id_imm;
        ::IData/*31:0*/ tb_riscv_core__DOT__uut__DOT__alu_in1;
        ::IData/*31:0*/ tb_riscv_core__DOT__uut__DOT__alu_in2;
        ::IData/*31:0*/ tb_riscv_core__DOT__uut__DOT__forward_b_data;
        ::IData/*31:0*/ tb_riscv_core__DOT__uut__DOT__ex_alu_out;
        ::IData/*31:0*/ tb_riscv_core__DOT__uut__DOT__ex_branch_target;
        ::IData/*31:0*/ tb_riscv_core__DOT__uut__DOT__mem_wb__DOT__read_data_out;
        ::IData/*31:0*/ tb_riscv_core__DOT__uut__DOT__mem_wb__DOT__alu_out_out;
        ::IData/*31:0*/ tb_riscv_core__DOT__uut__DOT__ex_mem__DOT__branch_target_out;
        ::IData/*31:0*/ tb_riscv_core__DOT__uut__DOT__ex_mem__DOT__alu_out_out;
        ::IData/*31:0*/ tb_riscv_core__DOT__uut__DOT__ex_mem__DOT__rs2_data_out;
        ::IData/*31:0*/ tb_riscv_core__DOT__uut__DOT__id_ex__DOT__pc_out;
    };
    struct {
        ::IData/*31:0*/ tb_riscv_core__DOT__uut__DOT__id_ex__DOT__rs1_data_out;
        ::IData/*31:0*/ tb_riscv_core__DOT__uut__DOT__id_ex__DOT__rs2_data_out;
        ::IData/*31:0*/ tb_riscv_core__DOT__uut__DOT__id_ex__DOT__imm_out;
        ::IData/*31:0*/ tb_riscv_core__DOT__uut__DOT__if_id__DOT__pc_out;
        ::IData/*31:0*/ tb_riscv_core__DOT__uut__DOT__if_id__DOT__instr_out;
        ::IData/*31:0*/ tb_riscv_core__DOT__uut__DOT__imem__DOT__unnamedblk1__DOT__test;
        ::IData/*31:0*/ __Vdly_Val__tb_riscv_core__DOT__uut__DOT__dmem__DOT__mem_41;
        ::IData/*31:0*/ __Vdly_Val__tb_riscv_core__DOT__uut__DOT__u_regfile__DOT__rf_44;
        ::IData/*31:0*/ __Vi;
        ::VlUnpacked<::IData/*31:0*/, 256> tb_riscv_core__DOT__uut__DOT__dmem__DOT__mem;
        ::VlUnpacked<::IData/*31:0*/, 32> tb_riscv_core__DOT__uut__DOT__u_regfile__DOT__rf;
        ::VlUnpacked<::IData/*31:0*/, 256> tb_riscv_core__DOT__uut__DOT__imem__DOT__mem;
        ::VlUnpacked<::QData/*63:0*/, 1> __VstlTriggered;
        ::VlUnpacked<::QData/*63:0*/, 1> __VicoTriggered;
        ::VlUnpacked<::QData/*63:0*/, 1> __VactTriggered;
        ::VlUnpacked<::QData/*63:0*/, 1> __VactTriggeredAcc;
        ::VlUnpacked<::QData/*63:0*/, 1> __VnbaTriggered;
        ::VlUnpacked<::CData/*0:0*/, 3> __VtraceActivity;
    };

    // NOT TRIVIALLY CONSTRUCTIBLE STATE
    union {
        struct {
            ::std::string __Vtask_tb_riscv_core__DOT__check_reg__test_desc_2;
            ::std::string __Vtask_tb_riscv_core__DOT__check_reg__test_desc_5;
            ::std::string __Vtask_tb_riscv_core__DOT__check_reg__test_desc_8;
            ::std::string __Vtask_tb_riscv_core__DOT__check_mem__test_desc_11;
            ::std::string __Vtask_tb_riscv_core__DOT__check_reg__test_desc_14;
            ::std::string __Vtask_tb_riscv_core__DOT__check_reg__test_desc_17;
            ::std::string __Vtask_tb_riscv_core__DOT__check_reg__test_desc_20;
            ::std::string __Vtask_tb_riscv_core__DOT__check_reg__test_desc_23;
            ::std::string __Vtask_tb_riscv_core__DOT__check_reg__test_desc_26;
            ::std::string __Vtask_tb_riscv_core__DOT__check_reg__test_desc_29;
            ::std::string __Vtask_tb_riscv_core__DOT__check_reg__test_desc_32;
            ::std::string __Vtask_tb_riscv_core__DOT__check_reg__test_desc_35;
            ::std::string __Vtask_tb_riscv_core__DOT__check_reg__test_desc_38;
            ::std::string __Vtask_tb_riscv_core__DOT__check_reg__test_desc_41;
            ::std::string __Vtask_tb_riscv_core__DOT__check_reg__test_desc_44;
            ::std::string __Vtask_tb_riscv_core__DOT__check_reg__test_desc_47;
            ::std::string __Vtask_tb_riscv_core__DOT__check_reg__test_desc_50;
            ::std::string __Vtask_tb_riscv_core__DOT__check_reg__test_desc_53;
            ::VlDelayScheduler __VdlySched;
        } __Vnontrivs;
    };

    // INTERNAL VARIABLES
    Vtb_riscv_core__Syms* vlSymsp;
    const char* vlNamep;

    // CONSTRUCTORS
    Vtb_riscv_core___024root(Vtb_riscv_core__Syms* symsp, const char* namep);
    ~Vtb_riscv_core___024root();
    VL_UNCOPYABLE(Vtb_riscv_core___024root);
    VL_UNMOVABLE(Vtb_riscv_core___024root);

    // INTERNAL METHODS
};


#endif  // guard
