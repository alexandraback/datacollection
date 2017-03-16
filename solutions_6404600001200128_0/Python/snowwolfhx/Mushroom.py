#!/usr/bin/env python
import numpy as np
import scipy as sp
import os
import sys

def compute(D,Darr):
    #first assumption
    result1=0
    minrate = 0
    print Darr
    count = 0
    for i in xrange(D-1):
        if Darr[i] ==0:
            count+=1
        if Darr[i]-Darr[i+1]>0:
            eat  =Darr[i]-Darr[i+1]
            result1+=eat
            if eat>minrate:
                minrate = eat
            print i,eat,minrate
    index = Darr<minrate
    print len(Darr[index]),np.sum(Darr[index])
    if Darr[-1]<minrate:
        result2 = np.sum(Darr[index])-Darr[-1]+minrate*(D-len(Darr[index]))
    else:
        result2 = np.sum(Darr[index])+minrate*(D-len(Darr[index])-1)

    return result1,result2

#def case2(D,Darr):
#    #second assumption
#    for i in xrange
#   return result

def main(infile):
    fin=open(infile,mode='r')
    fout = open("test_output.txt",mode='w')
    ncase = int(fin.readline())
    for i in xrange(ncase):
        #print i
        D = int(fin.readline())
        Darr = np.array(fin.readline().split()).astype(int)
        result1,result2 = compute(D,Darr)
        #result2 = case2(D,Darr)
        fout.write("Case #%d: %d %d\n" % ((i+1),result1,result2))
    fin.close()
    fout.close()
    return
if __name__=='__main__':
    main(sys.argv[1])
