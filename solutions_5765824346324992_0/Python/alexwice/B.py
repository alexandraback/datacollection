
from fractions import gcd
from collections import defaultdict as ddic
def lcm(x,y):
    return x*y/gcd(x,y)
def lcmargs(lt):
    return reduce(lcm, lt)
def solve(B,N,A):
    L = lcmargs(A)
    Adic = { i:j for i,j in enumerate(A) }
    Bans = ddic(set)
    ct = 0
    for i in xrange(L):
        for j in xrange(B):
            if i%Adic[j] == 0:
                Bans[j].add(ct)
                ct += 1
    N -= 1
    N = N%ct
    for i in xrange(B):
        if N in Bans[i]: return i+1
    raise


########
fo = open('out.txt','w')
with open('in.txt','r') as fi:
    rr = lambda: fi.readline().strip()
    rrI = lambda: int(rr())
    rrM = lambda: map(int,rr().split())
    for tc in xrange(rrI()):
        B,N = rrM()
        A = rrM()
        zetaans = solve(B,N,A)
        zeta = "Case #%i: "%(tc+1) + str(zetaans)
        print zeta
        fo.write(zeta+'\n')
fo.close()
