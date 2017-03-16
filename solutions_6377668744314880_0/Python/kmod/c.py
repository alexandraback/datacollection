import sys

if __name__ == "__main__":
    f = sys.stdin
    if len(sys.argv) >= 2:
        fn = sys.argv[1]
        if fn != '-':
            f = open(fn)

    T = int(f.readline())
    for _T in xrange(T):
        N = int(f.readline())
        coords = []
        for i in xrange(N):
            coords.append(map(int, f.readline().split()))

        print "Case #%d:" % (_T + 1,)

        if N <= 3:
            for i in xrange(N):
                print 0
            continue

        for i in xrange(N):
            best = 1000000098098
            pi = coords[i]
            for j in xrange(N):
                if i == j:
                    continue

                pj = coords[j]
                assert pj != pi
                l1, l2 = 0, 0

                for k in xrange(N):
                    if k == i or k == j:
                        l1 += 1
                        l2 += 1
                        continue
                    pk = coords[k]

                    x1 = pj[0] - pi[0]
                    y1 = pj[1] - pi[1]
                    x2 = pk[0] - pi[0]
                    y2 = pk[1] - pi[1]
                    r = x1 * y2 - x2 * y1
                    if r <= 0:
                        l1 += 1
                    if r >= 0:
                        l2 += 1

                # print i, j, l1, l2
                best = min(best, min(N - l1, N - l2))

            print best
