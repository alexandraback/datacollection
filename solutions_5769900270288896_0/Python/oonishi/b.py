#coding: cp932
# 2015 Round1-B Probleb B
input = iter('''
4
2 3 6
4 1 2
3 3 8
5 2 0
'''.splitlines()[1:])
import sys
output = sys.stderr

from ctypes import *
#cdll.c.solve.restype = c_ulonglong


filename = r'B-small-attempt0.in'
#filename = r'A-large.in'
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
	
def solve(R,C,N):
	best = float('inf')
	for L in itertools.combinations(range(R*C),N):
		G = [[0]*C for _ in range(R)]
		for n in L:
			G[n//C][n%C] = 1
		cnt = 0
		for r in range(R-1):
			for c in range(C-1):
				if G[r][c] == 1 and G[r+1][c] == 1:
					cnt += 1
				if G[r][c] == 1 and G[r][c+1] == 1:
					cnt += 1
		r = R-1	
		for c in range(C-1):
			if G[r][c] == 1 and G[r][c+1] == 1:
				cnt += 1
				r = R-1	
		c = C-1
		for r in range(R-1):
			if G[r][c] == 1 and G[r+1][c] == 1:
				cnt += 1
		best = min(cnt,best)
	return best

	
import time
st = time.time()
caseCnt = int(next(input))
for caseNo in range(caseCnt):
	R,C,N = map(int, next(input).split())
	answer = solve(R,C,N)
	print('Case #%d:'%(caseNo+1), answer, file=output)
	
	print(caseNo,time.time()-st)