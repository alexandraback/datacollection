def solve():
	r, c, n = map(int, raw_input().split())
	s = r * c
	best = 1 << 20
	for mask in xrange(1 << (r * c)):
		m = mask
		bits = 0
		while m > 0:
			if ((m & 1) == 1): bits += 1
			m >>= 1
		if bits != n: continue
		res = 0
		for i in xrange(r):
			for j in xrange(c):
				cur = i * c + j
				top = cur - c
				left = cur - 1
				if ((mask >> cur) & 1) == 0: continue
				if i > 0 and ((mask >> top) & 1) == 1: res += 1
				if j > 0 and ((mask >> left) & 1) == 1: res += 1
		if best > res: best = res
	return best
		

for i in xrange(input()):
	print "Case #%d: %d" % (i + 1, solve())
