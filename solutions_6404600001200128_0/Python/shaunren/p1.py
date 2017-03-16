#!/usr/bin/python3 -SOO
import math,string,itertools,fractions,re,array,bisect
from heapq import *
from collections import *


for cas in range(1,int(input())+1):
    n = int(input())
    m = list(map(int,input().strip().split()))
    a = sum(max(0,x-y) for x,y in zip(m,m[1:]))
    mr = max(max(0,x-y) for x,y in zip(m,m[1:]))
    b = sum(min(mr,x) for x,y in zip(m,m[1:]))
    print('Case #%d: %d %d'%(cas,a,b))
