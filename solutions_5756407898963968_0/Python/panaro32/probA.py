#!/usr/bin/env python

from sys import stdin

def parse():
	r1 = int(stdin.readline())
	m1 = []
	for i in range(4):
		m1.extend(map(int,stdin.readline().split()))
	r2 = int(stdin.readline())
	m2 = []
	for i in range(4):
		m2.extend(map(int,stdin.readline().split()))
	return (r1,m1,r2,m2)

def solve(r1,m1,r2,m2):
	l1 = m1[4*(r1-1):4*r1]
	l2 = m2[4*(r2-1):4*r2]
	l = list(set(l1) & set(l2))
	return (len(l),l)

if __name__ == "__main__":
	t = int(stdin.readline())
	for i in range(t):
		(r1,m1,r2,m2) = parse()
		(c,l) = solve(r1,m1,r2,m2)
		if c == 1:
			print "Case #{0}: {1}".format(i+1,l[0])
		elif c == 0:
			print "Case #{0}: {1}".format(i+1,"Volunteer cheated!")
		else:
			print "Case #{0}: {1}".format(i+1,"Bad magician!")
