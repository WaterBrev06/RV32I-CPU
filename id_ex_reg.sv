`timescale 1ns / 1ps

module id_ex_reg(
    input  logic        clk,
    input  logic        rst,
    input  logic        flush,         // Flush to bubble on hazard/branch
    input  logic        valid_in,

    // Control Inputs
    input  logic        reg_write_in,
    input  logic        mem_to_reg_in,
    input  logic        mem_read_in,
    input  logic        mem_write_in,
    input  logic        branch_in,
    input  logic        alu_src_in,
    input  logic [1:0]  alu_op_in,
    input  logic [1:0]  alu_a_sel_in,
    input  logic [1:0]  fwd_a_in,       // forwarding selects, precomputed in ID
    input  logic [1:0]  fwd_b_in,
    input  logic        jump_in,
    input  logic        jalr_in,
    input  logic        system_in,

    // Data Inputs
    input  logic [31:0] pc_in,
    input  logic [31:0] rs1_data_in,
    input  logic [31:0] rs2_data_in,
    input  logic [31:0] imm_in,
    input  logic [2:0]  funct3_in,
    input  logic        funct7_5_in,
    input  logic        op_bit5_in,
    input  logic [4:0]  rs1_addr_in,
    input  logic [4:0]  rd_addr_in,

    output logic        valid_out,
    output logic        jump_out,
    output logic        jalr_out,
    output logic        system_out,
    // Control Outputs
    output logic        reg_write_out,
    output logic        mem_to_reg_out,
    output logic        mem_read_out,
    output logic        mem_write_out,
    output logic        branch_out,
    output logic        alu_src_out,
    output logic [1:0]  alu_op_out,
    output logic [1:0]  alu_a_sel_out,
    output logic [1:0]  fwd_a_out,      // drive the EX forwarding muxes directly
    output logic [1:0]  fwd_b_out,

    // Data Outputs
    output logic [31:0] pc_out,
    output logic [31:0] rs1_data_out,
    output logic [31:0] rs2_data_out,
    output logic [31:0] imm_out,
    output logic [2:0]  funct3_out,
    output logic        funct7_5_out,
    output logic        op_bit5_out,
    output logic [4:0]  rs1_addr_out,
    output logic [4:0]  rd_addr_out
    );

    // ------------------------------------------------------------------------
    // Side-effect control bits: cleared by reset AND by flush.
    // Clearing these is all a bubble needs: it then writes no register,
    // touches no memory, redirects no PC, accesses no CSR and is not counted.
    // ------------------------------------------------------------------------
    always_ff @(posedge clk or posedge rst) begin
        if (rst) begin
            reg_write_out <= 1'b0;
            mem_read_out  <= 1'b0;
            mem_write_out <= 1'b0;
            branch_out    <= 1'b0;
            jump_out      <= 1'b0;
            jalr_out      <= 1'b0;
            system_out    <= 1'b0;
            valid_out     <= 1'b0;
        end else if (flush) begin
            reg_write_out <= 1'b0;
            mem_read_out  <= 1'b0;
            mem_write_out <= 1'b0;
            branch_out    <= 1'b0;
            jump_out      <= 1'b0;
            jalr_out      <= 1'b0;
            system_out    <= 1'b0;
            valid_out     <= 1'b0;
        end else begin
            reg_write_out <= reg_write_in;
            mem_read_out  <= mem_read_in;
            mem_write_out <= mem_write_in;
            branch_out    <= branch_in;
            jump_out      <= jump_in;
            jalr_out      <= jalr_in;
            system_out    <= system_in;
            valid_out     <= valid_in;
        end
    end

    // ------------------------------------------------------------------------
    // Everything else: reset only, never flushed. In a bubble these values
    // are ignored, because every consumer is gated by a control bit above.
    // Keeping flush off these ~150 bits cuts the flush net's fanout.
    // ------------------------------------------------------------------------
    always_ff @(posedge clk or posedge rst) begin
        if (rst) begin
            mem_to_reg_out <= 1'b0;
            alu_src_out    <= 1'b0;
            alu_op_out     <= 2'b00;
            alu_a_sel_out  <= 2'b00;
            fwd_a_out      <= 2'b00;
            fwd_b_out      <= 2'b00;
            pc_out         <= 32'd0;
            rs1_data_out   <= 32'd0;
            rs2_data_out   <= 32'd0;
            imm_out        <= 32'd0;
            funct3_out     <= 3'd0;
            funct7_5_out   <= 1'b0;
            op_bit5_out    <= 1'b0;
            rs1_addr_out   <= 5'd0;
            rd_addr_out    <= 5'd0;
        end else begin
            mem_to_reg_out <= mem_to_reg_in;
            alu_src_out    <= alu_src_in;
            alu_op_out     <= alu_op_in;
            alu_a_sel_out  <= alu_a_sel_in;
            fwd_a_out      <= fwd_a_in;
            fwd_b_out      <= fwd_b_in;
            pc_out         <= pc_in;
            rs1_data_out   <= rs1_data_in;
            rs2_data_out   <= rs2_data_in;
            imm_out        <= imm_in;
            funct3_out     <= funct3_in;
            funct7_5_out   <= funct7_5_in;
            op_bit5_out    <= op_bit5_in;
            rs1_addr_out   <= rs1_addr_in;
            rd_addr_out    <= rd_addr_in;
        end
    end

endmodule
