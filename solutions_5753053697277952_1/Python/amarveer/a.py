import sys

for cases in xrange(int(sys.stdin.readline())):
    N = int(sys.stdin.readline())
    s = 'ABCDEFGHIJKLMNOPQRSTUVWXYZ'
    L =list(map(int,sys.stdin.readline().split()))
    l = []
    for i in xrange(N):
        l.append([L[i],s[i]])
    plan = ''
    l.sort()
    while l[-1][0] > 0:
        num = l[-1][0]
        c = 0
        for i in l[::-1]:
            if i[0] == num:
                c += 1
            if c > 2: break
                
        if c == 1:
            plan += l[-1][1] + ' '
            l[-1][0] -= 1
        elif c == 2:
            plan += l[-1][1] + l[-2][1] + ' '
            l[-1][0] -= 1
            l[-2][0] -= 1
        else:
            plan += l[-1][1] + ' '
            l[-1][0] -= 1
        l.sort()
    print "Case #%d: %s"%(cases+1,plan)
    
    
