t = int(input())
for ttt in range(t):
    b, n = map(int, raw_input().split())
    m = map(int, raw_input().split())
    m2 = [0]*b
    re = 0
    nx = 1
    ny = 0
    for i in m:
        nx *= i
    for j in m:
        ny += nx/j
    n = (n-1) % ny
    if n == 0:
        re = b
    else:
        for i in range(n):
            m2[m2.index(min(m2))] += m[m2.index(min(m2))]
        re = m2.index(min(m2)) + 1
    print 'Case #%d'%(ttt+1) + ':', re