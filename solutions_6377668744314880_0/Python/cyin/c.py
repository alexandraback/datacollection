import sys
import math
ca = int(sys.stdin.readline())
x0 = 1000010 
y0 = 1000010
def mul(a0,b0,a1,b1,a2,b2):
    da1 = a1-a0
    db1 = b1-b0
    da2 = a2-a0
    db2 = b2-b0
    d1 = math.sqrt(da1**2+db1**2)
    d2 = math.sqrt(da2**2+db2**2)
    c = (da1*da2+db1*db2)/float(d1)/float(d2)
    if da1*db2-da2*db1<0:
        c = -5 - c
    return c        

def mm(a0,b0,a1,b1,a2,b2):
    da1 = a1-a0
    db1 = b1-b0
    da2 = a2-a0
    db2 = b2-b0
    d1 = math.sqrt(da1**2+db1**2)
    d2 = math.sqrt(da2**2+db2**2)
    c = (da1*da2+db1*db2)/float(d1)/float(d2)
    if da1*db2-da2*db1<0:
        return 0
    return 1

for nu in range(ca):
    print 'Case #%d:' %(nu+1)
    n = int(sys.stdin.readline())
    x = []
    y = []
    for i in range(n):
        a,b = sys.stdin.readline().strip().split(' ')
        x.append(int(a))
        y.append(int(b))
    for i in range(n):
        data = []
        for j in range(n):
            if i == j:
                continue
            data.append([x[j],y[j],mul(x[i],y[i],x0,y0,x[j],y[j])])
        data.sort(key=lambda x:x[2])
        data.reverse()
        r = 0
        res = -1
        if n == 1:
            res = 0
        for l in range(len(data)):
            r = (l + 1) % len(data)
            while r != l and mm(x[i],y[i],data[l][0],data[l][1],data[r][0],data[r][1]) > 0:
                r = (r + 1) % len(data)
            sum = r - l
            if sum<=0:
                sum += len(data)
            sum += 1
            if res < 0 or res > n-sum:
                res = n-sum
        print res
                
