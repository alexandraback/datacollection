if __name__ == '__main__':
    T = int(raw_input())
    for t in xrange(1, T + 1):
        N = int(raw_input())
        M = map(int, raw_input().split())
        eaten = []
        for i in xrange(1, len(M)):
            x = M[i - 1] - M[i]
            if x > 0:
                eaten.append(x)
        if not eaten:
            print "Case #%d: %d %d" % (t, 0, 0)
            continue

        method1 = sum(eaten)
        eaten_max = max(eaten)
        method2 = 0
        for i in xrange(len(M) - 1):
            method2 += min(M[i], eaten_max)

        print "Case #%d: %d %d" % (t, method1, method2)
