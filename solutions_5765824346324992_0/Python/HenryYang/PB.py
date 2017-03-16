import sys
input = file(sys.argv[1])
def gcd(*numbers):
    """Return the greatest common divisor of the given integers"""
    from fractions import gcd
    return reduce(gcd, numbers)

# Least common multiple is not in standard libraries? It's in gmpy, but this is simple enough:

def lcm(*numbers):
    """Return lowest common multiple."""
    def lcm(a, b):
        return (a * b) // gcd(a, b)
    return reduce(lcm, numbers, 1)

def solve(n, s):
    L = lcm(*s)
    tot = 0
    for x in s:
        tot += L/x
    ind = n % tot
    if not ind:
        ind = tot
    l = []
    for i, v in enumerate(s):
        for k in range(tot):
            l.append((v*k,i,))
    l = sorted(l)
    return l[ind-1][1]+1

for case in range(int(input.readline())):
    vs = [int(x) for x in input.readline().split()]
    vals = [int(x) for x in input.readline().split()]
    print "Case #%d: %d" % (case+1, solve(vs[1], vals))
