#!/usr/bin/env python

from sys import stdin

def parse():
	n = int(stdin.readline())
	a = stdin.readline().strip()
	b = stdin.readline().strip()
	return (a,b)

def change(l):
	s = ''
	for i in range(len(l)):
		if i==0:
			s += l[i]
		else:
			if l[i]!=l[i-1]:
				s += l[i]
	return s

def check(a,b):
	return change(a) == change(b)

def solve(a,b):
	x,y = len(a),len(b)
	return max(x,y) - min(x,y)

if __name__ == "__main__":
	t = int(stdin.readline())
	for i in range(t):
		(a,b) = parse()
		if not check(a,b):
			print "Case #{0}: {1}".format(i+1,'Fegla Won')
		else:
			s = solve(a,b)
			print "Case #{0}: {1}".format(i+1,s)
