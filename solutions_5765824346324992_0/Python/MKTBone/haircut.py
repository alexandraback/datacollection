#!/usr/bin/python
import sys

# Haircut

def sim(b, n, m):
    loop, chose = 0, 0
    zeros = [0 for i in m]
    state = zeros[:]
    while True:
        for i in xrange(b):
            if state[i] == 0:
                state[i] = m[i]
                chose = i + 1
                loop += 1
                n -= 1
                if n == 0:
                    return chose
        for i in xrange(b):
            if state[i] > 0:
                state[i] -= 1
        if state == zeros:
            n %= loop
            loop = 0
            if n == 0:
                return chose

lines = [l.rstrip() for l in sys.stdin.readlines()]
for x in xrange(int(lines.pop(0))):
    b, n = [int(c) for c in lines[2*x].split(' ')]
    m = [int(c) for c in lines[2*x+1].split(' ')]
    y = sim(b, n, m)
    print "Case #%u: %u" % (x + 1, y)
