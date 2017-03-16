#!/usr/bin/env python
def solve_any(a):
	amt = 0
	ret = 0
	for x in a:
		ret += max(0, amt - x)
		amt = x
	return ret
def solve_const(a):
	minrate = 0
	amt = 0
	for x in a:
		minrate = max(minrate, amt - x)
		amt = x
	amt = 0
	ret = 0
	for x in a:
		ret += min(amt, minrate)
		amt = x
	return ret
for t in xrange(1, int(raw_input()) + 1):
	print 'Case #%d:' % t,
	n = int(raw_input())
	a = map(int, raw_input().split())
	print solve_any(a), solve_const(a)
