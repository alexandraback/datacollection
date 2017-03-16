#!/usr/bin/python

import sys

def count(cakes):
	last = 0
	minA = 0
	minB = 0
	minRate = 0

	for i in cakes:
		eaten = max(0, last - i)
		minA += eaten
		
		minRate = max(minRate, eaten)
		last = i

	last = 0
	for i in cakes:
		minB += min(minRate, last)
		last = i

	return str(minA) + " " + str(minB)

if __name__ == "__main__":
	lines = int(sys.stdin.readline())
	for i in range(lines):
		sys.stdin.readline()
		cakes = map(int, sys.stdin.readline().strip().split())
		print "Case #{0}: {1}".format(str(i+1), count(cakes))
