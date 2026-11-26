import re, sys
# usage: python3 asic/trace.py <netlist> [inst/pin | inst | net] ...   (no targets = top fanout nets)
nl = open(sys.argv[1]).read()
OUT = {"X", "Y", "Q", "Q_N", "COUT", "SUM", "HI", "LO"}
pins, cells, driver, loads = {}, {}, {}, {}
for cell, name, body in re.findall(r'(sky130_\w+)\s+(\S+)\s*\((.*?)\);', nl, re.S):
    cells[name] = cell
    pins[name] = {p: n.strip() for p, n in re.findall(r'\.(\w+)\(([^()]*)\)', body)}
    for p, n in pins[name].items():
        if not n.strip(): continue
        (driver.__setitem__(n.strip(), (name, p)) if p in OUT
         else loads.setdefault(n.strip(), []).append(name))

def is_buf(c): return re.search(r'__(buf|clkbuf|dlygate|dlymetal)', c)

def trace(net):
    chain = []
    while True:
        chain.append(f"{net}  (fanout {len(loads.get(net, []))})")
        if net not in driver:
            chain.append("<- top-level input port"); break
        inst, pin = driver[net]
        c = cells[inst].replace("sky130_fd_sc_hd__", "")
        if is_buf(cells[inst]):
            chain.append(f"<- {inst} [{c}]"); net = pins[inst]["A"]
        else:
            chain.append(f"<- SOURCE {inst} [{c}] .{pin}")
            ins = {p: n for p, n in pins[inst].items() if p not in OUT and p not in ("VPWR","VGND","VPB","VNB")}
            chain.append(f"   its inputs: {ins}"); break
    print("\n   ".join(chain)); print()

args = sys.argv[2:]
if not args:
    top = sorted(loads, key=lambda n: -len(loads[n]))[:15]
    for n in top: print(len(loads[n]), n)
for a in args:
    if "/" in a:
        i, p = a.split("/"); n = pins[i][p]
    elif a in pins:
        n = pins[a].get("A") or next(iter(pins[a].values()))
    else:
        n = a
    print(f"== {a}"); trace(n)
