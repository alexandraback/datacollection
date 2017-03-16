def read(f):
    return f(raw_input().strip())


def read_arr(f):
    return map(f, raw_input().strip().split(" "))


def f(T):
    N = read(int)
    m = read_arr(int)
    # method 1
    m1 = 0
    for i in xrange(N-1):
        if m[i] > m[i+1]:
            m1 += (m[i] - m[i+1])

    # method 2
    derivative = [m[i] - m[i+1] for i in range(N-1)]
    rate = max(max(derivative), 0)
    m2 = 0
    for i in xrange(N-1):
        m2 += min(rate, m[i])

    print "Case #%d: %d %d" % (T, m1, m2)

if __name__ == "__main__":
    for T in xrange(input()):
        f(T+1)
