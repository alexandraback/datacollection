#!/usr/bin/python3
import sys
# import math
from heapq import *
import fractions
sys.setrecursionlimit(1000000)
DEBUG = 0


def rl(convert='', a=False):
    line = sys.stdin.readline().split()
    for i, c in enumerate(convert):
        if c == 'i':
            line[i] = int(line[i])
        elif c == 's':
            pass
        elif c == 'f':
            line[i] = float(line[i])
    if not a and len(line) == 1:
        return line[0]
    return line


def gcd(*args):
    if len(args) == 0:
        return 0
    g = args[0]
    for i in range(1, len(args)):
        g = fractions.gcd(g, args[i])
    return g


def lcm(*args):
    if len(args) == 0:
        return 0
    g = args[0]
    for i in range(1, len(args)):
        g *= args[i]
    return g / gcd(*args)


def avg(a):
    return sum(a) / len(a)


def debug(*args, **kwargs):
    level = 1
    if 'level' in kwargs:
        level = kwargs.pop('level')
    if DEBUG >= level:
        print(*args, **kwargs)
        # pass


def o(i, x):
    print('Case #{}: {}'.format(i + 1, x))


def toC(i):
    return chr(ord('A') + i)
# --------------------------------------------------------------------#
tc = rl('i')

for t in range(tc):
    n = rl('i')
    p = rl('i' * n, a=True)
    s = sum(p)
    h = list(zip((-x for x in p), range(n)))
    heapify(h)
    out = list()
    while s > 0:
        if s <= 3:
            c1, p1 = heappop(h)
            c2, p2 = heappop(h)
            if n > 2:
                c3, p3 = heappop(h)
            else:
                c3, p3 = 0, 2
            if c1 == c2 == c3:
                out.append(toC(p1))
                out.append('%s%s' % (toC(p2), toC(p3)))
            elif c1 == c2:
                out.append('%s%s' % (toC(p2), toC(p1)))
            else:
                out.append(toC(p1))
                out.append('%s%s' % (toC(p2), toC(p1)))
            break
        else:
            c1, p1 = heappop(h)
            c2, p2 = heappop(h)
            heappush(h, (c1 + 1, p1))
            heappush(h, (c2 + 1, p2))
            s -= 2
            out.append('%s%s' % (toC(p1), toC(p2)))
    o(t, ' '.join(str(x) for x in out))
