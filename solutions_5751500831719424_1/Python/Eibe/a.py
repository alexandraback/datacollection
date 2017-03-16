#! /usr/bin/env python

# python 2.7
#usage: cat input | this_program > output

from __future__ import division
import sys
import math

def representant(s):
	c = ""
	r = []
	for cc in s:
		if cc != c:
			r.append([cc, 1])
			c = cc
		else:
			r[-1][1] += 1
	return r

def r_rep(rep):
	return [x[0] for x in rep]

def shl(ss, i):
	l = 0
	lc = 0
	sh = 101
	lsh = 0
	for s in ss:
		if s[i][1] > l:
			l = s[i][1]
			lc = 1
		elif s[i][1] == l:
			lc += 1
		if s[i][1] < sh:
			sh = s[i][1]
			shc = 1
		elif s[i][1] == sh:
			shc += 1
	return l, lc, sh, shc
	
def solve(ss):
	ss = map(representant, ss)
	r = r_rep(ss[0])
	for rr in ss:
		if r_rep(rr) != r:
			return "Fegla Won"
	cnt = 0
	for i in range(len(r)):
		l, lc, sh, shc = shl(ss, i)
		while l != sh:
			if lc <= shc:
				for s in ss:
					if s[i][1] == l:
						s[i][1] -= 1
						cnt += 1
			elif shc < lc:
				for s in ss:
					if s[i][1] == sh:
						s[i][1] += 1
						cnt += 1
			l, lc, sh, shc = shl(ss, i)
	return str(cnt)
			
	
if __name__ == "__main__"	:	
	num_testcases = int(sys.stdin.readline())
	for case in range(1, num_testcases + 1):
		N = int(sys.stdin.readline())
		ss = []
		for _ in range(N):
			ss.append(sys.stdin.readline().strip())
		print "Case #%i: %s" %(case, solve(ss))

