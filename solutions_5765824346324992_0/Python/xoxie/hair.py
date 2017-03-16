import sys
import heapq as hq

def gcd(a, b):
    """Return greatest common divisor using Euclid's Algorithm."""
    while b:      
        a, b = b, a % b
    return a

def lcm(a, b):
    """Return lowest common multiple."""
    return a * b // gcd(a, b)

def lcmm(*args):
    """Return lcm of args."""   
    return reduce(lcm, args)

f = open(sys.argv[1])
f.readline()
casenum = 1
l = f.readline()
while l != "":
    b,n = l.split()
    n = int(n)

    m = [int(x) for x in f.readline().split()]

    
    lowest = lcmm(*m)
    mults = [lowest/x for x in m]
    summults = sum(mults)

    #print n
    n = n % summults
    if n == 0:
        n = summults
    #print n

    #print m
    #print lcmm(*m)
    #print mults

    b = [(0,i) for i in range(len(m))]
    hq.heapify(b)

    while n > 1:
        t,x = b[0]
        hq.heapreplace(b,(t+m[x],x))        
        n -= 1

    output = b[0][1]+1

    print "Case #{}: {}".format(casenum,output)
    casenum += 1
    l = f.readline()
