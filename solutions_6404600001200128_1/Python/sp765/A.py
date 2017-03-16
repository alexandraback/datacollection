#!/usr/bin/python

import sys
import math

def solve1(N, m):
	total = 0
	for i in range(0, N-1):
		if m[i+1] < m[i]:
			total += m[i] - m[i+1]
	return total



def solve2(N, m):
	highest = 0
	for i in range(0, N-1):
		if m[i] > m[i+1]:
			highest = max(highest, m[i] - m[i+1])
	total = 0
	#print highest
	for i in range(0, N-1):
		total += min(highest, m[i])
	return total

if __name__ == "__main__":
	T = int(sys.stdin.readline())

	for t in range(T):
		N = int(sys.stdin.readline())
		m = map(int, sys.stdin.readline().split())
		# s = sys.stdin.readline()
		print "Case #{}: {} {}".format(t+1, solve1(N, m), solve2(N, m))
