#!/usr/bin/python2.7

import sys

T = int(sys.stdin.readline())

for i in xrange(T):
    name = 'ABCDEFGHIJKLMNOPQRSTUVWXYZ'
    N    = int(sys.stdin.readline().strip())
    sumP = 0
    sP   = sys.stdin.readline().strip().split()
    P    = []
    inst = [] 
    for j in xrange(len(sP)):
        Pj = int(sP[j])
        P.append([Pj, name[j]])
        sumP += Pj
    P.sort()

    step = []
    done = False
    while not done:
        if P[-1][0] == 0:
            done = True
            if len(step) > 0:
                inst.append(step)
            break
        else:
            step.append(P[-1][1])
            P[-1][0] -= 1
            sumP     -= 1
            P.sort()
            if P[-1][0] <= sumP/2:
                inst.append(step)
                step = []

    print "Case #{0}: ".format(i+1),
    for j in xrange(len(inst)):
        inst[j].sort()
        step = ""
        for k in xrange(len(inst[j])):
            step += inst[j][k]
        print step,
    print

    
