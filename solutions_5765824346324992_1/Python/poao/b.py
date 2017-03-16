from sys import stdin
import sys
from fractions import gcd

def lcm(a, b):
	return a*b/gcd(a,b)

def lcmm(*args):
	return reduce(lcm, args)

def calc(t, m):
	if t < 0:
		return 0
	ans = 0
	for mi in m:
		ans += t/mi + 1
	return ans

def calc2(t, n, m):
	n -= calc(t-1, m)
	for i in xrange(len(m)):
		if t%m[i] == 0:
			n -= 1
			if n == 0:
				return i+1
	return -1

fin = open("B-large.in", 'r') #stdin

T = int(fin.readline())

for tc in xrange(T):
	(B,N) = map(int, fin.readline().split(' '))
	m = map(int, fin.readline().split(' '))
	max_m = max(m)
	rb = min( [lcmm(*m) - 1, max_m * N / len(m)] )
	lb = 0
	iter_count = calc(rb, m)
	N %= iter_count
	if N == 0:
		N = iter_count
	print >> sys.stderr, "lcm %d d iter %d" % (rb, iter_count)
	#print "rb = %d N = %d" % (rb, N)
	while lb < rb:
		mid = (lb+rb)/2
		#print "test %d: %d" % (mid, calc(mid,m))
		if calc(mid, m) < N:
			lb = mid+1
		else:
			rb = mid
	print "Case #%d: %d" % (tc+1, calc2(lb, N, m ))
