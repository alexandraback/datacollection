#!/usr/bin/env python2

def balanced(P):
    tP = sum(P)
    for x in P:
        if x > tP/2:
            return False
    return True

def solve(N, P):
    steps = []
    tP = sum(P)
    while tP > 0:
        done = False
        for i in xrange(N):
            if P[i] > 1:
                cP = P[:]
                cP[i] -= 2
                if balanced(cP):
                    steps.append(chr(ord('A') + i)*2)
                    P = cP
                    done = True
                    tP -= 2
                    break

        if done:
            continue

        for i in xrange(N):
            for j in xrange(i+1, N):
                if P[i] > 0 and P[j] > 0:
                    cP = P[:]
                    cP[i] -= 1
                    cP[j] -= 1
                    if balanced(cP):
                        steps.append(chr(ord('A') + i) + chr(ord('A') + j))
                        P = cP
                        done = True
                        tP -= 2
                        break
            if done:
                break

        if done:
            continue

        for i in xrange(N):
            if P[i] > 0:
                cP = P[:]
                cP[i] -= 1
                if balanced(cP):
                    steps.append(chr(ord('A') + i))
                    P = cP
                    done = True
                    tP -= 1
                    break

    return " ".join(steps)

T = int(raw_input())
for i in xrange(1, T+1):
    N = int(raw_input())
    P = [int(x) for x in raw_input().strip().split()]

    print "Case #%s: %s" % (i, solve(N, P))
