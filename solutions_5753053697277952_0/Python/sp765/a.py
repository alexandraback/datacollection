#!/usr/bin/python

import sys
import math

def equal(a,b):
	return math.rabs(a-b) <= 0.000001

def count(P):
	c = 0
	for p in P:
		if p != 0:
			c += 1
	return c


def solve(N, P):
	str = ''
	while True:
		if count(P) > 2:
			Max = max(P)
			I = None
			for i in range(N):
				if P[i] == Max:
					I = i
					break
			str += ' ' + chr(65+I)
			P[I] -= 1
		else:
			Max = max(P)
			I = None
			J = None
			for i in range(N):
				if P[i] == Max and I == None:
					I = i
				elif P[i] == Max and I != None:
					J = i

			if J == None:
				str += ' ' + chr(65+I)
				P[I] -= 1
			else:
				str += ' ' + chr(65+I) + chr(65+J) 
				P[I] -= 1
				P[J] -= 1

		if count(P) == 0:
			break

	return str

if __name__ == "__main__":
	T = int(sys.stdin.readline())

	for t in range(T):
		N = int(sys.stdin.readline())
		P = map(int, sys.stdin.readline().strip().split())
		print "Case #{}: {}".format(t+1, solve(N, P))
