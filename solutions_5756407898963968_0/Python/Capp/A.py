#!/usr/bin/env python

from sys import stdin

T = int(stdin.readline())

for t in range(T):
    n0 = int(stdin.readline()) - 1
    l0 = []
    for i in range(4): l0.append(stdin.readline())
    n1 = int(stdin.readline()) - 1
    l1 = []
    for i in range(4): l1.append(stdin.readline())
    d0 = l0[n0].split()
    d1 = l1[n1].split()

    ret = []
    for d in d0:
        if d in d1:
            ret.append(d)
            pass
        pass

    print "Case #%d:" % (t+1),
    if len(ret) == 0:
        print "Volunteer cheated!"
    elif len(ret) == 1:
        print ret[0]
    else:
        print "Bad magician!"
