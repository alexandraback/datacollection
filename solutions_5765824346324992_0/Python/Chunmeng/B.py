def gcd(a, b):
    while b:
        a, b = b, a % b
    return a
def lcm(a, b):
    return a* b // gcd(a, b)

for ii in xrange(input()):
    B, N = map(int, raw_input().split())
    M = map(int, raw_input().split())
    S = 0
    C = 0
    find = False
    L = reduce(lcm, M)
    R = reduce(gcd, M)
    T = 0
    for i in range(0, B):
        T += L // M[i]
    N = N % T
    if N == 0: N = T
    while True:
        for i in range(0, B):
            if S % M[i] == 0:
                C += 1
            if C == N:
                A = i + 1
                find = True
                break
        if find:
            break
        S += R
    print "Case #%d: %d" % (ii+1,A)
