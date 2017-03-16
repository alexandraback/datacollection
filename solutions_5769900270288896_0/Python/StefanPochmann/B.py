from functools import *
from itertools import *

#f = open('B.in')
#def input():
#    return next(f)

@lru_cache(16**3)
def calc(R, C, N):
    #print(R, C, N)
    best = 999
    for A in combinations(range(R*C), N):
        unh = sum((a%C and a-1 in A)+(a+C in A) for a in A)
        #print(A, unh)
        best = min(best, unh)
    return best

for x in range(1, int(input()) + 1):
    R, C, N = map(int, input().split())
    print('Case #%d:' % x, calc(R, C, N))
