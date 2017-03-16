#!/usr/bin/python3 -SOO
import math,string,itertools,fractions,re,array,bisect
from heapq import *
from collections import *
from operator import mul


for cas in range(1,int(input())+1):
    b,n = map(int,input().strip().split())
    m = list(map(int,input().strip().split()))
    if n<=b:
        print('Case #%d: %d'%(cas,n))
        continue
    lo,hi = 0,100000000001
    v = 0
    while hi-lo>0:
        mid = (lo+hi)//2
        v = b+sum(mid//x for x in m)
        if v < n:
            lo=mid+1
        else:
            hi=mid
    #print(lo,hi)
    v = b+sum((lo-1)//x for x in m)
    i = n-v
    for j,x in enumerate(m):
        if (lo)%x == 0:
            i -= 1
            if i<=0:
                print('Case #%d: %d'%(cas,j+1))
                break
        
