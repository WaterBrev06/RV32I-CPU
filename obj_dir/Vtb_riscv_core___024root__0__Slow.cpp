// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vtb_riscv_core.h for the primary calling header

#include "Vtb_riscv_core__pch.h"

VL_ATTR_COLD void Vtb_riscv_core___024root___eval_static(Vtb_riscv_core___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_riscv_core___024root___eval_static\n"); );
    Vtb_riscv_core__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    {
        // Inlined CFunc: _eval_static__TOP
        vlSelfRef.tb_riscv_core__DOT__error_count = 0U;
        vlSelfRef.tb_riscv_core__DOT__test_count = 0U;
        vlSelfRef.tb_riscv_core__DOT__cycles = 0U;
        vlSelfRef.tb_riscv_core__DOT__retired = 0U;
        vlSelfRef.tb_riscv_core__DOT__done = 0U;
        vlSelfRef.tb_riscv_core__DOT__test = 0U;
        vlSelfRef.tb_riscv_core__DOT__uut__DOT__imem__DOT__unnamedblk1__DOT__test = 0U;
    }
    {
        // Inlined CFunc: __VtraceActivitySetAll
        vlSelfRef.__VtraceActivity[0U] = 1U;
        vlSelfRef.__VtraceActivity[1U] = 1U;
        vlSelfRef.__VtraceActivity[2U] = 1U;
    }
    vlSelfRef.__Vtrigprevexpr___TOP__tb_riscv_core__DOT__clk__0 
        = vlSelfRef.tb_riscv_core__DOT__clk;
    vlSelfRef.__Vtrigprevexpr___TOP__tb_riscv_core__DOT__rst__0 
        = vlSelfRef.tb_riscv_core__DOT__rst;
    do {
        vlSelfRef.__VactTriggeredAcc[vlSelfRef.__Vi] 
            = vlSelfRef.__VactTriggered[vlSelfRef.__Vi];
        vlSelfRef.__Vi = ((::IData)(1U) + vlSelfRef.__Vi);
    } while ((0U >= vlSelfRef.__Vi));
}

#ifdef VL_DEBUG
VL_ATTR_COLD void Vtb_riscv_core___024root___dump_triggers__stl(const ::VlUnpacked<::QData/*63:0*/, 1> &triggers, const ::std::string &tag);
#endif  // VL_DEBUG
VL_ATTR_COLD bool Vtb_riscv_core___024root___trigger_anySet__stl(const ::VlUnpacked<::QData/*63:0*/, 1> &in);
VL_ATTR_COLD void Vtb_riscv_core___024root___stl_comb__TOP__0(Vtb_riscv_core___024root* vlSelf);

VL_ATTR_COLD bool Vtb_riscv_core___024root___eval_stl(Vtb_riscv_core___024root* vlSelf, ::CData/*0:0*/ firstIteration) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_riscv_core___024root___eval_stl\n"); );
    Vtb_riscv_core__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Locals
    ::CData/*0:0*/ __VstlExecute;
    // Body
    vlSelfRef.__VstlTriggered[0U] = ((0xfffffffffffffffeULL 
                                      & vlSelfRef.__VstlTriggered[0U]) 
                                     | (::IData)((::IData)(firstIteration)));
#ifdef VL_DEBUG
    if (VL_UNLIKELY(vlSymsp->_vm_contextp__->debug())) {
        Vtb_riscv_core___024root___dump_triggers__stl(vlSelfRef.__VstlTriggered, "stl"s);
    }
#endif
    __VstlExecute = Vtb_riscv_core___024root___trigger_anySet__stl(vlSelfRef.__VstlTriggered);
    if (__VstlExecute) {
        {
            // Inlined CFunc: _eval_body__stl
            if ((((1ULL & vlSelfRef.__VstlTriggered[0U])) != 0ULL)) {
                Vtb_riscv_core___024root___stl_comb__TOP__0(vlSelf);
                {
                    // Inlined CFunc: __VtraceActivitySetAll
                    vlSelfRef.__VtraceActivity[0U] = 1U;
                    vlSelfRef.__VtraceActivity[1U] = 1U;
                    vlSelfRef.__VtraceActivity[2U] = 1U;
                }
            }
        }
    }
    return (__VstlExecute);
}

VL_ATTR_COLD void Vtb_riscv_core___024root___eval_dump_triggers__stl(Vtb_riscv_core___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_riscv_core___024root___eval_dump_triggers__stl\n"); );
    Vtb_riscv_core__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
#ifdef VL_DEBUG
    Vtb_riscv_core___024root___dump_triggers__stl(vlSelfRef.__VstlTriggered, "stl"s);
#endif
}

#ifdef VL_DEBUG
VL_ATTR_COLD void Vtb_riscv_core___024root___dump_triggers__ico(const ::VlUnpacked<::QData/*63:0*/, 1> &triggers, const ::std::string &tag);
#endif  // VL_DEBUG

VL_ATTR_COLD void Vtb_riscv_core___024root___eval_dump_triggers__ico(Vtb_riscv_core___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_riscv_core___024root___eval_dump_triggers__ico\n"); );
    Vtb_riscv_core__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
#ifdef VL_DEBUG
    Vtb_riscv_core___024root___dump_triggers__ico(vlSelfRef.__VicoTriggered, "ico"s);
#endif
}

#ifdef VL_DEBUG
VL_ATTR_COLD void Vtb_riscv_core___024root___dump_triggers__act(const ::VlUnpacked<::QData/*63:0*/, 1> &triggers, const ::std::string &tag);
#endif  // VL_DEBUG

VL_ATTR_COLD void Vtb_riscv_core___024root___eval_dump_triggers__act(Vtb_riscv_core___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_riscv_core___024root___eval_dump_triggers__act\n"); );
    Vtb_riscv_core__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
#ifdef VL_DEBUG
    Vtb_riscv_core___024root___dump_triggers__act(vlSelfRef.__VactTriggered, "act"s);
#endif
}

VL_ATTR_COLD void Vtb_riscv_core___024root___eval_dump_triggers__nba(Vtb_riscv_core___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_riscv_core___024root___eval_dump_triggers__nba\n"); );
    Vtb_riscv_core__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
#ifdef VL_DEBUG
    Vtb_riscv_core___024root___dump_triggers__act(vlSelfRef.__VnbaTriggered, "nba"s);
#endif
}

VL_ATTR_COLD void Vtb_riscv_core___024root___eval_dump_triggers__obs(Vtb_riscv_core___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_riscv_core___024root___eval_dump_triggers__obs\n"); );
    Vtb_riscv_core__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
}

VL_ATTR_COLD void Vtb_riscv_core___024root___eval_dump_triggers__react(Vtb_riscv_core___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_riscv_core___024root___eval_dump_triggers__react\n"); );
    Vtb_riscv_core__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
}

VL_ATTR_COLD void Vtb_riscv_core___024root___eval_final(Vtb_riscv_core___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_riscv_core___024root___eval_final\n"); );
    Vtb_riscv_core__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
}

VL_ATTR_COLD void Vtb_riscv_core___024root___eval_initial__TOP(Vtb_riscv_core___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_riscv_core___024root___eval_initial__TOP\n"); );
    Vtb_riscv_core__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Locals
    ::IData/*31:0*/ tb_riscv_core__DOT__uut__DOT__dmem__DOT__unnamedblk1__DOT__i;
    tb_riscv_core__DOT__uut__DOT__dmem__DOT__unnamedblk1__DOT__i = 0;
    ::IData/*31:0*/ tb_riscv_core__DOT__uut__DOT__imem__DOT__unnamedblk1__DOT__unnamedblk2__DOT__i;
    tb_riscv_core__DOT__uut__DOT__imem__DOT__unnamedblk1__DOT__unnamedblk2__DOT__i = 0;
    // Body
    vlSymsp->_vm_contextp__->dumpfile("wave.vcd"s);
    vlSymsp->_traceDumpOpen();
    tb_riscv_core__DOT__uut__DOT__dmem__DOT__unnamedblk1__DOT__i = 0U;
    while (VL_GTS_III(32, 0x00000100U, tb_riscv_core__DOT__uut__DOT__dmem__DOT__unnamedblk1__DOT__i)) {
        vlSelfRef.tb_riscv_core__DOT__uut__DOT__dmem__DOT__mem[(0x000000ffU 
                                                                & tb_riscv_core__DOT__uut__DOT__dmem__DOT__unnamedblk1__DOT__i)] = 0U;
        tb_riscv_core__DOT__uut__DOT__dmem__DOT__unnamedblk1__DOT__i 
            = ((::IData)(1U) + tb_riscv_core__DOT__uut__DOT__dmem__DOT__unnamedblk1__DOT__i);
    }
    tb_riscv_core__DOT__uut__DOT__imem__DOT__unnamedblk1__DOT__unnamedblk2__DOT__i = 0U;
    while (VL_GTS_III(32, 0x00000100U, tb_riscv_core__DOT__uut__DOT__imem__DOT__unnamedblk1__DOT__unnamedblk2__DOT__i)) {
        vlSelfRef.tb_riscv_core__DOT__uut__DOT__imem__DOT__mem[(0x000000ffU 
                                                                & tb_riscv_core__DOT__uut__DOT__imem__DOT__unnamedblk1__DOT__unnamedblk2__DOT__i)] = 0x00000013U;
        tb_riscv_core__DOT__uut__DOT__imem__DOT__unnamedblk1__DOT__unnamedblk2__DOT__i 
            = ((::IData)(1U) + tb_riscv_core__DOT__uut__DOT__imem__DOT__unnamedblk1__DOT__unnamedblk2__DOT__i);
    }
    std::ignore = VL_VALUEPLUSARGS_INI(32, "TEST=%d"s, 
                                       vlSelfRef.tb_riscv_core__DOT__uut__DOT__imem__DOT__unnamedblk1__DOT__test);
    if ((0U == vlSelfRef.tb_riscv_core__DOT__uut__DOT__imem__DOT__unnamedblk1__DOT__test)) {
        vlSelfRef.tb_riscv_core__DOT__uut__DOT__imem__DOT__mem[0U] = 0x00a00093U;
        vlSelfRef.tb_riscv_core__DOT__uut__DOT__imem__DOT__mem[1U] = 0x01400113U;
        vlSelfRef.tb_riscv_core__DOT__uut__DOT__imem__DOT__mem[2U] = 0x002081b3U;
        vlSelfRef.tb_riscv_core__DOT__uut__DOT__imem__DOT__mem[3U] = 0x00302023U;
        vlSelfRef.tb_riscv_core__DOT__uut__DOT__imem__DOT__mem[4U] = 0x00002203U;
        vlSelfRef.tb_riscv_core__DOT__uut__DOT__imem__DOT__mem[5U] = 0x00700313U;
    } else if ((1U == vlSelfRef.tb_riscv_core__DOT__uut__DOT__imem__DOT__unnamedblk1__DOT__test)) {
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
    } else if ((2U == vlSelfRef.tb_riscv_core__DOT__uut__DOT__imem__DOT__unnamedblk1__DOT__test)) {
        vlSelfRef.tb_riscv_core__DOT__uut__DOT__imem__DOT__mem[0U] = 0x00500093U;
        vlSelfRef.tb_riscv_core__DOT__uut__DOT__imem__DOT__mem[1U] = 0x00c0056fU;
        vlSelfRef.tb_riscv_core__DOT__uut__DOT__imem__DOT__mem[2U] = 0x00100193U;
        vlSelfRef.tb_riscv_core__DOT__uut__DOT__imem__DOT__mem[3U] = 0x00100213U;
        vlSelfRef.tb_riscv_core__DOT__uut__DOT__imem__DOT__mem[4U] = 0x00100293U;
        vlSelfRef.tb_riscv_core__DOT__uut__DOT__imem__DOT__mem[5U] = 0x02000593U;
        vlSelfRef.tb_riscv_core__DOT__uut__DOT__imem__DOT__mem[6U] = 0x00058667U;
        vlSelfRef.tb_riscv_core__DOT__uut__DOT__imem__DOT__mem[7U] = 0x00100413U;
        vlSelfRef.tb_riscv_core__DOT__uut__DOT__imem__DOT__mem[8U] = 0x00c504b3U;
        vlSelfRef.tb_riscv_core__DOT__uut__DOT__imem__DOT__mem[9U] = 0x00700313U;
    } else if (VL_LIKELY(((3U == vlSelfRef.tb_riscv_core__DOT__uut__DOT__imem__DOT__unnamedblk1__DOT__test)))) {
        vlSelfRef.tb_riscv_core__DOT__uut__DOT__imem__DOT__mem[0U] = 0x06300413U;
        vlSelfRef.tb_riscv_core__DOT__uut__DOT__imem__DOT__mem[1U] = 0x06300f93U;
        vlSelfRef.tb_riscv_core__DOT__uut__DOT__imem__DOT__mem[2U] = 0x123450b7U;
        vlSelfRef.tb_riscv_core__DOT__uut__DOT__imem__DOT__mem[3U] = 0x00001117U;
        vlSelfRef.tb_riscv_core__DOT__uut__DOT__imem__DOT__mem[4U] = 0x67808193U;
        vlSelfRef.tb_riscv_core__DOT__uut__DOT__imem__DOT__mem[5U] = 0xfffff237U;
        vlSelfRef.tb_riscv_core__DOT__uut__DOT__imem__DOT__mem[6U] = 0x00000297U;
        vlSelfRef.tb_riscv_core__DOT__uut__DOT__imem__DOT__mem[7U] = 0x00700313U;
    } else {
        VL_WRITEF_NX("[%0t] %%Fatal: instr_mem.sv:69: Assertion failed in %m: Unknown TEST=%0d (use 0, 1 or 2)\n",4, 'M',vlSymsp->__Vm_topNames[1].c_str(),"uut.imem.unnamedblk1", 'T',-9
                     , '#',64,VL_TIME_UNITED_Q(1000)
                     , '~',32,vlSelfRef.tb_riscv_core__DOT__uut__DOT__imem__DOT__unnamedblk1__DOT__test);
        VL_STOP_MT("instr_mem.sv", 69, "", false);
    }
}

#ifdef VL_DEBUG
VL_ATTR_COLD void Vtb_riscv_core___024root___dump_triggers__stl(const ::VlUnpacked<::QData/*63:0*/, 1> &triggers, const ::std::string &tag) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_riscv_core___024root___dump_triggers__stl\n"); );
    // Body
    if ((1U & (~ (::IData)(Vtb_riscv_core___024root___trigger_anySet__stl(triggers))))) {
        VL_DBG_MSGS("         No '" + tag + "' region triggers active\n");
    }
    if ((1U & (::IData)(triggers[0U]))) {
        VL_DBG_MSGS("         '" + tag + "' region trigger index 0 is active: Internal 'stl' trigger - first iteration\n");
    }
}
#endif  // VL_DEBUG

VL_ATTR_COLD bool Vtb_riscv_core___024root___trigger_anySet__stl(const ::VlUnpacked<::QData/*63:0*/, 1> &in) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_riscv_core___024root___trigger_anySet__stl\n"); );
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

extern const ::VlWide<128>/*4095:0*/ Vtb_riscv_core__ConstPool__CONST_0;
extern const ::VlUnpacked<::CData/*3:0*/, 128> Vtb_riscv_core__ConstPool__CONSARRAY_1;

VL_ATTR_COLD void Vtb_riscv_core___024root___stl_comb__TOP__0(Vtb_riscv_core___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_riscv_core___024root___stl_comb__TOP__0\n"); );
    Vtb_riscv_core__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Locals
    ::CData/*0:0*/ __Vdfg_Regularize_279;
    __Vdfg_Regularize_279 = 0;
    ::CData/*0:0*/ __Vdfg_Regularize_280;
    __Vdfg_Regularize_280 = 0;
    ::IData/*31:0*/ __Vdfg_Regularize_282;
    __Vdfg_Regularize_282 = 0;
    ::CData/*0:0*/ __Vdfg_Regularize_283;
    __Vdfg_Regularize_283 = 0;
    ::CData/*0:0*/ __Vdfg_Regularize_284;
    __Vdfg_Regularize_284 = 0;
    ::CData/*0:0*/ __Vdfg_Regularize_285;
    __Vdfg_Regularize_285 = 0;
    ::IData/*31:0*/ __Vdfg_Regularize_287;
    __Vdfg_Regularize_287 = 0;
    // Body
    vlSelfRef.__Vdfg_Regularize_278 = (0x00000fffU 
                                       & Vtb_riscv_core__ConstPool__CONST_0
                                       [(0x0000007fU 
                                         & vlSelfRef.tb_riscv_core__DOT__uut__DOT__if_id__DOT__instr_out)]);
    __Vdfg_Regularize_282 = ((((- (::IData)((vlSelfRef.tb_riscv_core__DOT__uut__DOT__if_id__DOT__instr_out 
                                             >> 0x0000001fU))) 
                               << 0x0000000cU) | (vlSelfRef.tb_riscv_core__DOT__uut__DOT__if_id__DOT__instr_out 
                                                  >> 0x00000014U)) 
                             & (- (::IData)((3U == 
                                             (3U & vlSelfRef.tb_riscv_core__DOT__uut__DOT__if_id__DOT__instr_out)))));
    __Vdfg_Regularize_287 = (0xfffff000U & (vlSelfRef.tb_riscv_core__DOT__uut__DOT__if_id__DOT__instr_out 
                                            & (- (::IData)(
                                                           (3U 
                                                            == 
                                                            (3U 
                                                             & vlSelfRef.tb_riscv_core__DOT__uut__DOT__if_id__DOT__instr_out))))));
    vlSelfRef.tb_riscv_core__DOT__uut__DOT__pc_stall 
        = ((::IData)(vlSelfRef.tb_riscv_core__DOT__uut__DOT__id_ex__DOT__mem_read_out) 
           & ((0U != (::IData)(vlSelfRef.tb_riscv_core__DOT__uut__DOT__id_ex__DOT__rd_addr_out)) 
              & (((::IData)(vlSelfRef.tb_riscv_core__DOT__uut__DOT__id_ex__DOT__rd_addr_out) 
                  == (0x0000001fU & (vlSelfRef.tb_riscv_core__DOT__uut__DOT__if_id__DOT__instr_out 
                                     >> 0x0000000fU))) 
                 | ((::IData)(vlSelfRef.tb_riscv_core__DOT__uut__DOT__id_ex__DOT__rd_addr_out) 
                    == (0x0000001fU & (vlSelfRef.tb_riscv_core__DOT__uut__DOT__if_id__DOT__instr_out 
                                       >> 0x00000014U))))));
    vlSelfRef.tb_riscv_core__DOT__uut__DOT__ex_branch_target 
        = (vlSelfRef.tb_riscv_core__DOT__uut__DOT__id_ex__DOT__pc_out 
           + vlSelfRef.tb_riscv_core__DOT__uut__DOT__id_ex__DOT__imm_out);
    __Vdfg_Regularize_279 = (1U & Vtb_riscv_core__ConstPool__CONSARRAY_1
                             [((((::IData)(vlSelfRef.tb_riscv_core__DOT__uut__DOT__id_ex__DOT__op_bit5_out) 
                                 << 6U) | ((::IData)(vlSelfRef.tb_riscv_core__DOT__uut__DOT__id_ex__DOT__funct7_5_out) 
                                           << 5U)) 
                               | (((::IData)(vlSelfRef.tb_riscv_core__DOT__uut__DOT__id_ex__DOT__funct3_out) 
                                   << 2U) | (::IData)(vlSelfRef.tb_riscv_core__DOT__uut__DOT__id_ex__DOT__alu_op_out)))]);
    __Vdfg_Regularize_280 = (1U & (Vtb_riscv_core__ConstPool__CONSARRAY_1
                                   [((((::IData)(vlSelfRef.tb_riscv_core__DOT__uut__DOT__id_ex__DOT__op_bit5_out) 
                                       << 6U) | ((::IData)(vlSelfRef.tb_riscv_core__DOT__uut__DOT__id_ex__DOT__funct7_5_out) 
                                                 << 5U)) 
                                     | (((::IData)(vlSelfRef.tb_riscv_core__DOT__uut__DOT__id_ex__DOT__funct3_out) 
                                         << 2U) | (::IData)(vlSelfRef.tb_riscv_core__DOT__uut__DOT__id_ex__DOT__alu_op_out)))] 
                                   >> 1U));
    __Vdfg_Regularize_285 = (1U & (Vtb_riscv_core__ConstPool__CONSARRAY_1
                                   [((((::IData)(vlSelfRef.tb_riscv_core__DOT__uut__DOT__id_ex__DOT__op_bit5_out) 
                                       << 6U) | ((::IData)(vlSelfRef.tb_riscv_core__DOT__uut__DOT__id_ex__DOT__funct7_5_out) 
                                                 << 5U)) 
                                     | (((::IData)(vlSelfRef.tb_riscv_core__DOT__uut__DOT__id_ex__DOT__funct3_out) 
                                         << 2U) | (::IData)(vlSelfRef.tb_riscv_core__DOT__uut__DOT__id_ex__DOT__alu_op_out)))] 
                                   >> 2U));
    vlSelfRef.tb_riscv_core__DOT__wb_result = ((::IData)(vlSelfRef.tb_riscv_core__DOT__uut__DOT__mem_wb__DOT__mem_to_reg_out)
                                                ? vlSelfRef.tb_riscv_core__DOT__uut__DOT__mem_wb__DOT__read_data_out
                                                : vlSelfRef.tb_riscv_core__DOT__uut__DOT__mem_wb__DOT__alu_out_out);
    __Vdfg_Regularize_283 = ((::IData)(vlSelfRef.tb_riscv_core__DOT__uut__DOT__ex_mem__DOT__reg_write_out) 
                             & (0U != (::IData)(vlSelfRef.tb_riscv_core__DOT__uut__DOT__ex_mem__DOT__rd_addr_out)));
    __Vdfg_Regularize_284 = ((::IData)(vlSelfRef.tb_riscv_core__DOT__uut__DOT__mem_wb__DOT__reg_write_out) 
                             & (0U != (::IData)(vlSelfRef.tb_riscv_core__DOT__uut__DOT__mem_wb__DOT__rd_addr_out)));
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
                      ? __Vdfg_Regularize_282 : (((
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
                    & __Vdfg_Regularize_287) : ((((- (::IData)(
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
                      ? __Vdfg_Regularize_287 : __Vdfg_Regularize_282) 
                    & (- (::IData)((1U & (~ (vlSelfRef.tb_riscv_core__DOT__uut__DOT__if_id__DOT__instr_out 
                                             >> 3U))))))
                 : (__Vdfg_Regularize_282 & ((- (::IData)(
                                                          (1U 
                                                           & (~ 
                                                              (vlSelfRef.tb_riscv_core__DOT__uut__DOT__if_id__DOT__instr_out 
                                                               >> 3U))))) 
                                             & (- (::IData)(
                                                            (1U 
                                                             & (~ 
                                                                (vlSelfRef.tb_riscv_core__DOT__uut__DOT__if_id__DOT__instr_out 
                                                                 >> 2U))))))))));
    vlSelfRef.tb_riscv_core__DOT__uut__DOT__forward_a 
        = ((((::IData)(vlSelfRef.tb_riscv_core__DOT__uut__DOT__id_ex__DOT__rs1_addr_out) 
             == (::IData)(vlSelfRef.tb_riscv_core__DOT__uut__DOT__ex_mem__DOT__rd_addr_out)) 
            & (::IData)(__Vdfg_Regularize_283)) ? 2U
            : (1U & (- (::IData)((((::IData)(vlSelfRef.tb_riscv_core__DOT__uut__DOT__mem_wb__DOT__rd_addr_out) 
                                   == (::IData)(vlSelfRef.tb_riscv_core__DOT__uut__DOT__id_ex__DOT__rs1_addr_out)) 
                                  & (::IData)(__Vdfg_Regularize_284))))));
    vlSelfRef.tb_riscv_core__DOT__uut__DOT__forward_b 
        = ((((::IData)(vlSelfRef.tb_riscv_core__DOT__uut__DOT__id_ex__DOT__rs2_addr_out) 
             == (::IData)(vlSelfRef.tb_riscv_core__DOT__uut__DOT__ex_mem__DOT__rd_addr_out)) 
            & (::IData)(__Vdfg_Regularize_283)) ? 2U
            : (1U & (- (::IData)((((::IData)(vlSelfRef.tb_riscv_core__DOT__uut__DOT__mem_wb__DOT__rd_addr_out) 
                                   == (::IData)(vlSelfRef.tb_riscv_core__DOT__uut__DOT__id_ex__DOT__rs2_addr_out)) 
                                  & (::IData)(__Vdfg_Regularize_284))))));
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
    vlSelfRef.tb_riscv_core__DOT__uut__DOT__alu_in2 
        = ((::IData)(vlSelfRef.tb_riscv_core__DOT__uut__DOT__id_ex__DOT__alu_src_out)
            ? vlSelfRef.tb_riscv_core__DOT__uut__DOT__id_ex__DOT__imm_out
            : vlSelfRef.tb_riscv_core__DOT__uut__DOT__forward_b_data);
    vlSelfRef.tb_riscv_core__DOT__uut__DOT__id_ex_flush 
        = ((::IData)(vlSelfRef.tb_riscv_core__DOT__uut__DOT__pc_stall) 
           | (::IData)(vlSelfRef.tb_riscv_core__DOT__uut__DOT__if_id_flush));
    vlSelfRef.tb_riscv_core__DOT__uut__DOT__ex_alu_out 
        = ((8U & Vtb_riscv_core__ConstPool__CONSARRAY_1
            [((((::IData)(vlSelfRef.tb_riscv_core__DOT__uut__DOT__id_ex__DOT__op_bit5_out) 
                << 6U) | ((::IData)(vlSelfRef.tb_riscv_core__DOT__uut__DOT__id_ex__DOT__funct7_5_out) 
                          << 5U)) | (((::IData)(vlSelfRef.tb_riscv_core__DOT__uut__DOT__id_ex__DOT__funct3_out) 
                                      << 2U) | (::IData)(vlSelfRef.tb_riscv_core__DOT__uut__DOT__id_ex__DOT__alu_op_out)))])
            ? ((- (::IData)((1U & (~ (::IData)(__Vdfg_Regularize_280))))) 
               & (((::IData)(__Vdfg_Regularize_279)
                    ? (1U & (- (::IData)((vlSelfRef.tb_riscv_core__DOT__uut__DOT__alu_a 
                                          < vlSelfRef.tb_riscv_core__DOT__uut__DOT__alu_in2))))
                    : (1U & (- (::IData)(VL_LTS_III(32, vlSelfRef.tb_riscv_core__DOT__uut__DOT__alu_a, vlSelfRef.tb_riscv_core__DOT__uut__DOT__alu_in2))))) 
                  & (- (::IData)((1U & (~ (::IData)(__Vdfg_Regularize_285)))))))
            : ((::IData)(__Vdfg_Regularize_285) ? ((::IData)(__Vdfg_Regularize_280)
                                                    ? 
                                                   ((::IData)(__Vdfg_Regularize_279)
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
                                                   ((::IData)(__Vdfg_Regularize_279)
                                                     ? 
                                                    (vlSelfRef.tb_riscv_core__DOT__uut__DOT__alu_a 
                                                     << 
                                                     (0x0000001fU 
                                                      & vlSelfRef.tb_riscv_core__DOT__uut__DOT__alu_in2))
                                                     : 
                                                    (vlSelfRef.tb_riscv_core__DOT__uut__DOT__alu_a 
                                                     ^ vlSelfRef.tb_riscv_core__DOT__uut__DOT__alu_in2)))
                : ((::IData)(__Vdfg_Regularize_280)
                    ? ((::IData)(__Vdfg_Regularize_279)
                        ? (vlSelfRef.tb_riscv_core__DOT__uut__DOT__alu_a 
                           | vlSelfRef.tb_riscv_core__DOT__uut__DOT__alu_in2)
                        : (vlSelfRef.tb_riscv_core__DOT__uut__DOT__alu_a 
                           & vlSelfRef.tb_riscv_core__DOT__uut__DOT__alu_in2))
                    : ((::IData)(__Vdfg_Regularize_279)
                        ? (vlSelfRef.tb_riscv_core__DOT__uut__DOT__alu_a 
                           - vlSelfRef.tb_riscv_core__DOT__uut__DOT__alu_in2)
                        : (vlSelfRef.tb_riscv_core__DOT__uut__DOT__alu_a 
                           + vlSelfRef.tb_riscv_core__DOT__uut__DOT__alu_in2)))));
    vlSelfRef.tb_riscv_core__DOT__uut__DOT__next_pc 
        = ((::IData)(vlSelfRef.tb_riscv_core__DOT__uut__DOT__if_id_flush)
            ? ((::IData)(vlSelfRef.tb_riscv_core__DOT__uut__DOT__id_ex__DOT__jalr_out)
                ? (0xfffffffeU & vlSelfRef.tb_riscv_core__DOT__uut__DOT__ex_alu_out)
                : vlSelfRef.tb_riscv_core__DOT__uut__DOT__ex_branch_target)
            : ((::IData)(4U) + vlSelfRef.tb_riscv_core__DOT__uut__DOT__pc));
}

bool Vtb_riscv_core___024root___trigger_anySet__ico(const ::VlUnpacked<::QData/*63:0*/, 1> &in);

#ifdef VL_DEBUG
VL_ATTR_COLD void Vtb_riscv_core___024root___dump_triggers__ico(const ::VlUnpacked<::QData/*63:0*/, 1> &triggers, const ::std::string &tag) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_riscv_core___024root___dump_triggers__ico\n"); );
    // Body
    if ((1U & (~ (::IData)(Vtb_riscv_core___024root___trigger_anySet__ico(triggers))))) {
        VL_DBG_MSGS("         No '" + tag + "' region triggers active\n");
    }
    if ((1U & (::IData)(triggers[0U]))) {
        VL_DBG_MSGS("         '" + tag + "' region trigger index 0 is active: Internal 'ico' trigger - first iteration\n");
    }
}
#endif  // VL_DEBUG

bool Vtb_riscv_core___024root___trigger_anySet__act(const ::VlUnpacked<::QData/*63:0*/, 1> &in);

#ifdef VL_DEBUG
VL_ATTR_COLD void Vtb_riscv_core___024root___dump_triggers__act(const ::VlUnpacked<::QData/*63:0*/, 1> &triggers, const ::std::string &tag) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_riscv_core___024root___dump_triggers__act\n"); );
    // Body
    if ((1U & (~ (::IData)(Vtb_riscv_core___024root___trigger_anySet__act(triggers))))) {
        VL_DBG_MSGS("         No '" + tag + "' region triggers active\n");
    }
    if ((1U & (::IData)(triggers[0U]))) {
        VL_DBG_MSGS("         '" + tag + "' region trigger index 0 is active: @(posedge tb_riscv_core.clk)\n");
    }
    if ((1U & (::IData)((triggers[0U] >> 1U)))) {
        VL_DBG_MSGS("         '" + tag + "' region trigger index 1 is active: @(posedge tb_riscv_core.rst)\n");
    }
    if ((1U & (::IData)((triggers[0U] >> 2U)))) {
        VL_DBG_MSGS("         '" + tag + "' region trigger index 2 is active: @([true] __VdlySched.awaitingCurrentTime())\n");
    }
}
#endif  // VL_DEBUG

VL_ATTR_COLD void Vtb_riscv_core___024root___ctor_var_reset(Vtb_riscv_core___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_riscv_core___024root___ctor_var_reset\n"); );
    Vtb_riscv_core__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    const uint64_t __VscopeHash = VL_MURMUR64_HASH(vlSelf->vlNamep);
    vlSelf->tb_riscv_core__DOT__clk = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 927428257173894171ull);
    vlSelf->tb_riscv_core__DOT__rst = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 17458373662447087105ull);
    vlSelf->tb_riscv_core__DOT__wb_result = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 7935629636720741075ull);
    vlSelf->tb_riscv_core__DOT__uut__DOT__pc = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 11587839362951495431ull);
    vlSelf->tb_riscv_core__DOT__uut__DOT__next_pc = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 2163486302889694352ull);
    vlSelf->tb_riscv_core__DOT__uut__DOT__pc_stall = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 1894375518670712691ull);
    vlSelf->tb_riscv_core__DOT__uut__DOT__if_id_flush = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 10538585027071448598ull);
    vlSelf->tb_riscv_core__DOT__uut__DOT__id_ex_flush = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 12282020651893691931ull);
    vlSelf->tb_riscv_core__DOT__uut__DOT__id_imm = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 17139181405097122171ull);
    vlSelf->tb_riscv_core__DOT__uut__DOT__forward_a = VL_SCOPED_RAND_RESET_I(2, __VscopeHash, 607379904485559884ull);
    vlSelf->tb_riscv_core__DOT__uut__DOT__forward_b = VL_SCOPED_RAND_RESET_I(2, __VscopeHash, 15305600083387748970ull);
    vlSelf->tb_riscv_core__DOT__uut__DOT__alu_in1 = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 11326203380301862610ull);
    vlSelf->tb_riscv_core__DOT__uut__DOT__alu_in2 = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 10383492590781425667ull);
    vlSelf->tb_riscv_core__DOT__uut__DOT__forward_b_data = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 8454001638088227590ull);
    vlSelf->tb_riscv_core__DOT__uut__DOT__ex_alu_out = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 13403471087210559354ull);
    vlSelf->tb_riscv_core__DOT__uut__DOT__ex_branch_target = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 8925179014821661270ull);
    vlSelf->tb_riscv_core__DOT__uut__DOT__alu_a = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 6336978928245396974ull);
    vlSelf->tb_riscv_core__DOT__uut__DOT__mem_wb__DOT__valid_out = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 11716333795246329935ull);
    vlSelf->tb_riscv_core__DOT__uut__DOT__mem_wb__DOT__reg_write_out = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 9369817129104060527ull);
    vlSelf->tb_riscv_core__DOT__uut__DOT__mem_wb__DOT__mem_to_reg_out = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 13437335583198908769ull);
    vlSelf->tb_riscv_core__DOT__uut__DOT__mem_wb__DOT__read_data_out = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 8993411632754449228ull);
    vlSelf->tb_riscv_core__DOT__uut__DOT__mem_wb__DOT__alu_out_out = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 5542614603601656398ull);
    vlSelf->tb_riscv_core__DOT__uut__DOT__mem_wb__DOT__rd_addr_out = VL_SCOPED_RAND_RESET_I(5, __VscopeHash, 8102829147135228090ull);
    vlSelf->tb_riscv_core__DOT__uut__DOT__dmem__DOT__mem[0] = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 10673250170301591202ull);
    VL_UNPACKED_FILL(vlSelf->tb_riscv_core__DOT__uut__DOT__dmem__DOT__mem.data(), sizeof(vlSelf->tb_riscv_core__DOT__uut__DOT__dmem__DOT__mem[0]), 256);
    vlSelf->tb_riscv_core__DOT__uut__DOT__ex_mem__DOT__valid_out = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 10200011613181894317ull);
    vlSelf->tb_riscv_core__DOT__uut__DOT__ex_mem__DOT__reg_write_out = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 5931471504173279201ull);
    vlSelf->tb_riscv_core__DOT__uut__DOT__ex_mem__DOT__mem_to_reg_out = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 12380658256121984573ull);
    vlSelf->tb_riscv_core__DOT__uut__DOT__ex_mem__DOT__mem_read_out = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 2289540764256425473ull);
    vlSelf->tb_riscv_core__DOT__uut__DOT__ex_mem__DOT__mem_write_out = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 15355101046051103286ull);
    vlSelf->tb_riscv_core__DOT__uut__DOT__ex_mem__DOT__branch_out = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 2811971069792743679ull);
    vlSelf->tb_riscv_core__DOT__uut__DOT__ex_mem__DOT__branch_target_out = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 3922208588790973353ull);
    vlSelf->tb_riscv_core__DOT__uut__DOT__ex_mem__DOT__zero_out = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 915652999088914196ull);
    vlSelf->tb_riscv_core__DOT__uut__DOT__ex_mem__DOT__alu_out_out = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 3922511479077296310ull);
    vlSelf->tb_riscv_core__DOT__uut__DOT__ex_mem__DOT__rs2_data_out = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 10621553052237070440ull);
    vlSelf->tb_riscv_core__DOT__uut__DOT__ex_mem__DOT__rd_addr_out = VL_SCOPED_RAND_RESET_I(5, __VscopeHash, 9071241991499252576ull);
    vlSelf->tb_riscv_core__DOT__uut__DOT__id_ex__DOT__valid_out = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 15067350583345724479ull);
    vlSelf->tb_riscv_core__DOT__uut__DOT__id_ex__DOT__jump_out = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 9957626421365324601ull);
    vlSelf->tb_riscv_core__DOT__uut__DOT__id_ex__DOT__jalr_out = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 9235478551347094327ull);
    vlSelf->tb_riscv_core__DOT__uut__DOT__id_ex__DOT__reg_write_out = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 14307504349864401543ull);
    vlSelf->tb_riscv_core__DOT__uut__DOT__id_ex__DOT__mem_to_reg_out = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 1982194188022084651ull);
    vlSelf->tb_riscv_core__DOT__uut__DOT__id_ex__DOT__mem_read_out = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 16961503566280200858ull);
    vlSelf->tb_riscv_core__DOT__uut__DOT__id_ex__DOT__mem_write_out = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 3309200171289687139ull);
    vlSelf->tb_riscv_core__DOT__uut__DOT__id_ex__DOT__branch_out = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 16186795279169913357ull);
    vlSelf->tb_riscv_core__DOT__uut__DOT__id_ex__DOT__alu_src_out = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 15483093225368425118ull);
    vlSelf->tb_riscv_core__DOT__uut__DOT__id_ex__DOT__alu_op_out = VL_SCOPED_RAND_RESET_I(2, __VscopeHash, 8436148950039776349ull);
    vlSelf->tb_riscv_core__DOT__uut__DOT__id_ex__DOT__alu_a_sel_out = VL_SCOPED_RAND_RESET_I(2, __VscopeHash, 1739120993677917138ull);
    vlSelf->tb_riscv_core__DOT__uut__DOT__id_ex__DOT__pc_out = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 2903208488969385209ull);
    vlSelf->tb_riscv_core__DOT__uut__DOT__id_ex__DOT__rs1_data_out = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 1447371532761635568ull);
    vlSelf->tb_riscv_core__DOT__uut__DOT__id_ex__DOT__rs2_data_out = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 13248291197428432301ull);
    vlSelf->tb_riscv_core__DOT__uut__DOT__id_ex__DOT__imm_out = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 18175708108875963637ull);
    vlSelf->tb_riscv_core__DOT__uut__DOT__id_ex__DOT__funct3_out = VL_SCOPED_RAND_RESET_I(3, __VscopeHash, 9178126864907786353ull);
    vlSelf->tb_riscv_core__DOT__uut__DOT__id_ex__DOT__funct7_5_out = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 9189034077418952435ull);
    vlSelf->tb_riscv_core__DOT__uut__DOT__id_ex__DOT__op_bit5_out = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 8307163275377636398ull);
    vlSelf->tb_riscv_core__DOT__uut__DOT__id_ex__DOT__rs1_addr_out = VL_SCOPED_RAND_RESET_I(5, __VscopeHash, 4969467133932742249ull);
    vlSelf->tb_riscv_core__DOT__uut__DOT__id_ex__DOT__rs2_addr_out = VL_SCOPED_RAND_RESET_I(5, __VscopeHash, 17943378851313591003ull);
    vlSelf->tb_riscv_core__DOT__uut__DOT__id_ex__DOT__rd_addr_out = VL_SCOPED_RAND_RESET_I(5, __VscopeHash, 16481807143327176342ull);
    vlSelf->tb_riscv_core__DOT__uut__DOT__u_regfile__DOT__rf[0] = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 2108885517398092298ull);
    VL_UNPACKED_FILL(vlSelf->tb_riscv_core__DOT__uut__DOT__u_regfile__DOT__rf.data(), sizeof(vlSelf->tb_riscv_core__DOT__uut__DOT__u_regfile__DOT__rf[0]), 32);
    vlSelf->tb_riscv_core__DOT__uut__DOT__if_id__DOT__pc_out = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 7115610537505870491ull);
    vlSelf->tb_riscv_core__DOT__uut__DOT__if_id__DOT__instr_out = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 17982601417925286966ull);
    vlSelf->tb_riscv_core__DOT__uut__DOT__if_id__DOT__valid_out = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 712482440610682025ull);
    vlSelf->tb_riscv_core__DOT__uut__DOT__imem__DOT__mem[0] = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 11835699637080297204ull);
    VL_UNPACKED_FILL(vlSelf->tb_riscv_core__DOT__uut__DOT__imem__DOT__mem.data(), sizeof(vlSelf->tb_riscv_core__DOT__uut__DOT__imem__DOT__mem[0]), 256);
    vlSelf->__Vdfg_Regularize_278 = 0;
    vlSelf->__Vdly_Val__tb_riscv_core__DOT__uut__DOT__dmem__DOT__mem_42 = 0;
    vlSelf->__Vdly_Dim0__tb_riscv_core__DOT__uut__DOT__dmem__DOT__mem_43 = 0;
    vlSelf->__Vdly_Set__tb_riscv_core__DOT__uut__DOT__dmem__DOT__mem_44 = 0;
    vlSelf->__Vdly_Val__tb_riscv_core__DOT__uut__DOT__u_regfile__DOT__rf_45 = 0;
    vlSelf->__Vdly_Dim0__tb_riscv_core__DOT__uut__DOT__u_regfile__DOT__rf_46 = 0;
    vlSelf->__Vdly_Set__tb_riscv_core__DOT__uut__DOT__u_regfile__DOT__rf_47 = 0;
    vlSelf->__VstlTriggered[0] = 0;
    VL_UNPACKED_FILL(vlSelf->__VstlTriggered.data(), sizeof(vlSelf->__VstlTriggered[0]), 1);
    vlSelf->__VicoTriggered[0] = 0;
    VL_UNPACKED_FILL(vlSelf->__VicoTriggered.data(), sizeof(vlSelf->__VicoTriggered[0]), 1);
    vlSelf->__VactTriggered[0] = 0;
    VL_UNPACKED_FILL(vlSelf->__VactTriggered.data(), sizeof(vlSelf->__VactTriggered[0]), 1);
    vlSelf->__VactTriggeredAcc[0] = 0;
    VL_UNPACKED_FILL(vlSelf->__VactTriggeredAcc.data(), sizeof(vlSelf->__VactTriggeredAcc[0]), 1);
    vlSelf->__Vtrigprevexpr___TOP__tb_riscv_core__DOT__clk__0 = 0;
    vlSelf->__Vtrigprevexpr___TOP__tb_riscv_core__DOT__rst__0 = 0;
    vlSelf->__VnbaTriggered[0] = 0;
    VL_UNPACKED_FILL(vlSelf->__VnbaTriggered.data(), sizeof(vlSelf->__VnbaTriggered[0]), 1);
    vlSelf->__Vi = 0;
    vlSelf->__VtraceActivity[0] = 0;
    VL_UNPACKED_FILL(vlSelf->__VtraceActivity.data(), sizeof(vlSelf->__VtraceActivity[0]), 3);
}
