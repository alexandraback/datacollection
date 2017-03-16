from __future__ import print_function
import sys
import itertools

def solve():
	# parse input
	B, N = map(int, raw_input().split())
	M = map(int, raw_input().split())

	# solve
	if N <= B:
		return N
	r = sum(1/float(m) for m in M)
	t = int((N-B-1)/r)

	# print(r, file=sys.stderr)
	# print(t, file=sys.stderr)
	b = []
	N2 = N
	for barber in M:
		N2 -= t/barber + 1
		b.append(barber - t%barber)

	while N2>0:
		# print(N2, b, file=sys.stderr)
		bmin = min(b)
		b = map(lambda x:x-bmin, b)
		for barber in range(len(b)):
			if b[barber]==0:
				if N2==1:
					return barber+1
				b[barber] = M[barber]
				N2 -= 1
	assert False


T = int(raw_input())
for case in xrange(T):
	print(case, file=sys.stderr)
	print("Case #%d: %s"%(case+1, solve()))
