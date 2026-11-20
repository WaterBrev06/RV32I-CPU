module sync_fifo #(
    parameter int DEPTH = 8,
    parameter int WIDTH = 8
)(
    input  logic             clk,
    input  logic             rst_n,
    input  logic             wr_en,
    input  logic [WIDTH-1:0] din,
    input  logic             rd_en,
    output logic [WIDTH-1:0] dout,
    output logic             full,
    output logic             empty
);
    localparam int AW = $clog2(DEPTH);       // address width: 3 bits for 8 entries

    logic [WIDTH-1:0] mem [DEPTH];           // the storage
    logic [AW-1:0]    wptr, rptr;            // 3-bit pointers wrap 7 → 0 by themselves
    logic [AW:0]      count;                 // Q1: why AW+1 bits (4), not AW (3)?

    // An operation is "accepted" only if the FIFO can take it (the count bug from earlier!)
    logic do_write, do_read;
    assign do_write = wr_en && 1'b1;                  // Q2: write enabled AND ...?
    // assign do_write = wr_en && !full;                  // Q2: write enabled AND ...?
    assign do_read  = rd_en && !empty;                  //     read enabled AND ...?

    // Storage: no reset needed, since the data is only valid once written
    always_ff @(posedge clk)
        if (do_write) mem[wptr] <= din;

    // Pointers and count
    always_ff @(posedge clk or negedge rst_n) begin
        if (!rst_n) begin
            wptr  <= '0;
            rptr  <= '0;
            count <= '0;
        end else begin
            if (do_write) wptr <= wptr + 1'b1;      // Q3: move the write pointer
            if (do_read)  rptr <= rptr + 1'b1;      //     move the read pointer

            case ({do_write, do_read})
                2'b10:   count <= count + 1'b1;      // Q4: write only
                2'b01:   count <= count - 1'b1;      //     read only
                default: count <= count;     // both or neither: unchanged
            endcase
        end
    end

    // Outputs
    assign full  = (count == DEPTH);                     // Q5
    assign empty = (count == 0);
    assign dout  = mem[rptr];                // FWFT: always show the oldest entry
endmodule
