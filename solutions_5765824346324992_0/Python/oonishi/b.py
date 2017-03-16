#coding: cp932
# 2015 Round1-A Probleb B
input = iter('''
3
2 4
10 5
3 12
7 7 7
3 8
4 2 1
'''.splitlines()[1:])
import sys
output = sys.stdout

from ctypes import *
#cdll.c.solve.restype = c_ulonglong


filename = r'B-small-attempt2.in'
#filename = r'C-large-practice (1).in'
input  = open(filename)
output = open(filename[:-3]+'.out', 'w')


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
	
def gcd(n,m):
	r = n%m
	while r:
		n = m
		m = r
		r = n%m
	return m
	

def solve(N,M):
	print(N,M)
	
	x = M[0]
	for m in M[1:]:
		g = gcd(m,x)
		x = m*x//g
		
	y = 0
	for m in M:
		y += x//m
	print(M,x,y)
	#return x
	
	N %= y
	if N==0:
		N = y
	
	C = list(range(len(M)))
	m = M[:]
	c = len(M)
	while c<N:
		for i,_ in enumerate(m):
			m[i] -= 1
			if m[i] == 0:
				C[i] = c
				c += 1
				m[i] = M[i]
	print(C,N)
	#C.index(N-1)+1
	return C.index(N-1)+1

	
import time
st = time.time()
caseCnt = int(next(input))
for caseNo in range(caseCnt):
	B,N = map(int, next(input).split())
	*M, = map(int, next(input).split())
	answer = solve(N,M)
	print('Case #%d:'%(caseNo+1), answer, file=output)
	
print(time.time()-st)