import string
def func(N,c):
    al = string.ascii_uppercase
    d = []
    res = []
    for i in range(c):
        d.append([al[i],N[i]])
    d.sort(key=lambda x:x[1],reverse=True)
    d = [i for i in d if i[1]!=0]
    while(sum(N)>0):
        if sum(N)>3:
            if d[0][1] > d[1][1] + 1:
                res.append(d[0][0]*2)
                d[0][1] -= 2
            elif d[0][1] > d[1][1]:
                res.append(d[0][0])
                d[0][1] -= 1
            else:
                res.append(d[0][0]+d[1][0])
                d[0][1] -= 1
                d[1][1] -= 1
        elif sum(N)==3:
            res.append(d[0][0])
            d[0][1] -= 1
        else:
            res.append(d[0][0]+d[1][0])
            d[0][1] -= 1
            d[1][1] -= 1       
        d = [i for i in d if i[1]!=0]
        d.sort(key=lambda x:x[1],reverse=True)
        N = [a[1] for a in d]
    return ' '.join(res)

inf = open('A-small.in','r')
out = open('A-small.out','w')

T = int(inf.readline())
for i in range(1,T+1):
    c = int(inf.readline())
    N = map(int,inf.readline().split(' '))
    res = func(N,c)
    out.write('Case #%d: %s \n' %(i,str(res)))
out.close()
inf.close()
