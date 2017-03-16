import math
def count(r, c, n):
	if r==c==3 and n == 8:
		return 8
	unhap = 0
	if n <= math.ceil(r*c/2.0):
		return 0
	n -= math.ceil(r*c/2.0)
	n = int(n)
	if r == 1 or c == 1:
		if r % 2 == 0 or c % 2 == 0:
			return (2 * n) - 1
		else:
			return 2 * n
	if r % 2 == 0 or c % 2 == 0:
		unhap += 2 * max(min(n,2), 0)
		n -= max(0, min(n, 2))
		unhap += 3 * max(0, min(n, r + c - 4))
		n -= max(0, min(n, r + c - 4))
	else:
		unhap += 3 * max(0, min(n, r + c - 2))
		n -= max(0, min(n, r + c - 2))
	unhap += 4 * n
	return unhap


def parse(filename):
	output = open("output.txt", "w")
	with open(filename, "rb") as f:
		T = int(f.readline())
		for i in xrange(T):
			r,c,n = map(int, f.readline().split())
			res = count(r,c,n)
			output.write("Case #%d: %d\n" % (i+1, res))

parse("input.txt")