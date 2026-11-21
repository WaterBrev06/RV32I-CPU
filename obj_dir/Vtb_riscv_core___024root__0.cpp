// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vtb_riscv_core.h for the primary calling header

#include "Vtb_riscv_core__pch.h"

VL_ATTR_COLD void Vtb_riscv_core___024root___eval_initial__TOP(Vtb_riscv_core___024root* vlSelf);
VlCoroutine Vtb_riscv_core___024root___eval_initial__TOP__Vtiming__0(Vtb_riscv_core___024root* vlSelf);
VlCoroutine Vtb_riscv_core___024root___eval_initial__TOP__Vtiming__1(Vtb_riscv_core___024root* vlSelf);

void Vtb_riscv_core___024root___eval_initial(Vtb_riscv_core___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_riscv_core___024root___eval_initial\n"); );
    Vtb_riscv_core__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    Vtb_riscv_core___024root___eval_initial__TOP(vlSelf);
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

void Vtb_riscv_core___024root___eval_body__nba(Vtb_riscv_core___024root* vlSelf);
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
        Vtb_riscv_core___024root___eval_body__nba(vlSelf);
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
    ::IData/*31:0*/ __Vtask_tb_riscv_core__DOT__check_mem__mem_addr_9;
    __Vtask_tb_riscv_core__DOT__check_mem__mem_addr_9 = 0;
    ::IData/*31:0*/ __Vtask_tb_riscv_core__DOT__check_mem__expected_val_10;
    __Vtask_tb_riscv_core__DOT__check_mem__expected_val_10 = 0;
    ::CData/*4:0*/ __Vtask_tb_riscv_core__DOT__check_reg__reg_addr_12;
    __Vtask_tb_riscv_core__DOT__check_reg__reg_addr_12 = 0;
    ::IData/*31:0*/ __Vtask_tb_riscv_core__DOT__check_reg__expected_val_13;
    __Vtask_tb_riscv_core__DOT__check_reg__expected_val_13 = 0;
    ::CData/*4:0*/ __Vtask_tb_riscv_core__DOT__check_reg__reg_addr_15;
    __Vtask_tb_riscv_core__DOT__check_reg__reg_addr_15 = 0;
    ::IData/*31:0*/ __Vtask_tb_riscv_core__DOT__check_reg__expected_val_16;
    __Vtask_tb_riscv_core__DOT__check_reg__expected_val_16 = 0;
    ::CData/*4:0*/ __Vtask_tb_riscv_core__DOT__check_reg__reg_addr_18;
    __Vtask_tb_riscv_core__DOT__check_reg__reg_addr_18 = 0;
    ::IData/*31:0*/ __Vtask_tb_riscv_core__DOT__check_reg__expected_val_19;
    __Vtask_tb_riscv_core__DOT__check_reg__expected_val_19 = 0;
    ::CData/*4:0*/ __Vtask_tb_riscv_core__DOT__check_reg__reg_addr_21;
    __Vtask_tb_riscv_core__DOT__check_reg__reg_addr_21 = 0;
    ::IData/*31:0*/ __Vtask_tb_riscv_core__DOT__check_reg__expected_val_22;
    __Vtask_tb_riscv_core__DOT__check_reg__expected_val_22 = 0;
    ::CData/*4:0*/ __Vtask_tb_riscv_core__DOT__check_reg__reg_addr_24;
    __Vtask_tb_riscv_core__DOT__check_reg__reg_addr_24 = 0;
    ::IData/*31:0*/ __Vtask_tb_riscv_core__DOT__check_reg__expected_val_25;
    __Vtask_tb_riscv_core__DOT__check_reg__expected_val_25 = 0;
    ::CData/*4:0*/ __Vtask_tb_riscv_core__DOT__check_reg__reg_addr_27;
    __Vtask_tb_riscv_core__DOT__check_reg__reg_addr_27 = 0;
    ::IData/*31:0*/ __Vtask_tb_riscv_core__DOT__check_reg__expected_val_28;
    __Vtask_tb_riscv_core__DOT__check_reg__expected_val_28 = 0;
    ::CData/*4:0*/ __Vtask_tb_riscv_core__DOT__check_reg__reg_addr_30;
    __Vtask_tb_riscv_core__DOT__check_reg__reg_addr_30 = 0;
    ::IData/*31:0*/ __Vtask_tb_riscv_core__DOT__check_reg__expected_val_31;
    __Vtask_tb_riscv_core__DOT__check_reg__expected_val_31 = 0;
    ::CData/*4:0*/ __Vtask_tb_riscv_core__DOT__check_reg__reg_addr_33;
    __Vtask_tb_riscv_core__DOT__check_reg__reg_addr_33 = 0;
    ::IData/*31:0*/ __Vtask_tb_riscv_core__DOT__check_reg__expected_val_34;
    __Vtask_tb_riscv_core__DOT__check_reg__expected_val_34 = 0;
    ::CData/*4:0*/ __Vtask_tb_riscv_core__DOT__check_reg__reg_addr_36;
    __Vtask_tb_riscv_core__DOT__check_reg__reg_addr_36 = 0;
    ::IData/*31:0*/ __Vtask_tb_riscv_core__DOT__check_reg__expected_val_37;
    __Vtask_tb_riscv_core__DOT__check_reg__expected_val_37 = 0;
    ::CData/*4:0*/ __Vtask_tb_riscv_core__DOT__check_reg__reg_addr_39;
    __Vtask_tb_riscv_core__DOT__check_reg__reg_addr_39 = 0;
    ::IData/*31:0*/ __Vtask_tb_riscv_core__DOT__check_reg__expected_val_40;
    __Vtask_tb_riscv_core__DOT__check_reg__expected_val_40 = 0;
    ::CData/*4:0*/ __Vtask_tb_riscv_core__DOT__check_reg__reg_addr_42;
    __Vtask_tb_riscv_core__DOT__check_reg__reg_addr_42 = 0;
    ::IData/*31:0*/ __Vtask_tb_riscv_core__DOT__check_reg__expected_val_43;
    __Vtask_tb_riscv_core__DOT__check_reg__expected_val_43 = 0;
    ::CData/*4:0*/ __Vtask_tb_riscv_core__DOT__check_reg__reg_addr_45;
    __Vtask_tb_riscv_core__DOT__check_reg__reg_addr_45 = 0;
    ::IData/*31:0*/ __Vtask_tb_riscv_core__DOT__check_reg__expected_val_46;
    __Vtask_tb_riscv_core__DOT__check_reg__expected_val_46 = 0;
    ::CData/*4:0*/ __Vtask_tb_riscv_core__DOT__check_reg__reg_addr_48;
    __Vtask_tb_riscv_core__DOT__check_reg__reg_addr_48 = 0;
    ::IData/*31:0*/ __Vtask_tb_riscv_core__DOT__check_reg__expected_val_49;
    __Vtask_tb_riscv_core__DOT__check_reg__expected_val_49 = 0;
    ::CData/*4:0*/ __Vtask_tb_riscv_core__DOT__check_reg__reg_addr_51;
    __Vtask_tb_riscv_core__DOT__check_reg__reg_addr_51 = 0;
    ::IData/*31:0*/ __Vtask_tb_riscv_core__DOT__check_reg__expected_val_52;
    __Vtask_tb_riscv_core__DOT__check_reg__expected_val_52 = 0;
    ::CData/*4:0*/ __Vtask_tb_riscv_core__DOT__check_reg__reg_addr_54;
    __Vtask_tb_riscv_core__DOT__check_reg__reg_addr_54 = 0;
    ::IData/*31:0*/ __Vtask_tb_riscv_core__DOT__check_reg__expected_val_55;
    __Vtask_tb_riscv_core__DOT__check_reg__expected_val_55 = 0;
    ::CData/*4:0*/ __Vtask_tb_riscv_core__DOT__check_reg__reg_addr_57;
    __Vtask_tb_riscv_core__DOT__check_reg__reg_addr_57 = 0;
    ::IData/*31:0*/ __Vtask_tb_riscv_core__DOT__check_reg__expected_val_58;
    __Vtask_tb_riscv_core__DOT__check_reg__expected_val_58 = 0;
    ::CData/*4:0*/ __Vtask_tb_riscv_core__DOT__check_reg__reg_addr_60;
    __Vtask_tb_riscv_core__DOT__check_reg__reg_addr_60 = 0;
    ::IData/*31:0*/ __Vtask_tb_riscv_core__DOT__check_reg__expected_val_61;
    __Vtask_tb_riscv_core__DOT__check_reg__expected_val_61 = 0;
    ::CData/*4:0*/ __Vtask_tb_riscv_core__DOT__check_reg__reg_addr_63;
    __Vtask_tb_riscv_core__DOT__check_reg__reg_addr_63 = 0;
    ::IData/*31:0*/ __Vtask_tb_riscv_core__DOT__check_reg__expected_val_64;
    __Vtask_tb_riscv_core__DOT__check_reg__expected_val_64 = 0;
    ::CData/*4:0*/ __Vtask_tb_riscv_core__DOT__check_reg__reg_addr_66;
    __Vtask_tb_riscv_core__DOT__check_reg__reg_addr_66 = 0;
    ::IData/*31:0*/ __Vtask_tb_riscv_core__DOT__check_reg__expected_val_67;
    __Vtask_tb_riscv_core__DOT__check_reg__expected_val_67 = 0;
    ::CData/*4:0*/ __Vtask_tb_riscv_core__DOT__check_reg__reg_addr_69;
    __Vtask_tb_riscv_core__DOT__check_reg__reg_addr_69 = 0;
    ::IData/*31:0*/ __Vtask_tb_riscv_core__DOT__check_reg__expected_val_70;
    __Vtask_tb_riscv_core__DOT__check_reg__expected_val_70 = 0;
    ::CData/*4:0*/ __Vtask_tb_riscv_core__DOT__check_reg__reg_addr_72;
    __Vtask_tb_riscv_core__DOT__check_reg__reg_addr_72 = 0;
    ::IData/*31:0*/ __Vtask_tb_riscv_core__DOT__check_reg__expected_val_73;
    __Vtask_tb_riscv_core__DOT__check_reg__expected_val_73 = 0;
    ::CData/*4:0*/ __Vtask_tb_riscv_core__DOT__check_reg__reg_addr_75;
    __Vtask_tb_riscv_core__DOT__check_reg__reg_addr_75 = 0;
    ::IData/*31:0*/ __Vtask_tb_riscv_core__DOT__check_reg__expected_val_76;
    __Vtask_tb_riscv_core__DOT__check_reg__expected_val_76 = 0;
    ::CData/*4:0*/ __Vtask_tb_riscv_core__DOT__check_reg__reg_addr_78;
    __Vtask_tb_riscv_core__DOT__check_reg__reg_addr_78 = 0;
    ::IData/*31:0*/ __Vtask_tb_riscv_core__DOT__check_reg__expected_val_79;
    __Vtask_tb_riscv_core__DOT__check_reg__expected_val_79 = 0;
    ::CData/*4:0*/ __Vtask_tb_riscv_core__DOT__check_reg__reg_addr_81;
    __Vtask_tb_riscv_core__DOT__check_reg__reg_addr_81 = 0;
    ::IData/*31:0*/ __Vtask_tb_riscv_core__DOT__check_reg__expected_val_82;
    __Vtask_tb_riscv_core__DOT__check_reg__expected_val_82 = 0;
    ::CData/*4:0*/ __Vtask_tb_riscv_core__DOT__check_reg__reg_addr_84;
    __Vtask_tb_riscv_core__DOT__check_reg__reg_addr_84 = 0;
    ::IData/*31:0*/ __Vtask_tb_riscv_core__DOT__check_reg__expected_val_85;
    __Vtask_tb_riscv_core__DOT__check_reg__expected_val_85 = 0;
    ::CData/*4:0*/ __Vtask_tb_riscv_core__DOT__check_reg__reg_addr_87;
    __Vtask_tb_riscv_core__DOT__check_reg__reg_addr_87 = 0;
    ::IData/*31:0*/ __Vtask_tb_riscv_core__DOT__check_reg__expected_val_88;
    __Vtask_tb_riscv_core__DOT__check_reg__expected_val_88 = 0;
    ::IData/*31:0*/ __Vtask_tb_riscv_core__DOT__check_mem__mem_addr_90;
    __Vtask_tb_riscv_core__DOT__check_mem__mem_addr_90 = 0;
    ::IData/*31:0*/ __Vtask_tb_riscv_core__DOT__check_mem__expected_val_91;
    __Vtask_tb_riscv_core__DOT__check_mem__expected_val_91 = 0;
    ::CData/*4:0*/ __Vtask_tb_riscv_core__DOT__check_reg__reg_addr_93;
    __Vtask_tb_riscv_core__DOT__check_reg__reg_addr_93 = 0;
    ::IData/*31:0*/ __Vtask_tb_riscv_core__DOT__check_reg__expected_val_94;
    __Vtask_tb_riscv_core__DOT__check_reg__expected_val_94 = 0;
    ::CData/*4:0*/ __Vtask_tb_riscv_core__DOT__check_reg__reg_addr_96;
    __Vtask_tb_riscv_core__DOT__check_reg__reg_addr_96 = 0;
    ::IData/*31:0*/ __Vtask_tb_riscv_core__DOT__check_reg__expected_val_97;
    __Vtask_tb_riscv_core__DOT__check_reg__expected_val_97 = 0;
    // Body
    std::ignore = VL_VALUEPLUSARGS_INI(32, "TEST=%d"s, 
                                       vlSelfRef.tb_riscv_core__DOT__test);
    vlSelfRef.tb_riscv_core__DOT__clk = 0U;
    vlSelfRef.tb_riscv_core__DOT__rst = 1U;
    VL_WRITEF_NX("==================================================\n STARTING RISC-V TOP-LEVEL END-TO-END CORE TEST   \n==================================================\n",0);
    co_await vlSelfRef.__Vnontrivs.__VdlySched.delay(0x0000000000004e20ULL, 
                                                     nullptr, 
                                                     "tb_riscv_core.sv", 
                                                     88);
    vlSelfRef.tb_riscv_core__DOT__rst = 0U;
    co_await vlSelfRef.__Vnontrivs.__VdlySched.delay(0x00000000000c3500ULL, 
                                                     nullptr, 
                                                     "tb_riscv_core.sv", 
                                                     91);
    VL_WRITEF_NX("\n--------------------------------------------------\n VERIFYING PIPELINE EXECUTION & HAZARD RESOLUTION \n--------------------------------------------------\n",0);
    if ((0U == vlSelfRef.tb_riscv_core__DOT__test)) {
        vlSelfRef.__Vnontrivs.__Vtask_tb_riscv_core__DOT__check_reg__test_desc_2 = "ALU: addi x1"s;
        __Vtask_tb_riscv_core__DOT__check_reg__expected_val_1 = 0x0000000aU;
        __Vtask_tb_riscv_core__DOT__check_reg__reg_addr_0 = 1U;
        vlSelfRef.tb_riscv_core__DOT__test_count = 
            ((::IData)(1U) + vlSelfRef.tb_riscv_core__DOT__test_count);
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
            vlSelfRef.tb_riscv_core__DOT__error_count 
                = ((::IData)(1U) + vlSelfRef.tb_riscv_core__DOT__error_count);
        } else {
            VL_WRITEF_NX("PASS [%s]: x%0d = 0x%h (%0d)\n",4
                         , 'S',&(vlSelfRef.__Vnontrivs.__Vtask_tb_riscv_core__DOT__check_reg__test_desc_2)
                         , '#',5,(::IData)(__Vtask_tb_riscv_core__DOT__check_reg__reg_addr_0)
                         , '#',32,vlSelfRef.tb_riscv_core__DOT__uut__DOT__u_regfile__DOT__rf
                         [__Vtask_tb_riscv_core__DOT__check_reg__reg_addr_0]
                         , '#',32,vlSelfRef.tb_riscv_core__DOT__uut__DOT__u_regfile__DOT__rf
                         [__Vtask_tb_riscv_core__DOT__check_reg__reg_addr_0]);
        }
        vlSelfRef.__Vnontrivs.__Vtask_tb_riscv_core__DOT__check_reg__test_desc_5 = "ALU: addi x2"s;
        __Vtask_tb_riscv_core__DOT__check_reg__expected_val_4 = 0x00000014U;
        __Vtask_tb_riscv_core__DOT__check_reg__reg_addr_3 = 2U;
        vlSelfRef.tb_riscv_core__DOT__test_count = 
            ((::IData)(1U) + vlSelfRef.tb_riscv_core__DOT__test_count);
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
            vlSelfRef.tb_riscv_core__DOT__error_count 
                = ((::IData)(1U) + vlSelfRef.tb_riscv_core__DOT__error_count);
        } else {
            VL_WRITEF_NX("PASS [%s]: x%0d = 0x%h (%0d)\n",4
                         , 'S',&(vlSelfRef.__Vnontrivs.__Vtask_tb_riscv_core__DOT__check_reg__test_desc_5)
                         , '#',5,(::IData)(__Vtask_tb_riscv_core__DOT__check_reg__reg_addr_3)
                         , '#',32,vlSelfRef.tb_riscv_core__DOT__uut__DOT__u_regfile__DOT__rf
                         [__Vtask_tb_riscv_core__DOT__check_reg__reg_addr_3]
                         , '#',32,vlSelfRef.tb_riscv_core__DOT__uut__DOT__u_regfile__DOT__rf
                         [__Vtask_tb_riscv_core__DOT__check_reg__reg_addr_3]);
        }
        vlSelfRef.__Vnontrivs.__Vtask_tb_riscv_core__DOT__check_reg__test_desc_8 = "Forwarding: add x3 = x1 + x2"s;
        __Vtask_tb_riscv_core__DOT__check_reg__expected_val_7 = 0x0000001eU;
        __Vtask_tb_riscv_core__DOT__check_reg__reg_addr_6 = 3U;
        vlSelfRef.tb_riscv_core__DOT__test_count = 
            ((::IData)(1U) + vlSelfRef.tb_riscv_core__DOT__test_count);
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
            vlSelfRef.tb_riscv_core__DOT__error_count 
                = ((::IData)(1U) + vlSelfRef.tb_riscv_core__DOT__error_count);
        } else {
            VL_WRITEF_NX("PASS [%s]: x%0d = 0x%h (%0d)\n",4
                         , 'S',&(vlSelfRef.__Vnontrivs.__Vtask_tb_riscv_core__DOT__check_reg__test_desc_8)
                         , '#',5,(::IData)(__Vtask_tb_riscv_core__DOT__check_reg__reg_addr_6)
                         , '#',32,vlSelfRef.tb_riscv_core__DOT__uut__DOT__u_regfile__DOT__rf
                         [__Vtask_tb_riscv_core__DOT__check_reg__reg_addr_6]
                         , '#',32,vlSelfRef.tb_riscv_core__DOT__uut__DOT__u_regfile__DOT__rf
                         [__Vtask_tb_riscv_core__DOT__check_reg__reg_addr_6]);
        }
        vlSelfRef.__Vnontrivs.__Vtask_tb_riscv_core__DOT__check_mem__test_desc_11 = "Store: mem[0] = x3"s;
        __Vtask_tb_riscv_core__DOT__check_mem__expected_val_10 = 0x0000001eU;
        __Vtask_tb_riscv_core__DOT__check_mem__mem_addr_9 = 0U;
        vlSelfRef.tb_riscv_core__DOT__test_count = 
            ((::IData)(1U) + vlSelfRef.tb_riscv_core__DOT__test_count);
        if ((vlSelfRef.tb_riscv_core__DOT__uut__DOT__dmem__DOT__mem
             [(0x000000ffU & (__Vtask_tb_riscv_core__DOT__check_mem__mem_addr_9 
                              >> 2U))] != __Vtask_tb_riscv_core__DOT__check_mem__expected_val_10)) {
            VL_WRITEF_NX("FAIL [%s]: Mem[0x%h] = 0x%h, Expected = 0x%h\n",4
                         , 'S',&(vlSelfRef.__Vnontrivs.__Vtask_tb_riscv_core__DOT__check_mem__test_desc_11)
                         , '#',32,__Vtask_tb_riscv_core__DOT__check_mem__mem_addr_9
                         , '#',32,vlSelfRef.tb_riscv_core__DOT__uut__DOT__dmem__DOT__mem
                         [(0x000000ffU & (__Vtask_tb_riscv_core__DOT__check_mem__mem_addr_9 
                                          >> 2U))], '#',32,__Vtask_tb_riscv_core__DOT__check_mem__expected_val_10);
            vlSelfRef.tb_riscv_core__DOT__error_count 
                = ((::IData)(1U) + vlSelfRef.tb_riscv_core__DOT__error_count);
        } else {
            VL_WRITEF_NX("PASS [%s]: Mem[0x%h] = 0x%h\n",3
                         , 'S',&(vlSelfRef.__Vnontrivs.__Vtask_tb_riscv_core__DOT__check_mem__test_desc_11)
                         , '#',32,__Vtask_tb_riscv_core__DOT__check_mem__mem_addr_9
                         , '#',32,vlSelfRef.tb_riscv_core__DOT__uut__DOT__dmem__DOT__mem
                         [(0x000000ffU & (__Vtask_tb_riscv_core__DOT__check_mem__mem_addr_9 
                                          >> 2U))]);
        }
        vlSelfRef.__Vnontrivs.__Vtask_tb_riscv_core__DOT__check_reg__test_desc_14 = "Load: x4 = mem[0]"s;
        __Vtask_tb_riscv_core__DOT__check_reg__expected_val_13 = 0x0000001eU;
        __Vtask_tb_riscv_core__DOT__check_reg__reg_addr_12 = 4U;
        vlSelfRef.tb_riscv_core__DOT__test_count = 
            ((::IData)(1U) + vlSelfRef.tb_riscv_core__DOT__test_count);
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
            vlSelfRef.tb_riscv_core__DOT__error_count 
                = ((::IData)(1U) + vlSelfRef.tb_riscv_core__DOT__error_count);
        } else {
            VL_WRITEF_NX("PASS [%s]: x%0d = 0x%h (%0d)\n",4
                         , 'S',&(vlSelfRef.__Vnontrivs.__Vtask_tb_riscv_core__DOT__check_reg__test_desc_14)
                         , '#',5,(::IData)(__Vtask_tb_riscv_core__DOT__check_reg__reg_addr_12)
                         , '#',32,vlSelfRef.tb_riscv_core__DOT__uut__DOT__u_regfile__DOT__rf
                         [__Vtask_tb_riscv_core__DOT__check_reg__reg_addr_12]
                         , '#',32,vlSelfRef.tb_riscv_core__DOT__uut__DOT__u_regfile__DOT__rf
                         [__Vtask_tb_riscv_core__DOT__check_reg__reg_addr_12]);
        }
    } else if ((1U == vlSelfRef.tb_riscv_core__DOT__test)) {
        vlSelfRef.__Vnontrivs.__Vtask_tb_riscv_core__DOT__check_reg__test_desc_17 = "BNE taken: x3 skipped"s;
        __Vtask_tb_riscv_core__DOT__check_reg__expected_val_16 = 0U;
        __Vtask_tb_riscv_core__DOT__check_reg__reg_addr_15 = 3U;
        vlSelfRef.tb_riscv_core__DOT__test_count = 
            ((::IData)(1U) + vlSelfRef.tb_riscv_core__DOT__test_count);
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
            vlSelfRef.tb_riscv_core__DOT__error_count 
                = ((::IData)(1U) + vlSelfRef.tb_riscv_core__DOT__error_count);
        } else {
            VL_WRITEF_NX("PASS [%s]: x%0d = 0x%h (%0d)\n",4
                         , 'S',&(vlSelfRef.__Vnontrivs.__Vtask_tb_riscv_core__DOT__check_reg__test_desc_17)
                         , '#',5,(::IData)(__Vtask_tb_riscv_core__DOT__check_reg__reg_addr_15)
                         , '#',32,vlSelfRef.tb_riscv_core__DOT__uut__DOT__u_regfile__DOT__rf
                         [__Vtask_tb_riscv_core__DOT__check_reg__reg_addr_15]
                         , '#',32,vlSelfRef.tb_riscv_core__DOT__uut__DOT__u_regfile__DOT__rf
                         [__Vtask_tb_riscv_core__DOT__check_reg__reg_addr_15]);
        }
        vlSelfRef.__Vnontrivs.__Vtask_tb_riscv_core__DOT__check_reg__test_desc_20 = "BLT taken: x4 skipped"s;
        __Vtask_tb_riscv_core__DOT__check_reg__expected_val_19 = 0U;
        __Vtask_tb_riscv_core__DOT__check_reg__reg_addr_18 = 4U;
        vlSelfRef.tb_riscv_core__DOT__test_count = 
            ((::IData)(1U) + vlSelfRef.tb_riscv_core__DOT__test_count);
        if ((vlSelfRef.tb_riscv_core__DOT__uut__DOT__u_regfile__DOT__rf
             [__Vtask_tb_riscv_core__DOT__check_reg__reg_addr_18] 
             != __Vtask_tb_riscv_core__DOT__check_reg__expected_val_19)) {
            VL_WRITEF_NX("FAIL [%s]: x%0d = 0x%h (%0d), Expected = 0x%h (%0d)\n",6
                         , 'S',&(vlSelfRef.__Vnontrivs.__Vtask_tb_riscv_core__DOT__check_reg__test_desc_20)
                         , '#',5,(::IData)(__Vtask_tb_riscv_core__DOT__check_reg__reg_addr_18)
                         , '#',32,vlSelfRef.tb_riscv_core__DOT__uut__DOT__u_regfile__DOT__rf
                         [__Vtask_tb_riscv_core__DOT__check_reg__reg_addr_18]
                         , '#',32,vlSelfRef.tb_riscv_core__DOT__uut__DOT__u_regfile__DOT__rf
                         [__Vtask_tb_riscv_core__DOT__check_reg__reg_addr_18]
                         , '#',32,__Vtask_tb_riscv_core__DOT__check_reg__expected_val_19
                         , '#',32,__Vtask_tb_riscv_core__DOT__check_reg__expected_val_19);
            vlSelfRef.tb_riscv_core__DOT__error_count 
                = ((::IData)(1U) + vlSelfRef.tb_riscv_core__DOT__error_count);
        } else {
            VL_WRITEF_NX("PASS [%s]: x%0d = 0x%h (%0d)\n",4
                         , 'S',&(vlSelfRef.__Vnontrivs.__Vtask_tb_riscv_core__DOT__check_reg__test_desc_20)
                         , '#',5,(::IData)(__Vtask_tb_riscv_core__DOT__check_reg__reg_addr_18)
                         , '#',32,vlSelfRef.tb_riscv_core__DOT__uut__DOT__u_regfile__DOT__rf
                         [__Vtask_tb_riscv_core__DOT__check_reg__reg_addr_18]
                         , '#',32,vlSelfRef.tb_riscv_core__DOT__uut__DOT__u_regfile__DOT__rf
                         [__Vtask_tb_riscv_core__DOT__check_reg__reg_addr_18]);
        }
        vlSelfRef.__Vnontrivs.__Vtask_tb_riscv_core__DOT__check_reg__test_desc_23 = "BGE not taken: x5 executed"s;
        __Vtask_tb_riscv_core__DOT__check_reg__expected_val_22 = 1U;
        __Vtask_tb_riscv_core__DOT__check_reg__reg_addr_21 = 5U;
        vlSelfRef.tb_riscv_core__DOT__test_count = 
            ((::IData)(1U) + vlSelfRef.tb_riscv_core__DOT__test_count);
        if ((vlSelfRef.tb_riscv_core__DOT__uut__DOT__u_regfile__DOT__rf
             [__Vtask_tb_riscv_core__DOT__check_reg__reg_addr_21] 
             != __Vtask_tb_riscv_core__DOT__check_reg__expected_val_22)) {
            VL_WRITEF_NX("FAIL [%s]: x%0d = 0x%h (%0d), Expected = 0x%h (%0d)\n",6
                         , 'S',&(vlSelfRef.__Vnontrivs.__Vtask_tb_riscv_core__DOT__check_reg__test_desc_23)
                         , '#',5,(::IData)(__Vtask_tb_riscv_core__DOT__check_reg__reg_addr_21)
                         , '#',32,vlSelfRef.tb_riscv_core__DOT__uut__DOT__u_regfile__DOT__rf
                         [__Vtask_tb_riscv_core__DOT__check_reg__reg_addr_21]
                         , '#',32,vlSelfRef.tb_riscv_core__DOT__uut__DOT__u_regfile__DOT__rf
                         [__Vtask_tb_riscv_core__DOT__check_reg__reg_addr_21]
                         , '#',32,__Vtask_tb_riscv_core__DOT__check_reg__expected_val_22
                         , '#',32,__Vtask_tb_riscv_core__DOT__check_reg__expected_val_22);
            vlSelfRef.tb_riscv_core__DOT__error_count 
                = ((::IData)(1U) + vlSelfRef.tb_riscv_core__DOT__error_count);
        } else {
            VL_WRITEF_NX("PASS [%s]: x%0d = 0x%h (%0d)\n",4
                         , 'S',&(vlSelfRef.__Vnontrivs.__Vtask_tb_riscv_core__DOT__check_reg__test_desc_23)
                         , '#',5,(::IData)(__Vtask_tb_riscv_core__DOT__check_reg__reg_addr_21)
                         , '#',32,vlSelfRef.tb_riscv_core__DOT__uut__DOT__u_regfile__DOT__rf
                         [__Vtask_tb_riscv_core__DOT__check_reg__reg_addr_21]
                         , '#',32,vlSelfRef.tb_riscv_core__DOT__uut__DOT__u_regfile__DOT__rf
                         [__Vtask_tb_riscv_core__DOT__check_reg__reg_addr_21]);
        }
        vlSelfRef.__Vnontrivs.__Vtask_tb_riscv_core__DOT__check_reg__test_desc_26 = "BLT signed taken: x8 skipped"s;
        __Vtask_tb_riscv_core__DOT__check_reg__expected_val_25 = 0U;
        __Vtask_tb_riscv_core__DOT__check_reg__reg_addr_24 = 8U;
        vlSelfRef.tb_riscv_core__DOT__test_count = 
            ((::IData)(1U) + vlSelfRef.tb_riscv_core__DOT__test_count);
        if ((vlSelfRef.tb_riscv_core__DOT__uut__DOT__u_regfile__DOT__rf
             [__Vtask_tb_riscv_core__DOT__check_reg__reg_addr_24] 
             != __Vtask_tb_riscv_core__DOT__check_reg__expected_val_25)) {
            VL_WRITEF_NX("FAIL [%s]: x%0d = 0x%h (%0d), Expected = 0x%h (%0d)\n",6
                         , 'S',&(vlSelfRef.__Vnontrivs.__Vtask_tb_riscv_core__DOT__check_reg__test_desc_26)
                         , '#',5,(::IData)(__Vtask_tb_riscv_core__DOT__check_reg__reg_addr_24)
                         , '#',32,vlSelfRef.tb_riscv_core__DOT__uut__DOT__u_regfile__DOT__rf
                         [__Vtask_tb_riscv_core__DOT__check_reg__reg_addr_24]
                         , '#',32,vlSelfRef.tb_riscv_core__DOT__uut__DOT__u_regfile__DOT__rf
                         [__Vtask_tb_riscv_core__DOT__check_reg__reg_addr_24]
                         , '#',32,__Vtask_tb_riscv_core__DOT__check_reg__expected_val_25
                         , '#',32,__Vtask_tb_riscv_core__DOT__check_reg__expected_val_25);
            vlSelfRef.tb_riscv_core__DOT__error_count 
                = ((::IData)(1U) + vlSelfRef.tb_riscv_core__DOT__error_count);
        } else {
            VL_WRITEF_NX("PASS [%s]: x%0d = 0x%h (%0d)\n",4
                         , 'S',&(vlSelfRef.__Vnontrivs.__Vtask_tb_riscv_core__DOT__check_reg__test_desc_26)
                         , '#',5,(::IData)(__Vtask_tb_riscv_core__DOT__check_reg__reg_addr_24)
                         , '#',32,vlSelfRef.tb_riscv_core__DOT__uut__DOT__u_regfile__DOT__rf
                         [__Vtask_tb_riscv_core__DOT__check_reg__reg_addr_24]
                         , '#',32,vlSelfRef.tb_riscv_core__DOT__uut__DOT__u_regfile__DOT__rf
                         [__Vtask_tb_riscv_core__DOT__check_reg__reg_addr_24]);
        }
        vlSelfRef.__Vnontrivs.__Vtask_tb_riscv_core__DOT__check_reg__test_desc_29 = "BLTU not taken: x9 executed"s;
        __Vtask_tb_riscv_core__DOT__check_reg__expected_val_28 = 1U;
        __Vtask_tb_riscv_core__DOT__check_reg__reg_addr_27 = 9U;
        vlSelfRef.tb_riscv_core__DOT__test_count = 
            ((::IData)(1U) + vlSelfRef.tb_riscv_core__DOT__test_count);
        if ((vlSelfRef.tb_riscv_core__DOT__uut__DOT__u_regfile__DOT__rf
             [__Vtask_tb_riscv_core__DOT__check_reg__reg_addr_27] 
             != __Vtask_tb_riscv_core__DOT__check_reg__expected_val_28)) {
            VL_WRITEF_NX("FAIL [%s]: x%0d = 0x%h (%0d), Expected = 0x%h (%0d)\n",6
                         , 'S',&(vlSelfRef.__Vnontrivs.__Vtask_tb_riscv_core__DOT__check_reg__test_desc_29)
                         , '#',5,(::IData)(__Vtask_tb_riscv_core__DOT__check_reg__reg_addr_27)
                         , '#',32,vlSelfRef.tb_riscv_core__DOT__uut__DOT__u_regfile__DOT__rf
                         [__Vtask_tb_riscv_core__DOT__check_reg__reg_addr_27]
                         , '#',32,vlSelfRef.tb_riscv_core__DOT__uut__DOT__u_regfile__DOT__rf
                         [__Vtask_tb_riscv_core__DOT__check_reg__reg_addr_27]
                         , '#',32,__Vtask_tb_riscv_core__DOT__check_reg__expected_val_28
                         , '#',32,__Vtask_tb_riscv_core__DOT__check_reg__expected_val_28);
            vlSelfRef.tb_riscv_core__DOT__error_count 
                = ((::IData)(1U) + vlSelfRef.tb_riscv_core__DOT__error_count);
        } else {
            VL_WRITEF_NX("PASS [%s]: x%0d = 0x%h (%0d)\n",4
                         , 'S',&(vlSelfRef.__Vnontrivs.__Vtask_tb_riscv_core__DOT__check_reg__test_desc_29)
                         , '#',5,(::IData)(__Vtask_tb_riscv_core__DOT__check_reg__reg_addr_27)
                         , '#',32,vlSelfRef.tb_riscv_core__DOT__uut__DOT__u_regfile__DOT__rf
                         [__Vtask_tb_riscv_core__DOT__check_reg__reg_addr_27]
                         , '#',32,vlSelfRef.tb_riscv_core__DOT__uut__DOT__u_regfile__DOT__rf
                         [__Vtask_tb_riscv_core__DOT__check_reg__reg_addr_27]);
        }
    } else if ((2U == vlSelfRef.tb_riscv_core__DOT__test)) {
        vlSelfRef.__Vnontrivs.__Vtask_tb_riscv_core__DOT__check_reg__test_desc_32 = "JAL: x3 skipped"s;
        __Vtask_tb_riscv_core__DOT__check_reg__expected_val_31 = 0U;
        __Vtask_tb_riscv_core__DOT__check_reg__reg_addr_30 = 3U;
        vlSelfRef.tb_riscv_core__DOT__test_count = 
            ((::IData)(1U) + vlSelfRef.tb_riscv_core__DOT__test_count);
        if ((vlSelfRef.tb_riscv_core__DOT__uut__DOT__u_regfile__DOT__rf
             [__Vtask_tb_riscv_core__DOT__check_reg__reg_addr_30] 
             != __Vtask_tb_riscv_core__DOT__check_reg__expected_val_31)) {
            VL_WRITEF_NX("FAIL [%s]: x%0d = 0x%h (%0d), Expected = 0x%h (%0d)\n",6
                         , 'S',&(vlSelfRef.__Vnontrivs.__Vtask_tb_riscv_core__DOT__check_reg__test_desc_32)
                         , '#',5,(::IData)(__Vtask_tb_riscv_core__DOT__check_reg__reg_addr_30)
                         , '#',32,vlSelfRef.tb_riscv_core__DOT__uut__DOT__u_regfile__DOT__rf
                         [__Vtask_tb_riscv_core__DOT__check_reg__reg_addr_30]
                         , '#',32,vlSelfRef.tb_riscv_core__DOT__uut__DOT__u_regfile__DOT__rf
                         [__Vtask_tb_riscv_core__DOT__check_reg__reg_addr_30]
                         , '#',32,__Vtask_tb_riscv_core__DOT__check_reg__expected_val_31
                         , '#',32,__Vtask_tb_riscv_core__DOT__check_reg__expected_val_31);
            vlSelfRef.tb_riscv_core__DOT__error_count 
                = ((::IData)(1U) + vlSelfRef.tb_riscv_core__DOT__error_count);
        } else {
            VL_WRITEF_NX("PASS [%s]: x%0d = 0x%h (%0d)\n",4
                         , 'S',&(vlSelfRef.__Vnontrivs.__Vtask_tb_riscv_core__DOT__check_reg__test_desc_32)
                         , '#',5,(::IData)(__Vtask_tb_riscv_core__DOT__check_reg__reg_addr_30)
                         , '#',32,vlSelfRef.tb_riscv_core__DOT__uut__DOT__u_regfile__DOT__rf
                         [__Vtask_tb_riscv_core__DOT__check_reg__reg_addr_30]
                         , '#',32,vlSelfRef.tb_riscv_core__DOT__uut__DOT__u_regfile__DOT__rf
                         [__Vtask_tb_riscv_core__DOT__check_reg__reg_addr_30]);
        }
        vlSelfRef.__Vnontrivs.__Vtask_tb_riscv_core__DOT__check_reg__test_desc_35 = "JAL: x4 skipped"s;
        __Vtask_tb_riscv_core__DOT__check_reg__expected_val_34 = 0U;
        __Vtask_tb_riscv_core__DOT__check_reg__reg_addr_33 = 4U;
        vlSelfRef.tb_riscv_core__DOT__test_count = 
            ((::IData)(1U) + vlSelfRef.tb_riscv_core__DOT__test_count);
        if ((vlSelfRef.tb_riscv_core__DOT__uut__DOT__u_regfile__DOT__rf
             [__Vtask_tb_riscv_core__DOT__check_reg__reg_addr_33] 
             != __Vtask_tb_riscv_core__DOT__check_reg__expected_val_34)) {
            VL_WRITEF_NX("FAIL [%s]: x%0d = 0x%h (%0d), Expected = 0x%h (%0d)\n",6
                         , 'S',&(vlSelfRef.__Vnontrivs.__Vtask_tb_riscv_core__DOT__check_reg__test_desc_35)
                         , '#',5,(::IData)(__Vtask_tb_riscv_core__DOT__check_reg__reg_addr_33)
                         , '#',32,vlSelfRef.tb_riscv_core__DOT__uut__DOT__u_regfile__DOT__rf
                         [__Vtask_tb_riscv_core__DOT__check_reg__reg_addr_33]
                         , '#',32,vlSelfRef.tb_riscv_core__DOT__uut__DOT__u_regfile__DOT__rf
                         [__Vtask_tb_riscv_core__DOT__check_reg__reg_addr_33]
                         , '#',32,__Vtask_tb_riscv_core__DOT__check_reg__expected_val_34
                         , '#',32,__Vtask_tb_riscv_core__DOT__check_reg__expected_val_34);
            vlSelfRef.tb_riscv_core__DOT__error_count 
                = ((::IData)(1U) + vlSelfRef.tb_riscv_core__DOT__error_count);
        } else {
            VL_WRITEF_NX("PASS [%s]: x%0d = 0x%h (%0d)\n",4
                         , 'S',&(vlSelfRef.__Vnontrivs.__Vtask_tb_riscv_core__DOT__check_reg__test_desc_35)
                         , '#',5,(::IData)(__Vtask_tb_riscv_core__DOT__check_reg__reg_addr_33)
                         , '#',32,vlSelfRef.tb_riscv_core__DOT__uut__DOT__u_regfile__DOT__rf
                         [__Vtask_tb_riscv_core__DOT__check_reg__reg_addr_33]
                         , '#',32,vlSelfRef.tb_riscv_core__DOT__uut__DOT__u_regfile__DOT__rf
                         [__Vtask_tb_riscv_core__DOT__check_reg__reg_addr_33]);
        }
        vlSelfRef.__Vnontrivs.__Vtask_tb_riscv_core__DOT__check_reg__test_desc_38 = "JAL target executed"s;
        __Vtask_tb_riscv_core__DOT__check_reg__expected_val_37 = 1U;
        __Vtask_tb_riscv_core__DOT__check_reg__reg_addr_36 = 5U;
        vlSelfRef.tb_riscv_core__DOT__test_count = 
            ((::IData)(1U) + vlSelfRef.tb_riscv_core__DOT__test_count);
        if ((vlSelfRef.tb_riscv_core__DOT__uut__DOT__u_regfile__DOT__rf
             [__Vtask_tb_riscv_core__DOT__check_reg__reg_addr_36] 
             != __Vtask_tb_riscv_core__DOT__check_reg__expected_val_37)) {
            VL_WRITEF_NX("FAIL [%s]: x%0d = 0x%h (%0d), Expected = 0x%h (%0d)\n",6
                         , 'S',&(vlSelfRef.__Vnontrivs.__Vtask_tb_riscv_core__DOT__check_reg__test_desc_38)
                         , '#',5,(::IData)(__Vtask_tb_riscv_core__DOT__check_reg__reg_addr_36)
                         , '#',32,vlSelfRef.tb_riscv_core__DOT__uut__DOT__u_regfile__DOT__rf
                         [__Vtask_tb_riscv_core__DOT__check_reg__reg_addr_36]
                         , '#',32,vlSelfRef.tb_riscv_core__DOT__uut__DOT__u_regfile__DOT__rf
                         [__Vtask_tb_riscv_core__DOT__check_reg__reg_addr_36]
                         , '#',32,__Vtask_tb_riscv_core__DOT__check_reg__expected_val_37
                         , '#',32,__Vtask_tb_riscv_core__DOT__check_reg__expected_val_37);
            vlSelfRef.tb_riscv_core__DOT__error_count 
                = ((::IData)(1U) + vlSelfRef.tb_riscv_core__DOT__error_count);
        } else {
            VL_WRITEF_NX("PASS [%s]: x%0d = 0x%h (%0d)\n",4
                         , 'S',&(vlSelfRef.__Vnontrivs.__Vtask_tb_riscv_core__DOT__check_reg__test_desc_38)
                         , '#',5,(::IData)(__Vtask_tb_riscv_core__DOT__check_reg__reg_addr_36)
                         , '#',32,vlSelfRef.tb_riscv_core__DOT__uut__DOT__u_regfile__DOT__rf
                         [__Vtask_tb_riscv_core__DOT__check_reg__reg_addr_36]
                         , '#',32,vlSelfRef.tb_riscv_core__DOT__uut__DOT__u_regfile__DOT__rf
                         [__Vtask_tb_riscv_core__DOT__check_reg__reg_addr_36]);
        }
        vlSelfRef.__Vnontrivs.__Vtask_tb_riscv_core__DOT__check_reg__test_desc_41 = "JAL link: x10 = PC+4"s;
        __Vtask_tb_riscv_core__DOT__check_reg__expected_val_40 = 8U;
        __Vtask_tb_riscv_core__DOT__check_reg__reg_addr_39 = 0x0aU;
        vlSelfRef.tb_riscv_core__DOT__test_count = 
            ((::IData)(1U) + vlSelfRef.tb_riscv_core__DOT__test_count);
        if ((vlSelfRef.tb_riscv_core__DOT__uut__DOT__u_regfile__DOT__rf
             [__Vtask_tb_riscv_core__DOT__check_reg__reg_addr_39] 
             != __Vtask_tb_riscv_core__DOT__check_reg__expected_val_40)) {
            VL_WRITEF_NX("FAIL [%s]: x%0d = 0x%h (%0d), Expected = 0x%h (%0d)\n",6
                         , 'S',&(vlSelfRef.__Vnontrivs.__Vtask_tb_riscv_core__DOT__check_reg__test_desc_41)
                         , '#',5,(::IData)(__Vtask_tb_riscv_core__DOT__check_reg__reg_addr_39)
                         , '#',32,vlSelfRef.tb_riscv_core__DOT__uut__DOT__u_regfile__DOT__rf
                         [__Vtask_tb_riscv_core__DOT__check_reg__reg_addr_39]
                         , '#',32,vlSelfRef.tb_riscv_core__DOT__uut__DOT__u_regfile__DOT__rf
                         [__Vtask_tb_riscv_core__DOT__check_reg__reg_addr_39]
                         , '#',32,__Vtask_tb_riscv_core__DOT__check_reg__expected_val_40
                         , '#',32,__Vtask_tb_riscv_core__DOT__check_reg__expected_val_40);
            vlSelfRef.tb_riscv_core__DOT__error_count 
                = ((::IData)(1U) + vlSelfRef.tb_riscv_core__DOT__error_count);
        } else {
            VL_WRITEF_NX("PASS [%s]: x%0d = 0x%h (%0d)\n",4
                         , 'S',&(vlSelfRef.__Vnontrivs.__Vtask_tb_riscv_core__DOT__check_reg__test_desc_41)
                         , '#',5,(::IData)(__Vtask_tb_riscv_core__DOT__check_reg__reg_addr_39)
                         , '#',32,vlSelfRef.tb_riscv_core__DOT__uut__DOT__u_regfile__DOT__rf
                         [__Vtask_tb_riscv_core__DOT__check_reg__reg_addr_39]
                         , '#',32,vlSelfRef.tb_riscv_core__DOT__uut__DOT__u_regfile__DOT__rf
                         [__Vtask_tb_riscv_core__DOT__check_reg__reg_addr_39]);
        }
        vlSelfRef.__Vnontrivs.__Vtask_tb_riscv_core__DOT__check_reg__test_desc_44 = "JALR: x8 skipped"s;
        __Vtask_tb_riscv_core__DOT__check_reg__expected_val_43 = 0U;
        __Vtask_tb_riscv_core__DOT__check_reg__reg_addr_42 = 8U;
        vlSelfRef.tb_riscv_core__DOT__test_count = 
            ((::IData)(1U) + vlSelfRef.tb_riscv_core__DOT__test_count);
        if ((vlSelfRef.tb_riscv_core__DOT__uut__DOT__u_regfile__DOT__rf
             [__Vtask_tb_riscv_core__DOT__check_reg__reg_addr_42] 
             != __Vtask_tb_riscv_core__DOT__check_reg__expected_val_43)) {
            VL_WRITEF_NX("FAIL [%s]: x%0d = 0x%h (%0d), Expected = 0x%h (%0d)\n",6
                         , 'S',&(vlSelfRef.__Vnontrivs.__Vtask_tb_riscv_core__DOT__check_reg__test_desc_44)
                         , '#',5,(::IData)(__Vtask_tb_riscv_core__DOT__check_reg__reg_addr_42)
                         , '#',32,vlSelfRef.tb_riscv_core__DOT__uut__DOT__u_regfile__DOT__rf
                         [__Vtask_tb_riscv_core__DOT__check_reg__reg_addr_42]
                         , '#',32,vlSelfRef.tb_riscv_core__DOT__uut__DOT__u_regfile__DOT__rf
                         [__Vtask_tb_riscv_core__DOT__check_reg__reg_addr_42]
                         , '#',32,__Vtask_tb_riscv_core__DOT__check_reg__expected_val_43
                         , '#',32,__Vtask_tb_riscv_core__DOT__check_reg__expected_val_43);
            vlSelfRef.tb_riscv_core__DOT__error_count 
                = ((::IData)(1U) + vlSelfRef.tb_riscv_core__DOT__error_count);
        } else {
            VL_WRITEF_NX("PASS [%s]: x%0d = 0x%h (%0d)\n",4
                         , 'S',&(vlSelfRef.__Vnontrivs.__Vtask_tb_riscv_core__DOT__check_reg__test_desc_44)
                         , '#',5,(::IData)(__Vtask_tb_riscv_core__DOT__check_reg__reg_addr_42)
                         , '#',32,vlSelfRef.tb_riscv_core__DOT__uut__DOT__u_regfile__DOT__rf
                         [__Vtask_tb_riscv_core__DOT__check_reg__reg_addr_42]
                         , '#',32,vlSelfRef.tb_riscv_core__DOT__uut__DOT__u_regfile__DOT__rf
                         [__Vtask_tb_riscv_core__DOT__check_reg__reg_addr_42]);
        }
        vlSelfRef.__Vnontrivs.__Vtask_tb_riscv_core__DOT__check_reg__test_desc_47 = "JALR link: x12 = PC+4"s;
        __Vtask_tb_riscv_core__DOT__check_reg__expected_val_46 = 0x0000001cU;
        __Vtask_tb_riscv_core__DOT__check_reg__reg_addr_45 = 0x0cU;
        vlSelfRef.tb_riscv_core__DOT__test_count = 
            ((::IData)(1U) + vlSelfRef.tb_riscv_core__DOT__test_count);
        if ((vlSelfRef.tb_riscv_core__DOT__uut__DOT__u_regfile__DOT__rf
             [__Vtask_tb_riscv_core__DOT__check_reg__reg_addr_45] 
             != __Vtask_tb_riscv_core__DOT__check_reg__expected_val_46)) {
            VL_WRITEF_NX("FAIL [%s]: x%0d = 0x%h (%0d), Expected = 0x%h (%0d)\n",6
                         , 'S',&(vlSelfRef.__Vnontrivs.__Vtask_tb_riscv_core__DOT__check_reg__test_desc_47)
                         , '#',5,(::IData)(__Vtask_tb_riscv_core__DOT__check_reg__reg_addr_45)
                         , '#',32,vlSelfRef.tb_riscv_core__DOT__uut__DOT__u_regfile__DOT__rf
                         [__Vtask_tb_riscv_core__DOT__check_reg__reg_addr_45]
                         , '#',32,vlSelfRef.tb_riscv_core__DOT__uut__DOT__u_regfile__DOT__rf
                         [__Vtask_tb_riscv_core__DOT__check_reg__reg_addr_45]
                         , '#',32,__Vtask_tb_riscv_core__DOT__check_reg__expected_val_46
                         , '#',32,__Vtask_tb_riscv_core__DOT__check_reg__expected_val_46);
            vlSelfRef.tb_riscv_core__DOT__error_count 
                = ((::IData)(1U) + vlSelfRef.tb_riscv_core__DOT__error_count);
        } else {
            VL_WRITEF_NX("PASS [%s]: x%0d = 0x%h (%0d)\n",4
                         , 'S',&(vlSelfRef.__Vnontrivs.__Vtask_tb_riscv_core__DOT__check_reg__test_desc_47)
                         , '#',5,(::IData)(__Vtask_tb_riscv_core__DOT__check_reg__reg_addr_45)
                         , '#',32,vlSelfRef.tb_riscv_core__DOT__uut__DOT__u_regfile__DOT__rf
                         [__Vtask_tb_riscv_core__DOT__check_reg__reg_addr_45]
                         , '#',32,vlSelfRef.tb_riscv_core__DOT__uut__DOT__u_regfile__DOT__rf
                         [__Vtask_tb_riscv_core__DOT__check_reg__reg_addr_45]);
        }
        vlSelfRef.__Vnontrivs.__Vtask_tb_riscv_core__DOT__check_reg__test_desc_50 = "JALR target: x9 = x10 + x12"s;
        __Vtask_tb_riscv_core__DOT__check_reg__expected_val_49 = 0x00000024U;
        __Vtask_tb_riscv_core__DOT__check_reg__reg_addr_48 = 9U;
        vlSelfRef.tb_riscv_core__DOT__test_count = 
            ((::IData)(1U) + vlSelfRef.tb_riscv_core__DOT__test_count);
        if ((vlSelfRef.tb_riscv_core__DOT__uut__DOT__u_regfile__DOT__rf
             [__Vtask_tb_riscv_core__DOT__check_reg__reg_addr_48] 
             != __Vtask_tb_riscv_core__DOT__check_reg__expected_val_49)) {
            VL_WRITEF_NX("FAIL [%s]: x%0d = 0x%h (%0d), Expected = 0x%h (%0d)\n",6
                         , 'S',&(vlSelfRef.__Vnontrivs.__Vtask_tb_riscv_core__DOT__check_reg__test_desc_50)
                         , '#',5,(::IData)(__Vtask_tb_riscv_core__DOT__check_reg__reg_addr_48)
                         , '#',32,vlSelfRef.tb_riscv_core__DOT__uut__DOT__u_regfile__DOT__rf
                         [__Vtask_tb_riscv_core__DOT__check_reg__reg_addr_48]
                         , '#',32,vlSelfRef.tb_riscv_core__DOT__uut__DOT__u_regfile__DOT__rf
                         [__Vtask_tb_riscv_core__DOT__check_reg__reg_addr_48]
                         , '#',32,__Vtask_tb_riscv_core__DOT__check_reg__expected_val_49
                         , '#',32,__Vtask_tb_riscv_core__DOT__check_reg__expected_val_49);
            vlSelfRef.tb_riscv_core__DOT__error_count 
                = ((::IData)(1U) + vlSelfRef.tb_riscv_core__DOT__error_count);
        } else {
            VL_WRITEF_NX("PASS [%s]: x%0d = 0x%h (%0d)\n",4
                         , 'S',&(vlSelfRef.__Vnontrivs.__Vtask_tb_riscv_core__DOT__check_reg__test_desc_50)
                         , '#',5,(::IData)(__Vtask_tb_riscv_core__DOT__check_reg__reg_addr_48)
                         , '#',32,vlSelfRef.tb_riscv_core__DOT__uut__DOT__u_regfile__DOT__rf
                         [__Vtask_tb_riscv_core__DOT__check_reg__reg_addr_48]
                         , '#',32,vlSelfRef.tb_riscv_core__DOT__uut__DOT__u_regfile__DOT__rf
                         [__Vtask_tb_riscv_core__DOT__check_reg__reg_addr_48]);
        }
    } else if ((3U == vlSelfRef.tb_riscv_core__DOT__test)) {
        vlSelfRef.__Vnontrivs.__Vtask_tb_riscv_core__DOT__check_reg__test_desc_53 = "Setup: x8 = 99"s;
        __Vtask_tb_riscv_core__DOT__check_reg__expected_val_52 = 0x00000063U;
        __Vtask_tb_riscv_core__DOT__check_reg__reg_addr_51 = 8U;
        vlSelfRef.tb_riscv_core__DOT__test_count = 
            ((::IData)(1U) + vlSelfRef.tb_riscv_core__DOT__test_count);
        if ((vlSelfRef.tb_riscv_core__DOT__uut__DOT__u_regfile__DOT__rf
             [__Vtask_tb_riscv_core__DOT__check_reg__reg_addr_51] 
             != __Vtask_tb_riscv_core__DOT__check_reg__expected_val_52)) {
            VL_WRITEF_NX("FAIL [%s]: x%0d = 0x%h (%0d), Expected = 0x%h (%0d)\n",6
                         , 'S',&(vlSelfRef.__Vnontrivs.__Vtask_tb_riscv_core__DOT__check_reg__test_desc_53)
                         , '#',5,(::IData)(__Vtask_tb_riscv_core__DOT__check_reg__reg_addr_51)
                         , '#',32,vlSelfRef.tb_riscv_core__DOT__uut__DOT__u_regfile__DOT__rf
                         [__Vtask_tb_riscv_core__DOT__check_reg__reg_addr_51]
                         , '#',32,vlSelfRef.tb_riscv_core__DOT__uut__DOT__u_regfile__DOT__rf
                         [__Vtask_tb_riscv_core__DOT__check_reg__reg_addr_51]
                         , '#',32,__Vtask_tb_riscv_core__DOT__check_reg__expected_val_52
                         , '#',32,__Vtask_tb_riscv_core__DOT__check_reg__expected_val_52);
            vlSelfRef.tb_riscv_core__DOT__error_count 
                = ((::IData)(1U) + vlSelfRef.tb_riscv_core__DOT__error_count);
        } else {
            VL_WRITEF_NX("PASS [%s]: x%0d = 0x%h (%0d)\n",4
                         , 'S',&(vlSelfRef.__Vnontrivs.__Vtask_tb_riscv_core__DOT__check_reg__test_desc_53)
                         , '#',5,(::IData)(__Vtask_tb_riscv_core__DOT__check_reg__reg_addr_51)
                         , '#',32,vlSelfRef.tb_riscv_core__DOT__uut__DOT__u_regfile__DOT__rf
                         [__Vtask_tb_riscv_core__DOT__check_reg__reg_addr_51]
                         , '#',32,vlSelfRef.tb_riscv_core__DOT__uut__DOT__u_regfile__DOT__rf
                         [__Vtask_tb_riscv_core__DOT__check_reg__reg_addr_51]);
        }
        vlSelfRef.__Vnontrivs.__Vtask_tb_riscv_core__DOT__check_reg__test_desc_56 = "Setup: x31 = 99"s;
        __Vtask_tb_riscv_core__DOT__check_reg__expected_val_55 = 0x00000063U;
        __Vtask_tb_riscv_core__DOT__check_reg__reg_addr_54 = 0x1fU;
        vlSelfRef.tb_riscv_core__DOT__test_count = 
            ((::IData)(1U) + vlSelfRef.tb_riscv_core__DOT__test_count);
        if ((vlSelfRef.tb_riscv_core__DOT__uut__DOT__u_regfile__DOT__rf
             [__Vtask_tb_riscv_core__DOT__check_reg__reg_addr_54] 
             != __Vtask_tb_riscv_core__DOT__check_reg__expected_val_55)) {
            VL_WRITEF_NX("FAIL [%s]: x%0d = 0x%h (%0d), Expected = 0x%h (%0d)\n",6
                         , 'S',&(vlSelfRef.__Vnontrivs.__Vtask_tb_riscv_core__DOT__check_reg__test_desc_56)
                         , '#',5,(::IData)(__Vtask_tb_riscv_core__DOT__check_reg__reg_addr_54)
                         , '#',32,vlSelfRef.tb_riscv_core__DOT__uut__DOT__u_regfile__DOT__rf
                         [__Vtask_tb_riscv_core__DOT__check_reg__reg_addr_54]
                         , '#',32,vlSelfRef.tb_riscv_core__DOT__uut__DOT__u_regfile__DOT__rf
                         [__Vtask_tb_riscv_core__DOT__check_reg__reg_addr_54]
                         , '#',32,__Vtask_tb_riscv_core__DOT__check_reg__expected_val_55
                         , '#',32,__Vtask_tb_riscv_core__DOT__check_reg__expected_val_55);
            vlSelfRef.tb_riscv_core__DOT__error_count 
                = ((::IData)(1U) + vlSelfRef.tb_riscv_core__DOT__error_count);
        } else {
            VL_WRITEF_NX("PASS [%s]: x%0d = 0x%h (%0d)\n",4
                         , 'S',&(vlSelfRef.__Vnontrivs.__Vtask_tb_riscv_core__DOT__check_reg__test_desc_56)
                         , '#',5,(::IData)(__Vtask_tb_riscv_core__DOT__check_reg__reg_addr_54)
                         , '#',32,vlSelfRef.tb_riscv_core__DOT__uut__DOT__u_regfile__DOT__rf
                         [__Vtask_tb_riscv_core__DOT__check_reg__reg_addr_54]
                         , '#',32,vlSelfRef.tb_riscv_core__DOT__uut__DOT__u_regfile__DOT__rf
                         [__Vtask_tb_riscv_core__DOT__check_reg__reg_addr_54]);
        }
        vlSelfRef.__Vnontrivs.__Vtask_tb_riscv_core__DOT__check_reg__test_desc_59 = "LUI ignores its rs1 bits (x8 = 99)"s;
        __Vtask_tb_riscv_core__DOT__check_reg__expected_val_58 = 0x12345000U;
        __Vtask_tb_riscv_core__DOT__check_reg__reg_addr_57 = 1U;
        vlSelfRef.tb_riscv_core__DOT__test_count = 
            ((::IData)(1U) + vlSelfRef.tb_riscv_core__DOT__test_count);
        if ((vlSelfRef.tb_riscv_core__DOT__uut__DOT__u_regfile__DOT__rf
             [__Vtask_tb_riscv_core__DOT__check_reg__reg_addr_57] 
             != __Vtask_tb_riscv_core__DOT__check_reg__expected_val_58)) {
            VL_WRITEF_NX("FAIL [%s]: x%0d = 0x%h (%0d), Expected = 0x%h (%0d)\n",6
                         , 'S',&(vlSelfRef.__Vnontrivs.__Vtask_tb_riscv_core__DOT__check_reg__test_desc_59)
                         , '#',5,(::IData)(__Vtask_tb_riscv_core__DOT__check_reg__reg_addr_57)
                         , '#',32,vlSelfRef.tb_riscv_core__DOT__uut__DOT__u_regfile__DOT__rf
                         [__Vtask_tb_riscv_core__DOT__check_reg__reg_addr_57]
                         , '#',32,vlSelfRef.tb_riscv_core__DOT__uut__DOT__u_regfile__DOT__rf
                         [__Vtask_tb_riscv_core__DOT__check_reg__reg_addr_57]
                         , '#',32,__Vtask_tb_riscv_core__DOT__check_reg__expected_val_58
                         , '#',32,__Vtask_tb_riscv_core__DOT__check_reg__expected_val_58);
            vlSelfRef.tb_riscv_core__DOT__error_count 
                = ((::IData)(1U) + vlSelfRef.tb_riscv_core__DOT__error_count);
        } else {
            VL_WRITEF_NX("PASS [%s]: x%0d = 0x%h (%0d)\n",4
                         , 'S',&(vlSelfRef.__Vnontrivs.__Vtask_tb_riscv_core__DOT__check_reg__test_desc_59)
                         , '#',5,(::IData)(__Vtask_tb_riscv_core__DOT__check_reg__reg_addr_57)
                         , '#',32,vlSelfRef.tb_riscv_core__DOT__uut__DOT__u_regfile__DOT__rf
                         [__Vtask_tb_riscv_core__DOT__check_reg__reg_addr_57]
                         , '#',32,vlSelfRef.tb_riscv_core__DOT__uut__DOT__u_regfile__DOT__rf
                         [__Vtask_tb_riscv_core__DOT__check_reg__reg_addr_57]);
        }
        vlSelfRef.__Vnontrivs.__Vtask_tb_riscv_core__DOT__check_reg__test_desc_62 = "AUIPC: pc(12) + 0x1000"s;
        __Vtask_tb_riscv_core__DOT__check_reg__expected_val_61 = 0x0000100cU;
        __Vtask_tb_riscv_core__DOT__check_reg__reg_addr_60 = 2U;
        vlSelfRef.tb_riscv_core__DOT__test_count = 
            ((::IData)(1U) + vlSelfRef.tb_riscv_core__DOT__test_count);
        if ((vlSelfRef.tb_riscv_core__DOT__uut__DOT__u_regfile__DOT__rf
             [__Vtask_tb_riscv_core__DOT__check_reg__reg_addr_60] 
             != __Vtask_tb_riscv_core__DOT__check_reg__expected_val_61)) {
            VL_WRITEF_NX("FAIL [%s]: x%0d = 0x%h (%0d), Expected = 0x%h (%0d)\n",6
                         , 'S',&(vlSelfRef.__Vnontrivs.__Vtask_tb_riscv_core__DOT__check_reg__test_desc_62)
                         , '#',5,(::IData)(__Vtask_tb_riscv_core__DOT__check_reg__reg_addr_60)
                         , '#',32,vlSelfRef.tb_riscv_core__DOT__uut__DOT__u_regfile__DOT__rf
                         [__Vtask_tb_riscv_core__DOT__check_reg__reg_addr_60]
                         , '#',32,vlSelfRef.tb_riscv_core__DOT__uut__DOT__u_regfile__DOT__rf
                         [__Vtask_tb_riscv_core__DOT__check_reg__reg_addr_60]
                         , '#',32,__Vtask_tb_riscv_core__DOT__check_reg__expected_val_61
                         , '#',32,__Vtask_tb_riscv_core__DOT__check_reg__expected_val_61);
            vlSelfRef.tb_riscv_core__DOT__error_count 
                = ((::IData)(1U) + vlSelfRef.tb_riscv_core__DOT__error_count);
        } else {
            VL_WRITEF_NX("PASS [%s]: x%0d = 0x%h (%0d)\n",4
                         , 'S',&(vlSelfRef.__Vnontrivs.__Vtask_tb_riscv_core__DOT__check_reg__test_desc_62)
                         , '#',5,(::IData)(__Vtask_tb_riscv_core__DOT__check_reg__reg_addr_60)
                         , '#',32,vlSelfRef.tb_riscv_core__DOT__uut__DOT__u_regfile__DOT__rf
                         [__Vtask_tb_riscv_core__DOT__check_reg__reg_addr_60]
                         , '#',32,vlSelfRef.tb_riscv_core__DOT__uut__DOT__u_regfile__DOT__rf
                         [__Vtask_tb_riscv_core__DOT__check_reg__reg_addr_60]);
        }
        vlSelfRef.__Vnontrivs.__Vtask_tb_riscv_core__DOT__check_reg__test_desc_65 = "LUI + ADDI builds a 32-bit constant"s;
        __Vtask_tb_riscv_core__DOT__check_reg__expected_val_64 = 0x12345678U;
        __Vtask_tb_riscv_core__DOT__check_reg__reg_addr_63 = 3U;
        vlSelfRef.tb_riscv_core__DOT__test_count = 
            ((::IData)(1U) + vlSelfRef.tb_riscv_core__DOT__test_count);
        if ((vlSelfRef.tb_riscv_core__DOT__uut__DOT__u_regfile__DOT__rf
             [__Vtask_tb_riscv_core__DOT__check_reg__reg_addr_63] 
             != __Vtask_tb_riscv_core__DOT__check_reg__expected_val_64)) {
            VL_WRITEF_NX("FAIL [%s]: x%0d = 0x%h (%0d), Expected = 0x%h (%0d)\n",6
                         , 'S',&(vlSelfRef.__Vnontrivs.__Vtask_tb_riscv_core__DOT__check_reg__test_desc_65)
                         , '#',5,(::IData)(__Vtask_tb_riscv_core__DOT__check_reg__reg_addr_63)
                         , '#',32,vlSelfRef.tb_riscv_core__DOT__uut__DOT__u_regfile__DOT__rf
                         [__Vtask_tb_riscv_core__DOT__check_reg__reg_addr_63]
                         , '#',32,vlSelfRef.tb_riscv_core__DOT__uut__DOT__u_regfile__DOT__rf
                         [__Vtask_tb_riscv_core__DOT__check_reg__reg_addr_63]
                         , '#',32,__Vtask_tb_riscv_core__DOT__check_reg__expected_val_64
                         , '#',32,__Vtask_tb_riscv_core__DOT__check_reg__expected_val_64);
            vlSelfRef.tb_riscv_core__DOT__error_count 
                = ((::IData)(1U) + vlSelfRef.tb_riscv_core__DOT__error_count);
        } else {
            VL_WRITEF_NX("PASS [%s]: x%0d = 0x%h (%0d)\n",4
                         , 'S',&(vlSelfRef.__Vnontrivs.__Vtask_tb_riscv_core__DOT__check_reg__test_desc_65)
                         , '#',5,(::IData)(__Vtask_tb_riscv_core__DOT__check_reg__reg_addr_63)
                         , '#',32,vlSelfRef.tb_riscv_core__DOT__uut__DOT__u_regfile__DOT__rf
                         [__Vtask_tb_riscv_core__DOT__check_reg__reg_addr_63]
                         , '#',32,vlSelfRef.tb_riscv_core__DOT__uut__DOT__u_regfile__DOT__rf
                         [__Vtask_tb_riscv_core__DOT__check_reg__reg_addr_63]);
        }
        vlSelfRef.__Vnontrivs.__Vtask_tb_riscv_core__DOT__check_reg__test_desc_68 = "LUI with top bit set (rs1 bits = x31 = 99)"s;
        __Vtask_tb_riscv_core__DOT__check_reg__expected_val_67 = 0xfffff000U;
        __Vtask_tb_riscv_core__DOT__check_reg__reg_addr_66 = 4U;
        vlSelfRef.tb_riscv_core__DOT__test_count = 
            ((::IData)(1U) + vlSelfRef.tb_riscv_core__DOT__test_count);
        if ((vlSelfRef.tb_riscv_core__DOT__uut__DOT__u_regfile__DOT__rf
             [__Vtask_tb_riscv_core__DOT__check_reg__reg_addr_66] 
             != __Vtask_tb_riscv_core__DOT__check_reg__expected_val_67)) {
            VL_WRITEF_NX("FAIL [%s]: x%0d = 0x%h (%0d), Expected = 0x%h (%0d)\n",6
                         , 'S',&(vlSelfRef.__Vnontrivs.__Vtask_tb_riscv_core__DOT__check_reg__test_desc_68)
                         , '#',5,(::IData)(__Vtask_tb_riscv_core__DOT__check_reg__reg_addr_66)
                         , '#',32,vlSelfRef.tb_riscv_core__DOT__uut__DOT__u_regfile__DOT__rf
                         [__Vtask_tb_riscv_core__DOT__check_reg__reg_addr_66]
                         , '#',32,vlSelfRef.tb_riscv_core__DOT__uut__DOT__u_regfile__DOT__rf
                         [__Vtask_tb_riscv_core__DOT__check_reg__reg_addr_66]
                         , '#',32,__Vtask_tb_riscv_core__DOT__check_reg__expected_val_67
                         , '#',32,__Vtask_tb_riscv_core__DOT__check_reg__expected_val_67);
            vlSelfRef.tb_riscv_core__DOT__error_count 
                = ((::IData)(1U) + vlSelfRef.tb_riscv_core__DOT__error_count);
        } else {
            VL_WRITEF_NX("PASS [%s]: x%0d = 0x%h (%0d)\n",4
                         , 'S',&(vlSelfRef.__Vnontrivs.__Vtask_tb_riscv_core__DOT__check_reg__test_desc_68)
                         , '#',5,(::IData)(__Vtask_tb_riscv_core__DOT__check_reg__reg_addr_66)
                         , '#',32,vlSelfRef.tb_riscv_core__DOT__uut__DOT__u_regfile__DOT__rf
                         [__Vtask_tb_riscv_core__DOT__check_reg__reg_addr_66]
                         , '#',32,vlSelfRef.tb_riscv_core__DOT__uut__DOT__u_regfile__DOT__rf
                         [__Vtask_tb_riscv_core__DOT__check_reg__reg_addr_66]);
        }
        vlSelfRef.__Vnontrivs.__Vtask_tb_riscv_core__DOT__check_reg__test_desc_71 = "AUIPC with imm 0 = pc(24)"s;
        __Vtask_tb_riscv_core__DOT__check_reg__expected_val_70 = 0x00000018U;
        __Vtask_tb_riscv_core__DOT__check_reg__reg_addr_69 = 5U;
        vlSelfRef.tb_riscv_core__DOT__test_count = 
            ((::IData)(1U) + vlSelfRef.tb_riscv_core__DOT__test_count);
        if ((vlSelfRef.tb_riscv_core__DOT__uut__DOT__u_regfile__DOT__rf
             [__Vtask_tb_riscv_core__DOT__check_reg__reg_addr_69] 
             != __Vtask_tb_riscv_core__DOT__check_reg__expected_val_70)) {
            VL_WRITEF_NX("FAIL [%s]: x%0d = 0x%h (%0d), Expected = 0x%h (%0d)\n",6
                         , 'S',&(vlSelfRef.__Vnontrivs.__Vtask_tb_riscv_core__DOT__check_reg__test_desc_71)
                         , '#',5,(::IData)(__Vtask_tb_riscv_core__DOT__check_reg__reg_addr_69)
                         , '#',32,vlSelfRef.tb_riscv_core__DOT__uut__DOT__u_regfile__DOT__rf
                         [__Vtask_tb_riscv_core__DOT__check_reg__reg_addr_69]
                         , '#',32,vlSelfRef.tb_riscv_core__DOT__uut__DOT__u_regfile__DOT__rf
                         [__Vtask_tb_riscv_core__DOT__check_reg__reg_addr_69]
                         , '#',32,__Vtask_tb_riscv_core__DOT__check_reg__expected_val_70
                         , '#',32,__Vtask_tb_riscv_core__DOT__check_reg__expected_val_70);
            vlSelfRef.tb_riscv_core__DOT__error_count 
                = ((::IData)(1U) + vlSelfRef.tb_riscv_core__DOT__error_count);
        } else {
            VL_WRITEF_NX("PASS [%s]: x%0d = 0x%h (%0d)\n",4
                         , 'S',&(vlSelfRef.__Vnontrivs.__Vtask_tb_riscv_core__DOT__check_reg__test_desc_71)
                         , '#',5,(::IData)(__Vtask_tb_riscv_core__DOT__check_reg__reg_addr_69)
                         , '#',32,vlSelfRef.tb_riscv_core__DOT__uut__DOT__u_regfile__DOT__rf
                         [__Vtask_tb_riscv_core__DOT__check_reg__reg_addr_69]
                         , '#',32,vlSelfRef.tb_riscv_core__DOT__uut__DOT__u_regfile__DOT__rf
                         [__Vtask_tb_riscv_core__DOT__check_reg__reg_addr_69]);
        }
    } else if ((4U == vlSelfRef.tb_riscv_core__DOT__test)) {
        vlSelfRef.__Vnontrivs.__Vtask_tb_riscv_core__DOT__check_reg__test_desc_74 = "LB byte 0, sign-extended"s;
        __Vtask_tb_riscv_core__DOT__check_reg__expected_val_73 = 0xffffffa1U;
        __Vtask_tb_riscv_core__DOT__check_reg__reg_addr_72 = 2U;
        vlSelfRef.tb_riscv_core__DOT__test_count = 
            ((::IData)(1U) + vlSelfRef.tb_riscv_core__DOT__test_count);
        if ((vlSelfRef.tb_riscv_core__DOT__uut__DOT__u_regfile__DOT__rf
             [__Vtask_tb_riscv_core__DOT__check_reg__reg_addr_72] 
             != __Vtask_tb_riscv_core__DOT__check_reg__expected_val_73)) {
            VL_WRITEF_NX("FAIL [%s]: x%0d = 0x%h (%0d), Expected = 0x%h (%0d)\n",6
                         , 'S',&(vlSelfRef.__Vnontrivs.__Vtask_tb_riscv_core__DOT__check_reg__test_desc_74)
                         , '#',5,(::IData)(__Vtask_tb_riscv_core__DOT__check_reg__reg_addr_72)
                         , '#',32,vlSelfRef.tb_riscv_core__DOT__uut__DOT__u_regfile__DOT__rf
                         [__Vtask_tb_riscv_core__DOT__check_reg__reg_addr_72]
                         , '#',32,vlSelfRef.tb_riscv_core__DOT__uut__DOT__u_regfile__DOT__rf
                         [__Vtask_tb_riscv_core__DOT__check_reg__reg_addr_72]
                         , '#',32,__Vtask_tb_riscv_core__DOT__check_reg__expected_val_73
                         , '#',32,__Vtask_tb_riscv_core__DOT__check_reg__expected_val_73);
            vlSelfRef.tb_riscv_core__DOT__error_count 
                = ((::IData)(1U) + vlSelfRef.tb_riscv_core__DOT__error_count);
        } else {
            VL_WRITEF_NX("PASS [%s]: x%0d = 0x%h (%0d)\n",4
                         , 'S',&(vlSelfRef.__Vnontrivs.__Vtask_tb_riscv_core__DOT__check_reg__test_desc_74)
                         , '#',5,(::IData)(__Vtask_tb_riscv_core__DOT__check_reg__reg_addr_72)
                         , '#',32,vlSelfRef.tb_riscv_core__DOT__uut__DOT__u_regfile__DOT__rf
                         [__Vtask_tb_riscv_core__DOT__check_reg__reg_addr_72]
                         , '#',32,vlSelfRef.tb_riscv_core__DOT__uut__DOT__u_regfile__DOT__rf
                         [__Vtask_tb_riscv_core__DOT__check_reg__reg_addr_72]);
        }
        vlSelfRef.__Vnontrivs.__Vtask_tb_riscv_core__DOT__check_reg__test_desc_77 = "LBU byte 0, zero-extended"s;
        __Vtask_tb_riscv_core__DOT__check_reg__expected_val_76 = 0x000000a1U;
        __Vtask_tb_riscv_core__DOT__check_reg__reg_addr_75 = 3U;
        vlSelfRef.tb_riscv_core__DOT__test_count = 
            ((::IData)(1U) + vlSelfRef.tb_riscv_core__DOT__test_count);
        if ((vlSelfRef.tb_riscv_core__DOT__uut__DOT__u_regfile__DOT__rf
             [__Vtask_tb_riscv_core__DOT__check_reg__reg_addr_75] 
             != __Vtask_tb_riscv_core__DOT__check_reg__expected_val_76)) {
            VL_WRITEF_NX("FAIL [%s]: x%0d = 0x%h (%0d), Expected = 0x%h (%0d)\n",6
                         , 'S',&(vlSelfRef.__Vnontrivs.__Vtask_tb_riscv_core__DOT__check_reg__test_desc_77)
                         , '#',5,(::IData)(__Vtask_tb_riscv_core__DOT__check_reg__reg_addr_75)
                         , '#',32,vlSelfRef.tb_riscv_core__DOT__uut__DOT__u_regfile__DOT__rf
                         [__Vtask_tb_riscv_core__DOT__check_reg__reg_addr_75]
                         , '#',32,vlSelfRef.tb_riscv_core__DOT__uut__DOT__u_regfile__DOT__rf
                         [__Vtask_tb_riscv_core__DOT__check_reg__reg_addr_75]
                         , '#',32,__Vtask_tb_riscv_core__DOT__check_reg__expected_val_76
                         , '#',32,__Vtask_tb_riscv_core__DOT__check_reg__expected_val_76);
            vlSelfRef.tb_riscv_core__DOT__error_count 
                = ((::IData)(1U) + vlSelfRef.tb_riscv_core__DOT__error_count);
        } else {
            VL_WRITEF_NX("PASS [%s]: x%0d = 0x%h (%0d)\n",4
                         , 'S',&(vlSelfRef.__Vnontrivs.__Vtask_tb_riscv_core__DOT__check_reg__test_desc_77)
                         , '#',5,(::IData)(__Vtask_tb_riscv_core__DOT__check_reg__reg_addr_75)
                         , '#',32,vlSelfRef.tb_riscv_core__DOT__uut__DOT__u_regfile__DOT__rf
                         [__Vtask_tb_riscv_core__DOT__check_reg__reg_addr_75]
                         , '#',32,vlSelfRef.tb_riscv_core__DOT__uut__DOT__u_regfile__DOT__rf
                         [__Vtask_tb_riscv_core__DOT__check_reg__reg_addr_75]);
        }
        vlSelfRef.__Vnontrivs.__Vtask_tb_riscv_core__DOT__check_reg__test_desc_80 = "LB byte 1, positive"s;
        __Vtask_tb_riscv_core__DOT__check_reg__expected_val_79 = 0x00000043U;
        __Vtask_tb_riscv_core__DOT__check_reg__reg_addr_78 = 4U;
        vlSelfRef.tb_riscv_core__DOT__test_count = 
            ((::IData)(1U) + vlSelfRef.tb_riscv_core__DOT__test_count);
        if ((vlSelfRef.tb_riscv_core__DOT__uut__DOT__u_regfile__DOT__rf
             [__Vtask_tb_riscv_core__DOT__check_reg__reg_addr_78] 
             != __Vtask_tb_riscv_core__DOT__check_reg__expected_val_79)) {
            VL_WRITEF_NX("FAIL [%s]: x%0d = 0x%h (%0d), Expected = 0x%h (%0d)\n",6
                         , 'S',&(vlSelfRef.__Vnontrivs.__Vtask_tb_riscv_core__DOT__check_reg__test_desc_80)
                         , '#',5,(::IData)(__Vtask_tb_riscv_core__DOT__check_reg__reg_addr_78)
                         , '#',32,vlSelfRef.tb_riscv_core__DOT__uut__DOT__u_regfile__DOT__rf
                         [__Vtask_tb_riscv_core__DOT__check_reg__reg_addr_78]
                         , '#',32,vlSelfRef.tb_riscv_core__DOT__uut__DOT__u_regfile__DOT__rf
                         [__Vtask_tb_riscv_core__DOT__check_reg__reg_addr_78]
                         , '#',32,__Vtask_tb_riscv_core__DOT__check_reg__expected_val_79
                         , '#',32,__Vtask_tb_riscv_core__DOT__check_reg__expected_val_79);
            vlSelfRef.tb_riscv_core__DOT__error_count 
                = ((::IData)(1U) + vlSelfRef.tb_riscv_core__DOT__error_count);
        } else {
            VL_WRITEF_NX("PASS [%s]: x%0d = 0x%h (%0d)\n",4
                         , 'S',&(vlSelfRef.__Vnontrivs.__Vtask_tb_riscv_core__DOT__check_reg__test_desc_80)
                         , '#',5,(::IData)(__Vtask_tb_riscv_core__DOT__check_reg__reg_addr_78)
                         , '#',32,vlSelfRef.tb_riscv_core__DOT__uut__DOT__u_regfile__DOT__rf
                         [__Vtask_tb_riscv_core__DOT__check_reg__reg_addr_78]
                         , '#',32,vlSelfRef.tb_riscv_core__DOT__uut__DOT__u_regfile__DOT__rf
                         [__Vtask_tb_riscv_core__DOT__check_reg__reg_addr_78]);
        }
        vlSelfRef.__Vnontrivs.__Vtask_tb_riscv_core__DOT__check_reg__test_desc_83 = "LH upper half, sign-extended"s;
        __Vtask_tb_riscv_core__DOT__check_reg__expected_val_82 = 0xffff8765U;
        __Vtask_tb_riscv_core__DOT__check_reg__reg_addr_81 = 5U;
        vlSelfRef.tb_riscv_core__DOT__test_count = 
            ((::IData)(1U) + vlSelfRef.tb_riscv_core__DOT__test_count);
        if ((vlSelfRef.tb_riscv_core__DOT__uut__DOT__u_regfile__DOT__rf
             [__Vtask_tb_riscv_core__DOT__check_reg__reg_addr_81] 
             != __Vtask_tb_riscv_core__DOT__check_reg__expected_val_82)) {
            VL_WRITEF_NX("FAIL [%s]: x%0d = 0x%h (%0d), Expected = 0x%h (%0d)\n",6
                         , 'S',&(vlSelfRef.__Vnontrivs.__Vtask_tb_riscv_core__DOT__check_reg__test_desc_83)
                         , '#',5,(::IData)(__Vtask_tb_riscv_core__DOT__check_reg__reg_addr_81)
                         , '#',32,vlSelfRef.tb_riscv_core__DOT__uut__DOT__u_regfile__DOT__rf
                         [__Vtask_tb_riscv_core__DOT__check_reg__reg_addr_81]
                         , '#',32,vlSelfRef.tb_riscv_core__DOT__uut__DOT__u_regfile__DOT__rf
                         [__Vtask_tb_riscv_core__DOT__check_reg__reg_addr_81]
                         , '#',32,__Vtask_tb_riscv_core__DOT__check_reg__expected_val_82
                         , '#',32,__Vtask_tb_riscv_core__DOT__check_reg__expected_val_82);
            vlSelfRef.tb_riscv_core__DOT__error_count 
                = ((::IData)(1U) + vlSelfRef.tb_riscv_core__DOT__error_count);
        } else {
            VL_WRITEF_NX("PASS [%s]: x%0d = 0x%h (%0d)\n",4
                         , 'S',&(vlSelfRef.__Vnontrivs.__Vtask_tb_riscv_core__DOT__check_reg__test_desc_83)
                         , '#',5,(::IData)(__Vtask_tb_riscv_core__DOT__check_reg__reg_addr_81)
                         , '#',32,vlSelfRef.tb_riscv_core__DOT__uut__DOT__u_regfile__DOT__rf
                         [__Vtask_tb_riscv_core__DOT__check_reg__reg_addr_81]
                         , '#',32,vlSelfRef.tb_riscv_core__DOT__uut__DOT__u_regfile__DOT__rf
                         [__Vtask_tb_riscv_core__DOT__check_reg__reg_addr_81]);
        }
        vlSelfRef.__Vnontrivs.__Vtask_tb_riscv_core__DOT__check_reg__test_desc_86 = "LHU upper half"s;
        __Vtask_tb_riscv_core__DOT__check_reg__expected_val_85 = 0x00008765U;
        __Vtask_tb_riscv_core__DOT__check_reg__reg_addr_84 = 7U;
        vlSelfRef.tb_riscv_core__DOT__test_count = 
            ((::IData)(1U) + vlSelfRef.tb_riscv_core__DOT__test_count);
        if ((vlSelfRef.tb_riscv_core__DOT__uut__DOT__u_regfile__DOT__rf
             [__Vtask_tb_riscv_core__DOT__check_reg__reg_addr_84] 
             != __Vtask_tb_riscv_core__DOT__check_reg__expected_val_85)) {
            VL_WRITEF_NX("FAIL [%s]: x%0d = 0x%h (%0d), Expected = 0x%h (%0d)\n",6
                         , 'S',&(vlSelfRef.__Vnontrivs.__Vtask_tb_riscv_core__DOT__check_reg__test_desc_86)
                         , '#',5,(::IData)(__Vtask_tb_riscv_core__DOT__check_reg__reg_addr_84)
                         , '#',32,vlSelfRef.tb_riscv_core__DOT__uut__DOT__u_regfile__DOT__rf
                         [__Vtask_tb_riscv_core__DOT__check_reg__reg_addr_84]
                         , '#',32,vlSelfRef.tb_riscv_core__DOT__uut__DOT__u_regfile__DOT__rf
                         [__Vtask_tb_riscv_core__DOT__check_reg__reg_addr_84]
                         , '#',32,__Vtask_tb_riscv_core__DOT__check_reg__expected_val_85
                         , '#',32,__Vtask_tb_riscv_core__DOT__check_reg__expected_val_85);
            vlSelfRef.tb_riscv_core__DOT__error_count 
                = ((::IData)(1U) + vlSelfRef.tb_riscv_core__DOT__error_count);
        } else {
            VL_WRITEF_NX("PASS [%s]: x%0d = 0x%h (%0d)\n",4
                         , 'S',&(vlSelfRef.__Vnontrivs.__Vtask_tb_riscv_core__DOT__check_reg__test_desc_86)
                         , '#',5,(::IData)(__Vtask_tb_riscv_core__DOT__check_reg__reg_addr_84)
                         , '#',32,vlSelfRef.tb_riscv_core__DOT__uut__DOT__u_regfile__DOT__rf
                         [__Vtask_tb_riscv_core__DOT__check_reg__reg_addr_84]
                         , '#',32,vlSelfRef.tb_riscv_core__DOT__uut__DOT__u_regfile__DOT__rf
                         [__Vtask_tb_riscv_core__DOT__check_reg__reg_addr_84]);
        }
        vlSelfRef.__Vnontrivs.__Vtask_tb_riscv_core__DOT__check_reg__test_desc_89 = "LW still works"s;
        __Vtask_tb_riscv_core__DOT__check_reg__expected_val_88 = 0x876543a1U;
        __Vtask_tb_riscv_core__DOT__check_reg__reg_addr_87 = 8U;
        vlSelfRef.tb_riscv_core__DOT__test_count = 
            ((::IData)(1U) + vlSelfRef.tb_riscv_core__DOT__test_count);
        if ((vlSelfRef.tb_riscv_core__DOT__uut__DOT__u_regfile__DOT__rf
             [__Vtask_tb_riscv_core__DOT__check_reg__reg_addr_87] 
             != __Vtask_tb_riscv_core__DOT__check_reg__expected_val_88)) {
            VL_WRITEF_NX("FAIL [%s]: x%0d = 0x%h (%0d), Expected = 0x%h (%0d)\n",6
                         , 'S',&(vlSelfRef.__Vnontrivs.__Vtask_tb_riscv_core__DOT__check_reg__test_desc_89)
                         , '#',5,(::IData)(__Vtask_tb_riscv_core__DOT__check_reg__reg_addr_87)
                         , '#',32,vlSelfRef.tb_riscv_core__DOT__uut__DOT__u_regfile__DOT__rf
                         [__Vtask_tb_riscv_core__DOT__check_reg__reg_addr_87]
                         , '#',32,vlSelfRef.tb_riscv_core__DOT__uut__DOT__u_regfile__DOT__rf
                         [__Vtask_tb_riscv_core__DOT__check_reg__reg_addr_87]
                         , '#',32,__Vtask_tb_riscv_core__DOT__check_reg__expected_val_88
                         , '#',32,__Vtask_tb_riscv_core__DOT__check_reg__expected_val_88);
            vlSelfRef.tb_riscv_core__DOT__error_count 
                = ((::IData)(1U) + vlSelfRef.tb_riscv_core__DOT__error_count);
        } else {
            VL_WRITEF_NX("PASS [%s]: x%0d = 0x%h (%0d)\n",4
                         , 'S',&(vlSelfRef.__Vnontrivs.__Vtask_tb_riscv_core__DOT__check_reg__test_desc_89)
                         , '#',5,(::IData)(__Vtask_tb_riscv_core__DOT__check_reg__reg_addr_87)
                         , '#',32,vlSelfRef.tb_riscv_core__DOT__uut__DOT__u_regfile__DOT__rf
                         [__Vtask_tb_riscv_core__DOT__check_reg__reg_addr_87]
                         , '#',32,vlSelfRef.tb_riscv_core__DOT__uut__DOT__u_regfile__DOT__rf
                         [__Vtask_tb_riscv_core__DOT__check_reg__reg_addr_87]);
        }
        vlSelfRef.__Vnontrivs.__Vtask_tb_riscv_core__DOT__check_mem__test_desc_92 = "SB then SH: only their bytes written"s;
        __Vtask_tb_riscv_core__DOT__check_mem__expected_val_91 = 0x0234ff00U;
        __Vtask_tb_riscv_core__DOT__check_mem__mem_addr_90 = 4U;
        vlSelfRef.tb_riscv_core__DOT__test_count = 
            ((::IData)(1U) + vlSelfRef.tb_riscv_core__DOT__test_count);
        if ((vlSelfRef.tb_riscv_core__DOT__uut__DOT__dmem__DOT__mem
             [(0x000000ffU & (__Vtask_tb_riscv_core__DOT__check_mem__mem_addr_90 
                              >> 2U))] != __Vtask_tb_riscv_core__DOT__check_mem__expected_val_91)) {
            VL_WRITEF_NX("FAIL [%s]: Mem[0x%h] = 0x%h, Expected = 0x%h\n",4
                         , 'S',&(vlSelfRef.__Vnontrivs.__Vtask_tb_riscv_core__DOT__check_mem__test_desc_92)
                         , '#',32,__Vtask_tb_riscv_core__DOT__check_mem__mem_addr_90
                         , '#',32,vlSelfRef.tb_riscv_core__DOT__uut__DOT__dmem__DOT__mem
                         [(0x000000ffU & (__Vtask_tb_riscv_core__DOT__check_mem__mem_addr_90 
                                          >> 2U))], '#',32,__Vtask_tb_riscv_core__DOT__check_mem__expected_val_91);
            vlSelfRef.tb_riscv_core__DOT__error_count 
                = ((::IData)(1U) + vlSelfRef.tb_riscv_core__DOT__error_count);
        } else {
            VL_WRITEF_NX("PASS [%s]: Mem[0x%h] = 0x%h\n",3
                         , 'S',&(vlSelfRef.__Vnontrivs.__Vtask_tb_riscv_core__DOT__check_mem__test_desc_92)
                         , '#',32,__Vtask_tb_riscv_core__DOT__check_mem__mem_addr_90
                         , '#',32,vlSelfRef.tb_riscv_core__DOT__uut__DOT__dmem__DOT__mem
                         [(0x000000ffU & (__Vtask_tb_riscv_core__DOT__check_mem__mem_addr_90 
                                          >> 2U))]);
        }
        vlSelfRef.__Vnontrivs.__Vtask_tb_riscv_core__DOT__check_reg__test_desc_95 = "LW reads back the merged word"s;
        __Vtask_tb_riscv_core__DOT__check_reg__expected_val_94 = 0x0234ff00U;
        __Vtask_tb_riscv_core__DOT__check_reg__reg_addr_93 = 0x0bU;
        vlSelfRef.tb_riscv_core__DOT__test_count = 
            ((::IData)(1U) + vlSelfRef.tb_riscv_core__DOT__test_count);
        if ((vlSelfRef.tb_riscv_core__DOT__uut__DOT__u_regfile__DOT__rf
             [__Vtask_tb_riscv_core__DOT__check_reg__reg_addr_93] 
             != __Vtask_tb_riscv_core__DOT__check_reg__expected_val_94)) {
            VL_WRITEF_NX("FAIL [%s]: x%0d = 0x%h (%0d), Expected = 0x%h (%0d)\n",6
                         , 'S',&(vlSelfRef.__Vnontrivs.__Vtask_tb_riscv_core__DOT__check_reg__test_desc_95)
                         , '#',5,(::IData)(__Vtask_tb_riscv_core__DOT__check_reg__reg_addr_93)
                         , '#',32,vlSelfRef.tb_riscv_core__DOT__uut__DOT__u_regfile__DOT__rf
                         [__Vtask_tb_riscv_core__DOT__check_reg__reg_addr_93]
                         , '#',32,vlSelfRef.tb_riscv_core__DOT__uut__DOT__u_regfile__DOT__rf
                         [__Vtask_tb_riscv_core__DOT__check_reg__reg_addr_93]
                         , '#',32,__Vtask_tb_riscv_core__DOT__check_reg__expected_val_94
                         , '#',32,__Vtask_tb_riscv_core__DOT__check_reg__expected_val_94);
            vlSelfRef.tb_riscv_core__DOT__error_count 
                = ((::IData)(1U) + vlSelfRef.tb_riscv_core__DOT__error_count);
        } else {
            VL_WRITEF_NX("PASS [%s]: x%0d = 0x%h (%0d)\n",4
                         , 'S',&(vlSelfRef.__Vnontrivs.__Vtask_tb_riscv_core__DOT__check_reg__test_desc_95)
                         , '#',5,(::IData)(__Vtask_tb_riscv_core__DOT__check_reg__reg_addr_93)
                         , '#',32,vlSelfRef.tb_riscv_core__DOT__uut__DOT__u_regfile__DOT__rf
                         [__Vtask_tb_riscv_core__DOT__check_reg__reg_addr_93]
                         , '#',32,vlSelfRef.tb_riscv_core__DOT__uut__DOT__u_regfile__DOT__rf
                         [__Vtask_tb_riscv_core__DOT__check_reg__reg_addr_93]);
        }
    }
    vlSelfRef.__Vnontrivs.__Vtask_tb_riscv_core__DOT__check_reg__test_desc_98 = "End marker reached"s;
    __Vtask_tb_riscv_core__DOT__check_reg__expected_val_97 = 7U;
    __Vtask_tb_riscv_core__DOT__check_reg__reg_addr_96 = 6U;
    vlSelfRef.tb_riscv_core__DOT__test_count = ((::IData)(1U) 
                                                + vlSelfRef.tb_riscv_core__DOT__test_count);
    if ((vlSelfRef.tb_riscv_core__DOT__uut__DOT__u_regfile__DOT__rf
         [__Vtask_tb_riscv_core__DOT__check_reg__reg_addr_96] 
         != __Vtask_tb_riscv_core__DOT__check_reg__expected_val_97)) {
        VL_WRITEF_NX("FAIL [%s]: x%0d = 0x%h (%0d), Expected = 0x%h (%0d)\n",6
                     , 'S',&(vlSelfRef.__Vnontrivs.__Vtask_tb_riscv_core__DOT__check_reg__test_desc_98)
                     , '#',5,(::IData)(__Vtask_tb_riscv_core__DOT__check_reg__reg_addr_96)
                     , '#',32,vlSelfRef.tb_riscv_core__DOT__uut__DOT__u_regfile__DOT__rf
                     [__Vtask_tb_riscv_core__DOT__check_reg__reg_addr_96]
                     , '#',32,vlSelfRef.tb_riscv_core__DOT__uut__DOT__u_regfile__DOT__rf
                     [__Vtask_tb_riscv_core__DOT__check_reg__reg_addr_96]
                     , '#',32,__Vtask_tb_riscv_core__DOT__check_reg__expected_val_97
                     , '#',32,__Vtask_tb_riscv_core__DOT__check_reg__expected_val_97);
        vlSelfRef.tb_riscv_core__DOT__error_count = 
            ((::IData)(1U) + vlSelfRef.tb_riscv_core__DOT__error_count);
    } else {
        VL_WRITEF_NX("PASS [%s]: x%0d = 0x%h (%0d)\n",4
                     , 'S',&(vlSelfRef.__Vnontrivs.__Vtask_tb_riscv_core__DOT__check_reg__test_desc_98)
                     , '#',5,(::IData)(__Vtask_tb_riscv_core__DOT__check_reg__reg_addr_96)
                     , '#',32,vlSelfRef.tb_riscv_core__DOT__uut__DOT__u_regfile__DOT__rf
                     [__Vtask_tb_riscv_core__DOT__check_reg__reg_addr_96]
                     , '#',32,vlSelfRef.tb_riscv_core__DOT__uut__DOT__u_regfile__DOT__rf
                     [__Vtask_tb_riscv_core__DOT__check_reg__reg_addr_96]);
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
    VL_FINISH_MT("tb_riscv_core.sv", 153, "");
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
    ::CData/*0:0*/ __Vdfg_Regularize_331;
    __Vdfg_Regularize_331 = 0;
    ::CData/*0:0*/ __Vdfg_Regularize_332;
    __Vdfg_Regularize_332 = 0;
    ::IData/*31:0*/ __Vdfg_Regularize_334;
    __Vdfg_Regularize_334 = 0;
    ::CData/*0:0*/ __Vdfg_Regularize_335;
    __Vdfg_Regularize_335 = 0;
    ::CData/*0:0*/ __Vdfg_Regularize_336;
    __Vdfg_Regularize_336 = 0;
    ::CData/*0:0*/ __Vdfg_Regularize_337;
    __Vdfg_Regularize_337 = 0;
    ::IData/*31:0*/ __Vdfg_Regularize_339;
    __Vdfg_Regularize_339 = 0;
    // Body
    vlSelfRef.tb_riscv_core__DOT__uut__DOT__ex_mem__DOT__zero_out 
        = ((1U & (~ (::IData)(vlSelfRef.tb_riscv_core__DOT__rst))) 
           && (0U == vlSelfRef.tb_riscv_core__DOT__uut__DOT__ex_alu_out));
    vlSelfRef.tb_riscv_core__DOT__uut__DOT__id_ex__DOT__jalr_out 
        = ((1U & (~ ((::IData)(vlSelfRef.tb_riscv_core__DOT__rst) 
                     | (::IData)(vlSelfRef.tb_riscv_core__DOT__uut__DOT__id_ex_flush)))) 
           && (1U & (::IData)(vlSelfRef.__Vdfg_Regularize_330)));
    vlSelfRef.tb_riscv_core__DOT__uut__DOT__id_ex__DOT__alu_src_out 
        = ((1U & (~ ((::IData)(vlSelfRef.tb_riscv_core__DOT__rst) 
                     | (::IData)(vlSelfRef.tb_riscv_core__DOT__uut__DOT__id_ex_flush)))) 
           && (1U & ((::IData)(vlSelfRef.__Vdfg_Regularize_330) 
                     >> 6U)));
    if (((::IData)(vlSelfRef.tb_riscv_core__DOT__rst) 
         | (::IData)(vlSelfRef.tb_riscv_core__DOT__uut__DOT__id_ex_flush))) {
        vlSelfRef.tb_riscv_core__DOT__uut__DOT__id_ex__DOT__alu_a_sel_out = 0U;
        vlSelfRef.tb_riscv_core__DOT__uut__DOT__id_ex__DOT__imm_out = 0U;
        vlSelfRef.tb_riscv_core__DOT__uut__DOT__id_ex__DOT__alu_op_out = 0U;
        vlSelfRef.tb_riscv_core__DOT__uut__DOT__id_ex__DOT__rs1_addr_out = 0U;
        vlSelfRef.tb_riscv_core__DOT__uut__DOT__id_ex__DOT__rs2_addr_out = 0U;
        vlSelfRef.tb_riscv_core__DOT__uut__DOT__id_ex__DOT__rs1_data_out = 0U;
        vlSelfRef.tb_riscv_core__DOT__uut__DOT__id_ex__DOT__rs2_data_out = 0U;
    } else {
        vlSelfRef.tb_riscv_core__DOT__uut__DOT__id_ex__DOT__alu_a_sel_out 
            = (3U & ((::IData)(vlSelfRef.__Vdfg_Regularize_330) 
                     >> 8U));
        vlSelfRef.tb_riscv_core__DOT__uut__DOT__id_ex__DOT__imm_out 
            = vlSelfRef.tb_riscv_core__DOT__uut__DOT__id_imm;
        vlSelfRef.tb_riscv_core__DOT__uut__DOT__id_ex__DOT__alu_op_out 
            = (3U & ((::IData)(vlSelfRef.__Vdfg_Regularize_330) 
                     >> 0x0000000aU));
        vlSelfRef.tb_riscv_core__DOT__uut__DOT__id_ex__DOT__rs1_addr_out 
            = (0x0000001fU & (vlSelfRef.tb_riscv_core__DOT__uut__DOT__if_id__DOT__instr_out 
                              >> 0x0000000fU));
        vlSelfRef.tb_riscv_core__DOT__uut__DOT__id_ex__DOT__rs2_addr_out 
            = (0x0000001fU & (vlSelfRef.tb_riscv_core__DOT__uut__DOT__if_id__DOT__instr_out 
                              >> 0x00000014U));
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
        vlSelfRef.tb_riscv_core__DOT__uut__DOT__ex_mem__DOT__rs2_data_out = 0U;
        vlSelfRef.tb_riscv_core__DOT__uut__DOT__mem_wb__DOT__alu_out_out = 0U;
        vlSelfRef.tb_riscv_core__DOT__uut__DOT__mem_wb__DOT__read_data_out = 0U;
        vlSelfRef.tb_riscv_core__DOT__uut__DOT__ex_mem__DOT__funct3_out = 0U;
    } else {
        vlSelfRef.tb_riscv_core__DOT__uut__DOT__ex_mem__DOT__branch_target_out 
            = vlSelfRef.tb_riscv_core__DOT__uut__DOT__ex_branch_target;
        vlSelfRef.tb_riscv_core__DOT__uut__DOT__ex_mem__DOT__rs2_data_out 
            = vlSelfRef.tb_riscv_core__DOT__uut__DOT__forward_b_data;
        vlSelfRef.tb_riscv_core__DOT__uut__DOT__mem_wb__DOT__alu_out_out 
            = vlSelfRef.tb_riscv_core__DOT__uut__DOT__ex_mem__DOT__alu_out_out;
        vlSelfRef.tb_riscv_core__DOT__uut__DOT__mem_wb__DOT__read_data_out 
            = (((4U & (::IData)(vlSelfRef.tb_riscv_core__DOT__uut__DOT__ex_mem__DOT__funct3_out))
                 ? ((2U & (::IData)(vlSelfRef.tb_riscv_core__DOT__uut__DOT__ex_mem__DOT__funct3_out))
                     ? vlSelfRef.tb_riscv_core__DOT__uut__DOT__dmem__DOT__mem
                    [(0x000000ffU & (vlSelfRef.tb_riscv_core__DOT__uut__DOT__ex_mem__DOT__alu_out_out 
                                     >> 2U))] : ((1U 
                                                  & (::IData)(vlSelfRef.tb_riscv_core__DOT__uut__DOT__ex_mem__DOT__funct3_out))
                                                  ? (::IData)(vlSelfRef.tb_riscv_core__DOT__uut__DOT__dmem__DOT__half_sel)
                                                  : (::IData)(vlSelfRef.tb_riscv_core__DOT__uut__DOT__dmem__DOT__byte_sel)))
                 : ((2U & (::IData)(vlSelfRef.tb_riscv_core__DOT__uut__DOT__ex_mem__DOT__funct3_out))
                     ? vlSelfRef.tb_riscv_core__DOT__uut__DOT__dmem__DOT__mem
                    [(0x000000ffU & (vlSelfRef.tb_riscv_core__DOT__uut__DOT__ex_mem__DOT__alu_out_out 
                                     >> 2U))] : ((1U 
                                                  & (::IData)(vlSelfRef.tb_riscv_core__DOT__uut__DOT__ex_mem__DOT__funct3_out))
                                                  ? 
                                                 (((- (::IData)(
                                                                (1U 
                                                                 & ((::IData)(vlSelfRef.tb_riscv_core__DOT__uut__DOT__dmem__DOT__half_sel) 
                                                                    >> 0x0000000fU)))) 
                                                   << 0x00000010U) 
                                                  | (::IData)(vlSelfRef.tb_riscv_core__DOT__uut__DOT__dmem__DOT__half_sel))
                                                  : 
                                                 (((- (::IData)(
                                                                (1U 
                                                                 & ((::IData)(vlSelfRef.tb_riscv_core__DOT__uut__DOT__dmem__DOT__byte_sel) 
                                                                    >> 7U)))) 
                                                   << 8U) 
                                                  | (::IData)(vlSelfRef.tb_riscv_core__DOT__uut__DOT__dmem__DOT__byte_sel))))) 
               & (- (::IData)((::IData)(vlSelfRef.tb_riscv_core__DOT__uut__DOT__ex_mem__DOT__mem_read_out))));
        vlSelfRef.tb_riscv_core__DOT__uut__DOT__ex_mem__DOT__funct3_out 
            = vlSelfRef.tb_riscv_core__DOT__uut__DOT__id_ex__DOT__funct3_out;
    }
    vlSelfRef.tb_riscv_core__DOT__uut__DOT__id_ex__DOT__funct3_out 
        = (((::IData)(vlSelfRef.tb_riscv_core__DOT__rst) 
            | (::IData)(vlSelfRef.tb_riscv_core__DOT__uut__DOT__id_ex_flush))
            ? 0U : (7U & (vlSelfRef.tb_riscv_core__DOT__uut__DOT__if_id__DOT__instr_out 
                          >> 0x0000000cU)));
    vlSelfRef.tb_riscv_core__DOT__uut__DOT__ex_mem__DOT__alu_out_out 
        = ((::IData)(vlSelfRef.tb_riscv_core__DOT__rst)
            ? 0U : ((::IData)(vlSelfRef.tb_riscv_core__DOT__uut__DOT__id_ex__DOT__jump_out)
                     ? ((::IData)(4U) + vlSelfRef.tb_riscv_core__DOT__uut__DOT__id_ex__DOT__pc_out)
                     : vlSelfRef.tb_riscv_core__DOT__uut__DOT__ex_alu_out));
    vlSelfRef.tb_riscv_core__DOT__uut__DOT__id_ex__DOT__pc_out 
        = (((::IData)(vlSelfRef.tb_riscv_core__DOT__rst) 
            | (::IData)(vlSelfRef.tb_riscv_core__DOT__uut__DOT__id_ex_flush))
            ? 0U : vlSelfRef.tb_riscv_core__DOT__uut__DOT__if_id__DOT__pc_out);
    if (vlSelfRef.tb_riscv_core__DOT__rst) {
        vlSelfRef.tb_riscv_core__DOT__uut__DOT__mem_wb__DOT__rd_addr_out = 0U;
        vlSelfRef.tb_riscv_core__DOT__uut__DOT__ex_mem__DOT__rd_addr_out = 0U;
    } else {
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
           && (1U & ((::IData)(vlSelfRef.__Vdfg_Regularize_330) 
                     >> 2U)));
    vlSelfRef.tb_riscv_core__DOT__uut__DOT__ex_mem__DOT__mem_to_reg_out 
        = ((1U & (~ (::IData)(vlSelfRef.tb_riscv_core__DOT__rst))) 
           && (::IData)(vlSelfRef.tb_riscv_core__DOT__uut__DOT__id_ex__DOT__mem_to_reg_out));
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
           && (1U & ((::IData)(vlSelfRef.__Vdfg_Regularize_330) 
                     >> 3U)));
    vlSelfRef.tb_riscv_core__DOT__uut__DOT__id_ex__DOT__mem_to_reg_out 
        = ((1U & (~ ((::IData)(vlSelfRef.tb_riscv_core__DOT__rst) 
                     | (::IData)(vlSelfRef.tb_riscv_core__DOT__uut__DOT__id_ex_flush)))) 
           && (1U & ((::IData)(vlSelfRef.__Vdfg_Regularize_330) 
                     >> 5U)));
    vlSelfRef.tb_riscv_core__DOT__uut__DOT__id_ex__DOT__mem_read_out 
        = ((1U & (~ ((::IData)(vlSelfRef.tb_riscv_core__DOT__rst) 
                     | (::IData)(vlSelfRef.tb_riscv_core__DOT__uut__DOT__id_ex_flush)))) 
           && (1U & ((::IData)(vlSelfRef.__Vdfg_Regularize_330) 
                     >> 4U)));
    if ((0U == (3U & (::IData)(vlSelfRef.tb_riscv_core__DOT__uut__DOT__ex_mem__DOT__funct3_out)))) {
        vlSelfRef.tb_riscv_core__DOT__uut__DOT__dmem__DOT__wdata 
            = ((vlSelfRef.tb_riscv_core__DOT__uut__DOT__ex_mem__DOT__rs2_data_out 
                << 0x00000018U) | ((0x00ff0000U & (vlSelfRef.tb_riscv_core__DOT__uut__DOT__ex_mem__DOT__rs2_data_out 
                                                   << 0x00000010U)) 
                                   | ((0x0000ff00U 
                                       & (vlSelfRef.tb_riscv_core__DOT__uut__DOT__ex_mem__DOT__rs2_data_out 
                                          << 8U)) | 
                                      (0x000000ffU 
                                       & vlSelfRef.tb_riscv_core__DOT__uut__DOT__ex_mem__DOT__rs2_data_out))));
        vlSelfRef.tb_riscv_core__DOT__uut__DOT__dmem__DOT__be 
            = (0x0000000fU & ((::IData)(1U) << (3U 
                                                & vlSelfRef.tb_riscv_core__DOT__uut__DOT__ex_mem__DOT__alu_out_out)));
    } else {
        vlSelfRef.tb_riscv_core__DOT__uut__DOT__dmem__DOT__wdata 
            = ((1U == (3U & (::IData)(vlSelfRef.tb_riscv_core__DOT__uut__DOT__ex_mem__DOT__funct3_out)))
                ? ((vlSelfRef.tb_riscv_core__DOT__uut__DOT__ex_mem__DOT__rs2_data_out 
                    << 0x00000010U) | (0x0000ffffU 
                                       & vlSelfRef.tb_riscv_core__DOT__uut__DOT__ex_mem__DOT__rs2_data_out))
                : vlSelfRef.tb_riscv_core__DOT__uut__DOT__ex_mem__DOT__rs2_data_out);
        vlSelfRef.tb_riscv_core__DOT__uut__DOT__dmem__DOT__be 
            = (0x0000000fU & (((::IData)(3U) << (3U 
                                                 & vlSelfRef.tb_riscv_core__DOT__uut__DOT__ex_mem__DOT__alu_out_out)) 
                              | (- (::IData)((1U != 
                                              (3U & (::IData)(vlSelfRef.tb_riscv_core__DOT__uut__DOT__ex_mem__DOT__funct3_out)))))));
    }
    vlSelfRef.tb_riscv_core__DOT__uut__DOT__id_ex__DOT__jump_out 
        = ((1U & (~ ((::IData)(vlSelfRef.tb_riscv_core__DOT__rst) 
                     | (::IData)(vlSelfRef.tb_riscv_core__DOT__uut__DOT__id_ex_flush)))) 
           && (1U & ((::IData)(vlSelfRef.__Vdfg_Regularize_330) 
                     >> 1U)));
    vlSelfRef.tb_riscv_core__DOT__uut__DOT__ex_mem__DOT__reg_write_out 
        = ((1U & (~ (::IData)(vlSelfRef.tb_riscv_core__DOT__rst))) 
           && (::IData)(vlSelfRef.tb_riscv_core__DOT__uut__DOT__id_ex__DOT__reg_write_out));
    __Vdfg_Regularize_336 = ((::IData)(vlSelfRef.tb_riscv_core__DOT__uut__DOT__mem_wb__DOT__reg_write_out) 
                             & (0U != (::IData)(vlSelfRef.tb_riscv_core__DOT__uut__DOT__mem_wb__DOT__rd_addr_out)));
    vlSelfRef.tb_riscv_core__DOT__uut__DOT__id_ex__DOT__valid_out 
        = ((1U & (~ ((::IData)(vlSelfRef.tb_riscv_core__DOT__rst) 
                     | (::IData)(vlSelfRef.tb_riscv_core__DOT__uut__DOT__id_ex_flush)))) 
           && (::IData)(vlSelfRef.tb_riscv_core__DOT__uut__DOT__if_id__DOT__valid_out));
    __Vdfg_Regularize_331 = (1U & Vtb_riscv_core__ConstPool__CONSARRAY_1
                             [((((::IData)(vlSelfRef.tb_riscv_core__DOT__uut__DOT__id_ex__DOT__op_bit5_out) 
                                 << 6U) | ((::IData)(vlSelfRef.tb_riscv_core__DOT__uut__DOT__id_ex__DOT__funct7_5_out) 
                                           << 5U)) 
                               | (((::IData)(vlSelfRef.tb_riscv_core__DOT__uut__DOT__id_ex__DOT__funct3_out) 
                                   << 2U) | (::IData)(vlSelfRef.tb_riscv_core__DOT__uut__DOT__id_ex__DOT__alu_op_out)))]);
    __Vdfg_Regularize_332 = (1U & (Vtb_riscv_core__ConstPool__CONSARRAY_1
                                   [((((::IData)(vlSelfRef.tb_riscv_core__DOT__uut__DOT__id_ex__DOT__op_bit5_out) 
                                       << 6U) | ((::IData)(vlSelfRef.tb_riscv_core__DOT__uut__DOT__id_ex__DOT__funct7_5_out) 
                                                 << 5U)) 
                                     | (((::IData)(vlSelfRef.tb_riscv_core__DOT__uut__DOT__id_ex__DOT__funct3_out) 
                                         << 2U) | (::IData)(vlSelfRef.tb_riscv_core__DOT__uut__DOT__id_ex__DOT__alu_op_out)))] 
                                   >> 1U));
    __Vdfg_Regularize_337 = (1U & (Vtb_riscv_core__ConstPool__CONSARRAY_1
                                   [((((::IData)(vlSelfRef.tb_riscv_core__DOT__uut__DOT__id_ex__DOT__op_bit5_out) 
                                       << 6U) | ((::IData)(vlSelfRef.tb_riscv_core__DOT__uut__DOT__id_ex__DOT__funct7_5_out) 
                                                 << 5U)) 
                                     | (((::IData)(vlSelfRef.tb_riscv_core__DOT__uut__DOT__id_ex__DOT__funct3_out) 
                                         << 2U) | (::IData)(vlSelfRef.tb_riscv_core__DOT__uut__DOT__id_ex__DOT__alu_op_out)))] 
                                   >> 2U));
    vlSelfRef.tb_riscv_core__DOT__uut__DOT__ex_branch_target 
        = (vlSelfRef.tb_riscv_core__DOT__uut__DOT__id_ex__DOT__pc_out 
           + vlSelfRef.tb_riscv_core__DOT__uut__DOT__id_ex__DOT__imm_out);
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
           && (1U & ((::IData)(vlSelfRef.__Vdfg_Regularize_330) 
                     >> 7U)));
    __Vdfg_Regularize_335 = ((::IData)(vlSelfRef.tb_riscv_core__DOT__uut__DOT__ex_mem__DOT__reg_write_out) 
                             & (0U != (::IData)(vlSelfRef.tb_riscv_core__DOT__uut__DOT__ex_mem__DOT__rd_addr_out)));
    vlSelfRef.tb_riscv_core__DOT__uut__DOT__forward_a 
        = ((((::IData)(vlSelfRef.tb_riscv_core__DOT__uut__DOT__id_ex__DOT__rs1_addr_out) 
             == (::IData)(vlSelfRef.tb_riscv_core__DOT__uut__DOT__ex_mem__DOT__rd_addr_out)) 
            & (::IData)(__Vdfg_Regularize_335)) ? 2U
            : (1U & (- (::IData)((((::IData)(vlSelfRef.tb_riscv_core__DOT__uut__DOT__mem_wb__DOT__rd_addr_out) 
                                   == (::IData)(vlSelfRef.tb_riscv_core__DOT__uut__DOT__id_ex__DOT__rs1_addr_out)) 
                                  & (::IData)(__Vdfg_Regularize_336))))));
    vlSelfRef.tb_riscv_core__DOT__uut__DOT__forward_b 
        = ((((::IData)(vlSelfRef.tb_riscv_core__DOT__uut__DOT__id_ex__DOT__rs2_addr_out) 
             == (::IData)(vlSelfRef.tb_riscv_core__DOT__uut__DOT__ex_mem__DOT__rd_addr_out)) 
            & (::IData)(__Vdfg_Regularize_335)) ? 2U
            : (1U & (- (::IData)((((::IData)(vlSelfRef.tb_riscv_core__DOT__uut__DOT__mem_wb__DOT__rd_addr_out) 
                                   == (::IData)(vlSelfRef.tb_riscv_core__DOT__uut__DOT__id_ex__DOT__rs2_addr_out)) 
                                  & (::IData)(__Vdfg_Regularize_336))))));
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
    vlSelfRef.tb_riscv_core__DOT__uut__DOT__alu_a = 
        ((1U == (::IData)(vlSelfRef.tb_riscv_core__DOT__uut__DOT__id_ex__DOT__alu_a_sel_out))
          ? vlSelfRef.tb_riscv_core__DOT__uut__DOT__id_ex__DOT__pc_out
          : (vlSelfRef.tb_riscv_core__DOT__uut__DOT__alu_in1 
             & (- (::IData)((2U != (::IData)(vlSelfRef.tb_riscv_core__DOT__uut__DOT__id_ex__DOT__alu_a_sel_out))))));
    vlSelfRef.tb_riscv_core__DOT__uut__DOT__alu_in2 
        = ((::IData)(vlSelfRef.tb_riscv_core__DOT__uut__DOT__id_ex__DOT__alu_src_out)
            ? vlSelfRef.tb_riscv_core__DOT__uut__DOT__id_ex__DOT__imm_out
            : vlSelfRef.tb_riscv_core__DOT__uut__DOT__forward_b_data);
    vlSelfRef.tb_riscv_core__DOT__uut__DOT__if_id_flush 
        = ((::IData)(vlSelfRef.tb_riscv_core__DOT__uut__DOT__id_ex__DOT__jump_out) 
           | ((::IData)(vlSelfRef.tb_riscv_core__DOT__uut__DOT__id_ex__DOT__branch_out) 
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
                                        == vlSelfRef.tb_riscv_core__DOT__uut__DOT__forward_b_data))))));
    vlSelfRef.tb_riscv_core__DOT__uut__DOT__ex_alu_out 
        = ((8U & Vtb_riscv_core__ConstPool__CONSARRAY_1
            [((((::IData)(vlSelfRef.tb_riscv_core__DOT__uut__DOT__id_ex__DOT__op_bit5_out) 
                << 6U) | ((::IData)(vlSelfRef.tb_riscv_core__DOT__uut__DOT__id_ex__DOT__funct7_5_out) 
                          << 5U)) | (((::IData)(vlSelfRef.tb_riscv_core__DOT__uut__DOT__id_ex__DOT__funct3_out) 
                                      << 2U) | (::IData)(vlSelfRef.tb_riscv_core__DOT__uut__DOT__id_ex__DOT__alu_op_out)))])
            ? ((- (::IData)((1U & (~ (::IData)(__Vdfg_Regularize_332))))) 
               & (((::IData)(__Vdfg_Regularize_331)
                    ? (1U & (- (::IData)((vlSelfRef.tb_riscv_core__DOT__uut__DOT__alu_a 
                                          < vlSelfRef.tb_riscv_core__DOT__uut__DOT__alu_in2))))
                    : (1U & (- (::IData)(VL_LTS_III(32, vlSelfRef.tb_riscv_core__DOT__uut__DOT__alu_a, vlSelfRef.tb_riscv_core__DOT__uut__DOT__alu_in2))))) 
                  & (- (::IData)((1U & (~ (::IData)(__Vdfg_Regularize_337)))))))
            : ((::IData)(__Vdfg_Regularize_337) ? ((::IData)(__Vdfg_Regularize_332)
                                                    ? 
                                                   ((::IData)(__Vdfg_Regularize_331)
                                                     ? 
                                                    VL_SHIFTRS_III(32,32,5, vlSelfRef.tb_riscv_core__DOT__uut__DOT__alu_a, 
                                                                   (0x0000001fU 
                                                                    & vlSelfRef.tb_riscv_core__DOT__uut__DOT__alu_in2))
                                                     : 
                                                    (vlSelfRef.tb_riscv_core__DOT__uut__DOT__alu_a 
                                                     >> 
                                                     (0x0000001fU 
                                                      & vlSelfRef.tb_riscv_core__DOT__uut__DOT__alu_in2)))
                                                    : 
                                                   ((::IData)(__Vdfg_Regularize_331)
                                                     ? 
                                                    (vlSelfRef.tb_riscv_core__DOT__uut__DOT__alu_a 
                                                     << 
                                                     (0x0000001fU 
                                                      & vlSelfRef.tb_riscv_core__DOT__uut__DOT__alu_in2))
                                                     : 
                                                    (vlSelfRef.tb_riscv_core__DOT__uut__DOT__alu_a 
                                                     ^ vlSelfRef.tb_riscv_core__DOT__uut__DOT__alu_in2)))
                : ((::IData)(__Vdfg_Regularize_332)
                    ? ((::IData)(__Vdfg_Regularize_331)
                        ? (vlSelfRef.tb_riscv_core__DOT__uut__DOT__alu_a 
                           | vlSelfRef.tb_riscv_core__DOT__uut__DOT__alu_in2)
                        : (vlSelfRef.tb_riscv_core__DOT__uut__DOT__alu_a 
                           & vlSelfRef.tb_riscv_core__DOT__uut__DOT__alu_in2))
                    : ((::IData)(__Vdfg_Regularize_331)
                        ? (vlSelfRef.tb_riscv_core__DOT__uut__DOT__alu_a 
                           - vlSelfRef.tb_riscv_core__DOT__uut__DOT__alu_in2)
                        : (vlSelfRef.tb_riscv_core__DOT__uut__DOT__alu_a 
                           + vlSelfRef.tb_riscv_core__DOT__uut__DOT__alu_in2)))));
    vlSelfRef.__Vdfg_Regularize_330 = (0x00000fffU 
                                       & Vtb_riscv_core__ConstPool__CONST_0
                                       [(0x0000007fU 
                                         & vlSelfRef.tb_riscv_core__DOT__uut__DOT__if_id__DOT__instr_out)]);
    __Vdfg_Regularize_334 = ((((- (::IData)((vlSelfRef.tb_riscv_core__DOT__uut__DOT__if_id__DOT__instr_out 
                                             >> 0x0000001fU))) 
                               << 0x0000000cU) | (vlSelfRef.tb_riscv_core__DOT__uut__DOT__if_id__DOT__instr_out 
                                                  >> 0x00000014U)) 
                             & (- (::IData)((3U == 
                                             (3U & vlSelfRef.tb_riscv_core__DOT__uut__DOT__if_id__DOT__instr_out)))));
    __Vdfg_Regularize_339 = (0xfffff000U & (vlSelfRef.tb_riscv_core__DOT__uut__DOT__if_id__DOT__instr_out 
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
                      ? __Vdfg_Regularize_334 : (((
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
                    & __Vdfg_Regularize_339) : ((((- (::IData)(
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
                      ? __Vdfg_Regularize_339 : __Vdfg_Regularize_334) 
                    & (- (::IData)((1U & (~ (vlSelfRef.tb_riscv_core__DOT__uut__DOT__if_id__DOT__instr_out 
                                             >> 3U))))))
                 : (__Vdfg_Regularize_334 & ((- (::IData)(
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
            ? ((::IData)(vlSelfRef.tb_riscv_core__DOT__uut__DOT__id_ex__DOT__jalr_out)
                ? (0xfffffffeU & vlSelfRef.tb_riscv_core__DOT__uut__DOT__ex_alu_out)
                : vlSelfRef.tb_riscv_core__DOT__uut__DOT__ex_branch_target)
            : ((::IData)(4U) + vlSelfRef.tb_riscv_core__DOT__uut__DOT__pc));
    vlSelfRef.tb_riscv_core__DOT__uut__DOT__id_ex_flush 
        = ((::IData)(vlSelfRef.tb_riscv_core__DOT__uut__DOT__pc_stall) 
           | (::IData)(vlSelfRef.tb_riscv_core__DOT__uut__DOT__if_id_flush));
}

void Vtb_riscv_core___024root___eval_body__nba(Vtb_riscv_core___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_riscv_core___024root___eval_body__nba\n"); );
    Vtb_riscv_core__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    if ((((1ULL & vlSelfRef.__VnbaTriggered[0U])) != 0ULL)) {
        {
            // Inlined CFunc: _nba_sequent__TOP__0
            vlSelfRef.__Vdly_Set__tb_riscv_core__DOT__uut__DOT__dmem__DOT__mem_45 = 0U;
            vlSelfRef.__Vdly_Set__tb_riscv_core__DOT__uut__DOT__dmem__DOT__mem_48 = 0U;
            vlSelfRef.__Vdly_Set__tb_riscv_core__DOT__uut__DOT__dmem__DOT__mem_51 = 0U;
            vlSelfRef.__Vdly_Set__tb_riscv_core__DOT__uut__DOT__dmem__DOT__mem_54 = 0U;
            vlSelfRef.__Vdly_Set__tb_riscv_core__DOT__uut__DOT__u_regfile__DOT__rf_57 = 0U;
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
                if ((1U & (::IData)(vlSelfRef.tb_riscv_core__DOT__uut__DOT__dmem__DOT__be))) {
                    vlSelfRef.__Vdly_Val__tb_riscv_core__DOT__uut__DOT__dmem__DOT__mem_43 
                        = (0x000000ffU & vlSelfRef.tb_riscv_core__DOT__uut__DOT__dmem__DOT__wdata);
                    vlSelfRef.__Vdly_Dim0__tb_riscv_core__DOT__uut__DOT__dmem__DOT__mem_44 
                        = (0x000000ffU & (vlSelfRef.tb_riscv_core__DOT__uut__DOT__ex_mem__DOT__alu_out_out 
                                          >> 2U));
                    vlSelfRef.__Vdly_Set__tb_riscv_core__DOT__uut__DOT__dmem__DOT__mem_45 = 1U;
                }
                if ((2U & (::IData)(vlSelfRef.tb_riscv_core__DOT__uut__DOT__dmem__DOT__be))) {
                    vlSelfRef.__Vdly_Val__tb_riscv_core__DOT__uut__DOT__dmem__DOT__mem_46 
                        = (0x000000ffU & (vlSelfRef.tb_riscv_core__DOT__uut__DOT__dmem__DOT__wdata 
                                          >> 8U));
                    vlSelfRef.__Vdly_Dim0__tb_riscv_core__DOT__uut__DOT__dmem__DOT__mem_47 
                        = (0x000000ffU & (vlSelfRef.tb_riscv_core__DOT__uut__DOT__ex_mem__DOT__alu_out_out 
                                          >> 2U));
                    vlSelfRef.__Vdly_Set__tb_riscv_core__DOT__uut__DOT__dmem__DOT__mem_48 = 1U;
                }
                if ((4U & (::IData)(vlSelfRef.tb_riscv_core__DOT__uut__DOT__dmem__DOT__be))) {
                    vlSelfRef.__Vdly_Val__tb_riscv_core__DOT__uut__DOT__dmem__DOT__mem_49 
                        = (0x000000ffU & (vlSelfRef.tb_riscv_core__DOT__uut__DOT__dmem__DOT__wdata 
                                          >> 0x10U));
                    vlSelfRef.__Vdly_Dim0__tb_riscv_core__DOT__uut__DOT__dmem__DOT__mem_50 
                        = (0x000000ffU & (vlSelfRef.tb_riscv_core__DOT__uut__DOT__ex_mem__DOT__alu_out_out 
                                          >> 2U));
                    vlSelfRef.__Vdly_Set__tb_riscv_core__DOT__uut__DOT__dmem__DOT__mem_51 = 1U;
                }
                if ((8U & (::IData)(vlSelfRef.tb_riscv_core__DOT__uut__DOT__dmem__DOT__be))) {
                    vlSelfRef.__Vdly_Val__tb_riscv_core__DOT__uut__DOT__dmem__DOT__mem_52 
                        = (vlSelfRef.tb_riscv_core__DOT__uut__DOT__dmem__DOT__wdata 
                           >> 0x18U);
                    vlSelfRef.__Vdly_Dim0__tb_riscv_core__DOT__uut__DOT__dmem__DOT__mem_53 
                        = (0x000000ffU & (vlSelfRef.tb_riscv_core__DOT__uut__DOT__ex_mem__DOT__alu_out_out 
                                          >> 2U));
                    vlSelfRef.__Vdly_Set__tb_riscv_core__DOT__uut__DOT__dmem__DOT__mem_54 = 1U;
                }
            }
            if (((::IData)(vlSelfRef.tb_riscv_core__DOT__uut__DOT__mem_wb__DOT__reg_write_out) 
                 & (0U != (::IData)(vlSelfRef.tb_riscv_core__DOT__uut__DOT__mem_wb__DOT__rd_addr_out)))) {
                vlSelfRef.__Vdly_Val__tb_riscv_core__DOT__uut__DOT__u_regfile__DOT__rf_55 
                    = vlSelfRef.tb_riscv_core__DOT__wb_result;
                vlSelfRef.__Vdly_Dim0__tb_riscv_core__DOT__uut__DOT__u_regfile__DOT__rf_56 
                    = vlSelfRef.tb_riscv_core__DOT__uut__DOT__mem_wb__DOT__rd_addr_out;
                vlSelfRef.__Vdly_Set__tb_riscv_core__DOT__uut__DOT__u_regfile__DOT__rf_57 = 1U;
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
            if (vlSelfRef.__Vdly_Set__tb_riscv_core__DOT__uut__DOT__dmem__DOT__mem_45) {
                vlSelfRef.tb_riscv_core__DOT__uut__DOT__dmem__DOT__mem[vlSelfRef.__Vdly_Dim0__tb_riscv_core__DOT__uut__DOT__dmem__DOT__mem_44] 
                    = ((0xffffff00U & vlSelfRef.tb_riscv_core__DOT__uut__DOT__dmem__DOT__mem
                        [vlSelfRef.__Vdly_Dim0__tb_riscv_core__DOT__uut__DOT__dmem__DOT__mem_44]) 
                       | (::IData)(vlSelfRef.__Vdly_Val__tb_riscv_core__DOT__uut__DOT__dmem__DOT__mem_43));
            }
            if (vlSelfRef.__Vdly_Set__tb_riscv_core__DOT__uut__DOT__dmem__DOT__mem_48) {
                vlSelfRef.tb_riscv_core__DOT__uut__DOT__dmem__DOT__mem[vlSelfRef.__Vdly_Dim0__tb_riscv_core__DOT__uut__DOT__dmem__DOT__mem_47] 
                    = ((0xffff00ffU & vlSelfRef.tb_riscv_core__DOT__uut__DOT__dmem__DOT__mem
                        [vlSelfRef.__Vdly_Dim0__tb_riscv_core__DOT__uut__DOT__dmem__DOT__mem_47]) 
                       | ((::IData)(vlSelfRef.__Vdly_Val__tb_riscv_core__DOT__uut__DOT__dmem__DOT__mem_46) 
                          << 8U));
            }
            if (vlSelfRef.__Vdly_Set__tb_riscv_core__DOT__uut__DOT__dmem__DOT__mem_51) {
                vlSelfRef.tb_riscv_core__DOT__uut__DOT__dmem__DOT__mem[vlSelfRef.__Vdly_Dim0__tb_riscv_core__DOT__uut__DOT__dmem__DOT__mem_50] 
                    = ((0xff00ffffU & vlSelfRef.tb_riscv_core__DOT__uut__DOT__dmem__DOT__mem
                        [vlSelfRef.__Vdly_Dim0__tb_riscv_core__DOT__uut__DOT__dmem__DOT__mem_50]) 
                       | ((::IData)(vlSelfRef.__Vdly_Val__tb_riscv_core__DOT__uut__DOT__dmem__DOT__mem_49) 
                          << 0x00000010U));
            }
            if (vlSelfRef.__Vdly_Set__tb_riscv_core__DOT__uut__DOT__dmem__DOT__mem_54) {
                vlSelfRef.tb_riscv_core__DOT__uut__DOT__dmem__DOT__mem[vlSelfRef.__Vdly_Dim0__tb_riscv_core__DOT__uut__DOT__dmem__DOT__mem_53] 
                    = ((0x00ffffffU & vlSelfRef.tb_riscv_core__DOT__uut__DOT__dmem__DOT__mem
                        [vlSelfRef.__Vdly_Dim0__tb_riscv_core__DOT__uut__DOT__dmem__DOT__mem_53]) 
                       | ((::IData)(vlSelfRef.__Vdly_Val__tb_riscv_core__DOT__uut__DOT__dmem__DOT__mem_52) 
                          << 0x00000018U));
            }
            if (vlSelfRef.__Vdly_Set__tb_riscv_core__DOT__uut__DOT__u_regfile__DOT__rf_57) {
                vlSelfRef.tb_riscv_core__DOT__uut__DOT__u_regfile__DOT__rf[vlSelfRef.__Vdly_Dim0__tb_riscv_core__DOT__uut__DOT__u_regfile__DOT__rf_56] 
                    = vlSelfRef.__Vdly_Val__tb_riscv_core__DOT__uut__DOT__u_regfile__DOT__rf_55;
            }
        }
    }
    if ((((3ULL & vlSelfRef.__VnbaTriggered[0U])) != 0ULL)) {
        {
            // Inlined CFunc: _nba_comb__TOP__0
            vlSelfRef.tb_riscv_core__DOT__uut__DOT__dmem__DOT__byte_sel 
                = (0x000000ffU & (vlSelfRef.tb_riscv_core__DOT__uut__DOT__dmem__DOT__mem
                                  [(0x000000ffU & (vlSelfRef.tb_riscv_core__DOT__uut__DOT__ex_mem__DOT__alu_out_out 
                                                   >> 2U))] 
                                  >> (0x00000018U & 
                                      (vlSelfRef.tb_riscv_core__DOT__uut__DOT__ex_mem__DOT__alu_out_out 
                                       << 3U))));
            vlSelfRef.tb_riscv_core__DOT__uut__DOT__dmem__DOT__half_sel 
                = (0x0000ffffU & ((2U & vlSelfRef.tb_riscv_core__DOT__uut__DOT__ex_mem__DOT__alu_out_out)
                                   ? (vlSelfRef.tb_riscv_core__DOT__uut__DOT__dmem__DOT__mem
                                      [(0x000000ffU 
                                        & (vlSelfRef.tb_riscv_core__DOT__uut__DOT__ex_mem__DOT__alu_out_out 
                                           >> 2U))] 
                                      >> 0x00000010U)
                                   : vlSelfRef.tb_riscv_core__DOT__uut__DOT__dmem__DOT__mem
                                  [(0x000000ffU & (vlSelfRef.tb_riscv_core__DOT__uut__DOT__ex_mem__DOT__alu_out_out 
                                                   >> 2U))]));
        }
    }
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
