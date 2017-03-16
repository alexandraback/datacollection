from itertools import combinations,product
def adj(a,b):
    x,y = a
    m,n = b
    return (abs(x-m)==1 and y==n) or (abs(y-n)==1 and x==m)
for i,Ns in enumerate(open('B-small.in').read().split('\n')[:-1]):
 if i:
    rs,cs,ns=Ns.split(' ')
    R=int(rs)
    C=int(cs)
    N=int(ns)
    arrangement,best = "None",N*4
    for units in combinations(list(product(xrange(R),xrange(C))),N):
        unhappy = 0
        for a,b in combinations(units,2):
            if adj(a,b):
                unhappy += 1
        if unhappy < best:
            arrangement,best = units,unhappy
        
    
    print "Case #%d: %d" % (i,best)