#!/usr/bin/python
# -*- coding: utf-8 -*-

import math

def solve(N,M):
	minT = 0
	maxT = N * max(M)
	while True:
		T = int((minT+maxT)/2)
		sumceils = sum(math.ceil(T/Mk) for Mk in M)
		sumceils1 = sum(math.ceil((T+1)/Mk) for Mk in M)
		if sumceils < N and sumceils1 >= N:
			rank = N-sumceils
			break
		if sumceils1 < N:
			minT = T+1
		if sumceils >= N:
			maxT = max(minT,T-1)
	for k,Mk in enumerate(M,start=1):
		if T % Mk == 0:
			if rank == 1: return k
			rank -= 1

T = int(input())
for test in range(T):
	[B, N] = [int(i) for i in input().split()]
	M = [int(i) for i in input().split()]
	print ('Case #%d:' % (test+1), solve(N,M))
