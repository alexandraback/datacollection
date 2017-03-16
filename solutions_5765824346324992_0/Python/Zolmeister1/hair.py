import sys
import math
from bitarray import bitarray
import heapq

inName = sys.argv[1]
outName = inName[:inName.index('.')] + '.out'

fin = open(inName)
fout = open(outName, 'w')

cases = int(fin.readline())

def pp(case, out):
    ss= "Case #%d: %s\n" % (case+1, out)
    print ss,
    fout.write(ss)

def gcd(a, b):
    """Return greatest common divisor using Euclid's Algorithm."""
    while b:
        a, b = b, a % b
    return a

def lcm(a, b):
    """Return lowest common multiple."""
    return a * b // gcd(a, b)

def lcmm(ls):
    return reduce(lcm, ls)

for case in xrange(cases):
    [B, N] = map(int, fin.readline().strip().split(' '))
    barbers = map(int, fin.readline().strip().split(' '))

    LCM = lcmm(barbers)
    minSize = min(LCM, N)
    heap = []

    # cuts_per_min = sum(map(lambda x: 1.0/x, barbers))
    #print cuts_per_min
    # max_mins = minSize / cuts_per_min
    #print max_mins
    for barber, speed in enumerate(barbers):
        mins = 0
        while True:
            heapq.heappush(heap, (mins, barber))
            mins += speed
            if mins >= LCM:
                break

    last = heapq.nsmallest(len(heap), heap)
    ans = last[(N - 1) % len(last)][1] + 1

    pp(case, ans)

fout.close()
