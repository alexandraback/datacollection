#!/usr/bin/python

import sys

f = sys.stdin


T = int(f.readline())

for index in range(1, T+1):
    N = int(f.readline())
    
    s = []
    for i in range(N):
        s.append(f.readline())

    s1 = s[0]
    s2 = s[1]
    
    i =  0
    mods = 0
    won = False
    
    while True:
        if i == len(s1) and i == len(s2):
            won = True
            break
        if i < len(s1) and i < len(s2) and s1[i] == s2[i]:
            i += 1
        elif i > 0 and i < len(s1) and s1[i] == s1[i-1]:
            s1 = s1[:i] + s1[i+1:]
            mods += 1
        elif i > 0 and i < len(s2) and s2[i] == s2[i-1]:
            s2 = s2[:i] + s2[i+1:]
            mods += 1
        else:
            break
    
    if won:
        res = str(mods)
    else:
        res = "Fegla Won"
    
    print("Case #{}: {}".format(index, res))
    