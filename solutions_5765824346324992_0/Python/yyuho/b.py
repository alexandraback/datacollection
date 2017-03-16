for T in range(1, input() + 1):
    B, N = map(int, raw_input().split())
    Ms = map(int, raw_input().split())
    Bs = [0 for i in range(len(Ms))]

    mm = reduce(lambda x, y: x * y, list(set(Ms)))
    nm = sum([mm / i for i in Ms])

    N = N % nm
    if N == 0: N = nm

    n = 1 # next customer
    while n < N:
        m = min(Bs)
        i = Bs.index(m)
        Bs[i] += Ms[i]
        n += 1

    y = Bs.index(min(Bs)) + 1

    print "Case #%d: %d" % (T, y)
