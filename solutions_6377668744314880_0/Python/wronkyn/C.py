#!/usr/bin/python

import sys, Queue

def compute(coords):
	needed = len(coords)

	for i in range(len(coords)):
		test = len(coords)
		for j in range(len(coords)):
			if coords[i][0]*coords[j][1] - coords[i][1]*coords[j][0] <= 0:
				test -= 1

		needed = min(needed, test)
	print needed
	return needed

def count(coords):
	output = []

	for i in range(len(coords)):
		others = []
		for j in range(len(coords)):
			if i == j:
				continue
			others.append([coords[j][0] - coords[i][0], coords[j][1] - coords[i][1]])
		output.append(compute(others))
	return str(output)

if __name__ == "__main__":
	lines = int(sys.stdin.readline())
	for i in range(lines):
		counts = int(sys.stdin.readline())
		coords = []
		for j in range(counts):
			coords.append(map(int, sys.stdin.readline().split()))

		print "Case #{0}:".format(str(i+1))
		count(coords)
