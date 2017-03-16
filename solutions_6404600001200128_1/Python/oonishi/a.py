#coding: cp932
# 2015 Round1-A Probleb C
input = iter('''
4
4
10 5 15 5
2
100 100
8
81 81 81 81 81 81 81 0
6
23 90 40 0 100 9
'''.splitlines()[1:])
import sys
output = sys.stdout

from ctypes import *
#cdll.c.solve.restype = c_ulonglong


filename = r'A-small-attempt0.in'
filename = r'A-large.in'
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
	
def solve1(M):
	cnt = 0
	prev = M[0]
	for m in M[1:]:
		if m < prev:
			cnt += prev-m
		prev = m
	
	return cnt

def solve2(M):
	cnt = 0
	D = [m1-m2 for m1,m2 in zip(M[:-1],M[1:])]
	d = max(D)
	for m in M[:-1]:
		cnt += min(m,d)
	
	return cnt
	
import time
st = time.time()
caseCnt = int(next(input))
for caseNo in range(caseCnt):
	N, = map(int, next(input).split())
	*M, = map(int, next(input).split())
	answer1 = solve1(M)
	answer2 = solve2(M)
	print('Case #%d:'%(caseNo+1), answer1,answer2, file=output)
	
	print(caseNo,time.time()-st)