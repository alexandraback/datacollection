#! /opt/local/bin/python
#import numpy as np

f = open("B-small-attempt1.in")
#f = open("A-large.in")
#f = open("exB.in")

T= int(f.readline().strip());
def gcd(a, b):
    """Return greatest common divisor using Euclid's Algorithm."""
    while b:
        a, b = b, a % b
    return a

def lcm(a, b):
    """Return lowest common multiple."""
    return a * b // gcd(a, b)

for t in range(T):
    (B,N) = [int(x) for x in f.readline().strip().split()]
    Mi= [int(x) for x in f.readline().strip().split()]
    Tf=zip([0]*len(Mi),range(1,len(Mi)+1))
    k=0
    LCM_M=reduce(lcm,Mi)
    #print LCM_M
    eq_num = sum([LCM_M//m for m in Mi])

    N=N%eq_num
    if N==0: N=eq_num
    for i in range(N):
        #print B, Tf
        (freetime,i)=min(Tf)
        Tf[i-1] = (Tf[i-1][0]+Mi[i-1],i)
        #print B, Tf
        k=i


    print "Case #"+str(t+1)+": ",k
