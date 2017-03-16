#!/usr/bin/python
# -*- coding: utf-8 -*-

def solve(N,M):
	cuts = []
	for X0,Y0 in M:
		mincut = N-1
		for Xi,Yi in M:
			if (Xi,Yi) == (X0,Y0): continue
			cut = 0
			for x,y in M:
				if (x-X0)*(Yi-Y0)<(y-Y0)*(Xi-X0): cut += 1
			mincut = min(cut, mincut)
		cuts.append(mincut)
	return "\n".join(str(i) for i in cuts)

T = int(input())
for test in range(T):
	N = int(input())
	M = []
	for _ in range(N):
		M.append(tuple(int(i) for i in input().split()))
	print ('Case #%d:' % (test+1))
	print (solve(N,M))
