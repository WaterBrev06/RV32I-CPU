`timescale 1ns / 1ps

module tb_imm_gen;

    // Testbench signals
    logic [31:0] instr;
    logic [31:0] imm_ext;

    int error_count = 0;
    int test_count  = 0;

    // Instantiate Unit Under Test (UUT)
    immgen uut (
        .instr   (instr),
        .imm_ext (imm_ext)
    );

    // Opcodes for test instruction construction
    localparam logic [6:0] OP_I_TYPE = 7'b0010011;
    localparam logic [6:0] OP_STORE  = 7'b0100011;
    localparam logic [6:0] OP_BRANCH = 7'b1100011;
    localparam logic [6:0] OP_LUI    = 7'b0110111;
    localparam logic [6:0] OP_JAL    = 7'b1101111;

    // Task to apply instruction and verify immediate extraction
    task automatic check_imm(
        input logic [31:0] test_instr,
        input logic [31:0] exp_imm,
        input string       test_name
    );
        instr = test_instr;
        #10; // Allow combinational logic to settle

        test_count++;

        if (imm_ext !== exp_imm) begin
            $display("FAIL [%s]:", test_name);
            $display("  Instruction = 0x%h", test_instr);
            $display("  Expected    = 0x%h (%0d)", exp_imm, $signed(exp_imm));
            $display("  Got         = 0x%h (%0d)", imm_ext, $signed(imm_ext));
            error_count++;
        end else begin
            $display("PASS [%s]: Instr = 0x%h -> Imm = 0x%h (%0d)", 
                     test_name, test_instr, imm_ext, $signed(imm_ext));
        end
    endtask

    initial begin
        $display("============================================");
        $display(" STARTING IMMEDIATE GENERATOR TESTBENCH     ");
        $display("============================================");

        // --------------------------------------------------------------------
        // 1. I-Type Format (addi x1, x2, imm)
        // --------------------------------------------------------------------
        // Positive immediate: +100
        check_imm({12'sd100, 5'd2, 3'b000, 5'd1, OP_I_TYPE}, 32'd100, "I-Type Positive (+100)");
        // Negative immediate: -50 (12'hFC2)
        check_imm({-12'sd50, 5'd2, 3'b000, 5'd1, OP_I_TYPE}, -32'd50, "I-Type Negative (-50)");

        // --------------------------------------------------------------------
        // 2. S-Type Format (sw x2, imm(x1))
        // --------------------------------------------------------------------
        // Positive immediate: +20 -> imm[11:5] = 7'b0000000, imm[4:0] = 5'b10100
        check_imm({7'b0000000, 5'd2, 5'd1, 3'b010, 5'b10100, OP_STORE}, 32'd20, "S-Type Positive (+20)");
        // Negative immediate: -16 -> imm[11:5] = 7'b1111111, imm[4:0] = 5'b10000
        check_imm({7'b1111111, 5'd2, 5'd1, 3'b010, 5'b10000, OP_STORE}, -32'd16, "S-Type Negative (-16)");

        // --------------------------------------------------------------------
        // 3. B-Type Format (beq x1, x2, imm)
        // --------------------------------------------------------------------
        // Positive branch offset: +16 (13'b0_0_000000_1000_0)
        check_imm({1'b0, 6'b000000, 5'd2, 5'd1, 3'b000, 4'b1000, 1'b0, OP_BRANCH}, 32'd16, "B-Type Positive (+16)");
        // Negative branch offset: -12 (13'b1_1_111111_0100_0)
        check_imm({1'b1, 6'b111111, 5'd2, 5'd1, 3'b000, 4'b1010, 1'b1, OP_BRANCH}, -32'd12, "B-Type Negative (-12)");

        // --------------------------------------------------------------------
        // 4. U-Type Format (lui x1, imm)
        // --------------------------------------------------------------------
        // Upper immediate: 0x12345 -> outputs 0x12345000
        check_imm({20'h12345, 5'd1, OP_LUI}, 32'h1234_5000, "U-Type Upper Immediate (0x12345)");
        // Upper immediate with MSB set: 0x80000 -> outputs 0x80000000
        check_imm({20'h80000, 5'd1, OP_LUI}, 32'h8000_0000, "U-Type MSB Set (0x80000)");

        // --------------------------------------------------------------------
        // 5. J-Type Format (jal x1, imm)
        // --------------------------------------------------------------------
        // Positive jump offset: +2048
        check_imm({1'b0, 10'b0000000000, 1'b1, 8'b00000000, 5'd1, OP_JAL}, 32'd2048, "J-Type Positive (+2048)");
        // Negative jump offset: -100
        check_imm({1'b1, 10'b1111001110, 1'b1, 8'b11111111, 5'd1, OP_JAL}, -32'd100, "J-Type Negative (-100)");

        // Verification Summary
        $display("============================================");
        if (error_count == 0) begin
            $display("SUCCESS: All %0d immediate extraction tests passed!", test_count);
        end else begin
            $display("FAILURE: %0d out of %0d tests failed.", error_count, test_count);
        end
        $display("============================================");

        $finish;
    end

endmodule