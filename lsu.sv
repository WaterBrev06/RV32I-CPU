`timescale 1ns / 1ps

// Load/store unit (MEM stage): turns a load or store into a word access with
// byte enables, and extracts + extends the loaded byte/halfword.
module lsu(
    input  logic        mem_read,
    input  logic        mem_write,
    input  logic [2:0]  funct3,       // size and signedness
    input  logic [31:0] addr,         // byte address from the ALU
    input  logic [31:0] store_data,   // rs2
    input  logic [31:0] dmem_rdata,   // whole word from the data memory
    output logic [31:0] dmem_addr,    // word-aligned address
    output logic [31:0] dmem_wdata,
    output logic [3:0]  dmem_be,      // which of the 4 bytes to write
    output logic        dmem_we,
    output logic        dmem_re,
    output logic [31:0] load_data     // extended result, to MEM/WB
);
    logic [1:0] off;                  // byte offset within the word
    assign off       = addr[1:0];
    assign dmem_addr = {addr[31:2], 2'b00};
    assign dmem_we   = mem_write;
    assign dmem_re   = mem_read;

    // ---------------- Stores: byte enables + replicated data ----------------
    always_comb begin
        case (funct3[1:0])
            2'b00:   begin dmem_be = 4'b0001 << off; dmem_wdata = {4{store_data[7:0]}};  end  // SB
            2'b01:   begin dmem_be = 4'b0011 << off; dmem_wdata = {2{store_data[15:0]}}; end  // SH
            default: begin dmem_be = 4'b1111;        dmem_wdata = store_data;            end  // SW
        endcase
    end

    // ---------------- Loads: select, then extend ----------------
    logic [7:0]  byte_sel;
    logic [15:0] half_sel;
    assign byte_sel = dmem_rdata[8*off +: 8];
    assign half_sel = off[1] ? dmem_rdata[31:16] : dmem_rdata[15:0];

    always_comb begin
        case (funct3)
            3'b000:  load_data = {{24{byte_sel[7]}}, byte_sel};    // LB:  sign-extend
            3'b100:  load_data = {24'd0, byte_sel};                // LBU: zero-extend
            3'b001:  load_data = {{16{half_sel[15]}}, half_sel};   // LH:  sign-extend
            3'b101:  load_data = {16'd0, half_sel};                // LHU: zero-extend
            default: load_data = dmem_rdata;                       // LW
        endcase
    end
endmodule
