`timescale 1ns / 1ps

module if_id_reg(
    input  logic        clk,
    input  logic        rst,
    input  logic        stall,     // Freeze register content on load-use hazard
    input  logic        flush,     // Flush instruction to NOP on branch/jump
    input  logic [31:0] pc_in,
    input  logic [31:0] instr_in,
    output logic [31:0] pc_out,
    output logic [31:0] instr_out
    );
    
    always_ff @(posedge clk or posedge rst) begin
        if (rst || flush) begin
            pc_out    <= 32'd0;
            instr_out <= 32'h0000_0013; // NOP (addi x0, x0, 0)
        end else if (!stall) begin
            pc_out    <= pc_in;
            instr_out <= instr_in;
        end
    end
    
endmodule
