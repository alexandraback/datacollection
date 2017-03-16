#!/usr/bin/env python
# -*- coding: utf-8 -*-

def solve(bn, m):
	b, n = map(int, bn.split())
	m = map(int, m.split())

	product = 1
	for i in range(b):
		product *= m[i]

	cycle = 0
	for i in range(b):
		cycle += product / m[i]

	n = (n-1) % cycle + 1

	if n <= b:
		return n
	else:
		n -= b
	time = 1
	while n > 0:
		for i in range(b):
			if time % m[i] == 0:
				n -= 1
				if n == 0:
					return i + 1
		time += 1


if __name__ == "__main__":
    testcases = input()
     
    for caseNr in xrange(1, testcases+1):
        bn = raw_input()
        m = raw_input()
        print("Case #%i: %s" % (caseNr, solve(bn, m)))