#!/usr/bin/env python
import numpy as np
import scipy as sp
import os
import sys
import fractions


def LCM(a,b):
    return a*b/fractions.gcd(a,b)

def compute_small(B,N,Marr):
    if N<=B:
        return N
    else:
        count = B
        time = 1
        while (not count==N):
            for i in xrange(B):
                #print 'debug',time,time%Marr[i],i,Marr[i]
                if time%Marr[i]==0:
                    count+=1
                    if count==N:
                        return i+1
            time+=1

def compute(B,N,Marr):
    if N<=B:
        return N
    elif (len(np.unique(Marr))==1):
        if N%B==0:
            return B
        else:
            return (N%B)

    else:
        lcmall = LCM(Marr[0],Marr[1])
        for i in xrange(B-2):
            lcmall = LCM(lcmall,Marr[i+2])
        total = 0
        for i in xrange(B):
            total+=lcmall/Marr[i]
        newN = (N-1)%(total)+1
        print lcmall,newN,total
        return compute_small(B,newN,Marr)
def main(infile):
    fin=open(infile,mode='r')
    fout = open("test_output.txt",mode='w')
    ncase = int(fin.readline())
    for i in xrange(ncase):
        print i
        B,N = map(int,fin.readline().split())
        Marr = np.array(fin.readline().split()).astype(int)
        result = compute(B,N,Marr)
        fout.write("Case #%d: %d\n" % ((i+1),result))
    fin.close()
    fout.close()
    return
if __name__=='__main__':
    main(sys.argv[1])
