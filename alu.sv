`timescale 1ns / 1ps

module alu(
    input logic[31:0] a,
    input logic[31:0] b,
    input logic[3:0] alu_ctrl,
    output logic[31:0] alu_out,
    output logic        zero
    );
    
    localparam logic [3:0] ALU_ADD  = 4'b0000;
    localparam logic [3:0] ALU_SUB  = 4'b0001;
    localparam logic [3:0] ALU_AND  = 4'b0010;
    localparam logic [3:0] ALU_OR   = 4'b0011;
    localparam logic [3:0] ALU_XOR  = 4'b0100;
    localparam logic [3:0] ALU_SLL  = 4'b0101;
    localparam logic [3:0] ALU_SRL  = 4'b0110;
    localparam logic [3:0] ALU_SRA  = 4'b0111;
    localparam logic [3:0] ALU_SLT  = 4'b1000;
    localparam logic [3:0] ALU_SLTU = 4'b1001;
    
    always_comb begin
        case (alu_ctrl)
            ALU_ADD: alu_out = a + b;
            ALU_SUB: alu_out = a - b;
            ALU_AND: alu_out = a & b;
            ALU_OR: alu_out = a | b;
            ALU_XOR: alu_out = a ^ b;
            ALU_SLL: alu_out = a << b[4:0];
            ALU_SRL: alu_out = a >> b[4:0];
            ALU_SRA: alu_out = $signed(a) >>> b[4:0];
            ALU_SLT: alu_out = ($signed(a) < $signed(b)) ? 32'd1 : 32'd0;
            ALU_SLTU: alu_out = (a < b) ? 32'd1 : 32'd0;
            default: alu_out = 32'd0;
        endcase
    end
    assign zero = (alu_out == 32'd0);
endmodule
