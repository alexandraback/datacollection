#!/usr/bin/python
# -*- coding: utf-8 -*-

def solve(m):
	maxdiff = 0
	sumdiff = 0
	for mi,mj in zip(m,m[1:]):
		diff = mi-mj
		if diff>0:
			sumdiff += diff
			if diff>maxdiff: maxdiff = diff
	summaxdiff = 0
	for mi,mj in zip(m,m[1:]):
		summaxdiff += min(mi,maxdiff)
	return "{} {}".format(sumdiff,summaxdiff)

T=int(input())
for test in range(T):
	N = int(input())
	m = [int(i) for i in input().split()]
	print ('Case #%d:' % (test+1), solve(m))
