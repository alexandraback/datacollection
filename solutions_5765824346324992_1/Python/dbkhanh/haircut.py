#!/usr/bin/env python

import os, sys
import heapq
from fractions import gcd
import random

def lcm(numbers):
    return reduce(lambda x, y: (x*y)/gcd(x,y), numbers, 1)

def solve(line1, line2):
    B, N = map(int, line1.split())
    ms = map(int, line2.split())
    lcm_time = lcm(ms)
    ahead = (N-1) % sum(lcm_time / m for m in ms)

    time_barbers = [(0, b) for b in range(1, B+1)]

    maxm = max(ms)
    timecap = int(ahead / sum(1./m for m in ms) / maxm) * maxm
    for i, m in enumerate(ms):
        c = timecap / m
        time_barbers[i] = (c*m, i+1)
        ahead -= c

    heapq.heapify(time_barbers)

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

def gen_big():
    print(100)
    for t in xrange(100):
        N = random.randint(1, 1000000000)
        print("1000 {}".format(N))
        ms = []
        for i in xrange(1000):
            ms.append(random.randint(1, 100000))
        print(" ".join(map(str, ms)))

if __name__ == "__main__":
    # gen_big()
    main()
