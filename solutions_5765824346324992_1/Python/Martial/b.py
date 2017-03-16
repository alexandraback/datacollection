import sys
sys.stdin = open('B-large.in')
sys.stdout = open('out.txt', 'w')





n_cases = int(input())
for case in range(n_cases):
    print(case, end=' ', file=sys.stderr)
    b,n = list(map(int, list(input().split())))
    m = list(map(int, list(input().split())))
    if b>=n:
        res = n
    else:
        u=0
        v=10**20
        while v-u > 1:
            w = u + (v-u) // 2
            s = 0
            for bt in m:
                s += w // bt + 1
            if s >= n:
                v = w
            else:
                u = w
        done = 0
        c = []
        for i in range(b):
            done += v // m[i]
            if v % m[i] > 0:
                done += 1
            else:
                c.append(i+1)
        res = c[n - done -1]
    print('Case #{}: {}'.format(case+1, res))