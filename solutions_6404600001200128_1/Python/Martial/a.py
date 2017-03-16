import sys
sys.stdin = open('A-large.in')
sys.stdout = open('out.txt', 'w')



n_cases = int(input())
for case in range(n_cases):
    print(case, end=' ', file=sys.stderr)
    n = int(input())
    m = list(map(int, list(input().split())))
    res = 0
    for i in range(n-1):
        if m[i] > m[i+1]:
            res += m[i] - m[i+1]
    d = 0
    for i in range(n-1):
        if m[i] - m[i+1] > d:
            d = m[i] - m[i+1]
    res2 = 0
    for i in range(n-1):
        res2 += min(d,m[i])
    print('Case #{}: {} {}'.format(case+1, res, res2))