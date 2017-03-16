#!/usr/bin/env python3

# This code jam solution is powered by Nathan West's LibCodeJam; see
# https://github.com/Lucretiel/LibCodeJam for source code and (ostensibly) some
# documentation.

from code_jam import *
import code_jam
from collections import Counter

#code_jam.INSERT_NEWLINE = True

# quick reference:
#   @autosolve, @collects, @cases(n)
#   tokens.token(t), tokens.many(n, t)
#   debug(expr), @unroll(t) gen, @trace func|gen
#   solve(int_token: int, list_token: ('int_token', str)):

parties = 'ABCDEFGHIJKLMNOPQRSTUVWXWZ'

def largest_count(counts):
	return counts.most_common(1)[0][1]

def total_count(counts):
	return sum(counts.values())

def has_majority(counts, *leavers):
	counts = counts.copy()
	counts.subtract(leavers)

	return largest_count(counts) * 2 > total_count(counts)

def to_take(counts, *leavers):
	counts = counts.copy()
	counts.subtract(leavers)

	return counts.most_common(1)[0][0]

@autosolve
@collects
def solve(N: int, P: ('N', int)):
	counts = Counter()

	for party, count in zip(parties, P):
		counts.update(party * count)

	order = []

	while total_count(counts):
		first_pick = to_take(counts)
		second_pick = to_take(counts, first_pick)

		if has_majority(counts, first_pick):
			group = first_pick + second_pick
		else:
			group = first_pick

		order.append(group)
		counts.subtract(group)

	return order
