import sys

if __name__ == "__main__":
    f = sys.stdin
    if len(sys.argv) >= 2:
        fn = sys.argv[1]
        if fn != '-':
            f = open(fn)

    T = int(f.readline())
    for _T in xrange(T):
        B, N = map(int, f.readline().split())
        M = map(int, f.readline().split())

        def started_at_end_of(n):
            t = len(M)
            for m in M:
                t += n // m
            return t

        if N <= B:
            print "Case #%d: %d" % (_T + 1, N)
            continue

        low = 0
        high = max(M) * N
        while True:
            assert started_at_end_of(low) < N
            assert started_at_end_of(high) >= N

            if high == low + 1:
                break

            g = (low + high + 1) // 2
            if started_at_end_of(g) >= N:
                high = g
            else:
                low = g

        # print low, high
        needed = N - started_at_end_of(low)
        # print low, high
        # print N, needed
        for i, m in enumerate(M):
            if high % m == 0:
                # print i, "done"
                needed -= 1
                if needed == 0:
                    print "Case #%d: %d" % (_T + 1, i + 1)
                    break
        else:
            assert 0
