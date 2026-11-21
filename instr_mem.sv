`timescale 1ns / 1ps

module instr_mem(
    /* verilator lint_off UNUSEDSIGNAL */
    input  logic [31:0] addr,   // Program Counter (PC) input address
    /* verilator lint_on UNUSEDSIGNAL */
    output logic [31:0] instr  // 32-bit instruction output
    );
    
    // 256-word instruction memory (1 KB total)
    logic [31:0] mem [0:255];

    initial begin
        string hexfile;
        int test = 0;

        // Initialize memory with NOPs (addi x0, x0, 0)
        for (int i = 0; i < 256; i++) mem[i] = 32'h0000_0013;
        if($value$plusargs("HEX=%s", hexfile))
            $readmemh(hexfile, mem);
        else begin
        // Pick the program from the command line: +TEST=0, +TEST=1 or +TEST=2
        void'($value$plusargs("TEST=%d", test));

        case (test)
            0: begin  // Original: ALU, forwarding, store, load
                mem[0] = 32'h00a00093; // addi x1, x0, 10
                mem[1] = 32'h01400113; // addi x2, x0, 20
                mem[2] = 32'h002081b3; // add  x3, x1, x2
                mem[3] = 32'h00302023; // sw   x3, 0(x0)
                mem[4] = 32'h00002203; // lw   x4, 0(x0)
                mem[5] = 32'h00700313; // addi x6, x0, 7    end marker
            end
            1: begin  // All branch types
                mem[0]  = 32'h00500093; // addi x1, x0, 5
                mem[1]  = 32'h00700113; // addi x2, x0, 7
                mem[2]  = 32'hfff00393; // addi x7, x0, -1
                mem[3]  = 32'h00209463; // bne  x1, x2, +8   taken
                mem[4]  = 32'h00100193; // addi x3, x0, 1    SKIPPED
                mem[5]  = 32'h0020c463; // blt  x1, x2, +8   taken
                mem[6]  = 32'h00100213; // addi x4, x0, 1    SKIPPED
                mem[7]  = 32'h0020d463; // bge  x1, x2, +8   NOT taken
                mem[8]  = 32'h00100293; // addi x5, x0, 1    executes
                mem[9]  = 32'h0013c463; // blt  x7, x1, +8   taken (-1 < 5 signed)
                mem[10] = 32'h00100413; // addi x8, x0, 1    SKIPPED
                mem[11] = 32'h0013e463; // bltu x7, x1, +8   NOT taken (unsigned)
                mem[12] = 32'h00100493; // addi x9, x0, 1    executes
                mem[13] = 32'h00700313; // addi x6, x0, 7    end marker
            end
            2: begin  // JAL / JALR
                mem[0] = 32'h00500093; // addi x1, x0, 5
                mem[1] = 32'h00c0056f; // jal  x10, +12      jump to mem[4], x10 = 8
                mem[2] = 32'h00100193; // addi x3, x0, 1     SKIPPED
                mem[3] = 32'h00100213; // addi x4, x0, 1     SKIPPED
                mem[4] = 32'h00100293; // addi x5, x0, 1     JAL target
                mem[5] = 32'h02000593; // addi x11, x0, 32
                mem[6] = 32'h00058667; // jalr x12, 0(x11)   jump to 32, x12 = 28
                mem[7] = 32'h00100413; // addi x8, x0, 1     SKIPPED
                mem[8] = 32'h00c504b3; // add  x9, x10, x12  = 36
                mem[9] = 32'h00700313; // addi x6, x0, 7     end marker
            end
            3: begin
                mem[0] = 32'h06300413; // addi x8,  x0, 99    make LUI's "rs1" bits point at a non-zero register
                mem[1] = 32'h06300f93; // addi x31, x0, 99
                mem[2] = 32'h123450b7; // lui   x1, 0x12345     x1 = 0x12345000
                mem[3] = 32'h00001117; // auipc x2, 0x1         x2 = pc(12) + 0x1000 = 0x0000100c
                mem[4] = 32'h67808193; // addi  x3, x1, 0x678   x3 = 0x12345678
                mem[5] = 32'hfffff237; // lui   x4, 0xFFFFF     x4 = 0xFFFFF000
                mem[6] = 32'h00000297; // auipc x5, 0           x5 = pc = 0x00000018
                mem[7] = 32'h00700313; // addi  x6, x0, 7       end marker
            end
            4: begin
                mem[0]  = 32'h876540b7; // lui  x1, 0x87654      x1 = 0x87654000
                mem[1]  = 32'h3a108093; // addi x1, x1, 0x3A1    x1 = 0x876543A1
                mem[2]  = 32'h00102023; // sw   x1, 0(x0)        mem[0] = 0x876543A1 (bytes A1 43 65 87)
                mem[3]  = 32'h00000103; // lb   x2, 0(x0)        x2 = 0xFFFFFFA1 (sign-extended)
                mem[4]  = 32'h00004183; // lbu  x3, 0(x0)        x3 = 0x000000A1 (zero-extended)
                mem[5]  = 32'h00100203; // lb   x4, 1(x0)        x4 = 0x00000043 (byte 1)
                mem[6]  = 32'h00201283; // lh   x5, 2(x0)        x5 = 0xFFFF8765 (upper half, sign-extended)
                mem[7]  = 32'h00205383; // lhu  x7, 2(x0)        x7 = 0x00008765
                mem[8]  = 32'h00002403; // lw   x8, 0(x0)        x8 = 0x876543A1
                mem[9]  = 32'hfff00493; // addi x9, x0, -1       x9 = 0xFFFFFFFF
                mem[10] = 32'h009002a3; // sb   x9, 5(x0)        mem[1] = 0x0000FF00
                mem[11] = 32'h23400513; // addi x10, x0, 0x234   x10 = 0x00000234
                mem[12] = 32'h00a01323; // sh   x10, 6(x0)       mem[1] = 0x0234FF00
                mem[13] = 32'h00402583; // lw   x11, 4(x0)       x11 = 0x0234FF00
                mem[14] = 32'h00700313; // addi x6, x0, 7        end marker
            end
            default: $fatal(1, "Unknown TEST=%0d (use 0, 1 or 2)", test);
        endcase
        end
    end

    // Word-aligned combinational read (addr >> 2)
    assign instr = mem[addr[9:2]];
    
endmodule
