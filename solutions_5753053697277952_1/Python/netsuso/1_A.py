#!/usr/bin/python3

import sys

ncases = int(sys.stdin.readline().strip())

for t in range(1, ncases+1):
    n = int(sys.stdin.readline().strip())
    plist = sys.stdin.readline().strip().split()

    p = []
    pn = 1
    for pstr in plist:
        p.append([int(pstr), pn])
        pn += 1

    p.sort(reverse=True)

    plan = []

    while p:
        if p[0][0] > p[1][0]:
            plan.append(chr(64 + p[0][1]))
            p[0][0] -= 1
        else:
            if len(p) > 2 and p[0][0] == p[2][0]:
                plan.append(chr(64 + p[1][1]))
                p[1][0] -= 1
            else:
                plan.append(chr(64 + p[0][1]) + chr(64 + p[1][1]))
                p[0][0] -= 1
                p[1][0] -= 1
        #print(plan)

        while len(p) and p[0][0] == 0:
            p.pop(0)

        if len(p) > 2 and p[2][0] > p[1][0]:
            p.sort(reverse=True)
        
    print("Case #{0}: {1}".format(t, ' '.join(plan)))

