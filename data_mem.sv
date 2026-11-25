`timescale 1ns / 1ps

// Simulation model of a 16 KB data SRAM: word-addressed, byte-enabled writes,
// combinational read. Real silicon would use an SRAM macro with this interface.
module data_mem(
    input  logic        clk,
    input  logic        we,
    input  logic        re,
    input  logic [3:0]  be,           // byte enables
    input  logic [31:0] addr,         // word-aligned byte address
    input  logic [31:0] wdata,
    output logic [31:0] rdata
);
    logic [31:0] mem [0:4095];

    initial begin
        string dfile;
        for (int i = 0; i < 4096; i++) mem[i] = 32'd0;
        if ($value$plusargs("DHEX=%s", dfile))
            $readmemh(dfile, mem, 'h800);    // test data at byte address 0x2000 = word 0x800
    end

    // addr[1:0]: the LSU word-aligns addresses. addr[31:14]: beyond the 16 KB memory.
    logic unused_addr;
    assign unused_addr = ^{addr[31:14], addr[1:0]};

    logic [11:0] word_idx;
    assign word_idx = addr[13:2];

    always_ff @(posedge clk)
        if (we)
            for (int i = 0; i < 4; i++)
                if (be[i]) mem[word_idx][8*i +: 8] <= wdata[8*i +: 8];

    assign rdata = re ? mem[word_idx] : 32'd0;
endmodule
