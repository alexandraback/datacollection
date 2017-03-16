import sys
ca = int(sys.stdin.readline())
for nu in range(ca):
    n = int(sys.stdin.readline())
    a = [int(i) for i in sys.stdin.readline().strip().split(' ')]
    res1 = 0
    res2 = -1
    for i in range(1,n):
        if a[i-1] > a[i]:
            res1 += a[i-1] - a[i]
    for j in range(10010):
        res = 0
        flag = 1
        for i in range(1,n):
            if a[i-1] <= j:
                res += a[i-1]
            else:
                res += j
                left = a[i-1] - j
                if left > a[i]:
                    flag = 0
                    break
        if flag:
            if res2<0 or res2>res:
                res2 = res
    print 'Case #%d: %d %d' %(nu+1,res1,res2)

