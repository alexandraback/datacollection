"""
This script may use libraries publicly available at: https://github.com/grokit/dcore.

Does this solution solve:
   Small: ?.
   Big:   ?.
"""

import dcore.gcj_boot as boot

def readProblem(fh):

    fh.readline()
    a = [int(x) for x in fh.readline().strip().split()]

    return a

def meth1(a):
    t = 0
    for i, v in enumerate(a):
        if i < len(a)-1:
            drop = a[i] - a[i+1]
            if drop > 0:
                t += drop
    return t

def meth2(a):
    mDrop = 0
    for i, v in enumerate(a):
        if i < len(a)-1:
            drop = a[i] - a[i+1]
            if drop > mDrop:
                mDrop = drop

    t = 0
    for i, v in enumerate(a):
        if i < len(a)-1:
            drop = a[i] - a[i+1]

            if a[i] < mDrop:
                t += a[i]
            else:
                t += mDrop
    return t

def solve(a):
    m1 = meth1(a)
    m2 = meth2(a)

    return "%i %i" % (m1, m2)

boot.solve(solve, readProblem, '.*large')
