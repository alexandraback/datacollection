import sys
import bisect
import fractions

args = sys.argv
file = args[1]
f = open(file)

def flcm(a,b):
    return a*b // fractions.gcd(a,b)

cases = int(f.readline())

for i in range(cases):
    l = f.readline().split(' ')
    b = int(l[0])
    n = int(l[1])
    l = f.readline().split(' ')
    m = [int(x) for x in l]
    t = [(0,x) for x in range(b)]
    lcm = reduce(flcm,m,1)
    cpm = [lcm / x for x in m]
    tpm = sum(cpm)
    #print "Before num people: %s" % n
    n %= tpm
    if n == 0:
        n = tpm
    #print "After num people: %s" % n
    #print "Num barbers: %s" % b
    #print "Times: %s" % m
    #print "gcd: %s" % g
    #print "cpg: %s" % cpg
    while n > 1:
        #print t
        mb = t.pop(0)
        mint = mb[0]
        for j, (x,y) in enumerate(t):
            t[j] = (x - mint, y)
        bisect.insort(t,(m[mb[1]],mb[1]))
        n -= 1
    #print t
    lb = t.pop(0)[1]
    print "Case #%s: %s" % (i + 1,lb + 1)
    
