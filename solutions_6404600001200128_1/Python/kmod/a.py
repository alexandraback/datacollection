import sys

if __name__ == "__main__":
    f = sys.stdin
    if len(sys.argv) >= 2:
        fn = sys.argv[1]
        if fn != '-':
            f = open(fn)

    T = int(f.readline())
    for _T in xrange(T):
        L = int(f.readline())
        m = map(int, f.readline().split())
        assert L == len(m)

        def f1(m):
            n = 0
            c = m[0]
            for x in m:
                if x < c:
                    n += c - x
                c = x
            return n

        def f2(m):
            eat_per_period = 0
            for i in xrange(len(m) - 1):
                eat_per_period = max(eat_per_period, m[i] - m[i + 1])
            n = 0
            for x in m[:-1]:
                n += min(x, eat_per_period)
            return n

        print "Case #%d: %d %d" % (_T + 1, f1(m), f2(m))
