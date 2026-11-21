`timescale 1ns / 1ps

module data_mem(
    input  logic        clk,
    input  logic        mem_read,
    input  logic        mem_write,
    input  logic [2:0]  funct3,       // NEW: size and signedness
    input  logic [31:0] addr,
    input  logic [31:0] write_data,
    output logic [31:0] read_data
);
    logic [31:0] mem [0:255];
    initial for (int i = 0; i < 256; i++) mem[i] = 32'd0;

    logic unused_addr_hi;
    assign unused_addr_hi = ^addr[31:10];

    logic [7:0] word_idx;
    logic [1:0] off;                  // byte offset within the word
    assign word_idx = addr[9:2];
    assign off      = addr[1:0];

    // ---------------- Stores: byte enables + replicated data ----------------
    logic [3:0]  be;                  // which of the 4 bytes to write
    logic [31:0] wdata;

    always_comb begin
        case (funct3[1:0])
            2'b00: begin be = 4'b0001 << off;        wdata = {4{write_data[7:0]}};  end  // SB
            2'b01: begin be = 4'b0011 << off;        wdata = {2{write_data[15:0]}}; end  // SH  (Q1)
            default: begin be = 4'b1111;             wdata = write_data;            end  // SW
        endcase
    end

    always_ff @(posedge clk)
        if (mem_write)
            for (int i = 0; i < 4; i++)
                if (be[i]) mem[word_idx][8*i +: 8] <= wdata[8*i +: 8];

    // ---------------- Loads: select, then extend ----------------
    logic [31:0] word;
    logic [7:0]  byte_sel;
    logic [15:0] half_sel;

    assign word     = mem[word_idx];
    assign byte_sel = word[8*off +: 8];
    assign half_sel = off[1] ? word[31:16] : word[15:0];

    always_comb begin
        if (!mem_read) read_data = 32'd0;
        else case (funct3)
            3'b000:  read_data = {{24{byte_sel[7]}}, byte_sel};   // LB: sign-extend
            3'b100:  read_data = {{24{1'b0}}, byte_sel};                            // LBU         (Q2)
            3'b001:  read_data = {{16{half_sel[15]}}, half_sel};                            // LH          (Q3)
            3'b101:  read_data = {{16{1'b0}}, half_sel};                            // LHU
            default: read_data = word;                            // LW
        endcase
    end
endmodule
