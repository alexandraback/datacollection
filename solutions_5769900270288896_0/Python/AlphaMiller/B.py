from __future__ import print_function
import sys
import itertools

def calculate_score(combination, R, C, N):
	result = 0
	for p in combination:
		if (p+1)%C != 0 and p+1 in combination:
			result += 1
		if (p/C) != R-1 and p+C in combination:
			result += 1
	# print(combination, result, file=sys.stderr)
	return result

def solve():
	# parse input
	R, C, N = map(int, raw_input().split(" "))

	# solve
	minimum = float('inf')
	for combination in itertools.combinations(range(R*C), N):
		s = calculate_score(combination, R, C, N)
		if s < minimum:
			minimum = s
	return minimum

T = int(raw_input())
for case in xrange(T):
	print(case, file=sys.stderr)
	print("Case #%d: %s"%(case+1, solve()))
