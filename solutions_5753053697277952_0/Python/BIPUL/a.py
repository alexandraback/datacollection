############### Author: Bipul Ranjan @ranjanbipul ###############
import sys
import time
import os
import math
import operator
import random
from functools import lru_cache
from decimal import Decimal as D
from fractions import Fraction as F
#sys.setrecursionlimit(10000)
#@lru_cache(maxsize=None)
MOD = 1000000007
################################################################
QNO = 'a' #SET QUESTION NUMBER
FIN,FOUT = QNO+'.in.txt',QNO+'.out.txt'
FIN = QNO.capitalize()+'-small-attempt0.in'
#FIN = QNO+'.sample.txt'
#FIN = QNO.capitalize()+'-large.in'
fin = open(FIN)
fout = open(FOUT,'w')
sys.stdin = fin
######################## PROGRAM  START ##########################

def solve(a,n):
    return len(a)

for nu in range(int(input())):
    n = int(input())
    a = [int(i) for i in input().strip().split(" ")]
    t = 0
    for i in a: t+=i
    print("Case #{0}:".format(nu+1),file=fout,end=" ")
    while t>0:
        #print(t)
        s = []
        if t==2:
            for i in range(n):
                if a[i]==1:
                    s.append(i)
                    t-=1
                    a[i]-=1
                    if len(s)==2: break
        elif t==3:
            for i in range(n):
                if a[i]==1:
                    s.append(i)
                    t-=1
                    a[i]-=1
                    break
        else:
            m = 0
            for i in range(1,n):
                if a[i]>a[m]: m =i
            s.append(m)
            t-=1
            a[m]-=1
            m = 0
            for i in range(1,n):
                if a[i]>a[m]: m =i
            s.append(m)
            t-=1
            a[m]-=1
        s = [chr(i+65) for i in s]
        print("{0}".format("".join(s)),file=fout,end=" ")
    print("",file=fout)
######################## PROGRAM END #############################
fin.close()
fout.close()
print("Program complete")
