`timescale 1ns / 1ps

module alu_control(
    input logic[1:0] alu_op,
    input logic[2:0] funct3,
    input logic funct7_5,
    input logic op_bit5,
    output logic[3:0] alu_ctrl
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
        case (alu_op)
            2'b00: alu_ctrl = ALU_ADD;
            2'b01: alu_ctrl = ALU_SUB;
            
            2'b10: begin
                case (funct3)
                    3'b000: begin
                        if (funct7_5 && op_bit5)
                            alu_ctrl = ALU_SUB;
                        else
                            alu_ctrl = ALU_ADD;
                    end
                    
                    3'b001: alu_ctrl = ALU_SLL;
                    3'b010: alu_ctrl = ALU_SLT;
                    3'b011: alu_ctrl = ALU_SLTU;
                    3'b100: alu_ctrl = ALU_XOR;
                    3'b101: begin
                        if (funct7_5)
                            alu_ctrl = ALU_SRA;
                        else 
                            alu_ctrl = ALU_SRL;
                        end
                    3'b110: alu_ctrl = ALU_OR;
                    3'b111: alu_ctrl = ALU_AND;
                    default: alu_ctrl = ALU_ADD;
                endcase 
            end
            default: alu_ctrl = ALU_ADD;
        endcase
   end         
endmodule
