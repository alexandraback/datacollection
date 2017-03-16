from __future__ import print_function
import sys
import itertools

def solve():
	# parse input
	N = int(raw_input())
	m = map(int, raw_input().split())

	# solve
	maxshift = 0
	out1 = 0
	for i in range(N-1):
		maxshift = max(maxshift, m[i] - m[i+1])
		out1 += max(0, m[i] - m[i+1])

	print(maxshift, file=sys.stderr)
	out2 = 0
	for i in range(N-1):
		out2 += min(maxshift, m[i])

	return str(out1) + " " + str(out2)

T = int(raw_input())
for case in xrange(T):
	print(case, file=sys.stderr)
	print("Case #%d: %s"%(case+1, solve()))
