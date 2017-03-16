#from math import round
from functools import reduce
def LCM(x, y):
   if x > y:
       greater = x
   else:
       greater = y
   while(True):
       if((greater % x == 0) and (greater % y == 0)):
           lcm = greater
           break
       greater += 1
   return lcm


def solve(B, N, M):
    M = list(M)
    lcm = reduce(LCM, M)
    p = sum(lcm//m for m in M)
    if N % p == 0:
        N = p
    else:
        N %= p
    status = [0 for _ in range(B)]
    while N > 0:
        m = min(status)
        i = status.index(m)
        if N == 1:
            return i+1
        status = [s-m for s in status]
        status[i] = M[i]
        N -= 1


if __name__ == '__main__':
    for case in range(int(input())):
        B, N = map(int, input().split())
        M = map(int, input().split())
        print("Case #%d: %s" % (case+1, solve(B, N, M)))

