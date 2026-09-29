`timescale 1ns / 1ps

module ex_mem_reg(
    input  logic        clk,
    input  logic        rst,

    // Control Inputs
    input  logic        reg_write_in,
    input  logic        mem_to_reg_in,
    input  logic        mem_read_in,
    input  logic        mem_write_in,
    input  logic        branch_in,

    // Data Inputs
    input  logic [31:0] branch_target_in,
    input  logic        zero_in,
    input  logic [31:0] alu_out_in,
    input  logic [31:0] rs2_data_in,
    input  logic [4:0]  rd_addr_in,

    // Control Outputs
    output logic        reg_write_out,
    output logic        mem_to_reg_out,
    output logic        mem_read_out,
    output logic        mem_write_out,
    output logic        branch_out,

    // Data Outputs
    output logic [31:0] branch_target_out,
    output logic        zero_out,
    output logic [31:0] alu_out_out,
    output logic [31:0] rs2_data_out,
    output logic [4:0]  rd_addr_out

    );
    
    always_ff @(posedge clk or posedge rst) begin
        if (rst) begin
            reg_write_out     <= 1'b0;
            mem_to_reg_out    <= 1'b0;
            mem_read_out      <= 1'b0;
            mem_write_out     <= 1'b0;
            branch_out        <= 1'b0;

            branch_target_out <= 32'd0;
            zero_out          <= 1'b0;
            alu_out_out       <= 32'd0;
            rs2_data_out      <= 32'd0;
            rd_addr_out       <= 5'd0;
        end else begin
            reg_write_out     <= reg_write_in;
            mem_to_reg_out    <= mem_to_reg_in;
            mem_read_out      <= mem_read_in;
            mem_write_out     <= mem_write_in;
            branch_out        <= branch_in;

            branch_target_out <= branch_target_in;
            zero_out          <= zero_in;
            alu_out_out       <= alu_out_in;
            rs2_data_out      <= rs2_data_in;
            rd_addr_out       <= rd_addr_in;
        end
    end
    
endmodule
