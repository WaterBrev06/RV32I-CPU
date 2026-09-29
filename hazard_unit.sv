`timescale 1ns / 1ps

module hazard_unit(
    input  logic [4:0] if_id_rs1,      // Source register 1 in ID stage
    input  logic [4:0] if_id_rs2,      // Source register 2 in ID stage
    input  logic [4:0] id_ex_rd,       // Destination register in EX stage
    input  logic       id_ex_mem_read, // High if instruction in EX is a 'lw'
    input  logic       branch_taken,   // High when branch condition evaluates true
    output logic       pc_stall,       // Freezes PC update (1 cycle)
    output logic       if_id_stall,    // Freezes IF/ID pipeline register (1 cycle)
    output logic       if_id_flush,    // Flushes IF/ID pipeline register to NOP
    output logic       id_ex_flush     // Flushes ID/EX control signals to NOP
    );
    
    always_comb begin
        // Default execution: Pipeline advances normally
        pc_stall    = 1'b0;
        if_id_stall = 1'b0;
        if_id_flush = 1'b0;
        id_ex_flush = 1'b0;

        // --------------------------------------------------------------------
        // 1. Load-Use Data Hazard Detection
        // --------------------------------------------------------------------
        // If an instruction in EX stage is a LOAD, and its target register (rd)
        // matches either source register (rs1/rs2) of instruction in ID stage:
        if (id_ex_mem_read && (id_ex_rd != 5'd0) &&
           ((id_ex_rd == if_id_rs1) || (id_ex_rd == if_id_rs2))) begin
            pc_stall    = 1'b1; // Halt Program Counter
            if_id_stall = 1'b1; // Freeze IF/ID register to re-decode instruction
            id_ex_flush = 1'b1; // Convert instruction going into EX into a NOP bubble
        end

        // --------------------------------------------------------------------
        // 2. Control Hazard Detection (Branch / Jump Taken)
        // --------------------------------------------------------------------
        // When a branch condition evaluates true in EX stage, mispredicted
        // instructions fetched in IF and ID stages must be flushed.
        if (branch_taken) begin
            if_id_flush = 1'b1; // Flush IF/ID register
            id_ex_flush = 1'b1; // Flush ID/EX register
        end
    end
    
endmodule
