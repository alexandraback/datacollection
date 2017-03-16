def gcd(a, b):
    if b == 0:
        return a
    else:
        return gcd(b, a % b)

def lcm(a, b):
    return a * b / gcd(a, b)

T = int(raw_input())

for t in xrange(1, T+1):
    B, N = map(int, raw_input().split())
    M = map(int, raw_input().split())
    N -= 1 # 0-based numbering

    fullcycle = reduce(lcm, M)

    N %= sum(fullcycle / i for i in M)

    busytil = [0] * B
    res = -1
    while res == -1:
        for i in xrange(B):
            if busytil[i] == 0:
                busytil[i] = M[i]
                N -= 1
                if N == -1:
                    res = i
                    break
            busytil[i] -= 1
    print 'Case #{}: {}'.format(t, res + 1)









