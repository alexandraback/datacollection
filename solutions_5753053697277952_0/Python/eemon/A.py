#!/usr/bin/env python
# -*- coding: utf-8 -*-

def check(P):
    s = sum(P)
    if s == 0:
        return True
    return all(p/s <= 0.5 for p in P)

T = int(input())

for case in range(T):
    N = int(input())
    p = list(map(int,input().split()))
    ans = []
    alphabet = [chr(ord('A') + i) for i in range(26)]

    
    tmp = ""
    while True:
        idx, num = max(enumerate(p), key = lambda x:x[1])
        p[idx] -= 1

        if check(p):
            ans.append(tmp + alphabet[idx])
            tmp = ""
        else:
            tmp = alphabet[idx]

        if sum(p) == 0:
            break
    print("Case #{0}: {1}".format(case+1, ' '.join(ans)))


