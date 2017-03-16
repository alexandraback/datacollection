"""
Code Jam 2016 Round 1C
Problem A. 
"""

from __future__ import print_function
import sys
import StringIO
from functools import partial
from autolog import logfunction
import numpy as np

msg = partial(print, file=sys.stderr)

#===========================================================================

parties = "ABCDEFGHIJKLMNOPQRSTUVWXYZ"

def doit(P, N):
    plan = []
    P = np.array(P)
    while np.max(P) > 0:
        msg(P)
        maxP = np.max(P)
        i1 = np.argmax(P)
        ind = (P == maxP)
        if (sum(ind) > 1 and maxP > 1) or (sum(ind) == 2 and maxP == 1):
            i2 = i1 + 1 + np.argmax(P[i1+1:] == maxP)
            plan.append(parties[i1] + parties[i2])
            P[i1] -= 1
            P[i2] -= 1
        else:
            plan.append(parties[i1])
            P[i1] -= 1
    return " ".join(plan)

sample = """4
2
2 2
3
3 2 2
3
1 1 2
3
2 3 1
"""

test = """1
2 2 2
"""

#===========================================================================

def stripnl(s):
    if s[-1]=="\n":
        return s[:-1]
    return s

def main(data = None):
    if data is None:
        f = sys.stdin
    else:
        f = StringIO.StringIO(data)
    nt = int(f.readline())
    for tc in xrange(1, nt+1):
        N = int(stripnl(f.readline()))
        P = map(int, stripnl(f.readline()).split(" "))
        res = doit(P, N)
        msg( "Case #%d: %s" % (tc, res) )
        print( "Case #%d: %s" % (tc, res) )

main()
