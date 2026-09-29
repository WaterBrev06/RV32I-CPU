`timescale 1ns / 1ps

module data_mem(
    input  logic        clk,
    input  logic        mem_read,   // Read enable signal
    input  logic        mem_write,  // Write enable signal
    input  logic [31:0] addr,       // Address calculated by ALU
    input  logic [31:0] write_data, // Data to store (rs2)
    output logic [31:0] read_data   // Loaded data output
    );
    
    // 256-word data RAM (1 KB total)
    logic [31:0] mem [0:255];

    initial begin
        for (int i = 0; i < 256; i++) begin
            mem[i] = 32'd0;
        end
    end

    // Combinational Read for MEM stage timing
    assign read_data = (mem_read) ? mem[addr[9:2]] : 32'd0;

    // Synchronous Write on Clock Edge
    always_ff @(posedge clk) begin
        if (mem_write) begin
            mem[addr[9:2]] <= write_data;
        end
    end
    
endmodule
