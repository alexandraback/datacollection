import math

def check(a, t):
    return int(sum([math.ceil(float(t)/x) for x in a]))


f = open('3.in')
out = open('3-out', 'w')
t = int(f.readline())
case = 1
for q in range(t):
    (b, n) = [int(x) for x in f.readline().strip().split()]
    m = [int(x) for x in f.readline().strip().split()]

    #print b, n
    t = 1
    while check(m, t) < n:
        t = t * 2

    fro = t/2
    to = t

    while to >= fro:
        mid = (fro + to) / 2
        m1 = check(m, mid)
        m2 = check(m, mid+1)
        #print to, fro, mid, m1, m2
        if m1 < n and m2 >=n:
            t = mid
            break
        elif m1 >= n:
            to = mid - 1
        else:
            fro = mid + 1
    
    #print t
    total = check(m, t)
    #print total
    #print n - total

    a = [t%x for x in m]
    r = -2
    for i in range(len(a)):
        if a[i] == 0:
            total = total + 1
            if total == n:
                r = i + 1
    
    #print '****'
    out.write('Case #' + str(case) + ': ' + str(r) + '\n')
    case = case + 1
out.close()
