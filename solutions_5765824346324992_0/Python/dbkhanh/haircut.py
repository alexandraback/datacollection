#!/usr/bin/env python

import os, sys
import heapq
from fractions import gcd

def lcm(numbers):
    return reduce(lambda x, y: (x*y)/gcd(x,y), numbers, 1)

def solve(line1, line2):
    B, N = map(int, line1.split())
    ms = map(int, line2.split())
    lcm_time = lcm(ms)
    ahead = N - 1
    ahead = ahead % sum(lcm_time / m for m in ms)

    time_barbers = [(0, b+1) for b in range(B)]
    for i in xrange(ahead):
        t, b = heapq.heappop(time_barbers)
        heapq.heappush(time_barbers, (t + ms[b-1], b))

    return time_barbers[0][1]

def main():
    lines = open(sys.argv[1]).read().rstrip().splitlines()
    N = int(lines[0])
    for case in range(1, N+1):
        answer = solve(lines[2*case-1], lines[2*case])
        print("Case #{}: {}".format(case, answer))

if __name__ == "__main__":
    main()
