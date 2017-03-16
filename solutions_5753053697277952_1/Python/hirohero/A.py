a = open('A-large.in','r').readlines()
f = open('A.out','w')
now = 0
tests =  int(a[now].strip())
now += 1
for test in range(tests):
    n = int(a[now].strip())
    now += 1
    b = []
    c = ord('A')
    tmp = 0
    s = 0
    for x in a[now].split():
        b.append([int(x), chr(c + tmp)])
        s += int(x)
        tmp += 1
    now += 1
    res = 'Case #' + str(test + 1) + ':'
    b.sort()
    b = b[::-1]
    if s % 2 == 1:
        res = res + ' '  + b[0][1]
        b[0][0] -= 1
    b.sort()
    b = b[::-1]
    while (b[0][0] > 0):
        if n == 1:
            res = res + ' ' + b[0][1]
            b[0][0] -= 1
        else:
            if b[0][0] > b[1][0]:
                res = res + ' ' + b[0][1] + b[0][1]
                b[0][0] -= 2
            else:
                res = res + ' ' + b[0][1] + b[1][1]
                b[0][0] -= 1
                b[1][0] -= 1
        b.sort()
        b = b[::-1]
        
    print >> f, res
f.close()
            
    
