#!/usr/bin/env python

import os, sys

def solve(line):
    xs = [int(x) for x in line.split()]

    count1 = 0
    prev = 0
    for x in xs:
        if x < prev:
            count1 += prev - x
        prev = x

    rate = max((x - y) for x, y in zip(xs[:-1], xs[1:]))
    count2 = 0
    for x in xs[:-1]:
        if x > 0:
            count2 += min(x, rate)

    return "{} {}".format(count1, count2)

def main():
    lines = open(sys.argv[1]).read().rstrip().splitlines()
    N = int(lines[0])
    for case in range(1, N+1):
        answer = solve(lines[2*case])
        print("Case #{}: {}".format(case, answer))

if __name__ == "__main__":
    main()
