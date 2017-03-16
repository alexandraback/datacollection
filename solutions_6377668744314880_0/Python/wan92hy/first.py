import sys
sys.stdin = open('a.in', 'r')
sys.stdout = open('a.out', 'w')

ans = []
n = 0


def getline():
    return [int(c) for c in input().split()]

def same(q, u):
    t = 0
    for v in q:
        if v[0]*u[0]+v[1]*u[1]>=0:
            t += 1
    return t

def calc(q, n):
    ret = n
    for v in q:
        u = [v[1], -v[0]]
        ret = min(ret, n-1-same(q, u))
        u = [-v[1], v[0]]
        ret = min(ret, n-1-same(q, u))
    return ret

def solve():
    global ans
    global n
    [n] = getline()
    ans = [0 for i in range(n)]
    p = []
    for i in range(n):
        p.append(getline())
    for i in range(n):
        q = []
        for j in range(n):
            if i!=j:
                q.append([p[j][0]-p[i][0], p[j][1]-p[i][1]])
        ans[i] = calc(q, n)


for T in range(int(input())):
    sys.stderr.write(str(T))
    print('Case #%d:' % (T+1))
    solve()
    if n == 1:
        ans[0] = 0
    for i in range(n):
        print(ans[i])