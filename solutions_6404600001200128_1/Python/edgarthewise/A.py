from sys import stdin, stdout, exit
import numpy as np
from numpy import *

def getWords():
    return stdin.readline().strip().split()

def getInts():
    return array([int(i) for i in getWords()], dtype=int)

def getInt():
	i = getInts()
	assert len(i)==1
	return i

T = getInt()

for caseNo in xrange(1,T+1):

	N = getInt()
	m = getInts()
	
	first = np.maximum(m[:-1]-m[1:], 0).sum()
	
	minRate = max(0, (m[:-1]-m[1:]).max())
	second = np.minimum(m[:-1], minRate).sum()
	
	print "Case #%d: %d %d"%(caseNo, first, second)
