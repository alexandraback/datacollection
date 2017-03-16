#!/usr/bin/env python3

from itertools import *

def read_ints():
	return map(int, input().strip().split())

def ret(num, res):
	print("Case #{}: {}".format(num, res))

"""
def findval(row):
	minchange = float('inf')
	for num in row:
		change = 0
		for other in row:
			change += abs(num-other)
		minchange = min(change, minchange)

	return minchange
"""

def findval(row):
	row = list(row)
	row.sort()
	mid = row[len(row)//2]

	change = 0
	for num in row:
		change += abs(num-mid)
	return change


def test(tnum):
	n, = read_ints()
	strs = [ input().strip() for _ in range(n) ]

	chars = None
	rep = []

	impossible = False

	for x in strs:
		rt = []
		cht = []
		last = None
		for c in x:
			if c == last:
				rt[-1] += 1
			else:
				rt.append(1)
				cht.append(c)
				last = c

		if chars == None:
			chars = cht
		else:
			if chars != cht:
				impossible = True

		rep.append(rt)

	if impossible:
		ret(tnum, "Fegla Won")
		return

	res = 0
	byrow = zip(*rep)
	for row in byrow:
		res += findval(row)

	ret(tnum, res)
			

	

T, = read_ints()

for x in range(1, T+1):
	test(x)
