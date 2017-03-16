import sys

lines = sys.stdin.readlines()

def testcase(t):
	N = int(lines[2 * t - 1])
	vals = map(int, lines[2 * t].split())

	x = 0
	maxdec = 0
	for i in xrange(N - 1):
		if (vals[i + 1] < vals[i]):
			x += vals[i] - vals[i + 1]
			maxdec = max(maxdec, vals[i] - vals[i + 1])

	y = 0
	for i in xrange(N - 1):
		y += min(maxdec, vals[i])

	print "Case #%d: %d %d" % (t, x, y)

T = int(lines[0])
for t in xrange(1, T + 1):
	testcase(t)