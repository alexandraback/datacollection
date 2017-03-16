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

def solCase( case ):
    N = int(f.readline()[:-1])
    li = list(map( int, f.readline()[:-1].split(' ') ))
    #first method
    s1 = 0
    for i,v in enumerate(li[:-1]):
        d = li[i]-li[i+1]
        if d>0: s1+=d
    #method 2
    rate=0
    for i,v in enumerate(li[:-1]):
        r = li[i] - li[i+1]
        if r>rate: rate =r
    s2 = 0
    for i in li[:-1]:
        if i>rate:
            s2 += rate
        else: s2 += i
    output( 'Case #%d: %d %d'%(case, s1, s2) )
    pass

for case in range(1,int(f.readline()[:-1])+1):
    try:
        solCase(case)
    except BaseException as e:
        print( e.__class__.__name__+' while solving case %d:'%case )
        traceback.print_tb( sys.exc_info()[2] )
