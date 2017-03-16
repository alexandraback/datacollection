import sys, string
from copy import copy, deepcopy
import gmpy
import time

import sys
sys.setrecursionlimit(1000000)

def readlist():
	return [int(x) for x in sys.stdin.readline().strip().split(" ")]

def readbinlist():
	return [int(x,2) for x in sys.stdin.readline().strip().split(" ")]

def readint():
	return int(sys.stdin.readline())

T = readint()

def pr(M):
    for r in M:
        print r

def score(i,R,C):
    s = 0
    b = bin(i)[3:]
    
    M = []
    for i in range(R):
        M.append(b[i*C : (i+1)*C])

    #~ print b
    #~ pr(M)
    #~ print R, C
    for i in range(R):
        for j in range(C):
            if j < C-1 and M[i][j] == '1' and M[i][j+1] == '1':
                s += 1
            if i < R-1 and M[i][j] == '1' and M[i+1][j] == '1':
                s += 1
    return s

for t in range(T):
    R, C, N = readlist()
    
    print >> sys.stderr, "Solving case #%d..." % (t+1)
    print ("Case #%d:" % (t+1)),

    A = R*C
    
    s = 1e10
    for i in range(1<<A):
        if gmpy.popcount(i) == N:
            s = min(s, score(i | (1<<A), R, C))
            if s == 0: break
    print s
