`timescale 1ns / 1ps

module mem_wb_reg(
    input  logic        clk,
    input  logic        rst,

    // Control Inputs
    input  logic        reg_write_in,
    input  logic        mem_to_reg_in,

    // Data Inputs
    input  logic [31:0] read_data_in,
    input  logic [31:0] alu_out_in,
    input  logic [4:0]  rd_addr_in,

    // Control Outputs
    output logic        reg_write_out,
    output logic        mem_to_reg_out,

    // Data Outputs
    output logic [31:0] read_data_out,
    output logic [31:0] alu_out_out,
    output logic [4:0]  rd_addr_out
    );
    
    always_ff @(posedge clk or posedge rst) begin
        if (rst) begin
            reg_write_out  <= 1'b0;
            mem_to_reg_out <= 1'b0;

            read_data_out  <= 32'd0;
            alu_out_out    <= 32'd0;
            rd_addr_out    <= 5'd0;
        end else begin
            reg_write_out  <= reg_write_in;
            mem_to_reg_out <= mem_to_reg_in;

            read_data_out  <= read_data_in;
            alu_out_out    <= alu_out_in;
            rd_addr_out    <= rd_addr_in;
        end
    end
    
endmodule
