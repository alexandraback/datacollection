import sys
sys.stdin = open('B-large.in')
sys.stdout = open('out.txt', 'w')

from itertools import combinations

# for p in combinations(range(5),3):
#     print(p, file=sys.stderr)

def solve(r,c,n):
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
    return res

def solve2(r,c,n):

    m = 0
    for i in range(r*c,2):
        if n> 0:
            m |= 1 << i
            n -= 1
    for i in range(1,r*c,2):
        if n> 0:
            m |= 1 << i
            n -= 1

    s = 0
    for i in range(r-1):
        for j in range(c):
            if (m & (1<<(c*i+j))) > 0 and (m & (1<<(c*(i+1)+j))) > 0:
                s += 1
    for i in range(r):
        for j in range(c-1):
            if (m & (1<<(c*i+j))) > 0 and (m & (1<<(c*i+j+1))) > 0:
                s += 1
    return s

n_cases = int(input())
for case in range(n_cases):
    print(case, end=' ', file=sys.stderr)
    r,c,n = list(map(int,input().split()))
    res = solve2(r,c,n)
    print('Case #{}: {}'.format(case+1, res))

