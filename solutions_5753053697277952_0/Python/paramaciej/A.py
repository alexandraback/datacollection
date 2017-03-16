#!/usr/bin/env python3

cases = int(input())

def ev1(p):
    r = list(p)
    if len(r) == 0:
        return None, None
    party = r[-1][1]
    if r[-1][0] > 0:
        r[-1] = list(r[-1])
        r[-1][0] -= 1
        if r[-1][0] == 0:
            del r[-1]
    else:
        return None, None
    return sorted(r), party

def correct(p):
    if p is None:
        return False
    if len(p) == 0:
        return True
    this = p[-1][0]
    half = sum([x[0] for x in p]) / 2
    return not this > half

def evac(p):
    p1, l1 = ev1(p)
    p2, l2 = ev1(p1) if p1 is not None else (None, None)
    if correct(p2):
        return "{}{} {}".format(l1, l2, evac(p2))
    elif correct(p1):
        return "{} {}".format(l1, evac(p1))
    return ""



for T in range(1, cases+1):
    N = int(input())
    P = [int(x) for x in input().split()]
    parties = sorted([[q, chr(ord('A') + i)] for i, q in enumerate(P)])
    print("Case #{}: {}".format(T, evac(parties)))
