for t in xrange(input()):
    n = input()
    M = map(int, raw_input().split())
    d = [M[i] - M[i + 1] for i in xrange(n - 1)]
    a = sum([max(x, 0) for x in d])
    b = max(d)
    c = sum([min(b, x) for x in M[:-1]])
    print "Case #" + str(t + 1) + ": " + str(a) + " " + str(c)
