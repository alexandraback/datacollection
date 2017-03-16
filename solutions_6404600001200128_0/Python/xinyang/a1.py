# -*- coding: utf-8 -*-
"""
Created on Fri Apr 17 17:54:38 2015

@author: yx1992
"""

import string
import numpy as np
import scipy as sp
from numpy import *
from scipy import *

fin=open("A-small-attempt0.in",'r')
fout=open("A-output",'w')
num=int(fin.readline())
for j in range(num):
    N=int(fin.readline())    
    line=fin.readline()
    lines=string.split(line, " ")
    ans1=0
    ans2=0
    maxrate=0
    for i in range(1,N):
        if int(lines[i-1])>int(lines[i]):
            ans1+=int(lines[i-1])-int(lines[i])
            if maxrate<int(lines[i-1])-int(lines[i]):
                maxrate=int(lines[i-1])-int(lines[i])
    for i in range(N-1):
        ans2+=np.minimum(int(lines[i]),maxrate)

    fout.write("Case #"+str(j+1)+": "+str(int(ans1))+" "+str(int(ans2))+"\n")
    
fin.close();
fout.close();