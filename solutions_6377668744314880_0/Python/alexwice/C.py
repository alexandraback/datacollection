def cross(o, a, b):
    #positive if oab is counterclockwise
    #zero collinear, negative clockwise
    return (a[0] - o[0]) * (b[1] - o[1]) - (a[1] - o[1]) * (b[0] - o[0])

from collections import defaultdict as ddic
def solve(N,AA):
    
    A = [(j[0],j[1],i) for i,j in enumerate(AA)]
    A.sort()
    crossdic = ddic(int)
    for i in xrange(N):
        for j in xrange(N):
            for k in xrange(N):
                zz =cross(A[i],A[j],A[k])
                if zz > 0: crossdic[(i,j,k)] = 2
                elif zz<0: crossdic[(i,j,k)] = 1
    ansdic = ddic(int)
    #answer for ith point
    for i in xrange(N):
        ansdic[i] = 99999
    if N == 1: return [0]
    for i in xrange(N-1):
        for j in xrange(i+1,N):
            #look at the line A[i],A[j].  If the least number of pts to the left/right of it is M,
            # then A[i][2] and A[j][2] admit solutions of M.
            type1,type2 = 0,0
            for k in xrange(N):
                if k!=i and k!=j:
                    z = crossdic[(k,i,j)]
                    if z==2: type2 += 1
                    elif z==1: type1 += 1
                    else: pass #on the line so doesnt count
            #print i,j,A[i],A[j],type1,type2
            least = min(type1,type2)
            ansdic[A[i][2]] = min(least,ansdic[A[i][2]])
            ansdic[A[j][2]] = min(least,ansdic[A[j][2]])
    #print ansdic
    return [ansdic[i] for i in xrange(N)]


########
fo = open('out.txt','w')
with open('in.txt','r') as fi:
    rr = lambda: fi.readline().strip()
    rrI = lambda: int(rr())
    rrM = lambda: map(int,rr().split())
    for tc in xrange(rrI()):
        N = rrI()
        A = [tuple(rrM()) for i in xrange(N)]
        zetaans = solve(N,A)
        zeta = "Case #%i:"%(tc+1)
        print zeta
        fo.write(zeta+'\n')
        for i in zetaans:
            print i
            fo.write(str(i)+'\n')
fo.close()
