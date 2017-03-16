import sys
sys.stdin = open('B-small-attempt0.in')
sys.stdout = open('out.txt', 'w')

from itertools import combinations

# for p in combinations(range(5),3):
#     print(p, file=sys.stderr)

n_cases = int(input())
for case in range(n_cases):
    print(case, end=' ', file=sys.stderr)
    r,c,n = list(map(int,input().split()))
    res = 10000
    t = range(r*c)
    for p in combinations(t, n):
        m = 0
        for i in range(n):
            m |= 1 << p[i]
        s = 0
        for i in range(r-1):
            for j in range(c):
                if (m & (1<<(c*i+j))) > 0 and (m & (1<<(c*(i+1)+j))) > 0:
                    s += 1
        for i in range(r):
            for j in range(c-1):
                if (m & (1<<(c*i+j))) > 0 and (m & (1<<(c*i+j+1))) > 0:
                    s += 1
        if s < res:
            res = s
    print('Case #{}: {}'.format(case+1, res))

