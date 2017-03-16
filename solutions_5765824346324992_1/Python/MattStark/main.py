import sys
from queue import PriorityQueue
import functools
lines = open(sys.argv[1] + ".in", "rU").read().split("\n")
t, lines = int(lines[0]), lines[1:]

outfile = open(sys.argv[1] + ".out", "w")

def solve(b, n, m):
    if n <= b: return n
    # binary search over time
    lo = 0
    hi = n * 100001
#    print("for", n, b, m)
    while lo != hi - 1:
        mid = (lo + hi) // 2
#        print("for t={}, {} people processed".format(mid, sum(mid // mi for mi in m) + b))
        if sum(mid // mi for mi in m) + b < n:
            lo = mid
        else:
            hi = mid
    # we have lo = 1 before we are processed
    n -= sum(lo // mi for mi in m) + b
#    print(n)
    # at time lo, we are the nth person in line. Find the nth barber who becomes available at lo + 1 = hi
    for i, mi in enumerate(m):
        if hi % mi == 0:
            if n == 1: return i + 1  # barbers are 1-indexed
            n -= 1


for i in range(t):
    b, n = map(int, lines[i*2].split())
    m = list(map(int, lines[i*2 + 1].split()))
    print("Case #{}: {}".format(i + 1, solve(b, n, m)), file=outfile)

