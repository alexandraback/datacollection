#!/usr/bin/env python
import math
import pprint
pp = pprint.PrettyPrinter(indent=4)
def gcd(a, b):
    while b:
        a, b = b, a%b
    return a
def solve(line):
    n,k = line.split()
    n,k = int(n), int(k)

    line = raw_input()
    barbers = line.split()
    for i in xrange(n):
        barbers[i] = int(barbers[i])

    if k <= n:
        return k
    k -= n

    xlen = barbers[0]
    for i in xrange(1, n):
        g = gcd(xlen, barbers[i])
        xlen = xlen * barbers[i] / g;
    schedule = barbers[:]
    done = [False] * n
    path = []
    while k > 0 and xlen > 0:
        min_wait = min(schedule)
        for i in xrange(n):
            # if all(done):
            #     break
            if schedule[i] == min_wait:
                k -= 1
                if k == 0:
                    return i+1
                path.append(i + 1)
                done[i] = True
                schedule[i] = barbers[i]
            else:
                schedule[i] -= min_wait
        xlen -= min_wait
    # pp.pprint(path)
    # pp.pprint(k)
    return path[(k-1) % len(path)]

case_num = input()
for case in range(1, case_num + 1):
    line = raw_input()
    a = solve(line)
    print("Case #%i: %i" % (case, a))

