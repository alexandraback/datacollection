import sys

T = int(sys.stdin.readline())

# return number of people who have started getting their hair cut at time minute
def cut_at_m(minute, M):
    if minute < 0:
        return 0
    cut = 0
    for (i, m_i) in enumerate(M):
        cut += minute / m_i + 1
    return cut

for n in range(1, T+1):
    [B, N] = [int(x) for x in sys.stdin.readline().split()]
    M = [int(m) for m in sys.stdin.readline().split()]

    lo = -1
    hi = 1
    while cut_at_m(hi, M) < N:
        hi *= 2

    while True:
        # invariant: number of haircuts started at lo minutes < N <= number started at hi minutes
        if hi - lo <= 1:
            break
        mid = (hi + lo) / 2
        if cut_at_m(mid, M) >= N:
            hi = mid
        else:
            lo = mid

    minute = lo + 1
    others = N - cut_at_m(minute-1, M) - 1

    # print lo, cut_at_m(lo, M), cut_at_m(lo+1, M), others, [minute % m for m in M]
    
    # Our haircut started at time minute, as did others.
    answer = -1
    for (i, m) in enumerate(M):
        if minute % m == 0:
            if others == 0:
                answer = i + 1
                break
            others -= 1

    print "Case #{}: {}".format(n, answer)
