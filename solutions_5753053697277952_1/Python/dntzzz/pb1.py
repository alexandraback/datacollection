from sys import stdin

def imax(v):
    mx = 0
    mi = -1
    for (i,x) in enumerate(v):
        if x >= mx and x > 0:
           mi = i
           mx = x

    return mi

def imin(v):
    mx = 10000
    mi = -1
    for (i,x) in enumerate(v):
        if x < mx and x > 0:
           mi = i
           mx = x

    return mi

def check(v):
    s = sum(v)
    if s == 0:
        return True
    return len([x for x in v if x>0 and 2*x>s]) == 0

T = int(stdin.readline())

for t in range(1,T+1):
    N = int(stdin.readline())
    P = [int(x) for x in stdin.readline().strip().split()]

    output = ""
    sen = sum(P)
    while sen>0:
        pmax = imax(P)
        pmin = imin(P)
        # print P
        # print 'pmin {} pmax {}'.format(pmin, pmax)
        if P[pmin] == 1 and sen % 2 > 0:
            P[pmin] -= 1
            sen -= 1
            output += ' {}'.format(chr(ord('A')+pmin))
        else:
            P[pmin] -= 1
            P[pmax] -= 1
            output += ' {}{}'.format(chr(ord('A')+pmin), chr(ord('A')+pmax))
            sen -= 2

        # if not check(P):
        #    print 'Ouch'

    print 'Case #{}:{}'.format(t, output)

