#!/usr/bin/env python

import itertools

numTests = int(raw_input())

for testNo in xrange(1, numTests + 1):
	n = int(raw_input())
	strs = [raw_input() for i in xrange(n)]
	unique = [''.join(c for c, _ in itertools.groupby(s)) for s in strs]
	if not all(s==unique[0] for s in unique):
		print 'Case #{0}: Fegla Won'.format(testNo)
		continue
	unique = unique[0]
	lengths = [[len(list(b)) for a, b in itertools.groupby(s)] for s in strs]
	lengths = zip(*lengths)
	totalCost = 0
	for l in lengths:
		costs = []
		for finalCount in xrange(min(l), max(l) + 1):
			costs.append(0)
			for i in l:
				costs[-1] += (abs(i - finalCount))
		totalCost += min(costs)
	print 'Case #{0}:'.format(testNo), totalCost
