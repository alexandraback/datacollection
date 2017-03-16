import sys

from math import *
from itertools import *
from collections import defaultdict

def lg(a) :
    sys.stderr.write(str(a)+"\n")

def readM() :
    m = []
    for i in range(4) :
	l = map(int, sys.stdin.readline().split() )
	m.append(l)
    return m

def sol(a1,m1,a2,m2) :
    bm = "Bad magician!"
    vc = "Volunteer cheated!"
    s = set(m1[a1]) & set(m2[a2])
    if len(s)==0 :
	return vc
    elif len(s)>1 :
	return bm
    else :
	return s.pop()

t = int(sys.stdin.readline())
for testNr in range(1,t+1) :
    a1 = int(sys.stdin.readline())
    m1 = readM()
    a2 = int(sys.stdin.readline())
    m2 = readM()
    print "Case #%d:" % testNr ,
    print sol(a1-1,m1,a2-1,m2)
