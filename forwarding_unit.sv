`timescale 1ns / 1ps

module forwarding_unit(
    input  logic [4:0] id_ex_rs1,        // Source register 1 in EX stage
    input  logic [4:0] id_ex_rs2,        // Source register 2 in EX stage
    input  logic [4:0] ex_mem_rd,       // Destination register in MEM stage
    input  logic [4:0] mem_wb_rd,       // Destination register in WB stage
    input  logic       ex_mem_reg_write, // RegWrite signal in MEM stage
    input  logic       mem_wb_reg_write, // RegWrite signal in WB stage
    output logic [1:0] forward_a,        // Controls MUX for ALU input A
    output logic [1:0] forward_b         // Controls MUX for ALU input B
    
    );
    
    always_comb begin
        // Default: No forwarding (use values read from Register File)
        forward_a = 2'b00;
        forward_b = 2'b00;

        // --------------------------------------------------------------------
        // Forwarding Logic for ALU Input A (rs1)
        // --------------------------------------------------------------------
        // 1. EX Hazard (Forward from EX/MEM pipeline register)
        if (ex_mem_reg_write && (ex_mem_rd != 5'd0) && (ex_mem_rd == id_ex_rs1)) begin
            forward_a = 2'b10;
        end
        // 2. MEM Hazard (Forward from MEM/WB pipeline register)
        // Only forward if EX hazard condition is not met (EX stage has newest data)
        else if (mem_wb_reg_write && (mem_wb_rd != 5'd0) && (mem_wb_rd == id_ex_rs1)) begin
            forward_a = 2'b01;
        end

        // --------------------------------------------------------------------
        // Forwarding Logic for ALU Input B (rs2)
        // --------------------------------------------------------------------
        // 1. EX Hazard (Forward from EX/MEM pipeline register)
        if (ex_mem_reg_write && (ex_mem_rd != 5'd0) && (ex_mem_rd == id_ex_rs2)) begin
            forward_b = 2'b10;
        end
        // 2. MEM Hazard (Forward from MEM/WB pipeline register)
        else if (mem_wb_reg_write && (mem_wb_rd != 5'd0) && (mem_wb_rd == id_ex_rs2)) begin
            forward_b = 2'b01;
        end
    end
    
endmodule
