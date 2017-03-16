def ciel(x):
    if (x!=int(x)):
        return int(x+1)
    return x

def mod(x):
    if x<0:
        return x*(-1)
    return x
t = int(raw_input())
u = 0
while u<t:
    u+=1
    print "Case #%d:" %u,
    n= int(raw_input())
    p = map(int, raw_input().split())
    if sum(p)%2==0:
        f = 0
    else:
        f=1
    while f==0 and sum(p)>0:
        i = p.index(max(p))
        p[i] -= 1
        j = p.index(max(p))
        p[j] -= 1
        print chr(i+65)+chr(j+65),
    if f==0 and sum(p) == 0:
        print ''
    while f==1 and sum(p)>3:
        i = p.index(max(p))
        p[i] -= 1
        j = p.index(max(p))
        p[j] -= 1
        print chr(i+65)+chr(j+65),
    if sum(p)==3:
        i = p.index(max(p))
        p[i] -= 1
        j = p.index(max(p))
        p[j] -= 1
        k = p.index(max(p))
        print chr(i+65), chr(j+65)+chr(k+65)
