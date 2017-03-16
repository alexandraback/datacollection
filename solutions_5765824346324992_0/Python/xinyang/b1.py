# -*- coding: utf-8 -*-
"""
Created on Fri Apr 17 18:31:03 2015

@author: yx1992
"""

import string
import numpy as np
import scipy as sp
from numpy import *
from scipy import *

def gcd(a, b):
    while b:      
        a, b = b, a % b
    return a

def lcm(a, b):
    return a * b // gcd(a, b)

def lcmm(*args):
    return reduce(lcm, args)



fin=open("B-small-attempt0.in",'r')
fout=open("B-output",'w')
num=int(fin.readline())
for j in range(num):
    line=fin.readline()
    lines=string.split(line, " ")
    B=int(lines[0])
    N=int(lines[1])    
    line=fin.readline()
    lines=string.split(line, " ")
    bar=[]
    for i in range(B):
        bar.append(int(lines[i]))
    least=int(lcmm(*bar))
    leastpeople=0
    for i in range(B):
        leastpeople+=least/bar[i]
    #print "leastpeople"
    #print leastpeople
    N=N%leastpeople
    if N==0:
        N=leastpeople
    guests=zeros(B,dtype=int)
    for i in range(N):
        Next=np.argmin(guests)
        #print Next
        guests[Next]+=bar[Next]
    fout.write("Case #"+str(j+1)+": "+str(int(Next)+1)+"\n")
    
fin.close();
fout.close();