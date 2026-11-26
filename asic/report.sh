#!/bin/bash
# Summarize the newest LibreLane run: timing, slew/cap violations, area, critical path
R=$(ls -d asic/runs/RUN_* | sort | tail -1)
echo "Run: $R"
python3 - "$R" << 'PY'
import json, sys
m = json.load(open(sys.argv[1] + "/final/metrics.json"))
def g(k): return m.get(k, "n/a")
print(f"Setup WNS  ss: {g('timing__setup__ws__corner:max_ss_100C_1v60')}  tt: {g('timing__setup__ws__corner:max_tt_025C_1v80')}")
print(f"Hold  WNS  ff: {g('timing__hold__ws__corner:min_ff_n40C_1v95')}")
print(f"Max slew violations (ss): {g('design__max_slew_violation__count__corner:max_ss_100C_1v60')}")
print(f"Max cap  violations (ss): {g('design__max_cap_violation__count__corner:max_ss_100C_1v60')}")
print(f"Std cells: {g('design__instance__count__stdcell')}   repair buffers: {g('design__instance__count__class:timing_repair_buffer')}")
print(f"Std-cell area (um^2): {g('design__instance__area__stdcell')}")
PY
D=$(ls -d $R/*stapostpnr*)/max_ss_100C_1v60
N=$R/final/nl/riscv_core.nl.v
S=$(grep -m1 "Startpoint" $D/max.rpt | awk '{print $2}')
E=$(grep -m1 "Endpoint"   $D/max.rpt | awk '{print $2}')
echo "Critical path (ss):"
echo "  start: $S -> $(grep -A8 " $S (" $N | grep -m1 '\.Q' | sed 's/.*\.Q(//; s/ *));//')"
echo "  end:   $E -> $(grep -A8 " $E (" $N | grep -m1 '\.Q' | sed 's/.*\.Q(//; s/ *));//')"
