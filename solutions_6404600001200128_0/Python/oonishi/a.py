#coding: cp932
# 2015 Round1-A Probleb A
input = iter('''
'''.splitlines()[1:])
import sys
output = sys.stdout

from ctypes import *
cdll.c.solve.restype = c_ulonglong


#filename = r'C-small-practice (1).in'
#filename = r'C-large-practice (1).in'
#input  = open(filename)
#output = open(filename[:-3]+'.out', 'w')


def bsearch(key, l):
	if l == []: return 0
	if len(l) == 1:
		return 0 if l[0] > key else 1
	m = len(l)//2
	if l[m] > key:
		return bsearch(key, l[:m])
	else:
		return bsearch(key, l[m:])+m

import copy
import itertools
import pickle
import math

def binint(x):
	n = 0
	for i,c in enumerate(x[::-1]):
		if c == '1':
			n |= (1<<i)
	return n

def bitcnt(x):
	r = 0
	for i in range(64):
		r += (x>>i)&1
	return r
	
def solve():
	return 0

	
import time
st = time.time()
caseCnt = int(next(input))
for caseNo in range(caseCnt):
	N,M = map(int, next(input).split())
	Ac = [0]*N
	At = [0]*N
	*A, = map(int, next(input).split())
	for i,(c,t) in enumerate(zip(A[::2], A[1::2])):
		Ac[i] = c
		At[i] = t
		
	Bc = [0]*M
	Bt = [0]*M
	*B, = map(int, next(input).split())
	for i,(c,t) in enumerate(zip(B[::2], B[1::2])):
		Bc[i] = c
		Bt[i] = t
	#*A, = map(int, next(input).split())
	#*A, = zip(A[::2],A[1::2])
	#*B, = map(int, next(input).split())
	#*B, = zip(B[::2],B[1::2])
	#print(A,B)
	answer = solve(Ac,At,Bc,Bt)
	print('Case #%d:'%(caseNo+1), answer, file=output)
	
print(time.time()-st)