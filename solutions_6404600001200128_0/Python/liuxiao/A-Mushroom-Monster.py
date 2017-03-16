
def solve_first(mi):
    count = 0
    for i in range(len(mi) - 1):
        if mi[i] <= mi[i + 1]:
            continue
        count += mi[i] - mi[i + 1]
    return count

def solve_second(mi):
    rate = 0
    for i in range(len(mi) - 1):
        if mi[i] <= mi[i + 1]:
            continue
        now = mi[i] - mi[i + 1]
        if now > rate:
            rate = now
    count = 0
    for i in range(len(mi) - 1):
        now = min(mi[i], rate)
        count += now
    return count

def solve(mi):
    first = solve_first(mi)
    second = solve_second(mi)
    return first, second

T = input()
for t in range(T):
    n = input()
    mi = map(int, raw_input().split())
    first, second = solve(mi[:n])
    print "Case #%d: %d %d" % (t + 1, first, second)
