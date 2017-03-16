#!/usr/bin/python3

import sys
#int(sys.stdin.readline())
#[int(x) for x in sys.stdin.readline().split()]

def jj(n,j,k,N):
    r = 0
    for i in range(N):
        r += abs(n[i][j] - k)
    return r

def case():
    N = int(sys.stdin.readline())
    s = []
    c = []
    n = []
    for i in range(N):
        s.append(sys.stdin.readline().strip())
        x = s[i][0]
        count = 1
        c.append([])
        n.append([])
        for C in s[i][1:]:
            if C == x:
                count += 1
            else:
                c[i].append(x)
                n[i].append(count)
                x = C
                count = 1
        c[i].append(x)
        n[i].append(count)

    for i in range(1,N):
        if c[i] != c[0]:
            return "Fegla Won"
    #print(n)
    gcount = 0
    for j in range(len(c[0])):
        m = 100
        M = 0
        jcount = 100*100
        for i in range(N):
            m = min(m, n[i][j])
            M = max(M, n[i][j])
        for k in range(m, M+1):
            jcount = min(jcount, jj(n,j,k,N))
        gcount += jcount
    return gcount

T = int(sys.stdin.readline())
for i in range(1,T+1):
    print("Case #%s: %s" % (i, case()))
    

