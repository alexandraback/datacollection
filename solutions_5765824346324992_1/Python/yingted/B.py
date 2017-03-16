#!/usr/bin/env python
from heapq import *
def get_before(n):
	before = 0
	for x in a:
		before += (n - 1) / x + 1
	return before
def search(f, y, lo, hi):
	while hi - lo > 1:
		assert f(lo) < y <= f(hi)
		mid = lo + (hi - lo) / 2
		if f(mid) < y:
			lo = mid
		else: # y <= f(mid)
			hi = mid
	return lo
for t in xrange(1, 1 + int(raw_input())):
	print 'Case #%d:' % t,
	b, n = map(int, raw_input().split())
	a = map(int, raw_input().split())
	x = search(get_before, n, 0, n * min(a))
	y = get_before(x)
	i = None
	#print 'x=%(x)d y=%(y)d' % locals()
	for i, p in enumerate(a, 1):
		if x % p == 0:
			y += 1
			if y == n:
				break
	print i
