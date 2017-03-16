get = lambda: map(int, raw_input().split())

T, = get()

for testCase in range(1, T+1):
	N, = get()
	l = get()

	a = 0
	c = 0
	for v in l:
		if c > v:
			a += c - v
		c = v

	b = 0
	biggestDecrease = max(l[i-1] - l[i] for i in range(1, len(l)))
	
	if biggestDecrease > 0:
		for v in l[:-1]:
			b += min(v, biggestDecrease)

	print 'Case #%d: %d %d' % (testCase, a, b)