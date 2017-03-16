import sys

T = int(sys.stdin.readline())

def way1(a):
	s = 0
	for i in range(0, len(a)-1):
		if a[i] > a[i+1]:
			s += a[i] - a[i+1]
	return s

def way2(a):
	m_diff = 0
	for i in range(0, len(a)-1):
		m_diff = max(a[i] - a[i+1], m_diff)
	s = 0
	for i in range(0, len(a)-1):
		s += min(m_diff, a[i])
	return s

def solve():
	sys.stdin.readline()
	a = map(int, sys.stdin.readline().strip().split(' '))
	print way1(a),
	print way2(a),

for i in range(1, T+1):
	print "Case #%d: " % i,
	solve()
	print
