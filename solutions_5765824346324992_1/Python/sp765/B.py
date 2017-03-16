#!/usr/bin/python

import sys
import math

def computeTotal(T, M):
	total = 0
	for Mi in M:
		total += int(math.ceil(float(T) / Mi))
	return total

def binSearch(L, U, B, N, M):
	if L >= U - 10:
		return L
	mid = (L+U)/2

	T = mid
	total = 0
	for Mi in M:
		total += int(math.ceil(float(T) / Mi))
	#print L, U
	if total < N:
		return binSearch(mid, U, B, N, M)
	else:
		return binSearch(L, mid, B, N, M)

def solve(B, N, M):
	if N <= B:
		return N
	T = 1
	while True:
		total = 0
		for Mi in M:
			total += int(math.ceil(float(T) / Mi))
		#print "T: ", T, total
		if total < N:
			T = T*2
		else:
			break
	L = T/2
	U = T

	#print L, U, total, N
	#return 1

	T = binSearch(L, U, B, N, M)
	total = computeTotal(T, M)

	acc = [Mi*int(math.ceil(float(T) / Mi)) for Mi in M]

	while total < N:
		#print total, acc
		minA = -1
		minI = -1
		for i in range(B):
			if minA == -1 or acc[i] < minA:
				minA = acc[i]
				minI = i
		acc[minI] = acc[minI] + M[minI]
		total += 1
		if total == N:
			return minI+1

	#print "END"
	return -1


if __name__ == "__main__":
	T = int(sys.stdin.readline())

	for t in range(T):
		B, N = map(int, sys.stdin.readline().split())
		M = map(int, sys.stdin.readline().split())
		print "Case #{}: {}".format(t+1, solve(B, N, M))
