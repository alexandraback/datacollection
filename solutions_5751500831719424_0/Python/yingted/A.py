#!/usr/bin/env python2
from itertools import *
from numpy import median
class FelgaWon(Exception):
	pass
for t in xrange(1,1+int(raw_input())):
	n=int(raw_input())
	a=[([(k,len(list(g)))for k,g in groupby(raw_input().rstrip('\r\n'))])for _ in xrange(n)]
	print"Case #%d:"%t,
	lengths=map(len,a)
	try:
		if lengths!=lengths[:1]*len(lengths):
			raise FelgaWon()
		cost=0
		for b in zip(*a):
			chars,counts=zip(*b)
			if chars!=chars[:1]*len(chars):
				raise FelgaWon()
			desired=int(median(counts)) # round either way
			cost+=sum(abs(x-desired)for x in counts)
		print cost
	except FelgaWon:
		print "Fegla Won"
