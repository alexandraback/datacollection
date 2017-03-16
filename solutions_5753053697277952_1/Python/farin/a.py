#!/usr/bin/env python3

def solve(n):
    plan = []
    p = list(map(int, input().split()))
    #print(n, p)
    while True:
        mx = max(p)
        if not mx:
            break
        idxs = []
        vals = []
        for i, x in enumerate(p):
            if x == mx:
                idxs.append(i)
                vals.append(chr(ord('A') + i))
        if len(vals) == 2:
            plan.append(vals[0]+vals[1])
            p[idxs[0]] -= 1
            p[idxs[1]] -= 1
        else:
            plan.append(vals[0])
            p[idxs[0]] -= 1
    return ' '.join(plan)


testcases = int(input())

for case_n in range(1, testcases+1):
    case_data = map(int, input().split())
    #case_data = input().split()
    print("Case #%i: %s" % (case_n, solve(*case_data)))
