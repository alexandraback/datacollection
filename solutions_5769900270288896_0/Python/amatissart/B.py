# -*- coding: utf-8 -*-

import sys

def parseLine(s):
    line = s.split()
    return tuple(map(int,line))
    
def unhappiness(R,C,N):
    damier = (R*C+1)/2
    if N<= damier:
        return 0
    if R>C:
        R,C = C,R
    if R==1:
        if C%2 == 1:
            return (N-(C+1)/2)*2
        else:
            return (N-(C+1)/2)*2 - 1
    if R==3:
        res = 0
        coins = 0
        N -= (damier - (C-1)/2)
        bords = 1 + 2*((C-1)/2)
        if C %2 == 1:
            bords += 1
        else:
            coins = 2
        nc = min(coins,N)
        res += 2*nc
        N -= nc
        nb = min(bords,N)
        res += 2*nb
        N -= nb
        res += 2*min(N,(C-3)/2)
        N -= min(N,(C-3)/2)
        if C % 2 ==0:
            res += 3*min(1,N)
            N -=1
        return res + 4*N
    if R%2 == 1:
        N -= damier
        bords = R/2 + 2*((C-1)/2)
        coins = 0
        if C %2 == 1:
            bords += R/2
        else:
            bords += R/2 - 1
            coins = 2
        nc = min(coins,N)
        res = 2*nc
        N -= nc
        if N <= bords:
            return res + 3*N
        else:
            return res + 3*bords + 4*(N-bords)
    else:
        N -= damier
        bords = R + (C-2) - 2
        coins = 2
        nc = min(coins,N)
        res = 2*nc
        N -= nc
        if N <= bords:
            return res + 3*N
        else:
            return res + 3*bords + 4*(N-bords)
    return -1
         

filename = sys.argv[1]
with open(filename) as f:
    n_cases = int(f.readline())
    for i in xrange(n_cases):
        R,C,N = parseLine(f.readline())
        res = unhappiness(R,C,N)
        print 'Case #%d: %d' % (i+1,res)
        
