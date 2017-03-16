import sys
ca = int(sys.stdin.readline())
for nu in range(ca):
    def can(x):
        sum = 0
        for i in range(n):
            sum += (x+a[i]-1)/a[i]
        if sum >= m:
            return True
        return False

    n,m = sys.stdin.readline().strip().split(' ')
    n = int(n)
    m = int(m)
    a = [int(i) for i in sys.stdin.readline().strip().split(' ')]
    l = -1
    r = 100000 * 1000000000
    while l < r - 1:
        mid = (l+r)/2
        if can(mid):
            r = mid
        else:
            l = mid

    sum = 0
    d = 0
    for i in range(n):
        sum += (r+a[i]-1)/a[i]
        if r%a[i] == 1 or a[i] == 1:
            d += 1
    sum -= d
    for i in range(n):
        if r % a[i] == 1 or a[i] == 1:
            sum += 1
            if sum == m:
                print 'Case #%d: %d' %(nu+1,i+1)
                break

