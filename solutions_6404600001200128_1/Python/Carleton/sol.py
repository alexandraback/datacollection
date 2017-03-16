import sys

def method1(tc):
    _, diffs = tc
    negs = filter(lambda n: n < 0, diffs)
    return -1*sum(negs)

def diffs(ms):
    return [ms[i+1] - ms[i] for i in range(0, len(ms) - 1)]
    
def method2(tc):
    ts, diffs = tc
    rate = min(diffs)
    if rate >= 0:
        return 0
    
    rate *= -1
    
    eatens = map(lambda n: n if n < rate else rate, ts[:-1])
    return sum(eatens)

def run_both(tests):
    ts = [map(int, t[1].split()) for t in tests]
    tcs = zip(ts, map(diffs, ts))
    results = [(method1(tc), method2(tc)) for tc in tcs]
    return results 

def run_test(input_file):
    lines = open(input_file, "r").readlines()
    
    lines = lines[1:]
    tests = [(lines[i], lines[i+1]) for i in range(0, len(lines) - 1, 2)]
    
    
    results = run_both(tests)
    lines = ["Case #{}: {} {}".format(i+1, r[0], r[1]) for i, r in enumerate(results)]
    print lines
    with open("output.txt", "w+") as fh:
        fh.write("\n".join(lines))


run_test(sys.argv[1])