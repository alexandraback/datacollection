import os
import math
import copy
import sys
from collections import *

os.chdir('/Users/Dana/Downloads')
f = open('A-large.in','r')
fo = open('A.out','w')
T = int(f.readline())
for ite in range(T):
    N = int(f.readline())
    m = [0]*N
    m = [int(x) for x in str.split(f.readline())]
    #print(m)
    res1 = 0
    temp = 0
    for i in range(N-1):
        if m[i]>m[i+1]:
            res1 = res1+m[i]-m[i+1]
            if m[i]-m[i+1]>temp:
                temp = m[i]-m[i+1]

    res2 = 0
    #print(res1)
    #print(temp)
    for i in range(N-1):
        res2 = res2+min(m[i], temp)
    print(ite)


    
    fo.write('Case #')
    fo.write(str(ite+1))
    fo.write(': ')
    fo.write(str(res1))
    fo.write(' ')
    fo.write(str(res2))
    fo.write('\n')
fo.close()

