import sys
import os

T = int(sys.stdin.readline())

for t in xrange(T):
	N = int(sys.stdin.readline())
	m = map(int, sys.stdin.readline().strip().split())

	summ = 0
	maxdecr = 0
	for i in xrange(len(m)-1):
		if m[i+1] < m[i]:
			summ += m[i] - m[i+1]
			maxdecr = max(maxdecr, m[i] - m[i+1])

	summ2 = 0
	for i in xrange(len(m)-1):
		summ2 += min(m[i], maxdecr)

	sys.stdout.write('Case #{0}: {1} {2}\n'.format(t+1, summ, summ2))


