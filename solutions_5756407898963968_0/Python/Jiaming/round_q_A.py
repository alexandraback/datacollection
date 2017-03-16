#!/usr/bin/env python

import fileinput

def readCase(f):
	n1 = int(f.readline())
	mat1 = map(lambda x: map(int, x.split()), [f.readline() for i in range(4)])
	n2 = int(f.readline())
	mat2 = map(lambda x: map(int, x.split()), [f.readline() for i in range(4)])
	return n1, mat1, n2, mat2

def solve(n1, mat1, n2, mat2):
	result = set(mat1[n1-1]).intersection(set(mat2[n2-1]))
	if len(result) == 1:
		return list(result)[0]
	if len(result) == 0:
		return "Volunteer cheated!"
	return "Bad magician!"

def printResult(i, out):
	print "Case #%d: %s" % (i+1, out)

if __name__ == '__main__':
	f = fileinput.input()
	N = int(f.readline())
	for i in range(N):
		printResult(i,solve(*readCase(f)))