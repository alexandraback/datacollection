import sys

def gcd(a, b):
	if a < b:
		a, b = b, a
	while b != 0:
		a, b = b, a % b
	return a

def lcm(a, b):
	return a * b / gcd(a, b)

def blcm(array):
	g = array[0]
	for x in array[1:]:
		g = lcm(g, x)
	return g

def caln(array):
	num = blcm(array)
	return sum(num / x for x in array)

def solve(b, n, m):
	n %= caln(m)
	if n == 0:
		n = caln(m)
	if n <= b:
		return n
	n -= b
	times = m[:]
	while n > 1:
		mt = min(times)
		it = times.index(mt)
		n -= 1
		times[it] += m[it]
	mt = min(times)
	it = times.index(mt)
	return it + 1

with open(sys.argv[1]) as f:
	t = int(f.readline())
	for i in range(t):
		line1 = f.readline()
		line2 = f.readline()

		b, n = line1.split()
		m = line2.split()
		result = solve(int(b), int(n), [int(mi) for mi in m])
		print "Case #%d: %d" % (i+1, result)
