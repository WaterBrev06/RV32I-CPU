module branch_unit (
    input  logic [31:0] a,        // forwarded rs1 value
    input  logic [31:0] b,        // forwarded rs2 value
    input  logic [2:0]  funct3,
    output logic        take      // 1 if the branch condition is true
);
    always_comb begin
        take = 1'b0;              // default: never infer a latch
        case (funct3)
            3'b000: take = (a == b);
            3'b001: take = (a != b);
            3'b100: take = (signed'(a) < signed'(b));
            3'b101: take = (signed'(a) >= signed'(b));
            3'b110: take = (a < b);
            3'b111: take = (a >= b);
            default: take = 1'b0;
        endcase
    end
endmodule
