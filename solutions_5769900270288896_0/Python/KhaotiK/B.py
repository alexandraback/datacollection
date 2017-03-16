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
    x,y,n = map(int, f.readline()[:-1].split(' ') )
    if n<=((x*y+1)//2):
        output( 'Case #%d: 0'%case )
        return
    r = n - ((x*y)//2)
    x,y = sorted((x,y))
    if x==1:
        if y%2:
            output( 'Case #%d: %d'%(case,r*2) )
            return
        else:
            output( 'Case #%d: %d'%(case,r*2-1) )
            return
    elif x==2:
        if r<=2:
            output( 'Case #%d: %d'%(case,r*2) )
            return
        else:
            output( 'Case #%d: %d'%(case,r*3-2) )
            return
    else:
        if bool(x%2) and bool(y%2):
            c = 4
            ed = (((x-2)//2)+((y-2)//2))*2
        elif bool(x%2) or bool(y%2):
            c=2
            ed = (((x-1)//2)+((y-1)//2))*2-1
        else:
            c=2
            ed = (((x-1)//2)+((y-1)//2))*2
        if r<=c:
            output( 'Case #%d: %d'%(case,r*2) )
            return
        elif r<=ed:
            output( 'Case #%d: %d'%(case,r*3-c) )
            return
        else:
            output( 'Case #%d: %d'%(case,r*4-c*2-ed) )
            return
#    output( 'Case #%d: '%case )

for case in range(1,int(f.readline()[:-1])+1):
    try:
        solCase(case)
    except BaseException as e:
        print( e.__class__.__name__+' while solving case %d:'%case )
        traceback.print_tb( sys.exc_info()[2] )
