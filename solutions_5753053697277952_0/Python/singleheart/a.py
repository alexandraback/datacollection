#!/usr/bin/python

import math

def isAnyMajority(P):
	half = sum(P) / 2
	return any(x > half for x in P)

def rescue(P):
	maxIndex = P.index(max(P))
	P[maxIndex] -= 1
	result = chr(ord('A') + maxIndex)

	if all(x == 0 for x in P):
		return result, 1

	maxIndex2 = P.index(max(P))
	P[maxIndex2] -= 1
	if isAnyMajority(P):
		P[maxIndex2] += 1
	else:
		result += chr(ord('A') + maxIndex2)
	return result, len(result)

T = input()
for t in range(1, T + 1):
	N = input()
	P = [int(x) for x in raw_input().split()]

#print N
#print P

	result = []
	while any(x > 0 for x in P):
		senators, n = rescue(P)
#print senators, n
		result.append(senators)
		N -= n

	print "Case #%d: %s" % (t, ' '.join(result))
