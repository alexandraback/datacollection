# coding: cp932

lines = iter('''
5
2
mmaw
maw
2
gcj
cj
3
aaabbb
ab
aabb
2
abc
abc
3
aabc
abbc
abcc
'''.splitlines(False)[1:])


from math import sqrt
from datetime import datetime
import sys
class Out:
	def __init__(me, f):
		me.file = f
	def write(me, *args):
		sys.stdout.write(*args)
		me.file.write(*args)
out = sys.stdout
#sys.setrecursionlimit(1500)

#from decimal import Decimal, getcontext
#getcontext().prec = 64


date = datetime.now().strftime('%Y%m%d-%H%M%S')

infile = 'A-small-attempt0.in'
#infile = 'C-large-practice.in'
lines = iter(open(infile).read().splitlines(False))
out = Out(open(infile[:-3] + (date + '.answer'), 'w'))



class OffsetedList:
	def __init__(me, size, offset, init=0):
		me.l = [init]*(size+offset)
		me.offset = offset
	def __getitem__(me, index):
		return me.l[index+me.offset]
	def __setitem__(me, index, value):
		me.l[index+me.offset] = value
		
def Choice(n, c):
	if c == 0: return 1
	
	ret = 1
	div = 2
	for i in range(n, n-c, -1):
		ret *= i
		while ret % div == 0 and div <= c:
			ret //= div
			div += 1
	return ret

	
from collections import namedtuple, defaultdict
from itertools import count
from ctypes import*



memcpy = cdll.msvcrt.memcpy
from copy import deepcopy

MAX = float('inf')

import sys
sys.setrecursionlimit(1500)

def equation(a, b, c):
	right = 1.0e+10
	left  = -1.0
	while right-left>1.0e-6:
		t = (right+left)/2
		val = a*t*t + b*t + c
		if val**2 < 1.0e-12:
			return t
		elif val > 0:
			right = t
		else:
			left = t
		#print(t)
	return left
MAX = 1<<31		
def diff(M):
	V = len(M)
	H = len(M[0])
	
	
	ans = 0
	for i in range(H):
		mn = MAX
		for j in range(V):
			s = 0
			for k in range(V):
				try:
					d = M[j][i] - M[k][i]
				except IndexError:
					print(j,i,k)
					print(len(M[0]))
					print(len(M[1]))
					raise
				if d < 0: d = -d
				s += d
			mn = min(s, mn)
		ans += mn
	return ans
		
		
def solve(S):
	s = S[0]
	prev = ''
	m = []
	d = []
	for c in s:
		if c == prev:
			m[-1] += 1
		else:
			m += [1]
			d += [c]
		prev = c
	M = [m]
	D = tuple(d)

	for s in S[1:]:
		prev = ''
		m    = []
		di   = -1
		for c in s:
			if c == prev:
				m[-1] += 1
			else:
				di += 1
				if di >= len(D) or D[di] != c: return 'Fegla Won'
				m += [1]
				
			prev = c
		if di != len(D)-1:
			return 'Fegla Won'
		M += [m]
	#print(M, D)
	
	return diff(M)

	
	
	
#print(solve(13, 1, 3))
caseCnt = int(next(lines))

class C:
	def __init__(me, cnt, typ):
		me.cnt = cnt
		me.typ = typ
	def __repr__(me):
		return 'C(%d,%d)'%(me.cnt, me.typ)

for case in range(1, caseCnt+1):
	(N,) = map(int, next(lines).split())
	S = []
	for _ in range(N):
		S += [next(lines).split()[0]]
	#import pdb;pdb.set_trace()
	print('Case #%d:'%(case), solve(S), file=out)

