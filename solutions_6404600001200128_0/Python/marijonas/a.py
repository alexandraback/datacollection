import sys

def method1(l):
	a = 0
	for i in xrange(1, len(l)):
		a += max(0, l[i-1] - l[i])
	return a

def method2(l, rate):
	a = 0
	for i in xrange(0, len(l)-1):
		a += min(rate, l[i])
	return a

def solve():
	sys.stdin.readline()
	m = map(int, sys.stdin.readline().split())
	rate = max(max(p - q for p, q in zip(m, m[1:])), 0)
	return method1(m), method2(m, rate)

t = int(sys.stdin.readline())
for i in xrange(1, t+1):
	print 'Case #%d: %d %d' % ((i,) + solve())