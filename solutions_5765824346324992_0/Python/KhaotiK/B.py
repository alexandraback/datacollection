#!/usr/bin/python3
import sys
import os
import traceback
import code
from collections import *
from functools import *

if len(sys.argv) != 2:
    print ('Invalid args')
    sys.exit()
infile = sys.argv[1] 
if infile not in os.listdir('.'):
    print ('file not found!')
    sys.exit()
outfile = infile.replace('.in','.out')

f = open( infile, 'r' )
of = open( outfile, 'w' )

def output( *args, end='\n' ):
    print( ' '.join(map(str, args)), end=end )
    of.write( (' '.join(map(str,args)))+end )

def gcd(x,y):
    a,b = sorted((x,y))
    while a!=0:
        a,b = b%a, a
    return b

def solCase( case ):
    B,N = map(int,f.readline()[:-1].split(' '))
    li = list(map(int,f.readline()[:-1].split(' ')))
    vli = [0 for _ in li]
    g = reduce( gcd, li )
    period = 0
    for i in range(len(li)):
        li[i] //= g
    l = g*reduce( int.__mul__, li )
    for i in li:
        period += l//i

    print( 'pr', period )
    M = (N-1)//period
    N = (N-1)%period+1
    ii=0
    u = 0
    while u<N:
        for i,v in enumerate(vli):
            if v==0:
                vli[i] = li[i]
                ii=i
                break
        else:
            m = min(vli)
            for i in range(B):
                vli[i] -= m
            u -= 1
        u+=1
    output( 'Case #%d: %d'%(case, ii+1) )

for case in range(1,int(f.readline()[:-1])+1):
    try:
        solCase(case)
    except BaseException as e:
        print( e.__class__.__name__+' while solving case %d:'%case )
        traceback.print_tb( sys.exc_info()[2] )
