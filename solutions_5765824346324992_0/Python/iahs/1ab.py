from sys import stdin
import heapq
def gcd(a, b):
    """Return greatest common divisor using Euclid's Algorithm."""
    while b:
        a, b = b, a % b
    return a

def lcm(a, b):
    """Return lowest common multiple."""
    return a * b / gcd(a, b)

def lcmm(args):
    """Return lcm of args."""
    return reduce(lcm, args)

T = int(stdin.readline())
for case in xrange(1, T+1):
    b, n = map(int, stdin.readline().split(' '))
    m = map(int, stdin.readline().split(' '))
    pd = lcmm(m)
    mod = sum((pd / mk for mk in m))
    n = (n - 1) % mod + 1
    h = [(0, k+1, m[k]) for k in xrange(len(m))]
    heapq.heapify(h)
    top = heapq.heappop(h)
    for i in xrange(n - 1):
        top = heapq.heappushpop(h, (top[0] + top[2], top[1], top[2]))
    print "Case #%d: %d" % (case, top[1])
