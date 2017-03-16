#!/usr/bin/env python

import sys
from collections import defaultdict

def Solve(N, strings):
    tstrings = set()
    ch = defaultdict(list)
    for s in strings:
        x = list(s)
        t = x[0]
        pos = 0
        add = 0
        for i in range(len(x)-1):
            if x[i] != x[i+1]: 
                t += x[i+1]
                ch[pos].append(add)
                pos += 1
                add = 0
            else: 
                add += 1
        ch[pos].append(add)
        tstrings.add("".join(t))
    if len(tstrings) > 1: return "Fegla Won"
    
    tstring = list(tstrings)[0]
    #print ch
    res = 0
    for num in ch:
        cur = 100000
        for n in ch[num]:
            tr = sum([abs(x-n) for x in ch[num]])
            cur = min(cur, tr)
        res += cur
    return str(res)

inp = open(sys.argv[1], 'r').readlines()
T = int(inp[0].strip())
line = 0
for t in range(T):
    N = int(inp[line+1].strip())
    strings = [x.strip() for x in inp[line+2:line+2+N]]
    print "Case #"+str(t+1)+": "+Solve(N, strings)
    line += N+1


    
