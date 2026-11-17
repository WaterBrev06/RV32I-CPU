// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vtb_riscv_core.h for the primary calling header

#include "Vtb_riscv_core__pch.h"

VlCoroutine Vtb_riscv_core___024root___eval_initial__TOP__Vtiming__0(Vtb_riscv_core___024root* vlSelf);
VlCoroutine Vtb_riscv_core___024root___eval_initial__TOP__Vtiming__1(Vtb_riscv_core___024root* vlSelf);

void Vtb_riscv_core___024root___eval_initial(Vtb_riscv_core___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_riscv_core___024root___eval_initial\n"); );
    Vtb_riscv_core__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    {
        // Inlined CFunc: _eval_initial__TOP
        ::IData/*31:0*/ __Vinline_0__eval_initial__TOP_tb_riscv_core__DOT__uut__DOT__dmem__DOT__unnamedblk1__DOT__i;
        __Vinline_0__eval_initial__TOP_tb_riscv_core__DOT__uut__DOT__dmem__DOT__unnamedblk1__DOT__i = 0;
        ::IData/*31:0*/ __Vinline_0__eval_initial__TOP_tb_riscv_core__DOT__uut__DOT__imem__DOT__unnamedblk1__DOT__i;
        __Vinline_0__eval_initial__TOP_tb_riscv_core__DOT__uut__DOT__imem__DOT__unnamedblk1__DOT__i = 0;
        vlSymsp->_vm_contextp__->dumpfile("wave.vcd"s);
        vlSymsp->_traceDumpOpen();
        __Vinline_0__eval_initial__TOP_tb_riscv_core__DOT__uut__DOT__dmem__DOT__unnamedblk1__DOT__i = 0U;
        while (VL_GTS_III(32, 0x00000100U, __Vinline_0__eval_initial__TOP_tb_riscv_core__DOT__uut__DOT__dmem__DOT__unnamedblk1__DOT__i)) {
            vlSelfRef.tb_riscv_core__DOT__uut__DOT__dmem__DOT__mem[(0x000000ffU 
                                                                    & __Vinline_0__eval_initial__TOP_tb_riscv_core__DOT__uut__DOT__dmem__DOT__unnamedblk1__DOT__i)] = 0U;
            __Vinline_0__eval_initial__TOP_tb_riscv_core__DOT__uut__DOT__dmem__DOT__unnamedblk1__DOT__i 
                = ((::IData)(1U) + __Vinline_0__eval_initial__TOP_tb_riscv_core__DOT__uut__DOT__dmem__DOT__unnamedblk1__DOT__i);
        }
        __Vinline_0__eval_initial__TOP_tb_riscv_core__DOT__uut__DOT__imem__DOT__unnamedblk1__DOT__i = 0U;
        while (VL_GTS_III(32, 0x00000100U, __Vinline_0__eval_initial__TOP_tb_riscv_core__DOT__uut__DOT__imem__DOT__unnamedblk1__DOT__i)) {
            vlSelfRef.tb_riscv_core__DOT__uut__DOT__imem__DOT__mem[(0x000000ffU 
                                                                    & __Vinline_0__eval_initial__TOP_tb_riscv_core__DOT__uut__DOT__imem__DOT__unnamedblk1__DOT__i)] = 0x00000013U;
            __Vinline_0__eval_initial__TOP_tb_riscv_core__DOT__uut__DOT__imem__DOT__unnamedblk1__DOT__i 
                = ((::IData)(1U) + __Vinline_0__eval_initial__TOP_tb_riscv_core__DOT__uut__DOT__imem__DOT__unnamedblk1__DOT__i);
        }
        vlSelfRef.tb_riscv_core__DOT__uut__DOT__imem__DOT__mem[0U] = 0x00500093U;
        vlSelfRef.tb_riscv_core__DOT__uut__DOT__imem__DOT__mem[1U] = 0x00700113U;
        vlSelfRef.tb_riscv_core__DOT__uut__DOT__imem__DOT__mem[2U] = 0xfff00393U;
        vlSelfRef.tb_riscv_core__DOT__uut__DOT__imem__DOT__mem[3U] = 0x00209463U;
        vlSelfRef.tb_riscv_core__DOT__uut__DOT__imem__DOT__mem[4U] = 0x00100193U;
        vlSelfRef.tb_riscv_core__DOT__uut__DOT__imem__DOT__mem[5U] = 0x0020c463U;
        vlSelfRef.tb_riscv_core__DOT__uut__DOT__imem__DOT__mem[6U] = 0x00100213U;
        vlSelfRef.tb_riscv_core__DOT__uut__DOT__imem__DOT__mem[7U] = 0x0020d463U;
        vlSelfRef.tb_riscv_core__DOT__uut__DOT__imem__DOT__mem[8U] = 0x00100293U;
        vlSelfRef.tb_riscv_core__DOT__uut__DOT__imem__DOT__mem[9U] = 0x0013c463U;
        vlSelfRef.tb_riscv_core__DOT__uut__DOT__imem__DOT__mem[10U] = 0x00100413U;
        vlSelfRef.tb_riscv_core__DOT__uut__DOT__imem__DOT__mem[11U] = 0x0013e463U;
        vlSelfRef.tb_riscv_core__DOT__uut__DOT__imem__DOT__mem[12U] = 0x00100493U;
        vlSelfRef.tb_riscv_core__DOT__uut__DOT__imem__DOT__mem[13U] = 0x00700313U;
    }
    Vtb_riscv_core___024root___eval_initial__TOP__Vtiming__0(vlSelf);
    Vtb_riscv_core___024root___eval_initial__TOP__Vtiming__1(vlSelf);
}

void Vtb_riscv_core___024root___eval_sample(Vtb_riscv_core___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_riscv_core___024root___eval_sample\n"); );
    Vtb_riscv_core__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
}

#ifdef VL_DEBUG
VL_ATTR_COLD void Vtb_riscv_core___024root___dump_triggers__ico(const ::VlUnpacked<::QData/*63:0*/, 1> &triggers, const ::std::string &tag);
#endif  // VL_DEBUG

bool Vtb_riscv_core___024root___eval_ico(Vtb_riscv_core___024root* vlSelf, ::CData/*0:0*/ firstIteration) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_riscv_core___024root___eval_ico\n"); );
    Vtb_riscv_core__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    vlSelfRef.__VicoTriggered[0U] = ((0xfffffffffffffffeULL 
                                      & vlSelfRef.__VicoTriggered[0U]) 
                                     | (::IData)((::IData)(firstIteration)));
#ifdef VL_DEBUG
    if (VL_UNLIKELY(vlSymsp->_vm_contextp__->debug())) {
        Vtb_riscv_core___024root___dump_triggers__ico(vlSelfRef.__VicoTriggered, "ico"s);
    }
#endif
    return (0U);
}

void Vtb_riscv_core___024root___trigger_orInto__act_vec_vec(::VlUnpacked<::QData/*63:0*/, 1> &out, const ::VlUnpacked<::QData/*63:0*/, 1> &in);
#ifdef VL_DEBUG
VL_ATTR_COLD void Vtb_riscv_core___024root___dump_triggers__act(const ::VlUnpacked<::QData/*63:0*/, 1> &triggers, const ::std::string &tag);
#endif  // VL_DEBUG
bool Vtb_riscv_core___024root___trigger_anySet__act(const ::VlUnpacked<::QData/*63:0*/, 1> &in);

bool Vtb_riscv_core___024root___eval_act(Vtb_riscv_core___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_riscv_core___024root___eval_act\n"); );
    Vtb_riscv_core__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Locals
    ::CData/*0:0*/ __VactExecute;
    // Body
    {
        // Inlined CFunc: _eval_triggers_vec__act
        vlSelfRef.__VactTriggered[0U] = (::QData)((::IData)(
                                                            ((vlSelfRef.__Vnontrivs.__VdlySched.awaitingCurrentTime() 
                                                              << 2U) 
                                                             | ((((::IData)(vlSelfRef.tb_riscv_core__DOT__rst) 
                                                                  & (~ (::IData)(vlSelfRef.__Vtrigprevexpr___TOP__tb_riscv_core__DOT__rst__0))) 
                                                                 << 1U) 
                                                                | ((::IData)(vlSelfRef.tb_riscv_core__DOT__clk) 
                                                                   & (~ (::IData)(vlSelfRef.__Vtrigprevexpr___TOP__tb_riscv_core__DOT__clk__0)))))));
        vlSelfRef.__Vtrigprevexpr___TOP__tb_riscv_core__DOT__clk__0 
            = vlSelfRef.tb_riscv_core__DOT__clk;
        vlSelfRef.__Vtrigprevexpr___TOP__tb_riscv_core__DOT__rst__0 
            = vlSelfRef.tb_riscv_core__DOT__rst;
    }
    Vtb_riscv_core___024root___trigger_orInto__act_vec_vec(vlSelfRef.__VactTriggered, vlSelfRef.__VactTriggeredAcc);
#ifdef VL_DEBUG
    if (VL_UNLIKELY(vlSymsp->_vm_contextp__->debug())) {
        Vtb_riscv_core___024root___dump_triggers__act(vlSelfRef.__VactTriggered, "act"s);
    }
#endif
    Vtb_riscv_core___024root___trigger_orInto__act_vec_vec(vlSelfRef.__VnbaTriggered, vlSelfRef.__VactTriggered);
    __VactExecute = Vtb_riscv_core___024root___trigger_anySet__act(vlSelfRef.__VactTriggered);
    if (__VactExecute) {
        vlSelfRef.__VactTriggeredAcc.fill(0ULL);
        {
            // Inlined CFunc: _timing_resume
            if ((((4ULL & vlSelfRef.__VactTriggered[0U])) != 0ULL)) {
                vlSelfRef.__Vnontrivs.__VdlySched.resume();
            }
        }
    }
    return (__VactExecute);
}

bool Vtb_riscv_core___024root___eval_inact(Vtb_riscv_core___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_riscv_core___024root___eval_inact\n"); );
    Vtb_riscv_core__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Locals
    ::CData/*0:0*/ __VinactExecute;
    // Body
    __VinactExecute = vlSelfRef.__Vnontrivs.__VdlySched.awaitingZeroDelay();
    if (__VinactExecute) {
        VL_FATAL_MT("tb_riscv_core.sv", 3, "", "ZERODLY: Design Verilated with '--no-sched-zero-delay', but #0 delay executed at runtime");
    }
    return (__VinactExecute);
}

void Vtb_riscv_core___024root___nba_sequent__TOP__1(Vtb_riscv_core___024root* vlSelf);
void Vtb_riscv_core___024root___trigger_clear__act(::VlUnpacked<::QData/*63:0*/, 1> &out);

bool Vtb_riscv_core___024root___eval_nba(Vtb_riscv_core___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_riscv_core___024root___eval_nba\n"); );
    Vtb_riscv_core__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Locals
    ::CData/*0:0*/ __VnbaExecute;
    // Body
    __VnbaExecute = Vtb_riscv_core___024root___trigger_anySet__act(vlSelfRef.__VnbaTriggered);
    if (__VnbaExecute) {
        {
            // Inlined CFunc: _eval_body__nba
            if ((((1ULL & vlSelfRef.__VnbaTriggered[0U])) != 0ULL)) {
                {
                    // Inlined CFunc: _nba_sequent__TOP__0
                    vlSelfRef.__Vdly_Set__tb_riscv_core__DOT__uut__DOT__dmem__DOT__mem_41 = 0U;
                    vlSelfRef.__Vdly_Set__tb_riscv_core__DOT__uut__DOT__u_regfile__DOT__rf_44 = 0U;
                    if ((1U & ((~ (::IData)(vlSelfRef.tb_riscv_core__DOT__rst)) 
                               & (~ (::IData)(vlSelfRef.tb_riscv_core__DOT__done))))) {
                        vlSelfRef.tb_riscv_core__DOT__cycles 
                            = ((::IData)(1U) + vlSelfRef.tb_riscv_core__DOT__cycles);
                        if (vlSelfRef.tb_riscv_core__DOT__uut__DOT__mem_wb__DOT__valid_out) {
                            vlSelfRef.tb_riscv_core__DOT__retired 
                                = ((::IData)(1U) + vlSelfRef.tb_riscv_core__DOT__retired);
                        }
                        if ((((::IData)(vlSelfRef.tb_riscv_core__DOT__uut__DOT__mem_wb__DOT__valid_out) 
                              & (::IData)(vlSelfRef.tb_riscv_core__DOT__uut__DOT__mem_wb__DOT__reg_write_out)) 
                             & (6U == (::IData)(vlSelfRef.tb_riscv_core__DOT__uut__DOT__mem_wb__DOT__rd_addr_out)))) {
                            vlSelfRef.tb_riscv_core__DOT__done = 1U;
                        }
                    }
                    if (vlSelfRef.tb_riscv_core__DOT__uut__DOT__ex_mem__DOT__mem_write_out) {
                        vlSelfRef.__Vdly_Val__tb_riscv_core__DOT__uut__DOT__dmem__DOT__mem_39 
                            = vlSelfRef.tb_riscv_core__DOT__uut__DOT__ex_mem__DOT__rs2_data_out;
                        vlSelfRef.__Vdly_Dim0__tb_riscv_core__DOT__uut__DOT__dmem__DOT__mem_40 
                            = (0x000000ffU & (vlSelfRef.tb_riscv_core__DOT__uut__DOT__ex_mem__DOT__alu_out_out 
                                              >> 2U));
                        vlSelfRef.__Vdly_Set__tb_riscv_core__DOT__uut__DOT__dmem__DOT__mem_41 = 1U;
                    }
                    if (((::IData)(vlSelfRef.tb_riscv_core__DOT__uut__DOT__mem_wb__DOT__reg_write_out) 
                         & (0U != (::IData)(vlSelfRef.tb_riscv_core__DOT__uut__DOT__mem_wb__DOT__rd_addr_out)))) {
                        vlSelfRef.__Vdly_Val__tb_riscv_core__DOT__uut__DOT__u_regfile__DOT__rf_42 
                            = vlSelfRef.tb_riscv_core__DOT__wb_result;
                        vlSelfRef.__Vdly_Dim0__tb_riscv_core__DOT__uut__DOT__u_regfile__DOT__rf_43 
                            = vlSelfRef.tb_riscv_core__DOT__uut__DOT__mem_wb__DOT__rd_addr_out;
                        vlSelfRef.__Vdly_Set__tb_riscv_core__DOT__uut__DOT__u_regfile__DOT__rf_44 = 1U;
                    }
                }
                vlSelfRef.__VtraceActivity[1U] = 1U;
            }
            if ((((3ULL & vlSelfRef.__VnbaTriggered[0U])) != 0ULL)) {
                Vtb_riscv_core___024root___nba_sequent__TOP__1(vlSelf);
                vlSelfRef.__VtraceActivity[2U] = 1U;
            }
            if ((((1ULL & vlSelfRef.__VnbaTriggered[0U])) != 0ULL)) {
                {
                    // Inlined CFunc: _nba_sequent__TOP__2
                    if (vlSelfRef.__Vdly_Set__tb_riscv_core__DOT__uut__DOT__dmem__DOT__mem_41) {
                        vlSelfRef.tb_riscv_core__DOT__uut__DOT__dmem__DOT__mem[vlSelfRef.__Vdly_Dim0__tb_riscv_core__DOT__uut__DOT__dmem__DOT__mem_40] 
                            = vlSelfRef.__Vdly_Val__tb_riscv_core__DOT__uut__DOT__dmem__DOT__mem_39;
                    }
                    if (vlSelfRef.__Vdly_Set__tb_riscv_core__DOT__uut__DOT__u_regfile__DOT__rf_44) {
                        vlSelfRef.tb_riscv_core__DOT__uut__DOT__u_regfile__DOT__rf[vlSelfRef.__Vdly_Dim0__tb_riscv_core__DOT__uut__DOT__u_regfile__DOT__rf_43] 
                            = vlSelfRef.__Vdly_Val__tb_riscv_core__DOT__uut__DOT__u_regfile__DOT__rf_42;
                    }
                }
            }
        }
        Vtb_riscv_core___024root___trigger_clear__act(vlSelfRef.__VnbaTriggered);
    }
    return (__VnbaExecute);
}

bool Vtb_riscv_core___024root___eval_obs(Vtb_riscv_core___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_riscv_core___024root___eval_obs\n"); );
    Vtb_riscv_core__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    return (0U);
}

bool Vtb_riscv_core___024root___eval_react(Vtb_riscv_core___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_riscv_core___024root___eval_react\n"); );
    Vtb_riscv_core__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    return (0U);
}

void Vtb_riscv_core___024root___eval_postponed(Vtb_riscv_core___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_riscv_core___024root___eval_postponed\n"); );
    Vtb_riscv_core__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
}

VlCoroutine Vtb_riscv_core___024root___eval_initial__TOP__Vtiming__0(Vtb_riscv_core___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_riscv_core___024root___eval_initial__TOP__Vtiming__0\n"); );
    Vtb_riscv_core__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Locals
    ::CData/*4:0*/ __Vtask_tb_riscv_core__DOT__check_reg__reg_addr_0;
    __Vtask_tb_riscv_core__DOT__check_reg__reg_addr_0 = 0;
    ::IData/*31:0*/ __Vtask_tb_riscv_core__DOT__check_reg__expected_val_1;
    __Vtask_tb_riscv_core__DOT__check_reg__expected_val_1 = 0;
    ::CData/*4:0*/ __Vtask_tb_riscv_core__DOT__check_reg__reg_addr_3;
    __Vtask_tb_riscv_core__DOT__check_reg__reg_addr_3 = 0;
    ::IData/*31:0*/ __Vtask_tb_riscv_core__DOT__check_reg__expected_val_4;
    __Vtask_tb_riscv_core__DOT__check_reg__expected_val_4 = 0;
    ::CData/*4:0*/ __Vtask_tb_riscv_core__DOT__check_reg__reg_addr_6;
    __Vtask_tb_riscv_core__DOT__check_reg__reg_addr_6 = 0;
    ::IData/*31:0*/ __Vtask_tb_riscv_core__DOT__check_reg__expected_val_7;
    __Vtask_tb_riscv_core__DOT__check_reg__expected_val_7 = 0;
    ::CData/*4:0*/ __Vtask_tb_riscv_core__DOT__check_reg__reg_addr_9;
    __Vtask_tb_riscv_core__DOT__check_reg__reg_addr_9 = 0;
    ::IData/*31:0*/ __Vtask_tb_riscv_core__DOT__check_reg__expected_val_10;
    __Vtask_tb_riscv_core__DOT__check_reg__expected_val_10 = 0;
    ::CData/*4:0*/ __Vtask_tb_riscv_core__DOT__check_reg__reg_addr_12;
    __Vtask_tb_riscv_core__DOT__check_reg__reg_addr_12 = 0;
    ::IData/*31:0*/ __Vtask_tb_riscv_core__DOT__check_reg__expected_val_13;
    __Vtask_tb_riscv_core__DOT__check_reg__expected_val_13 = 0;
    ::CData/*4:0*/ __Vtask_tb_riscv_core__DOT__check_reg__reg_addr_15;
    __Vtask_tb_riscv_core__DOT__check_reg__reg_addr_15 = 0;
    ::IData/*31:0*/ __Vtask_tb_riscv_core__DOT__check_reg__expected_val_16;
    __Vtask_tb_riscv_core__DOT__check_reg__expected_val_16 = 0;
    // Body
    vlSelfRef.tb_riscv_core__DOT__clk = 0U;
    vlSelfRef.tb_riscv_core__DOT__rst = 1U;
    VL_WRITEF_NX("==================================================\n STARTING RISC-V TOP-LEVEL END-TO-END CORE TEST   \n==================================================\n",0);
    co_await vlSelfRef.__Vnontrivs.__VdlySched.delay(0x0000000000004e20ULL, 
                                                     nullptr, 
                                                     "tb_riscv_core.sv", 
                                                     86);
    vlSelfRef.tb_riscv_core__DOT__rst = 0U;
    co_await vlSelfRef.__Vnontrivs.__VdlySched.delay(0x00000000000c3500ULL, 
                                                     nullptr, 
                                                     "tb_riscv_core.sv", 
                                                     96);
    VL_WRITEF_NX("\n--------------------------------------------------\n VERIFYING PIPELINE EXECUTION & HAZARD RESOLUTION \n--------------------------------------------------\n",0);
    vlSelfRef.__Vnontrivs.__Vtask_tb_riscv_core__DOT__check_reg__test_desc_2 = "BNE taken: x3 skipped"s;
    __Vtask_tb_riscv_core__DOT__check_reg__expected_val_1 = 0U;
    __Vtask_tb_riscv_core__DOT__check_reg__reg_addr_0 = 3U;
    vlSelfRef.tb_riscv_core__DOT__test_count = ((::IData)(1U) 
                                                + vlSelfRef.tb_riscv_core__DOT__test_count);
    if ((vlSelfRef.tb_riscv_core__DOT__uut__DOT__u_regfile__DOT__rf
         [__Vtask_tb_riscv_core__DOT__check_reg__reg_addr_0] 
         != __Vtask_tb_riscv_core__DOT__check_reg__expected_val_1)) {
        VL_WRITEF_NX("FAIL [%s]: x%0d = 0x%h (%0d), Expected = 0x%h (%0d)\n",6
                     , 'S',&(vlSelfRef.__Vnontrivs.__Vtask_tb_riscv_core__DOT__check_reg__test_desc_2)
                     , '#',5,(::IData)(__Vtask_tb_riscv_core__DOT__check_reg__reg_addr_0)
                     , '#',32,vlSelfRef.tb_riscv_core__DOT__uut__DOT__u_regfile__DOT__rf
                     [__Vtask_tb_riscv_core__DOT__check_reg__reg_addr_0]
                     , '#',32,vlSelfRef.tb_riscv_core__DOT__uut__DOT__u_regfile__DOT__rf
                     [__Vtask_tb_riscv_core__DOT__check_reg__reg_addr_0]
                     , '#',32,__Vtask_tb_riscv_core__DOT__check_reg__expected_val_1
                     , '#',32,__Vtask_tb_riscv_core__DOT__check_reg__expected_val_1);
        vlSelfRef.tb_riscv_core__DOT__error_count = 
            ((::IData)(1U) + vlSelfRef.tb_riscv_core__DOT__error_count);
    } else {
        VL_WRITEF_NX("PASS [%s]: x%0d = 0x%h (%0d)\n",4
                     , 'S',&(vlSelfRef.__Vnontrivs.__Vtask_tb_riscv_core__DOT__check_reg__test_desc_2)
                     , '#',5,(::IData)(__Vtask_tb_riscv_core__DOT__check_reg__reg_addr_0)
                     , '#',32,vlSelfRef.tb_riscv_core__DOT__uut__DOT__u_regfile__DOT__rf
                     [__Vtask_tb_riscv_core__DOT__check_reg__reg_addr_0]
                     , '#',32,vlSelfRef.tb_riscv_core__DOT__uut__DOT__u_regfile__DOT__rf
                     [__Vtask_tb_riscv_core__DOT__check_reg__reg_addr_0]);
    }
    vlSelfRef.__Vnontrivs.__Vtask_tb_riscv_core__DOT__check_reg__test_desc_5 = "BLT taken: x4 skipped"s;
    __Vtask_tb_riscv_core__DOT__check_reg__expected_val_4 = 0U;
    __Vtask_tb_riscv_core__DOT__check_reg__reg_addr_3 = 4U;
    vlSelfRef.tb_riscv_core__DOT__test_count = ((::IData)(1U) 
                                                + vlSelfRef.tb_riscv_core__DOT__test_count);
    if ((vlSelfRef.tb_riscv_core__DOT__uut__DOT__u_regfile__DOT__rf
         [__Vtask_tb_riscv_core__DOT__check_reg__reg_addr_3] 
         != __Vtask_tb_riscv_core__DOT__check_reg__expected_val_4)) {
        VL_WRITEF_NX("FAIL [%s]: x%0d = 0x%h (%0d), Expected = 0x%h (%0d)\n",6
                     , 'S',&(vlSelfRef.__Vnontrivs.__Vtask_tb_riscv_core__DOT__check_reg__test_desc_5)
                     , '#',5,(::IData)(__Vtask_tb_riscv_core__DOT__check_reg__reg_addr_3)
                     , '#',32,vlSelfRef.tb_riscv_core__DOT__uut__DOT__u_regfile__DOT__rf
                     [__Vtask_tb_riscv_core__DOT__check_reg__reg_addr_3]
                     , '#',32,vlSelfRef.tb_riscv_core__DOT__uut__DOT__u_regfile__DOT__rf
                     [__Vtask_tb_riscv_core__DOT__check_reg__reg_addr_3]
                     , '#',32,__Vtask_tb_riscv_core__DOT__check_reg__expected_val_4
                     , '#',32,__Vtask_tb_riscv_core__DOT__check_reg__expected_val_4);
        vlSelfRef.tb_riscv_core__DOT__error_count = 
            ((::IData)(1U) + vlSelfRef.tb_riscv_core__DOT__error_count);
    } else {
        VL_WRITEF_NX("PASS [%s]: x%0d = 0x%h (%0d)\n",4
                     , 'S',&(vlSelfRef.__Vnontrivs.__Vtask_tb_riscv_core__DOT__check_reg__test_desc_5)
                     , '#',5,(::IData)(__Vtask_tb_riscv_core__DOT__check_reg__reg_addr_3)
                     , '#',32,vlSelfRef.tb_riscv_core__DOT__uut__DOT__u_regfile__DOT__rf
                     [__Vtask_tb_riscv_core__DOT__check_reg__reg_addr_3]
                     , '#',32,vlSelfRef.tb_riscv_core__DOT__uut__DOT__u_regfile__DOT__rf
                     [__Vtask_tb_riscv_core__DOT__check_reg__reg_addr_3]);
    }
    vlSelfRef.__Vnontrivs.__Vtask_tb_riscv_core__DOT__check_reg__test_desc_8 = "BGE not taken: x5 executed"s;
    __Vtask_tb_riscv_core__DOT__check_reg__expected_val_7 = 1U;
    __Vtask_tb_riscv_core__DOT__check_reg__reg_addr_6 = 5U;
    vlSelfRef.tb_riscv_core__DOT__test_count = ((::IData)(1U) 
                                                + vlSelfRef.tb_riscv_core__DOT__test_count);
    if ((vlSelfRef.tb_riscv_core__DOT__uut__DOT__u_regfile__DOT__rf
         [__Vtask_tb_riscv_core__DOT__check_reg__reg_addr_6] 
         != __Vtask_tb_riscv_core__DOT__check_reg__expected_val_7)) {
        VL_WRITEF_NX("FAIL [%s]: x%0d = 0x%h (%0d), Expected = 0x%h (%0d)\n",6
                     , 'S',&(vlSelfRef.__Vnontrivs.__Vtask_tb_riscv_core__DOT__check_reg__test_desc_8)
                     , '#',5,(::IData)(__Vtask_tb_riscv_core__DOT__check_reg__reg_addr_6)
                     , '#',32,vlSelfRef.tb_riscv_core__DOT__uut__DOT__u_regfile__DOT__rf
                     [__Vtask_tb_riscv_core__DOT__check_reg__reg_addr_6]
                     , '#',32,vlSelfRef.tb_riscv_core__DOT__uut__DOT__u_regfile__DOT__rf
                     [__Vtask_tb_riscv_core__DOT__check_reg__reg_addr_6]
                     , '#',32,__Vtask_tb_riscv_core__DOT__check_reg__expected_val_7
                     , '#',32,__Vtask_tb_riscv_core__DOT__check_reg__expected_val_7);
        vlSelfRef.tb_riscv_core__DOT__error_count = 
            ((::IData)(1U) + vlSelfRef.tb_riscv_core__DOT__error_count);
    } else {
        VL_WRITEF_NX("PASS [%s]: x%0d = 0x%h (%0d)\n",4
                     , 'S',&(vlSelfRef.__Vnontrivs.__Vtask_tb_riscv_core__DOT__check_reg__test_desc_8)
                     , '#',5,(::IData)(__Vtask_tb_riscv_core__DOT__check_reg__reg_addr_6)
                     , '#',32,vlSelfRef.tb_riscv_core__DOT__uut__DOT__u_regfile__DOT__rf
                     [__Vtask_tb_riscv_core__DOT__check_reg__reg_addr_6]
                     , '#',32,vlSelfRef.tb_riscv_core__DOT__uut__DOT__u_regfile__DOT__rf
                     [__Vtask_tb_riscv_core__DOT__check_reg__reg_addr_6]);
    }
    vlSelfRef.__Vnontrivs.__Vtask_tb_riscv_core__DOT__check_reg__test_desc_11 = "BLT signed (-1 < 5) taken: x8 skipped"s;
    __Vtask_tb_riscv_core__DOT__check_reg__expected_val_10 = 0U;
    __Vtask_tb_riscv_core__DOT__check_reg__reg_addr_9 = 8U;
    vlSelfRef.tb_riscv_core__DOT__test_count = ((::IData)(1U) 
                                                + vlSelfRef.tb_riscv_core__DOT__test_count);
    if ((vlSelfRef.tb_riscv_core__DOT__uut__DOT__u_regfile__DOT__rf
         [__Vtask_tb_riscv_core__DOT__check_reg__reg_addr_9] 
         != __Vtask_tb_riscv_core__DOT__check_reg__expected_val_10)) {
        VL_WRITEF_NX("FAIL [%s]: x%0d = 0x%h (%0d), Expected = 0x%h (%0d)\n",6
                     , 'S',&(vlSelfRef.__Vnontrivs.__Vtask_tb_riscv_core__DOT__check_reg__test_desc_11)
                     , '#',5,(::IData)(__Vtask_tb_riscv_core__DOT__check_reg__reg_addr_9)
                     , '#',32,vlSelfRef.tb_riscv_core__DOT__uut__DOT__u_regfile__DOT__rf
                     [__Vtask_tb_riscv_core__DOT__check_reg__reg_addr_9]
                     , '#',32,vlSelfRef.tb_riscv_core__DOT__uut__DOT__u_regfile__DOT__rf
                     [__Vtask_tb_riscv_core__DOT__check_reg__reg_addr_9]
                     , '#',32,__Vtask_tb_riscv_core__DOT__check_reg__expected_val_10
                     , '#',32,__Vtask_tb_riscv_core__DOT__check_reg__expected_val_10);
        vlSelfRef.tb_riscv_core__DOT__error_count = 
            ((::IData)(1U) + vlSelfRef.tb_riscv_core__DOT__error_count);
    } else {
        VL_WRITEF_NX("PASS [%s]: x%0d = 0x%h (%0d)\n",4
                     , 'S',&(vlSelfRef.__Vnontrivs.__Vtask_tb_riscv_core__DOT__check_reg__test_desc_11)
                     , '#',5,(::IData)(__Vtask_tb_riscv_core__DOT__check_reg__reg_addr_9)
                     , '#',32,vlSelfRef.tb_riscv_core__DOT__uut__DOT__u_regfile__DOT__rf
                     [__Vtask_tb_riscv_core__DOT__check_reg__reg_addr_9]
                     , '#',32,vlSelfRef.tb_riscv_core__DOT__uut__DOT__u_regfile__DOT__rf
                     [__Vtask_tb_riscv_core__DOT__check_reg__reg_addr_9]);
    }
    vlSelfRef.__Vnontrivs.__Vtask_tb_riscv_core__DOT__check_reg__test_desc_14 = "BLTU unsigned (0xFFFFFFFF > 5) not taken: x9 executed"s;
    __Vtask_tb_riscv_core__DOT__check_reg__expected_val_13 = 1U;
    __Vtask_tb_riscv_core__DOT__check_reg__reg_addr_12 = 9U;
    vlSelfRef.tb_riscv_core__DOT__test_count = ((::IData)(1U) 
                                                + vlSelfRef.tb_riscv_core__DOT__test_count);
    if ((vlSelfRef.tb_riscv_core__DOT__uut__DOT__u_regfile__DOT__rf
         [__Vtask_tb_riscv_core__DOT__check_reg__reg_addr_12] 
         != __Vtask_tb_riscv_core__DOT__check_reg__expected_val_13)) {
        VL_WRITEF_NX("FAIL [%s]: x%0d = 0x%h (%0d), Expected = 0x%h (%0d)\n",6
                     , 'S',&(vlSelfRef.__Vnontrivs.__Vtask_tb_riscv_core__DOT__check_reg__test_desc_14)
                     , '#',5,(::IData)(__Vtask_tb_riscv_core__DOT__check_reg__reg_addr_12)
                     , '#',32,vlSelfRef.tb_riscv_core__DOT__uut__DOT__u_regfile__DOT__rf
                     [__Vtask_tb_riscv_core__DOT__check_reg__reg_addr_12]
                     , '#',32,vlSelfRef.tb_riscv_core__DOT__uut__DOT__u_regfile__DOT__rf
                     [__Vtask_tb_riscv_core__DOT__check_reg__reg_addr_12]
                     , '#',32,__Vtask_tb_riscv_core__DOT__check_reg__expected_val_13
                     , '#',32,__Vtask_tb_riscv_core__DOT__check_reg__expected_val_13);
        vlSelfRef.tb_riscv_core__DOT__error_count = 
            ((::IData)(1U) + vlSelfRef.tb_riscv_core__DOT__error_count);
    } else {
        VL_WRITEF_NX("PASS [%s]: x%0d = 0x%h (%0d)\n",4
                     , 'S',&(vlSelfRef.__Vnontrivs.__Vtask_tb_riscv_core__DOT__check_reg__test_desc_14)
                     , '#',5,(::IData)(__Vtask_tb_riscv_core__DOT__check_reg__reg_addr_12)
                     , '#',32,vlSelfRef.tb_riscv_core__DOT__uut__DOT__u_regfile__DOT__rf
                     [__Vtask_tb_riscv_core__DOT__check_reg__reg_addr_12]
                     , '#',32,vlSelfRef.tb_riscv_core__DOT__uut__DOT__u_regfile__DOT__rf
                     [__Vtask_tb_riscv_core__DOT__check_reg__reg_addr_12]);
    }
    vlSelfRef.__Vnontrivs.__Vtask_tb_riscv_core__DOT__check_reg__test_desc_17 = "End marker: x6 reached"s;
    __Vtask_tb_riscv_core__DOT__check_reg__expected_val_16 = 7U;
    __Vtask_tb_riscv_core__DOT__check_reg__reg_addr_15 = 6U;
    vlSelfRef.tb_riscv_core__DOT__test_count = ((::IData)(1U) 
                                                + vlSelfRef.tb_riscv_core__DOT__test_count);
    if ((vlSelfRef.tb_riscv_core__DOT__uut__DOT__u_regfile__DOT__rf
         [__Vtask_tb_riscv_core__DOT__check_reg__reg_addr_15] 
         != __Vtask_tb_riscv_core__DOT__check_reg__expected_val_16)) {
        VL_WRITEF_NX("FAIL [%s]: x%0d = 0x%h (%0d), Expected = 0x%h (%0d)\n",6
                     , 'S',&(vlSelfRef.__Vnontrivs.__Vtask_tb_riscv_core__DOT__check_reg__test_desc_17)
                     , '#',5,(::IData)(__Vtask_tb_riscv_core__DOT__check_reg__reg_addr_15)
                     , '#',32,vlSelfRef.tb_riscv_core__DOT__uut__DOT__u_regfile__DOT__rf
                     [__Vtask_tb_riscv_core__DOT__check_reg__reg_addr_15]
                     , '#',32,vlSelfRef.tb_riscv_core__DOT__uut__DOT__u_regfile__DOT__rf
                     [__Vtask_tb_riscv_core__DOT__check_reg__reg_addr_15]
                     , '#',32,__Vtask_tb_riscv_core__DOT__check_reg__expected_val_16
                     , '#',32,__Vtask_tb_riscv_core__DOT__check_reg__expected_val_16);
        vlSelfRef.tb_riscv_core__DOT__error_count = 
            ((::IData)(1U) + vlSelfRef.tb_riscv_core__DOT__error_count);
    } else {
        VL_WRITEF_NX("PASS [%s]: x%0d = 0x%h (%0d)\n",4
                     , 'S',&(vlSelfRef.__Vnontrivs.__Vtask_tb_riscv_core__DOT__check_reg__test_desc_17)
                     , '#',5,(::IData)(__Vtask_tb_riscv_core__DOT__check_reg__reg_addr_15)
                     , '#',32,vlSelfRef.tb_riscv_core__DOT__uut__DOT__u_regfile__DOT__rf
                     [__Vtask_tb_riscv_core__DOT__check_reg__reg_addr_15]
                     , '#',32,vlSelfRef.tb_riscv_core__DOT__uut__DOT__u_regfile__DOT__rf
                     [__Vtask_tb_riscv_core__DOT__check_reg__reg_addr_15]);
    }
    VL_WRITEF_NX("==================================================\n",0);
    if ((0U == vlSelfRef.tb_riscv_core__DOT__error_count)) {
        VL_WRITEF_NX("SUCCESS: All %0d end-to-end integration tests passed!\n",1
                     , '~',32,vlSelfRef.tb_riscv_core__DOT__test_count);
    } else {
        VL_WRITEF_NX("FAILURE: %0d out of %0d tests failed.\n",2
                     , '~',32,vlSelfRef.tb_riscv_core__DOT__error_count
                     , '~',32,vlSelfRef.tb_riscv_core__DOT__test_count);
    }
    VL_WRITEF_NX("Retired %0d instructions in %0d cycles: IPC = %0.2f\n==================================================\n",3
                 , '~',32,vlSelfRef.tb_riscv_core__DOT__retired
                 , '~',32,vlSelfRef.tb_riscv_core__DOT__cycles
                 , 'D',(VL_ISTOR_D_I(32, vlSelfRef.tb_riscv_core__DOT__retired) 
                        / VL_ISTOR_D_I(32, vlSelfRef.tb_riscv_core__DOT__cycles)));
    VL_FINISH_MT("tb_riscv_core.sv", 134, "");
    co_return;
}

VlCoroutine Vtb_riscv_core___024root___eval_initial__TOP__Vtiming__1(Vtb_riscv_core___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_riscv_core___024root___eval_initial__TOP__Vtiming__1\n"); );
    Vtb_riscv_core__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    while (VL_LIKELY(!vlSymsp->_vm_contextp__->gotFinish())) {
        co_await vlSelfRef.__Vnontrivs.__VdlySched.delay(0x0000000000002710ULL, 
                                                         nullptr, 
                                                         "tb_riscv_core.sv", 
                                                         25);
        vlSelfRef.tb_riscv_core__DOT__clk = (1U & (~ (::IData)(vlSelfRef.tb_riscv_core__DOT__clk)));
    }
    co_return;
}

bool Vtb_riscv_core___024root___trigger_anySet__ico(const ::VlUnpacked<::QData/*63:0*/, 1> &in) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_riscv_core___024root___trigger_anySet__ico\n"); );
    // Locals
    ::IData/*31:0*/ n;
    // Body
    n = 0U;
    do {
        if (in[n]) {
            return (1U);
        }
        n = ((::IData)(1U) + n);
    } while ((1U > n));
    return (0U);
}

bool Vtb_riscv_core___024root___trigger_anySet__act(const ::VlUnpacked<::QData/*63:0*/, 1> &in) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_riscv_core___024root___trigger_anySet__act\n"); );
    // Locals
    ::IData/*31:0*/ n;
    // Body
    n = 0U;
    do {
        if (in[n]) {
            return (1U);
        }
        n = ((::IData)(1U) + n);
    } while ((1U > n));
    return (0U);
}

extern const ::VlUnpacked<::CData/*3:0*/, 128> Vtb_riscv_core__ConstPool__CONSARRAY_1;
extern const ::VlWide<128>/*4095:0*/ Vtb_riscv_core__ConstPool__CONST_0;

void Vtb_riscv_core___024root___nba_sequent__TOP__1(Vtb_riscv_core___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_riscv_core___024root___nba_sequent__TOP__1\n"); );
    Vtb_riscv_core__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Locals
    ::CData/*0:0*/ __Vdfg_Regularize_266;
    __Vdfg_Regularize_266 = 0;
    ::CData/*0:0*/ __Vdfg_Regularize_267;
    __Vdfg_Regularize_267 = 0;
    ::IData/*31:0*/ __Vdfg_Regularize_269;
    __Vdfg_Regularize_269 = 0;
    ::CData/*0:0*/ __Vdfg_Regularize_270;
    __Vdfg_Regularize_270 = 0;
    ::CData/*0:0*/ __Vdfg_Regularize_271;
    __Vdfg_Regularize_271 = 0;
    ::CData/*0:0*/ __Vdfg_Regularize_272;
    __Vdfg_Regularize_272 = 0;
    ::IData/*31:0*/ __Vdfg_Regularize_274;
    __Vdfg_Regularize_274 = 0;
    // Body
    vlSelfRef.tb_riscv_core__DOT__uut__DOT__ex_mem__DOT__zero_out 
        = ((1U & (~ (::IData)(vlSelfRef.tb_riscv_core__DOT__rst))) 
           && (0U == vlSelfRef.tb_riscv_core__DOT__uut__DOT__ex_alu_out));
    vlSelfRef.tb_riscv_core__DOT__uut__DOT__id_ex__DOT__alu_src_out 
        = ((1U & (~ ((::IData)(vlSelfRef.tb_riscv_core__DOT__rst) 
                     | (::IData)(vlSelfRef.tb_riscv_core__DOT__uut__DOT__id_ex_flush)))) 
           && (1U & ((::IData)(vlSelfRef.__Vdfg_Regularize_265) 
                     >> 5U)));
    if (((::IData)(vlSelfRef.tb_riscv_core__DOT__rst) 
         | (::IData)(vlSelfRef.tb_riscv_core__DOT__uut__DOT__id_ex_flush))) {
        vlSelfRef.tb_riscv_core__DOT__uut__DOT__id_ex__DOT__imm_out = 0U;
        vlSelfRef.tb_riscv_core__DOT__uut__DOT__id_ex__DOT__alu_op_out = 0U;
        vlSelfRef.tb_riscv_core__DOT__uut__DOT__id_ex__DOT__pc_out = 0U;
        vlSelfRef.tb_riscv_core__DOT__uut__DOT__id_ex__DOT__rs1_addr_out = 0U;
        vlSelfRef.tb_riscv_core__DOT__uut__DOT__id_ex__DOT__rs2_addr_out = 0U;
        vlSelfRef.tb_riscv_core__DOT__uut__DOT__id_ex__DOT__funct3_out = 0U;
        vlSelfRef.tb_riscv_core__DOT__uut__DOT__id_ex__DOT__rs1_data_out = 0U;
        vlSelfRef.tb_riscv_core__DOT__uut__DOT__id_ex__DOT__rs2_data_out = 0U;
    } else {
        vlSelfRef.tb_riscv_core__DOT__uut__DOT__id_ex__DOT__imm_out 
            = vlSelfRef.tb_riscv_core__DOT__uut__DOT__id_imm;
        vlSelfRef.tb_riscv_core__DOT__uut__DOT__id_ex__DOT__alu_op_out 
            = (3U & ((::IData)(vlSelfRef.__Vdfg_Regularize_265) 
                     >> 7U));
        vlSelfRef.tb_riscv_core__DOT__uut__DOT__id_ex__DOT__pc_out 
            = vlSelfRef.tb_riscv_core__DOT__uut__DOT__if_id__DOT__pc_out;
        vlSelfRef.tb_riscv_core__DOT__uut__DOT__id_ex__DOT__rs1_addr_out 
            = (0x0000001fU & (vlSelfRef.tb_riscv_core__DOT__uut__DOT__if_id__DOT__instr_out 
                              >> 0x0000000fU));
        vlSelfRef.tb_riscv_core__DOT__uut__DOT__id_ex__DOT__rs2_addr_out 
            = (0x0000001fU & (vlSelfRef.tb_riscv_core__DOT__uut__DOT__if_id__DOT__instr_out 
                              >> 0x00000014U));
        vlSelfRef.tb_riscv_core__DOT__uut__DOT__id_ex__DOT__funct3_out 
            = (7U & (vlSelfRef.tb_riscv_core__DOT__uut__DOT__if_id__DOT__instr_out 
                     >> 0x0000000cU));
        vlSelfRef.tb_riscv_core__DOT__uut__DOT__id_ex__DOT__rs1_data_out 
            = ((((::IData)(vlSelfRef.tb_riscv_core__DOT__uut__DOT__mem_wb__DOT__reg_write_out) 
                 & ((::IData)(vlSelfRef.tb_riscv_core__DOT__uut__DOT__mem_wb__DOT__rd_addr_out) 
                    == (0x0000001fU & (vlSelfRef.tb_riscv_core__DOT__uut__DOT__if_id__DOT__instr_out 
                                       >> 0x0000000fU))))
                 ? vlSelfRef.tb_riscv_core__DOT__wb_result
                 : vlSelfRef.tb_riscv_core__DOT__uut__DOT__u_regfile__DOT__rf
                [(0x0000001fU & (vlSelfRef.tb_riscv_core__DOT__uut__DOT__if_id__DOT__instr_out 
                                 >> 0x0000000fU))]) 
               & (- (::IData)((0U != (0x0000001fU & 
                                      (vlSelfRef.tb_riscv_core__DOT__uut__DOT__if_id__DOT__instr_out 
                                       >> 0x0000000fU))))));
        vlSelfRef.tb_riscv_core__DOT__uut__DOT__id_ex__DOT__rs2_data_out 
            = ((((::IData)(vlSelfRef.tb_riscv_core__DOT__uut__DOT__mem_wb__DOT__reg_write_out) 
                 & ((::IData)(vlSelfRef.tb_riscv_core__DOT__uut__DOT__mem_wb__DOT__rd_addr_out) 
                    == (0x0000001fU & (vlSelfRef.tb_riscv_core__DOT__uut__DOT__if_id__DOT__instr_out 
                                       >> 0x00000014U))))
                 ? vlSelfRef.tb_riscv_core__DOT__wb_result
                 : vlSelfRef.tb_riscv_core__DOT__uut__DOT__u_regfile__DOT__rf
                [(0x0000001fU & (vlSelfRef.tb_riscv_core__DOT__uut__DOT__if_id__DOT__instr_out 
                                 >> 0x00000014U))]) 
               & (- (::IData)((0U != (0x0000001fU & 
                                      (vlSelfRef.tb_riscv_core__DOT__uut__DOT__if_id__DOT__instr_out 
                                       >> 0x00000014U))))));
    }
    if (vlSelfRef.tb_riscv_core__DOT__rst) {
        vlSelfRef.tb_riscv_core__DOT__uut__DOT__ex_mem__DOT__branch_target_out = 0U;
        vlSelfRef.tb_riscv_core__DOT__uut__DOT__mem_wb__DOT__alu_out_out = 0U;
        vlSelfRef.tb_riscv_core__DOT__uut__DOT__mem_wb__DOT__read_data_out = 0U;
        vlSelfRef.tb_riscv_core__DOT__uut__DOT__ex_mem__DOT__rs2_data_out = 0U;
        vlSelfRef.tb_riscv_core__DOT__uut__DOT__ex_mem__DOT__alu_out_out = 0U;
        vlSelfRef.tb_riscv_core__DOT__uut__DOT__mem_wb__DOT__rd_addr_out = 0U;
        vlSelfRef.tb_riscv_core__DOT__uut__DOT__ex_mem__DOT__rd_addr_out = 0U;
    } else {
        vlSelfRef.tb_riscv_core__DOT__uut__DOT__ex_mem__DOT__branch_target_out 
            = vlSelfRef.tb_riscv_core__DOT__uut__DOT__ex_branch_target;
        vlSelfRef.tb_riscv_core__DOT__uut__DOT__mem_wb__DOT__alu_out_out 
            = vlSelfRef.tb_riscv_core__DOT__uut__DOT__ex_mem__DOT__alu_out_out;
        vlSelfRef.tb_riscv_core__DOT__uut__DOT__mem_wb__DOT__read_data_out 
            = ((::IData)(vlSelfRef.tb_riscv_core__DOT__uut__DOT__ex_mem__DOT__mem_read_out)
                ? vlSelfRef.tb_riscv_core__DOT__uut__DOT__dmem__DOT__mem
               [(0x000000ffU & (vlSelfRef.tb_riscv_core__DOT__uut__DOT__ex_mem__DOT__alu_out_out 
                                >> 2U))] : 0U);
        vlSelfRef.tb_riscv_core__DOT__uut__DOT__ex_mem__DOT__rs2_data_out 
            = vlSelfRef.tb_riscv_core__DOT__uut__DOT__forward_b_data;
        vlSelfRef.tb_riscv_core__DOT__uut__DOT__ex_mem__DOT__alu_out_out 
            = vlSelfRef.tb_riscv_core__DOT__uut__DOT__ex_alu_out;
        vlSelfRef.tb_riscv_core__DOT__uut__DOT__mem_wb__DOT__rd_addr_out 
            = vlSelfRef.tb_riscv_core__DOT__uut__DOT__ex_mem__DOT__rd_addr_out;
        vlSelfRef.tb_riscv_core__DOT__uut__DOT__ex_mem__DOT__rd_addr_out 
            = vlSelfRef.tb_riscv_core__DOT__uut__DOT__id_ex__DOT__rd_addr_out;
    }
    vlSelfRef.tb_riscv_core__DOT__uut__DOT__id_ex__DOT__rd_addr_out 
        = (((::IData)(vlSelfRef.tb_riscv_core__DOT__rst) 
            | (::IData)(vlSelfRef.tb_riscv_core__DOT__uut__DOT__id_ex_flush))
            ? 0U : (0x0000001fU & (vlSelfRef.tb_riscv_core__DOT__uut__DOT__if_id__DOT__instr_out 
                                   >> 7U)));
    vlSelfRef.tb_riscv_core__DOT__uut__DOT__ex_mem__DOT__branch_out 
        = ((1U & (~ (::IData)(vlSelfRef.tb_riscv_core__DOT__rst))) 
           && (::IData)(vlSelfRef.tb_riscv_core__DOT__uut__DOT__id_ex__DOT__branch_out));
    vlSelfRef.tb_riscv_core__DOT__uut__DOT__mem_wb__DOT__mem_to_reg_out 
        = ((1U & (~ (::IData)(vlSelfRef.tb_riscv_core__DOT__rst))) 
           && (::IData)(vlSelfRef.tb_riscv_core__DOT__uut__DOT__ex_mem__DOT__mem_to_reg_out));
    vlSelfRef.tb_riscv_core__DOT__uut__DOT__id_ex__DOT__funct7_5_out 
        = ((1U & (~ ((::IData)(vlSelfRef.tb_riscv_core__DOT__rst) 
                     | (::IData)(vlSelfRef.tb_riscv_core__DOT__uut__DOT__id_ex_flush)))) 
           && (1U & (vlSelfRef.tb_riscv_core__DOT__uut__DOT__if_id__DOT__instr_out 
                     >> 0x0000001eU)));
    vlSelfRef.tb_riscv_core__DOT__uut__DOT__id_ex__DOT__op_bit5_out 
        = ((1U & (~ ((::IData)(vlSelfRef.tb_riscv_core__DOT__rst) 
                     | (::IData)(vlSelfRef.tb_riscv_core__DOT__uut__DOT__id_ex_flush)))) 
           && (1U & (vlSelfRef.tb_riscv_core__DOT__uut__DOT__if_id__DOT__instr_out 
                     >> 5U)));
    vlSelfRef.tb_riscv_core__DOT__uut__DOT__mem_wb__DOT__valid_out 
        = ((1U & (~ (::IData)(vlSelfRef.tb_riscv_core__DOT__rst))) 
           && (::IData)(vlSelfRef.tb_riscv_core__DOT__uut__DOT__ex_mem__DOT__valid_out));
    vlSelfRef.tb_riscv_core__DOT__uut__DOT__ex_mem__DOT__mem_write_out 
        = ((1U & (~ (::IData)(vlSelfRef.tb_riscv_core__DOT__rst))) 
           && (::IData)(vlSelfRef.tb_riscv_core__DOT__uut__DOT__id_ex__DOT__mem_write_out));
    vlSelfRef.tb_riscv_core__DOT__uut__DOT__id_ex__DOT__branch_out 
        = ((1U & (~ ((::IData)(vlSelfRef.tb_riscv_core__DOT__rst) 
                     | (::IData)(vlSelfRef.tb_riscv_core__DOT__uut__DOT__id_ex_flush)))) 
           && (1U & ((::IData)(vlSelfRef.__Vdfg_Regularize_265) 
                     >> 1U)));
    vlSelfRef.tb_riscv_core__DOT__uut__DOT__ex_branch_target 
        = (vlSelfRef.tb_riscv_core__DOT__uut__DOT__id_ex__DOT__imm_out 
           + vlSelfRef.tb_riscv_core__DOT__uut__DOT__id_ex__DOT__pc_out);
    vlSelfRef.tb_riscv_core__DOT__uut__DOT__ex_mem__DOT__mem_to_reg_out 
        = ((1U & (~ (::IData)(vlSelfRef.tb_riscv_core__DOT__rst))) 
           && (::IData)(vlSelfRef.tb_riscv_core__DOT__uut__DOT__id_ex__DOT__mem_to_reg_out));
    __Vdfg_Regularize_266 = (1U & Vtb_riscv_core__ConstPool__CONSARRAY_1
                             [((((::IData)(vlSelfRef.tb_riscv_core__DOT__uut__DOT__id_ex__DOT__op_bit5_out) 
                                 << 6U) | ((::IData)(vlSelfRef.tb_riscv_core__DOT__uut__DOT__id_ex__DOT__funct7_5_out) 
                                           << 5U)) 
                               | (((::IData)(vlSelfRef.tb_riscv_core__DOT__uut__DOT__id_ex__DOT__funct3_out) 
                                   << 2U) | (::IData)(vlSelfRef.tb_riscv_core__DOT__uut__DOT__id_ex__DOT__alu_op_out)))]);
    __Vdfg_Regularize_267 = (1U & (Vtb_riscv_core__ConstPool__CONSARRAY_1
                                   [((((::IData)(vlSelfRef.tb_riscv_core__DOT__uut__DOT__id_ex__DOT__op_bit5_out) 
                                       << 6U) | ((::IData)(vlSelfRef.tb_riscv_core__DOT__uut__DOT__id_ex__DOT__funct7_5_out) 
                                                 << 5U)) 
                                     | (((::IData)(vlSelfRef.tb_riscv_core__DOT__uut__DOT__id_ex__DOT__funct3_out) 
                                         << 2U) | (::IData)(vlSelfRef.tb_riscv_core__DOT__uut__DOT__id_ex__DOT__alu_op_out)))] 
                                   >> 1U));
    __Vdfg_Regularize_272 = (1U & (Vtb_riscv_core__ConstPool__CONSARRAY_1
                                   [((((::IData)(vlSelfRef.tb_riscv_core__DOT__uut__DOT__id_ex__DOT__op_bit5_out) 
                                       << 6U) | ((::IData)(vlSelfRef.tb_riscv_core__DOT__uut__DOT__id_ex__DOT__funct7_5_out) 
                                                 << 5U)) 
                                     | (((::IData)(vlSelfRef.tb_riscv_core__DOT__uut__DOT__id_ex__DOT__funct3_out) 
                                         << 2U) | (::IData)(vlSelfRef.tb_riscv_core__DOT__uut__DOT__id_ex__DOT__alu_op_out)))] 
                                   >> 2U));
    vlSelfRef.tb_riscv_core__DOT__wb_result = ((::IData)(vlSelfRef.tb_riscv_core__DOT__uut__DOT__mem_wb__DOT__mem_to_reg_out)
                                                ? vlSelfRef.tb_riscv_core__DOT__uut__DOT__mem_wb__DOT__read_data_out
                                                : vlSelfRef.tb_riscv_core__DOT__uut__DOT__mem_wb__DOT__alu_out_out);
    vlSelfRef.tb_riscv_core__DOT__uut__DOT__ex_mem__DOT__mem_read_out 
        = ((1U & (~ (::IData)(vlSelfRef.tb_riscv_core__DOT__rst))) 
           && (::IData)(vlSelfRef.tb_riscv_core__DOT__uut__DOT__id_ex__DOT__mem_read_out));
    vlSelfRef.tb_riscv_core__DOT__uut__DOT__mem_wb__DOT__reg_write_out 
        = ((1U & (~ (::IData)(vlSelfRef.tb_riscv_core__DOT__rst))) 
           && (::IData)(vlSelfRef.tb_riscv_core__DOT__uut__DOT__ex_mem__DOT__reg_write_out));
    vlSelfRef.tb_riscv_core__DOT__uut__DOT__ex_mem__DOT__valid_out 
        = ((1U & (~ (::IData)(vlSelfRef.tb_riscv_core__DOT__rst))) 
           && (::IData)(vlSelfRef.tb_riscv_core__DOT__uut__DOT__id_ex__DOT__valid_out));
    vlSelfRef.tb_riscv_core__DOT__uut__DOT__id_ex__DOT__mem_write_out 
        = ((1U & (~ ((::IData)(vlSelfRef.tb_riscv_core__DOT__rst) 
                     | (::IData)(vlSelfRef.tb_riscv_core__DOT__uut__DOT__id_ex_flush)))) 
           && (1U & ((::IData)(vlSelfRef.__Vdfg_Regularize_265) 
                     >> 2U)));
    vlSelfRef.tb_riscv_core__DOT__uut__DOT__id_ex__DOT__mem_to_reg_out 
        = ((1U & (~ ((::IData)(vlSelfRef.tb_riscv_core__DOT__rst) 
                     | (::IData)(vlSelfRef.tb_riscv_core__DOT__uut__DOT__id_ex_flush)))) 
           && (1U & ((::IData)(vlSelfRef.__Vdfg_Regularize_265) 
                     >> 4U)));
    vlSelfRef.tb_riscv_core__DOT__uut__DOT__id_ex__DOT__mem_read_out 
        = ((1U & (~ ((::IData)(vlSelfRef.tb_riscv_core__DOT__rst) 
                     | (::IData)(vlSelfRef.tb_riscv_core__DOT__uut__DOT__id_ex_flush)))) 
           && (1U & ((::IData)(vlSelfRef.__Vdfg_Regularize_265) 
                     >> 3U)));
    vlSelfRef.tb_riscv_core__DOT__uut__DOT__ex_mem__DOT__reg_write_out 
        = ((1U & (~ (::IData)(vlSelfRef.tb_riscv_core__DOT__rst))) 
           && (::IData)(vlSelfRef.tb_riscv_core__DOT__uut__DOT__id_ex__DOT__reg_write_out));
    __Vdfg_Regularize_271 = ((::IData)(vlSelfRef.tb_riscv_core__DOT__uut__DOT__mem_wb__DOT__reg_write_out) 
                             & (0U != (::IData)(vlSelfRef.tb_riscv_core__DOT__uut__DOT__mem_wb__DOT__rd_addr_out)));
    vlSelfRef.tb_riscv_core__DOT__uut__DOT__id_ex__DOT__valid_out 
        = ((1U & (~ ((::IData)(vlSelfRef.tb_riscv_core__DOT__rst) 
                     | (::IData)(vlSelfRef.tb_riscv_core__DOT__uut__DOT__id_ex_flush)))) 
           && (::IData)(vlSelfRef.tb_riscv_core__DOT__uut__DOT__if_id__DOT__valid_out));
    if (((::IData)(vlSelfRef.tb_riscv_core__DOT__rst) 
         | (::IData)(vlSelfRef.tb_riscv_core__DOT__uut__DOT__if_id_flush))) {
        vlSelfRef.tb_riscv_core__DOT__uut__DOT__if_id__DOT__pc_out = 0U;
        vlSelfRef.tb_riscv_core__DOT__uut__DOT__if_id__DOT__valid_out = 0U;
        vlSelfRef.tb_riscv_core__DOT__uut__DOT__if_id__DOT__instr_out = 0x00000013U;
    } else if ((1U & (~ (::IData)(vlSelfRef.tb_riscv_core__DOT__uut__DOT__pc_stall)))) {
        vlSelfRef.tb_riscv_core__DOT__uut__DOT__if_id__DOT__pc_out 
            = vlSelfRef.tb_riscv_core__DOT__uut__DOT__pc;
        vlSelfRef.tb_riscv_core__DOT__uut__DOT__if_id__DOT__valid_out = 1U;
        vlSelfRef.tb_riscv_core__DOT__uut__DOT__if_id__DOT__instr_out 
            = vlSelfRef.tb_riscv_core__DOT__uut__DOT__imem__DOT__mem
            [(0x000000ffU & (vlSelfRef.tb_riscv_core__DOT__uut__DOT__pc 
                             >> 2U))];
    }
    if (vlSelfRef.tb_riscv_core__DOT__rst) {
        vlSelfRef.tb_riscv_core__DOT__uut__DOT__pc = 0U;
    } else if ((1U & (~ (::IData)(vlSelfRef.tb_riscv_core__DOT__uut__DOT__pc_stall)))) {
        vlSelfRef.tb_riscv_core__DOT__uut__DOT__pc 
            = vlSelfRef.tb_riscv_core__DOT__uut__DOT__next_pc;
    }
    vlSelfRef.tb_riscv_core__DOT__uut__DOT__id_ex__DOT__reg_write_out 
        = ((1U & (~ ((::IData)(vlSelfRef.tb_riscv_core__DOT__rst) 
                     | (::IData)(vlSelfRef.tb_riscv_core__DOT__uut__DOT__id_ex_flush)))) 
           && (1U & ((::IData)(vlSelfRef.__Vdfg_Regularize_265) 
                     >> 6U)));
    __Vdfg_Regularize_270 = ((::IData)(vlSelfRef.tb_riscv_core__DOT__uut__DOT__ex_mem__DOT__reg_write_out) 
                             & (0U != (::IData)(vlSelfRef.tb_riscv_core__DOT__uut__DOT__ex_mem__DOT__rd_addr_out)));
    vlSelfRef.tb_riscv_core__DOT__uut__DOT__forward_a 
        = ((((::IData)(vlSelfRef.tb_riscv_core__DOT__uut__DOT__id_ex__DOT__rs1_addr_out) 
             == (::IData)(vlSelfRef.tb_riscv_core__DOT__uut__DOT__ex_mem__DOT__rd_addr_out)) 
            & (::IData)(__Vdfg_Regularize_270)) ? 2U
            : (1U & (- (::IData)((((::IData)(vlSelfRef.tb_riscv_core__DOT__uut__DOT__mem_wb__DOT__rd_addr_out) 
                                   == (::IData)(vlSelfRef.tb_riscv_core__DOT__uut__DOT__id_ex__DOT__rs1_addr_out)) 
                                  & (::IData)(__Vdfg_Regularize_271))))));
    vlSelfRef.tb_riscv_core__DOT__uut__DOT__forward_b 
        = ((((::IData)(vlSelfRef.tb_riscv_core__DOT__uut__DOT__id_ex__DOT__rs2_addr_out) 
             == (::IData)(vlSelfRef.tb_riscv_core__DOT__uut__DOT__ex_mem__DOT__rd_addr_out)) 
            & (::IData)(__Vdfg_Regularize_270)) ? 2U
            : (1U & (- (::IData)((((::IData)(vlSelfRef.tb_riscv_core__DOT__uut__DOT__mem_wb__DOT__rd_addr_out) 
                                   == (::IData)(vlSelfRef.tb_riscv_core__DOT__uut__DOT__id_ex__DOT__rs2_addr_out)) 
                                  & (::IData)(__Vdfg_Regularize_271))))));
    vlSelfRef.tb_riscv_core__DOT__uut__DOT__alu_in1 
        = ((2U == (::IData)(vlSelfRef.tb_riscv_core__DOT__uut__DOT__forward_a))
            ? vlSelfRef.tb_riscv_core__DOT__uut__DOT__ex_mem__DOT__alu_out_out
            : ((1U == (::IData)(vlSelfRef.tb_riscv_core__DOT__uut__DOT__forward_a))
                ? vlSelfRef.tb_riscv_core__DOT__wb_result
                : vlSelfRef.tb_riscv_core__DOT__uut__DOT__id_ex__DOT__rs1_data_out));
    vlSelfRef.tb_riscv_core__DOT__uut__DOT__forward_b_data 
        = ((2U == (::IData)(vlSelfRef.tb_riscv_core__DOT__uut__DOT__forward_b))
            ? vlSelfRef.tb_riscv_core__DOT__uut__DOT__ex_mem__DOT__alu_out_out
            : ((1U == (::IData)(vlSelfRef.tb_riscv_core__DOT__uut__DOT__forward_b))
                ? vlSelfRef.tb_riscv_core__DOT__wb_result
                : vlSelfRef.tb_riscv_core__DOT__uut__DOT__id_ex__DOT__rs2_data_out));
    vlSelfRef.tb_riscv_core__DOT__uut__DOT__alu_in2 
        = ((::IData)(vlSelfRef.tb_riscv_core__DOT__uut__DOT__id_ex__DOT__alu_src_out)
            ? vlSelfRef.tb_riscv_core__DOT__uut__DOT__id_ex__DOT__imm_out
            : vlSelfRef.tb_riscv_core__DOT__uut__DOT__forward_b_data);
    vlSelfRef.tb_riscv_core__DOT__uut__DOT__if_id_flush 
        = ((::IData)(vlSelfRef.tb_riscv_core__DOT__uut__DOT__id_ex__DOT__branch_out) 
           & ((4U & (::IData)(vlSelfRef.tb_riscv_core__DOT__uut__DOT__id_ex__DOT__funct3_out))
               ? ((2U & (::IData)(vlSelfRef.tb_riscv_core__DOT__uut__DOT__id_ex__DOT__funct3_out))
                   ? ((1U & (::IData)(vlSelfRef.tb_riscv_core__DOT__uut__DOT__id_ex__DOT__funct3_out))
                       ? (vlSelfRef.tb_riscv_core__DOT__uut__DOT__alu_in1 
                          >= vlSelfRef.tb_riscv_core__DOT__uut__DOT__forward_b_data)
                       : (vlSelfRef.tb_riscv_core__DOT__uut__DOT__alu_in1 
                          < vlSelfRef.tb_riscv_core__DOT__uut__DOT__forward_b_data))
                   : ((1U & (::IData)(vlSelfRef.tb_riscv_core__DOT__uut__DOT__id_ex__DOT__funct3_out))
                       ? VL_GTES_III(32, vlSelfRef.tb_riscv_core__DOT__uut__DOT__alu_in1, vlSelfRef.tb_riscv_core__DOT__uut__DOT__forward_b_data)
                       : VL_LTS_III(32, vlSelfRef.tb_riscv_core__DOT__uut__DOT__alu_in1, vlSelfRef.tb_riscv_core__DOT__uut__DOT__forward_b_data)))
               : ((~ ((::IData)(vlSelfRef.tb_riscv_core__DOT__uut__DOT__id_ex__DOT__funct3_out) 
                      >> 1U)) & ((1U & (::IData)(vlSelfRef.tb_riscv_core__DOT__uut__DOT__id_ex__DOT__funct3_out))
                                  ? (vlSelfRef.tb_riscv_core__DOT__uut__DOT__alu_in1 
                                     != vlSelfRef.tb_riscv_core__DOT__uut__DOT__forward_b_data)
                                  : (vlSelfRef.tb_riscv_core__DOT__uut__DOT__alu_in1 
                                     == vlSelfRef.tb_riscv_core__DOT__uut__DOT__forward_b_data)))));
    vlSelfRef.tb_riscv_core__DOT__uut__DOT__ex_alu_out 
        = ((8U & Vtb_riscv_core__ConstPool__CONSARRAY_1
            [((((::IData)(vlSelfRef.tb_riscv_core__DOT__uut__DOT__id_ex__DOT__op_bit5_out) 
                << 6U) | ((::IData)(vlSelfRef.tb_riscv_core__DOT__uut__DOT__id_ex__DOT__funct7_5_out) 
                          << 5U)) | (((::IData)(vlSelfRef.tb_riscv_core__DOT__uut__DOT__id_ex__DOT__funct3_out) 
                                      << 2U) | (::IData)(vlSelfRef.tb_riscv_core__DOT__uut__DOT__id_ex__DOT__alu_op_out)))])
            ? ((- (::IData)((1U & (~ (::IData)(__Vdfg_Regularize_267))))) 
               & (((::IData)(__Vdfg_Regularize_266)
                    ? (1U & (- (::IData)((vlSelfRef.tb_riscv_core__DOT__uut__DOT__alu_in1 
                                          < vlSelfRef.tb_riscv_core__DOT__uut__DOT__alu_in2))))
                    : (1U & (- (::IData)(VL_LTS_III(32, vlSelfRef.tb_riscv_core__DOT__uut__DOT__alu_in1, vlSelfRef.tb_riscv_core__DOT__uut__DOT__alu_in2))))) 
                  & (- (::IData)((1U & (~ (::IData)(__Vdfg_Regularize_272)))))))
            : ((::IData)(__Vdfg_Regularize_272) ? ((::IData)(__Vdfg_Regularize_267)
                                                    ? 
                                                   ((::IData)(__Vdfg_Regularize_266)
                                                     ? 
                                                    VL_SHIFTRS_III(32,32,5, vlSelfRef.tb_riscv_core__DOT__uut__DOT__alu_in1, 
                                                                   (0x0000001fU 
                                                                    & vlSelfRef.tb_riscv_core__DOT__uut__DOT__alu_in2))
                                                     : 
                                                    (vlSelfRef.tb_riscv_core__DOT__uut__DOT__alu_in1 
                                                     >> 
                                                     (0x0000001fU 
                                                      & vlSelfRef.tb_riscv_core__DOT__uut__DOT__alu_in2)))
                                                    : 
                                                   ((::IData)(__Vdfg_Regularize_266)
                                                     ? 
                                                    (vlSelfRef.tb_riscv_core__DOT__uut__DOT__alu_in1 
                                                     << 
                                                     (0x0000001fU 
                                                      & vlSelfRef.tb_riscv_core__DOT__uut__DOT__alu_in2))
                                                     : 
                                                    (vlSelfRef.tb_riscv_core__DOT__uut__DOT__alu_in1 
                                                     ^ vlSelfRef.tb_riscv_core__DOT__uut__DOT__alu_in2)))
                : ((::IData)(__Vdfg_Regularize_267)
                    ? ((::IData)(__Vdfg_Regularize_266)
                        ? (vlSelfRef.tb_riscv_core__DOT__uut__DOT__alu_in1 
                           | vlSelfRef.tb_riscv_core__DOT__uut__DOT__alu_in2)
                        : (vlSelfRef.tb_riscv_core__DOT__uut__DOT__alu_in1 
                           & vlSelfRef.tb_riscv_core__DOT__uut__DOT__alu_in2))
                    : ((::IData)(__Vdfg_Regularize_266)
                        ? (vlSelfRef.tb_riscv_core__DOT__uut__DOT__alu_in1 
                           - vlSelfRef.tb_riscv_core__DOT__uut__DOT__alu_in2)
                        : (vlSelfRef.tb_riscv_core__DOT__uut__DOT__alu_in1 
                           + vlSelfRef.tb_riscv_core__DOT__uut__DOT__alu_in2)))));
    vlSelfRef.__Vdfg_Regularize_265 = (0x000001ffU 
                                       & Vtb_riscv_core__ConstPool__CONST_0
                                       [(0x0000007fU 
                                         & vlSelfRef.tb_riscv_core__DOT__uut__DOT__if_id__DOT__instr_out)]);
    __Vdfg_Regularize_269 = ((((- (::IData)((vlSelfRef.tb_riscv_core__DOT__uut__DOT__if_id__DOT__instr_out 
                                             >> 0x0000001fU))) 
                               << 0x0000000cU) | (vlSelfRef.tb_riscv_core__DOT__uut__DOT__if_id__DOT__instr_out 
                                                  >> 0x00000014U)) 
                             & (- (::IData)((3U == 
                                             (3U & vlSelfRef.tb_riscv_core__DOT__uut__DOT__if_id__DOT__instr_out)))));
    __Vdfg_Regularize_274 = (0xfffff000U & (vlSelfRef.tb_riscv_core__DOT__uut__DOT__if_id__DOT__instr_out 
                                            & (- (::IData)(
                                                           (3U 
                                                            == 
                                                            (3U 
                                                             & vlSelfRef.tb_riscv_core__DOT__uut__DOT__if_id__DOT__instr_out))))));
    vlSelfRef.tb_riscv_core__DOT__uut__DOT__id_imm 
        = ((0x00000040U & vlSelfRef.tb_riscv_core__DOT__uut__DOT__if_id__DOT__instr_out)
            ? ((- (::IData)((1U & (~ (vlSelfRef.tb_riscv_core__DOT__uut__DOT__if_id__DOT__instr_out 
                                      >> 4U))))) & 
               (((8U & vlSelfRef.tb_riscv_core__DOT__uut__DOT__if_id__DOT__instr_out)
                  ? (((((0x00000ffeU & ((- (::IData)(
                                                     (vlSelfRef.tb_riscv_core__DOT__uut__DOT__if_id__DOT__instr_out 
                                                      >> 0x0000001fU))) 
                                        << 1U)) | (vlSelfRef.tb_riscv_core__DOT__uut__DOT__if_id__DOT__instr_out 
                                                   >> 0x0000001fU)) 
                       << 0x00000014U) | ((((0x000001feU 
                                             & (vlSelfRef.tb_riscv_core__DOT__uut__DOT__if_id__DOT__instr_out 
                                                >> 0x0000000bU)) 
                                            | (1U & 
                                               (vlSelfRef.tb_riscv_core__DOT__uut__DOT__if_id__DOT__instr_out 
                                                >> 0x00000014U))) 
                                           << 0x0000000bU) 
                                          | (0x000007feU 
                                             & (vlSelfRef.tb_riscv_core__DOT__uut__DOT__if_id__DOT__instr_out 
                                                >> 0x00000014U)))) 
                     & (- (::IData)((7U == (7U & vlSelfRef.tb_riscv_core__DOT__uut__DOT__if_id__DOT__instr_out)))))
                  : ((4U & vlSelfRef.tb_riscv_core__DOT__uut__DOT__if_id__DOT__instr_out)
                      ? __Vdfg_Regularize_269 : (((
                                                   (- (::IData)(
                                                                (vlSelfRef.tb_riscv_core__DOT__uut__DOT__if_id__DOT__instr_out 
                                                                 >> 0x0000001fU))) 
                                                   << 0x0000000dU) 
                                                  | ((((2U 
                                                        & (vlSelfRef.tb_riscv_core__DOT__uut__DOT__if_id__DOT__instr_out 
                                                           >> 0x0000001eU)) 
                                                       | (1U 
                                                          & (vlSelfRef.tb_riscv_core__DOT__uut__DOT__if_id__DOT__instr_out 
                                                             >> 7U))) 
                                                      << 0x0000000bU) 
                                                     | ((0x000007e0U 
                                                         & (vlSelfRef.tb_riscv_core__DOT__uut__DOT__if_id__DOT__instr_out 
                                                            >> 0x00000014U)) 
                                                        | (0x0000001eU 
                                                           & (vlSelfRef.tb_riscv_core__DOT__uut__DOT__if_id__DOT__instr_out 
                                                              >> 7U))))) 
                                                 & (- (::IData)(
                                                                (3U 
                                                                 == 
                                                                 (3U 
                                                                  & vlSelfRef.tb_riscv_core__DOT__uut__DOT__if_id__DOT__instr_out))))))) 
                & (- (::IData)((1U & (vlSelfRef.tb_riscv_core__DOT__uut__DOT__if_id__DOT__instr_out 
                                      >> 5U)))))) : 
           ((0x00000020U & vlSelfRef.tb_riscv_core__DOT__uut__DOT__if_id__DOT__instr_out)
             ? ((0x00000010U & vlSelfRef.tb_riscv_core__DOT__uut__DOT__if_id__DOT__instr_out)
                 ? ((- (::IData)((::IData)((4U == (0x0000000cU 
                                                   & vlSelfRef.tb_riscv_core__DOT__uut__DOT__if_id__DOT__instr_out))))) 
                    & __Vdfg_Regularize_274) : ((((- (::IData)(
                                                               (vlSelfRef.tb_riscv_core__DOT__uut__DOT__if_id__DOT__instr_out 
                                                                >> 0x0000001fU))) 
                                                  << 0x0000000cU) 
                                                 | ((0x00000fe0U 
                                                     & (vlSelfRef.tb_riscv_core__DOT__uut__DOT__if_id__DOT__instr_out 
                                                        >> 0x00000014U)) 
                                                    | (0x0000001fU 
                                                       & (vlSelfRef.tb_riscv_core__DOT__uut__DOT__if_id__DOT__instr_out 
                                                          >> 7U)))) 
                                                & (- (::IData)((::IData)(
                                                                         (3U 
                                                                          == 
                                                                          (0x0000000fU 
                                                                           & vlSelfRef.tb_riscv_core__DOT__uut__DOT__if_id__DOT__instr_out)))))))
             : ((0x00000010U & vlSelfRef.tb_riscv_core__DOT__uut__DOT__if_id__DOT__instr_out)
                 ? (((4U & vlSelfRef.tb_riscv_core__DOT__uut__DOT__if_id__DOT__instr_out)
                      ? __Vdfg_Regularize_274 : __Vdfg_Regularize_269) 
                    & (- (::IData)((1U & (~ (vlSelfRef.tb_riscv_core__DOT__uut__DOT__if_id__DOT__instr_out 
                                             >> 3U))))))
                 : (__Vdfg_Regularize_269 & ((- (::IData)(
                                                          (1U 
                                                           & (~ 
                                                              (vlSelfRef.tb_riscv_core__DOT__uut__DOT__if_id__DOT__instr_out 
                                                               >> 3U))))) 
                                             & (- (::IData)(
                                                            (1U 
                                                             & (~ 
                                                                (vlSelfRef.tb_riscv_core__DOT__uut__DOT__if_id__DOT__instr_out 
                                                                 >> 2U))))))))));
    vlSelfRef.tb_riscv_core__DOT__uut__DOT__pc_stall 
        = ((::IData)(vlSelfRef.tb_riscv_core__DOT__uut__DOT__id_ex__DOT__mem_read_out) 
           & ((0U != (::IData)(vlSelfRef.tb_riscv_core__DOT__uut__DOT__id_ex__DOT__rd_addr_out)) 
              & (((::IData)(vlSelfRef.tb_riscv_core__DOT__uut__DOT__id_ex__DOT__rd_addr_out) 
                  == (0x0000001fU & (vlSelfRef.tb_riscv_core__DOT__uut__DOT__if_id__DOT__instr_out 
                                     >> 0x0000000fU))) 
                 | ((::IData)(vlSelfRef.tb_riscv_core__DOT__uut__DOT__id_ex__DOT__rd_addr_out) 
                    == (0x0000001fU & (vlSelfRef.tb_riscv_core__DOT__uut__DOT__if_id__DOT__instr_out 
                                       >> 0x00000014U))))));
    vlSelfRef.tb_riscv_core__DOT__uut__DOT__next_pc 
        = ((::IData)(vlSelfRef.tb_riscv_core__DOT__uut__DOT__if_id_flush)
            ? vlSelfRef.tb_riscv_core__DOT__uut__DOT__ex_branch_target
            : ((::IData)(4U) + vlSelfRef.tb_riscv_core__DOT__uut__DOT__pc));
    vlSelfRef.tb_riscv_core__DOT__uut__DOT__id_ex_flush 
        = ((::IData)(vlSelfRef.tb_riscv_core__DOT__uut__DOT__if_id_flush) 
           | (::IData)(vlSelfRef.tb_riscv_core__DOT__uut__DOT__pc_stall));
}

void Vtb_riscv_core___024root___trigger_orInto__act_vec_vec(::VlUnpacked<::QData/*63:0*/, 1> &out, const ::VlUnpacked<::QData/*63:0*/, 1> &in) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_riscv_core___024root___trigger_orInto__act_vec_vec\n"); );
    // Locals
    ::IData/*31:0*/ n;
    // Body
    n = 0U;
    do {
        out[n] = (out[n] | in[n]);
        n = ((::IData)(1U) + n);
    } while ((0U >= n));
}

void Vtb_riscv_core___024root___trigger_clear__act(::VlUnpacked<::QData/*63:0*/, 1> &out) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_riscv_core___024root___trigger_clear__act\n"); );
    // Locals
    ::IData/*31:0*/ n;
    // Body
    n = 0U;
    do {
        out[n] = 0ULL;
        n = ((::IData)(1U) + n);
    } while ((1U > n));
}

#ifdef VL_DEBUG
void Vtb_riscv_core___024root___eval_debug_assertions(Vtb_riscv_core___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_riscv_core___024root___eval_debug_assertions\n"); );
    Vtb_riscv_core__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
}
#endif  // VL_DEBUG
