`timescale 1ns / 1ps

module immgen(
    input logic[31:0] instr,
    output logic[31:0] imm_ext
    );
    
    localparam logic [6:0] OP_I_TYPE  = 7'b0010011; // ALU Immediate (addi, andi, etc.)
    localparam logic [6:0] OP_LOAD    = 7'b0000011; // Load instructions (lw, lh, lb)
    localparam logic [6:0] OP_JALR    = 7'b1100111; // Jump and Link Register
    localparam logic [6:0] OP_STORE   = 7'b0100011; // Store instructions (sw, sh, sb)
    localparam logic [6:0] OP_BRANCH  = 7'b1100011; // Branch instructions (beq, bne, etc.)
    localparam logic [6:0] OP_LUI     = 7'b0110111; // Load Upper Immediate
    localparam logic [6:0] OP_AUIPC   = 7'b0010111; // Add Upper Immediate to PC
    localparam logic [6:0] OP_JAL     = 7'b1101111; // Jump and Link
    
    always_comb begin 
        case (instr[6:0])
            OP_I_TYPE, OP_LOAD, OP_JALR: begin
                imm_ext = {{20{instr[31]}}, instr[31:20]};
            end
            
            OP_STORE: begin
                imm_ext = {{20{instr[31]}}, instr[31:25], instr[11:7]};
            end
            
            OP_BRANCH: begin
                imm_ext = {{19{instr[31]}}, instr[31], instr[7], instr[30:25], instr[11:8], 1'b0};
            end
            
            OP_LUI, OP_AUIPC: begin
                imm_ext = {instr[31:12], 12'b0};
            end
            
            OP_JAL: begin
                imm_ext = {{11{instr[31]}}, instr[31], instr[19:12], instr[20], instr[30:21], 1'b0};
            end
            
            default: begin
                imm_ext = 32'd0;
            end
        endcase
    end
    
endmodule
