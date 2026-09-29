`timescale 1ns / 1ps

module control_unit(
    input logic[6:0] opcode,
    output logic reg_write,
    output logic alu_src,
    output logic mem_to_reg,
    output logic mem_read,
    output logic mem_write,
    output logic branch,
    output logic jump,
    output logic[1:0] alu_op
    );
    
    localparam logic [6:0] OP_R_TYPE = 7'b0110011;
    localparam logic [6:0] OP_I_TYPE = 7'b0010011;
    localparam logic [6:0] OP_LOAD = 7'b0000011;
    localparam logic [6:0] OP_STORE = 7'b0100011;
    localparam logic [6:0] OP_BRANCH = 7'b1100011;
    localparam logic [6:0] OP_JAL = 7'b1101111;
    localparam logic [6:0] OP_JALR = 7'b1100111;
    
    always_comb begin
        reg_write  = 1'b0;
        alu_src    = 1'b0;
        mem_to_reg = 1'b0;
        mem_read   = 1'b0;
        mem_write  = 1'b0;
        branch     = 1'b0;
        jump       = 1'b0;
        alu_op     = 2'b00;
        
        case (opcode)
            OP_R_TYPE: begin
                reg_write = 1'b1;
                alu_src = 1'b0;
                alu_op = 2'b10;
            end
            
            OP_I_TYPE: begin
                reg_write = 1'b1;
                alu_src = 1'b1;
                alu_op = 2'b10;
            end
            
            OP_LOAD: begin
                reg_write = 1'b1;
                alu_src = 1'b1;
                mem_to_reg = 1'b1;
                mem_read = 1'b1;
                alu_op = 2'b00;
            end
            
            OP_STORE: begin
                alu_src = 1'b1;
                mem_write = 1'b1;
                alu_op = 2'b00;
            end
            
            OP_BRANCH: begin
                branch = 1'b1;
                alu_op = 2'b01;
            end
            
            OP_JAL: begin
                reg_write = 1'b1;
                jump = 1'b1;
                alu_op = 2'b01;
            end
            
            OP_JALR: begin
                reg_write = 1'b1;
                alu_src = 1'b1;
                jump = 1'b1;
                alu_op = 2'b01;
            end
            
            default: begin
            end
        endcase
    end
endmodule
