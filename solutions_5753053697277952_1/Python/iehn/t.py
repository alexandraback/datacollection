import math,string,itertools,fractions,heapq,collections,re,array,bisect

t = int(input())

for i in range(1,t+1):
    n = int(input())
    p = list(map(int, input().split()))
    l = len(p)
    sa = []
    um = sum(p)
    while max(p) > 0:
        m = max(p)
        s = ""
        for j in range(l):
            if p[j] == m:
                s += chr(65+j)
                p[j] -= 1
                um -= 1
                if len(s) == 2 or um == 2:
                    break
                if p[j] == max(p) and um < p[j]*2:
                    p[j] -=1
                    um -= 1
                    s += chr(65+j)
                    break
        sa.append(s)

    print("Case #{0}: {1}".format(i, ' '.join(sa)))
