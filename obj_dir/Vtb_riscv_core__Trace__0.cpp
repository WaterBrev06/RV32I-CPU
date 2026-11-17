// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Tracing implementation internals

#include "verilated_vcd_c.h"
#include "Vtb_riscv_core__Syms.h"


void Vtb_riscv_core___024root__trace_chg_0_sub_0(Vtb_riscv_core___024root* vlSelf, VerilatedVcd::Buffer* bufp);

void Vtb_riscv_core___024root__trace_chg_0(void* voidSelf, VerilatedVcd::Buffer* bufp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_riscv_core___024root__trace_chg_0\n"); );
    // Body
    Vtb_riscv_core___024root* const __restrict vlSelf VL_ATTR_UNUSED = static_cast<Vtb_riscv_core___024root*>(voidSelf);
    Vtb_riscv_core__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    if (VL_UNLIKELY(!vlSymsp->__Vm_activity)) return;
    Vtb_riscv_core___024root__trace_chg_0_sub_0((&vlSymsp->vlInst.TOP), bufp);
}

extern const ::VlUnpacked<::CData/*3:0*/, 128> Vtb_riscv_core__ConstPool__CONSARRAY_1;
void Vtb_riscv_core___024root__trace_chg_dtype____0(Vtb_riscv_core___024root* vlSelf, VerilatedVcd::Buffer* bufp, uint32_t offset, const ::VlUnpacked<::IData/*31:0*/, 32>& __VdtypeVar);

void Vtb_riscv_core___024root__trace_chg_0_sub_0(Vtb_riscv_core___024root* vlSelf, VerilatedVcd::Buffer* bufp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_riscv_core___024root__trace_chg_0_sub_0\n"); );
    Vtb_riscv_core__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    uint32_t* const oldp VL_ATTR_UNUSED = bufp->oldp(vlSymsp->__Vm_baseCode + 0);
    if (VL_UNLIKELY((vlSelfRef.__VtraceActivity[1U]))) {
        bufp->chgIData(oldp+0,(vlSelfRef.tb_riscv_core__DOT__cycles),32);
        bufp->chgIData(oldp+1,(vlSelfRef.tb_riscv_core__DOT__retired),32);
        bufp->chgBit(oldp+2,(vlSelfRef.tb_riscv_core__DOT__done));
    }
    if (VL_UNLIKELY((vlSelfRef.__VtraceActivity[2U]))) {
        bufp->chgIData(oldp+3,(vlSelfRef.tb_riscv_core__DOT__wb_result),32);
        bufp->chgIData(oldp+4,(vlSelfRef.tb_riscv_core__DOT__uut__DOT__pc),32);
        bufp->chgIData(oldp+5,(((::IData)(vlSelfRef.tb_riscv_core__DOT__uut__DOT__if_id_flush)
                                 ? ((::IData)(vlSelfRef.tb_riscv_core__DOT__uut__DOT__id_ex__DOT__jalr_out)
                                     ? (0xfffffffeU 
                                        & vlSelfRef.tb_riscv_core__DOT__uut__DOT__ex_alu_out)
                                     : vlSelfRef.tb_riscv_core__DOT__uut__DOT__ex_branch_target)
                                 : ((::IData)(4U) + vlSelfRef.tb_riscv_core__DOT__uut__DOT__pc))),32);
        bufp->chgIData(oldp+6,(((::IData)(4U) + vlSelfRef.tb_riscv_core__DOT__uut__DOT__pc)),32);
        bufp->chgBit(oldp+7,(vlSelfRef.tb_riscv_core__DOT__uut__DOT__pc_stall));
        bufp->chgBit(oldp+8,(vlSelfRef.tb_riscv_core__DOT__uut__DOT__if_id_flush));
        bufp->chgBit(oldp+9,(vlSelfRef.tb_riscv_core__DOT__uut__DOT__id_ex_flush));
        bufp->chgIData(oldp+10,(vlSelfRef.tb_riscv_core__DOT__uut__DOT__if_id__DOT__pc_out),32);
        bufp->chgIData(oldp+11,(vlSelfRef.tb_riscv_core__DOT__uut__DOT__if_id__DOT__instr_out),32);
        bufp->chgCData(oldp+12,((0x0000001fU & (vlSelfRef.tb_riscv_core__DOT__uut__DOT__if_id__DOT__instr_out 
                                                >> 0x0000000fU))),5);
        bufp->chgCData(oldp+13,((0x0000001fU & (vlSelfRef.tb_riscv_core__DOT__uut__DOT__if_id__DOT__instr_out 
                                                >> 0x00000014U))),5);
        bufp->chgCData(oldp+14,((0x0000001fU & (vlSelfRef.tb_riscv_core__DOT__uut__DOT__if_id__DOT__instr_out 
                                                >> 7U))),5);
        bufp->chgIData(oldp+15,(vlSelfRef.tb_riscv_core__DOT__uut__DOT__id_imm),32);
        bufp->chgBit(oldp+16,((1U & ((::IData)(vlSelfRef.__Vdfg_Regularize_273) 
                                     >> 7U))));
        bufp->chgBit(oldp+17,((1U & ((::IData)(vlSelfRef.__Vdfg_Regularize_273) 
                                     >> 5U))));
        bufp->chgBit(oldp+18,((1U & ((::IData)(vlSelfRef.__Vdfg_Regularize_273) 
                                     >> 4U))));
        bufp->chgBit(oldp+19,((1U & ((::IData)(vlSelfRef.__Vdfg_Regularize_273) 
                                     >> 3U))));
        bufp->chgBit(oldp+20,((1U & ((::IData)(vlSelfRef.__Vdfg_Regularize_273) 
                                     >> 2U))));
        bufp->chgBit(oldp+21,((1U & ((::IData)(vlSelfRef.__Vdfg_Regularize_273) 
                                     >> 1U))));
        bufp->chgBit(oldp+22,((1U & (::IData)(vlSelfRef.__Vdfg_Regularize_273))));
        bufp->chgBit(oldp+23,((1U & ((::IData)(vlSelfRef.__Vdfg_Regularize_273) 
                                     >> 6U))));
        bufp->chgBit(oldp+24,(vlSelfRef.tb_riscv_core__DOT__uut__DOT__if_id__DOT__valid_out));
        bufp->chgCData(oldp+25,((3U & ((::IData)(vlSelfRef.__Vdfg_Regularize_273) 
                                       >> 8U))),2);
        bufp->chgIData(oldp+26,(vlSelfRef.tb_riscv_core__DOT__uut__DOT__id_ex__DOT__pc_out),32);
        bufp->chgIData(oldp+27,(vlSelfRef.tb_riscv_core__DOT__uut__DOT__id_ex__DOT__rs1_data_out),32);
        bufp->chgIData(oldp+28,(vlSelfRef.tb_riscv_core__DOT__uut__DOT__id_ex__DOT__rs2_data_out),32);
        bufp->chgIData(oldp+29,(vlSelfRef.tb_riscv_core__DOT__uut__DOT__id_ex__DOT__imm_out),32);
        bufp->chgCData(oldp+30,(vlSelfRef.tb_riscv_core__DOT__uut__DOT__id_ex__DOT__funct3_out),3);
        bufp->chgBit(oldp+31,(vlSelfRef.tb_riscv_core__DOT__uut__DOT__id_ex__DOT__funct7_5_out));
        bufp->chgBit(oldp+32,(vlSelfRef.tb_riscv_core__DOT__uut__DOT__id_ex__DOT__op_bit5_out));
        bufp->chgCData(oldp+33,(vlSelfRef.tb_riscv_core__DOT__uut__DOT__id_ex__DOT__rs1_addr_out),5);
        bufp->chgCData(oldp+34,(vlSelfRef.tb_riscv_core__DOT__uut__DOT__id_ex__DOT__rs2_addr_out),5);
        bufp->chgCData(oldp+35,(vlSelfRef.tb_riscv_core__DOT__uut__DOT__id_ex__DOT__rd_addr_out),5);
        bufp->chgBit(oldp+36,(vlSelfRef.tb_riscv_core__DOT__uut__DOT__id_ex__DOT__reg_write_out));
        bufp->chgBit(oldp+37,(vlSelfRef.tb_riscv_core__DOT__uut__DOT__id_ex__DOT__mem_to_reg_out));
        bufp->chgBit(oldp+38,(vlSelfRef.tb_riscv_core__DOT__uut__DOT__id_ex__DOT__mem_read_out));
        bufp->chgBit(oldp+39,(vlSelfRef.tb_riscv_core__DOT__uut__DOT__id_ex__DOT__mem_write_out));
        bufp->chgBit(oldp+40,(vlSelfRef.tb_riscv_core__DOT__uut__DOT__id_ex__DOT__branch_out));
        bufp->chgBit(oldp+41,(vlSelfRef.tb_riscv_core__DOT__uut__DOT__id_ex__DOT__alu_src_out));
        bufp->chgCData(oldp+42,(vlSelfRef.tb_riscv_core__DOT__uut__DOT__id_ex__DOT__alu_op_out),2);
        bufp->chgCData(oldp+43,(Vtb_riscv_core__ConstPool__CONSARRAY_1
                                [((((::IData)(vlSelfRef.tb_riscv_core__DOT__uut__DOT__id_ex__DOT__op_bit5_out) 
                                    << 6U) | ((::IData)(vlSelfRef.tb_riscv_core__DOT__uut__DOT__id_ex__DOT__funct7_5_out) 
                                              << 5U)) 
                                  | (((::IData)(vlSelfRef.tb_riscv_core__DOT__uut__DOT__id_ex__DOT__funct3_out) 
                                      << 2U) | (::IData)(vlSelfRef.tb_riscv_core__DOT__uut__DOT__id_ex__DOT__alu_op_out)))]),4);
        bufp->chgCData(oldp+44,(vlSelfRef.tb_riscv_core__DOT__uut__DOT__forward_a),2);
        bufp->chgCData(oldp+45,(vlSelfRef.tb_riscv_core__DOT__uut__DOT__forward_b),2);
        bufp->chgIData(oldp+46,(vlSelfRef.tb_riscv_core__DOT__uut__DOT__alu_in1),32);
        bufp->chgIData(oldp+47,(vlSelfRef.tb_riscv_core__DOT__uut__DOT__alu_in2),32);
        bufp->chgIData(oldp+48,(vlSelfRef.tb_riscv_core__DOT__uut__DOT__forward_b_data),32);
        bufp->chgIData(oldp+49,(vlSelfRef.tb_riscv_core__DOT__uut__DOT__ex_alu_out),32);
        bufp->chgIData(oldp+50,(vlSelfRef.tb_riscv_core__DOT__uut__DOT__ex_branch_target),32);
        bufp->chgIData(oldp+51,(((::IData)(vlSelfRef.tb_riscv_core__DOT__uut__DOT__id_ex__DOT__jalr_out)
                                  ? (0xfffffffeU & vlSelfRef.tb_riscv_core__DOT__uut__DOT__ex_alu_out)
                                  : vlSelfRef.tb_riscv_core__DOT__uut__DOT__ex_branch_target)),32);
        bufp->chgIData(oldp+52,(((::IData)(vlSelfRef.tb_riscv_core__DOT__uut__DOT__id_ex__DOT__jump_out)
                                  ? ((::IData)(4U) 
                                     + vlSelfRef.tb_riscv_core__DOT__uut__DOT__id_ex__DOT__pc_out)
                                  : vlSelfRef.tb_riscv_core__DOT__uut__DOT__ex_alu_out)),32);
        bufp->chgBit(oldp+53,((0U == vlSelfRef.tb_riscv_core__DOT__uut__DOT__ex_alu_out)));
        bufp->chgBit(oldp+54,(((4U & (::IData)(vlSelfRef.tb_riscv_core__DOT__uut__DOT__id_ex__DOT__funct3_out))
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
                                       >> 1U)) & ((1U 
                                                   & (::IData)(vlSelfRef.tb_riscv_core__DOT__uut__DOT__id_ex__DOT__funct3_out))
                                                   ? 
                                                  (vlSelfRef.tb_riscv_core__DOT__uut__DOT__alu_in1 
                                                   != vlSelfRef.tb_riscv_core__DOT__uut__DOT__forward_b_data)
                                                   : 
                                                  (vlSelfRef.tb_riscv_core__DOT__uut__DOT__alu_in1 
                                                   == vlSelfRef.tb_riscv_core__DOT__uut__DOT__forward_b_data))))));
        bufp->chgBit(oldp+55,(vlSelfRef.tb_riscv_core__DOT__uut__DOT__id_ex__DOT__valid_out));
        bufp->chgBit(oldp+56,(vlSelfRef.tb_riscv_core__DOT__uut__DOT__id_ex__DOT__jump_out));
        bufp->chgBit(oldp+57,(vlSelfRef.tb_riscv_core__DOT__uut__DOT__id_ex__DOT__jalr_out));
        bufp->chgBit(oldp+58,(vlSelfRef.tb_riscv_core__DOT__uut__DOT__ex_mem__DOT__reg_write_out));
        bufp->chgBit(oldp+59,(vlSelfRef.tb_riscv_core__DOT__uut__DOT__ex_mem__DOT__mem_to_reg_out));
        bufp->chgBit(oldp+60,(vlSelfRef.tb_riscv_core__DOT__uut__DOT__ex_mem__DOT__mem_read_out));
        bufp->chgBit(oldp+61,(vlSelfRef.tb_riscv_core__DOT__uut__DOT__ex_mem__DOT__mem_write_out));
        bufp->chgBit(oldp+62,(vlSelfRef.tb_riscv_core__DOT__uut__DOT__ex_mem__DOT__branch_out));
        bufp->chgIData(oldp+63,(vlSelfRef.tb_riscv_core__DOT__uut__DOT__ex_mem__DOT__branch_target_out),32);
        bufp->chgIData(oldp+64,(vlSelfRef.tb_riscv_core__DOT__uut__DOT__ex_mem__DOT__alu_out_out),32);
        bufp->chgIData(oldp+65,(vlSelfRef.tb_riscv_core__DOT__uut__DOT__ex_mem__DOT__rs2_data_out),32);
        bufp->chgBit(oldp+66,(vlSelfRef.tb_riscv_core__DOT__uut__DOT__ex_mem__DOT__zero_out));
        bufp->chgCData(oldp+67,(vlSelfRef.tb_riscv_core__DOT__uut__DOT__ex_mem__DOT__rd_addr_out),5);
        bufp->chgBit(oldp+68,(vlSelfRef.tb_riscv_core__DOT__uut__DOT__ex_mem__DOT__valid_out));
        bufp->chgBit(oldp+69,(vlSelfRef.tb_riscv_core__DOT__uut__DOT__mem_wb__DOT__reg_write_out));
        bufp->chgBit(oldp+70,(vlSelfRef.tb_riscv_core__DOT__uut__DOT__mem_wb__DOT__mem_to_reg_out));
        bufp->chgIData(oldp+71,(vlSelfRef.tb_riscv_core__DOT__uut__DOT__mem_wb__DOT__read_data_out),32);
        bufp->chgIData(oldp+72,(vlSelfRef.tb_riscv_core__DOT__uut__DOT__mem_wb__DOT__alu_out_out),32);
        bufp->chgCData(oldp+73,(vlSelfRef.tb_riscv_core__DOT__uut__DOT__mem_wb__DOT__rd_addr_out),5);
        bufp->chgBit(oldp+74,(vlSelfRef.tb_riscv_core__DOT__uut__DOT__mem_wb__DOT__valid_out));
        bufp->chgCData(oldp+75,((0x0000007fU & vlSelfRef.tb_riscv_core__DOT__uut__DOT__if_id__DOT__instr_out)),7);
        bufp->chgCData(oldp+76,((7U & (vlSelfRef.tb_riscv_core__DOT__uut__DOT__if_id__DOT__instr_out 
                                       >> 0x0000000cU))),3);
        bufp->chgBit(oldp+77,((1U & (vlSelfRef.tb_riscv_core__DOT__uut__DOT__if_id__DOT__instr_out 
                                     >> 0x0000001eU))));
        bufp->chgBit(oldp+78,((1U & (vlSelfRef.tb_riscv_core__DOT__uut__DOT__if_id__DOT__instr_out 
                                     >> 5U))));
    }
    bufp->chgBit(oldp+79,(vlSelfRef.tb_riscv_core__DOT__clk));
    bufp->chgBit(oldp+80,(vlSelfRef.tb_riscv_core__DOT__rst));
    bufp->chgIData(oldp+81,(vlSelfRef.tb_riscv_core__DOT__error_count),32);
    bufp->chgIData(oldp+82,(vlSelfRef.tb_riscv_core__DOT__test_count),32);
    bufp->chgIData(oldp+83,(vlSelfRef.tb_riscv_core__DOT__test),32);
    bufp->chgIData(oldp+84,(vlSelfRef.tb_riscv_core__DOT__uut__DOT__imem__DOT__mem
                            [(0x000000ffU & (vlSelfRef.tb_riscv_core__DOT__uut__DOT__pc 
                                             >> 2U))]),32);
    bufp->chgIData(oldp+85,(((((::IData)(vlSelfRef.tb_riscv_core__DOT__uut__DOT__mem_wb__DOT__reg_write_out) 
                               & ((::IData)(vlSelfRef.tb_riscv_core__DOT__uut__DOT__mem_wb__DOT__rd_addr_out) 
                                  == (0x0000001fU & 
                                      (vlSelfRef.tb_riscv_core__DOT__uut__DOT__if_id__DOT__instr_out 
                                       >> 0x0000000fU))))
                               ? vlSelfRef.tb_riscv_core__DOT__wb_result
                               : vlSelfRef.tb_riscv_core__DOT__uut__DOT__u_regfile__DOT__rf
                              [(0x0000001fU & (vlSelfRef.tb_riscv_core__DOT__uut__DOT__if_id__DOT__instr_out 
                                               >> 0x0000000fU))]) 
                             & (- (::IData)((0U != 
                                             (0x0000001fU 
                                              & (vlSelfRef.tb_riscv_core__DOT__uut__DOT__if_id__DOT__instr_out 
                                                 >> 0x0000000fU))))))),32);
    bufp->chgIData(oldp+86,(((((::IData)(vlSelfRef.tb_riscv_core__DOT__uut__DOT__mem_wb__DOT__reg_write_out) 
                               & ((::IData)(vlSelfRef.tb_riscv_core__DOT__uut__DOT__mem_wb__DOT__rd_addr_out) 
                                  == (0x0000001fU & 
                                      (vlSelfRef.tb_riscv_core__DOT__uut__DOT__if_id__DOT__instr_out 
                                       >> 0x00000014U))))
                               ? vlSelfRef.tb_riscv_core__DOT__wb_result
                               : vlSelfRef.tb_riscv_core__DOT__uut__DOT__u_regfile__DOT__rf
                              [(0x0000001fU & (vlSelfRef.tb_riscv_core__DOT__uut__DOT__if_id__DOT__instr_out 
                                               >> 0x00000014U))]) 
                             & (- (::IData)((0U != 
                                             (0x0000001fU 
                                              & (vlSelfRef.tb_riscv_core__DOT__uut__DOT__if_id__DOT__instr_out 
                                                 >> 0x00000014U))))))),32);
    bufp->chgIData(oldp+87,(((::IData)(vlSelfRef.tb_riscv_core__DOT__uut__DOT__ex_mem__DOT__mem_read_out)
                              ? vlSelfRef.tb_riscv_core__DOT__uut__DOT__dmem__DOT__mem
                             [(0x000000ffU & (vlSelfRef.tb_riscv_core__DOT__uut__DOT__ex_mem__DOT__alu_out_out 
                                              >> 2U))]
                              : 0U)),32);
    bufp->chgIData(oldp+88,(vlSelfRef.tb_riscv_core__DOT__uut__DOT__imem__DOT__unnamedblk1__DOT__test),32);
    Vtb_riscv_core___024root__trace_chg_dtype____0(vlSelf, bufp, 89, vlSelfRef.tb_riscv_core__DOT__uut__DOT__u_regfile__DOT__rf);
}

void Vtb_riscv_core___024root__trace_chg_dtype____0(Vtb_riscv_core___024root* vlSelf, VerilatedVcd::Buffer* bufp, uint32_t offset, const ::VlUnpacked<::IData/*31:0*/, 32>& __VdtypeVar) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_riscv_core___024root__trace_chg_dtype____0\n"); );
    Vtb_riscv_core__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    uint32_t* const oldp VL_ATTR_UNUSED = bufp->oldp(vlSymsp->__Vm_baseCode +  offset);
    bufp->chgIData(oldp+0,(__VdtypeVar[31]),32);
    bufp->chgIData(oldp+1,(__VdtypeVar[30]),32);
    bufp->chgIData(oldp+2,(__VdtypeVar[29]),32);
    bufp->chgIData(oldp+3,(__VdtypeVar[28]),32);
    bufp->chgIData(oldp+4,(__VdtypeVar[27]),32);
    bufp->chgIData(oldp+5,(__VdtypeVar[26]),32);
    bufp->chgIData(oldp+6,(__VdtypeVar[25]),32);
    bufp->chgIData(oldp+7,(__VdtypeVar[24]),32);
    bufp->chgIData(oldp+8,(__VdtypeVar[23]),32);
    bufp->chgIData(oldp+9,(__VdtypeVar[22]),32);
    bufp->chgIData(oldp+10,(__VdtypeVar[21]),32);
    bufp->chgIData(oldp+11,(__VdtypeVar[20]),32);
    bufp->chgIData(oldp+12,(__VdtypeVar[19]),32);
    bufp->chgIData(oldp+13,(__VdtypeVar[18]),32);
    bufp->chgIData(oldp+14,(__VdtypeVar[17]),32);
    bufp->chgIData(oldp+15,(__VdtypeVar[16]),32);
    bufp->chgIData(oldp+16,(__VdtypeVar[15]),32);
    bufp->chgIData(oldp+17,(__VdtypeVar[14]),32);
    bufp->chgIData(oldp+18,(__VdtypeVar[13]),32);
    bufp->chgIData(oldp+19,(__VdtypeVar[12]),32);
    bufp->chgIData(oldp+20,(__VdtypeVar[11]),32);
    bufp->chgIData(oldp+21,(__VdtypeVar[10]),32);
    bufp->chgIData(oldp+22,(__VdtypeVar[9]),32);
    bufp->chgIData(oldp+23,(__VdtypeVar[8]),32);
    bufp->chgIData(oldp+24,(__VdtypeVar[7]),32);
    bufp->chgIData(oldp+25,(__VdtypeVar[6]),32);
    bufp->chgIData(oldp+26,(__VdtypeVar[5]),32);
    bufp->chgIData(oldp+27,(__VdtypeVar[4]),32);
    bufp->chgIData(oldp+28,(__VdtypeVar[3]),32);
    bufp->chgIData(oldp+29,(__VdtypeVar[2]),32);
    bufp->chgIData(oldp+30,(__VdtypeVar[1]),32);
    bufp->chgIData(oldp+31,(__VdtypeVar[0]),32);
}

void Vtb_riscv_core___024root__trace_cleanup(void* voidSelf, VerilatedVcd* /*unused*/) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_riscv_core___024root__trace_cleanup\n"); );
    // Body
    Vtb_riscv_core___024root* const __restrict vlSelf VL_ATTR_UNUSED = static_cast<Vtb_riscv_core___024root*>(voidSelf);
    Vtb_riscv_core__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    vlSymsp->__Vm_activity = false;
    vlSymsp->vlInst.TOP.__VtraceActivity[0U] = 0U;
    vlSymsp->vlInst.TOP.__VtraceActivity[1U] = 0U;
    vlSymsp->vlInst.TOP.__VtraceActivity[2U] = 0U;
}
