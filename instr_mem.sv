`timescale 1ns / 1ps

module instr_mem(
    input  logic [31:0] addr,   // Program Counter (PC) input address
    output logic [31:0] instr  // 32-bit instruction output
    );
    
    // 256-word instruction memory (1 KB total)
    logic [31:0] mem [0:255];

    initial begin
        // Initialize memory with NOPs (addi x0, x0, 0)
        for (int i = 0; i < 256; i++) begin
            mem[i] = 32'h0000_0013;
        end

        // Sample RISC-V test program:
        // Address 0x00: addi x1, x0, 10   -> 0x00a00093
        // Address 0x04: addi x2, x0, 20   -> 0x01400113
        // Address 0x08: add  x3, x1, x2   -> 0x002081b3
        // Address 0x0C: sw   x3, 0(x0)    -> 0x00302023
        // Address 0x10: lw   x4, 0(x0)    -> 0x00002203
        mem[0] = 32'h00a00093;
        mem[1] = 32'h01400113;
        mem[2] = 32'h002081b3;
        mem[3] = 32'h00302023;
        mem[4] = 32'h00002203;

        // To load from an external hex file in Vivado, uncomment:
        // $readmemh("program.mem", mem);
    end

    // Word-aligned combinational read (addr >> 2)
    assign instr = mem[addr[9:2]];
    
endmodule
