#!/usr/bin/env python

"""

[1, 1, 1, 1, 0, 1, 1, 1, 1]

2x2 2

x.
.x 0

2x2 3

xx
x. 2

2x3 3

x.x
xxx 0


2x3 4

x.x
x.x 2 ?

2x3 5

xxx
xx. 5 ?

2x3 6 

xxx
xxx 7 ?

xxx
x.x
xxx

xxx
xxx
xxx
xxx

.x.x
x.x.
.x.x
x.x.

x.x.x
.x = 2
x.x = 3 / 2 = 1.5 <= 
xxx = 3 / 3 = 1

x.x.
.x.x

x.x.x

x.x
x.x = 6.0 / 4 = 1.5 << 6.0 / 2

"""""

import sys

def max_fail(r, c):
    return (r - 1) * c + (c - 1) * r

def idx(x, y, r, c):
    return y * c + x

def nc(x, y, r, c, mfa):
    s = 0
    if x > 0:
        i = idx(x - 1, y, r, c)
        if mfa[i]:
            s += 1
    if y > 0:
        i = idx(x, y - 1, r, c)
        if mfa[i]:
            s += 1
    if x < c - 1:
        i = idx(x + 1, y, r, c)
        if mfa[i]:
            s += 1
    if y < r - 1:
        i = idx(x, y + 1, r, c)
        if mfa[i]:
            s += 1
    return s

def solve(r, c, n):
    if n - (r * c - n) <= 1:
        return 0
    mf = max_fail(r, c)
    if n == r * c:
        return mf

    mfa = [1] * (r * c)
    left = r * c - n
    for sw in [4, 3, 2, 1]:
        for x in range(c):
            for y in range(r):
                if mfa[idx(x, y, r, c)]: 
                    if nc(x, y, r, c, mfa) == sw:
                        mfa[idx(x, y, r, c)] = 0
                        mf -= sw
                        left -= 1
#                        print sw, mf, left
#                        for y in range(r):
#                            for x in range(c):
#                                print mfa[idx(x, y, r, c)],
#                            print 
#                        print
                    if left == 0:
#                        print r, c, n
#                        for y in range(r):
#                            for x in range(c):
#                                print mfa[idx(x, y, r, c)],
#                            print 

                        return mf

    print "retend?"
    return mf

infile = open(sys.argv[1])
T = infile.readline()
for x, line in enumerate(infile):
    r, c, n = [int(i) for i in line.strip().split()]
    print "Case #{case}: {solution}".format(
        case=x + 1,
        solution=solve(r, c, n)
    )
