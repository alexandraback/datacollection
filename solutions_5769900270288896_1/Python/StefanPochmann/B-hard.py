from functools import *
from itertools import *

#f = open('B.in')
#def input(): return next(f)

@lru_cache(16**3)
def calc(R, C, N):
    #print(R, C, N)
    best = 999
    for A in combinations(range(R*C), N):
        unh = sum((a%C and a-1 in A)+(a+C in A) for a in A)
        #print(A, unh)
        best = min(best, unh)
    return best

def doit(N, *u):
    #print(u)
    unh = 0
    for n, un in u:
        unh += max(0, min(N, n)) * un
        N -= n
        #print('  ', unh, N)
    unh += max(0, N) * 4
    return unh

def calc(R, C, N):
    if C == 1:
        R, C = C, R
    if R == 1:
        if C % 2:
            return doit(N, ((C+1)//2, 0), (99, 2))
        return doit(N, ((C+1)//2, 0), (1, 1), (99, 2))
    t = R*C
    if R%2 != C%2:
        if R%2:
            R, C = C, R
        return doit(N, (t//2, 0), (2, 2), (R+C-4, 3))
    if not R%2:
        return doit(N, (t//2, 0), (2, 2), (R+C-4, 3))
    return min(doit(N, (t//2, 0), (4, 2), (R+C-6, 3)),
               doit(N, (t//2+1, 0), (R+C-2, 3)))

if 0:
    import random
    for i in range(1000):
        R = 15
        C = 15
        N = R*C
        print(i, calc(R, C, N))

R, C = 5, 5
for N in range(R*C, -1, -1):
    best = 9999
    #for A in combinations(range(R*C), N):
    #    unh = sum((a%C and a-1 in A)+(a+C in A) for a in A)
    #    best = min(best, unh)
    #print(N, best, calc(R, C, N))


for x in range(1, int(input()) + 1):
    R, C, N = map(int, input().split())
    print('Case #%d:' % x, calc(R, C, N))

'''
5x5:
---
25 40
24 36
23 32
22 28
21 24
20 20
19 17
18 14
17 11
16 8
15 6
14 3
13 0
12 0
11 0
10 0
9 0
8 0
7 0
6 0
5 0
4 0
3 0
2 0
1 0
0 0
'''
