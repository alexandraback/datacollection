#coding: cp932
# 2015 Round1-A Probleb C
input = iter('''
2
5
0 0
10 0
10 10
0 10
5 5
9
0 0
5 0
10 0
0 5
5 5
10 5
0 10
5 10
10 10
'''.splitlines()[1:])
import sys
output = sys.stdout

from ctypes import *
#cdll.c.solve.restype = c_ulonglong


filename = r'C-small-attempt2.in'
#filename = r'C-large-practice (1).in'
input  = open(filename)
output = open(filename[:-3]+'2.out', 'w')


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
	
def isinclude(T,p):
	for i in range(3):
		v1 = (T[(i+1)%3][0]-T[i][0], T[(i+1)%3][1]-T[i][1])
		v2 = (T[(i+2)%3][0]-T[i][0], T[(i+2)%3][1]-T[i][1])
		u  = (p[0]-T[i][0], p[1]-T[i][1])
		
		c1 = v1[0]*u[1]-v1[1]*u[0]
		c2 = v2[0]*u[1]-v2[1]*u[0]
		if c1*c2>=0:
			return False
			
	return True

#import pdb;pdb.set_trace()
#print(isinclude([(0,0),(10,0),(0,5)],(5,0)))
#raise
def solve(F):
	res = [float('inf')]*len(F)
	for n in range(2**len(F)):
		l = [x for x in range(len(F)) if (n>>x)&1]
		if len(l) <= 3:
			for i in range(len(F)):
				res[i] = min(res[i],len(F)-bitcnt(n))
			continue
		
		check = [True]*len(F)
		
		#if n == 511:
		#	import pdb;pdb.set_trace()
		
		for T in itertools.permutations(l, 3):
			S = [F[t] for t in T]
			for i in l:
				if i in T: continue
				if isinclude(S, F[i]):
					check[i] = False
		#print(check)
		#if bitcnt(n) == 9:
		#	print(n, check)
		for i,c in enumerate(check):
			if c:
				res[i] = min(res[i],len(F)-bitcnt(n))
			
				
	return res
		
	
	#for i,p in enumerate(F):
		
	
def line(p1,p2):
	if p1[0]-p2[0] == 0 and p1[1]-p2[1] == 0:
		raise
	
	if p1[0]-p2[0] == 0:
		return (1, 0, -p1[0])
	if p1[1]-p2[1] == 0:
		return (0, 1, -p1[1])
	
	a = (p2[1]-p1[1])
	b = -(p2[0]-p1[0])
	c = -p1[0]*a-p1[1]*b
	return a,b,c
# print(line((5,5),(0,0)))
# print(line((1,9),(0,9)))
# print(line((0,9),(1,9)))
# print(line((1,9),(1,0)))
# print(line((0,2),(1,3)))
# print(line((0,2),(1,-5)))
# print(line((1,-5),(0,2)))
# raise
def solve(F):
	if len(F)<=3:
		return [0]*len(F)
	print(F)
	res = []
	for i,p1 in enumerate(F):
		#if i == 4:
		#	import pdb;pdb.set_trace()
		best = len(F) - 3#float('inf')
		for j,p2 in enumerate(F):
			if i==j:continue
			a,b,c = line(p1,p2)
			
			left = 0
			right= 0
			
			for k,p in enumerate(F):
				if k in (i,j): continue
				h = a*p[0]+b*p[1]+c
				if h < 0:
					left += 1
				elif h > 0:
					right += 1
			best = min([best, left, right])
		res += [best]
		
				
	return res

	
#def solve(F):
	
import time
st = time.time()
caseCnt = int(next(input))
for caseNo in range(caseCnt):
	N, = map(int, next(input).split())
	F = []
	for i in range(N):
		X,Y = map(int, next(input).split())
		F += [(X,Y)]
	answer = solve(F)
	print('Case #%d:'%(caseNo+1), file=output)
	for a in answer:
		print(a, file=output)
	
	print(caseNo,time.time()-st)