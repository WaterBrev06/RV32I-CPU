`timescale 1ns / 1ps

module tb_alu;

    // Testbench signals
    logic [31:0] a;
    logic [31:0] b;
    logic [3:0]  alu_ctrl;
    logic [31:0] alu_out;
    logic        zero;

    int error_count = 0;
    int test_count  = 0;

    // Instantiate Unit Under Test (UUT)
    alu uut (
        .a        (a),
        .b        (b),
        .alu_ctrl (alu_ctrl),
        .alu_out  (alu_out),
        .zero     (zero)
    );

    // ALU Encodings (matching alu.sv)
    localparam logic [3:0] ALU_ADD  = 4'b0000;
    localparam logic [3:0] ALU_SUB  = 4'b0001;
    localparam logic [3:0] ALU_AND  = 4'b0010;
    localparam logic [3:0] ALU_OR   = 4'b0011;
    localparam logic [3:0] ALU_XOR  = 4'b0100;
    localparam logic [3:0] ALU_SLL  = 4'b0101;
    localparam logic [3:0] ALU_SRL  = 4'b0110;
    localparam logic [3:0] ALU_SRA  = 4'b0111;
    localparam logic [3:0] ALU_SLT  = 4'b1000;
    localparam logic [3:0] ALU_SLTU = 4'b1001;

    // Task to apply inputs, wait for propagation, and verify outputs
    task automatic check_alu(
        input logic [31:0] in_a,
        input logic [31:0] in_b,
        input logic [3:0]  ctrl,
        input logic [31:0] exp_out,
        input logic        exp_zero,
        input string       op_name
    );
        a        = in_a;
        b        = in_b;
        alu_ctrl = ctrl;
        #10; // Allow 10ns for combinational output to settle

        test_count++;

        if (alu_out !== exp_out || zero !== exp_zero) begin
            $display("FAIL [%s]: A = 0x%h, B = 0x%h, Ctrl = %b", op_name, in_a, in_b, ctrl);
            $display("  Expected: Out = 0x%h, Zero = %b", exp_out, exp_zero);
            $display("  Got:      Out = 0x%h, Zero = %b", alu_out, zero);
            error_count++;
        end else begin
            $display("PASS [%s]: A = 0x%h, B = 0x%h -> Out = 0x%h, Zero = %b", op_name, in_a, in_b, alu_out, zero);
        end
    endtask

    initial begin
        $display("============================================");
        $display("   STARTING ALU SELF-CHECKING TESTBENCH     ");
        $display("============================================");

        // 1. ADD Operations
        check_alu(32'd15, 32'd10, ALU_ADD, 32'd25, 1'b0, "ADD Basic");
        check_alu(32'hFFFF_FFFF, 32'd1, ALU_ADD, 32'd0, 1'b1, "ADD Overflow to Zero");

        // 2. SUB Operations
        check_alu(32'd20, 32'd5, ALU_SUB, 32'd15, 1'b0, "SUB Basic");
        check_alu(32'd50, 32'd50, ALU_SUB, 32'd0, 1'b1, "SUB Zero Flag Check");

        // 3. Bitwise Logic
        check_alu(32'hF0F0_F0F0, 32'h0F0F_0F0F, ALU_AND, 32'h0000_0000, 1'b1, "AND All Clear");
        check_alu(32'hF0F0_F0F0, 32'h0F0F_0F0F, ALU_OR,  32'hFFFF_FFFF, 1'b0, "OR All Set");
        check_alu(32'hFFFF_0000, 32'hFF00_FF00, ALU_XOR, 32'h00FF_FF00, 1'b0, "XOR Check");

        // 4. Shift Operations (Includes testing b[4:0] masking for shift counts > 31)
        check_alu(32'h0000_0001, 32'd4,  ALU_SLL, 32'h0000_0010, 1'b0, "SLL Basic");
        check_alu(32'h8000_0000, 32'd2,  ALU_SRL, 32'h2000_0000, 1'b0, "SRL Logical Shift");
        check_alu(32'h8000_0000, 32'd2,  ALU_SRA, 32'hE000_0000, 1'b0, "SRA Arithmetic Sign Extension");
        check_alu(32'h0000_000F, 32'd36, ALU_SLL, 32'h0000_00F0, 1'b0, "SLL 5-bit Shift Masking (Shift by 4)");

        // 5. Signed Comparison (SLT)
        check_alu(-32'd10, 32'd5, ALU_SLT, 32'd1, 1'b0, "SLT Signed (-10 < 5)");
        check_alu(32'd5, -32'd10, ALU_SLT, 32'd0, 1'b1, "SLT Signed (5 < -10)");

        // 6. Unsigned Comparison (SLTU)
        // 0xFFFFFFFF is -1 in signed notation, but 4,294,967,295 in unsigned notation
        check_alu(32'hFFFF_FFFF, 32'd5, ALU_SLTU, 32'd0, 1'b1, "SLTU Unsigned (0xFFFFFFFF < 5)");
        check_alu(32'd5, 32'hFFFF_FFFF, ALU_SLTU, 32'd1, 1'b0, "SLTU Unsigned (5 < 0xFFFFFFFF)");

        // Verification Summary
        $display("============================================");
        if (error_count == 0) begin
            $display("SUCCESS: All %0d test cases passed!", test_count);
        end else begin
            $display("FAILURE: %0d out of %0d test cases failed.", error_count, test_count);
        end
        $display("============================================");

        $finish;
    end

endmodule