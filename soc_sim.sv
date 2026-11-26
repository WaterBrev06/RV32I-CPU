`timescale 1ns / 1ps

// Simulation-only top level: the core plus behavioural memories.
// Only riscv_core goes into synthesis / the ASIC flow.
module soc_sim(
    input  logic        clk,
    input  logic        rst,
    output logic [31:0] wb_result
);
    logic [31:0] imem_addr, imem_rdata;
    logic [31:0] dmem_addr, dmem_wdata, dmem_rdata;
    logic [3:0]  dmem_be;
    logic        dmem_we, dmem_re;

    riscv_core u_core (.*);          // every core port matches a signal name here

    instr_mem u_imem (
        .addr  (imem_addr),
        .instr (imem_rdata)
    );

    data_mem u_dmem (
        .clk   (clk),
        .we    (dmem_we),
        .re    (dmem_re),
        .be    (dmem_be),
        .addr  (dmem_addr),
        .wdata (dmem_wdata),
        .rdata (dmem_rdata)
    );

    // Alignment checks (simulation only): halfwords 2-byte aligned, words 4-byte aligned
    assert property (@(posedge clk) disable iff (rst)
        ((u_core.u_lsu.mem_read || u_core.u_lsu.mem_write) && u_core.u_lsu.funct3[1:0] == 2'b01)
        |-> (u_core.u_lsu.addr[0] == 1'b0));
    assert property (@(posedge clk) disable iff (rst)
        ((u_core.u_lsu.mem_read || u_core.u_lsu.mem_write) && u_core.u_lsu.funct3[1:0] == 2'b10)
        |-> (u_core.u_lsu.addr[1:0] == 2'b00));
    
        // forwarding_unit must never produce 11: the core's forwarding mux relies on one-hot selects
    always @(posedge clk) if (!rst) begin
        assert (u_core.forward_a != 2'b11) else $error("forward_a = 11");
        assert (u_core.forward_b != 2'b11) else $error("forward_b = 11");
    end
    
endmodule
