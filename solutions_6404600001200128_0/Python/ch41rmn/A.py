#/usr/bin/env python

import sys, os
from math import ceil

# the first line is the total number of cases
cases_total = int(sys.stdin.readline().strip())

case = 0                                # id of the case
while case < cases_total:
    case += 1                           # iterate case id

    # do your input here
    line = sys.stdin.readline()         # first line is len(m), discarded
    m = [ int(i) for i in sys.stdin.readline().strip().split() ]

    # difference between consecutive elements
    dm = [ m[i+1]-m[i] for i in range(len(m)-1) ]

    # method 1
    # only eat mushrooms if there is a negative difference
    # i.e. if there is a net increase in m, that means more has been added, but none eaten
    #      otherwise, none has been added, minimum eaten
    y = 0
    for i in dm:
        if i<0:
            y += abs(i)

    # method 2
    # the lowest dm/dt is the largest difference between two consecutive elements
    z = 0
    dmdt = abs(min(dm))
    for i in range(len(m)-1):
        if m[i]>dmdt:
            z+=dmdt
        else:
            z+=m[i]

    # __stuff__

    # set your output here
    out = str(y)+" "+str(z)

    print "Case #"+str(case)+": "+out   # the output format is 'Case #${case}: ${output}'
