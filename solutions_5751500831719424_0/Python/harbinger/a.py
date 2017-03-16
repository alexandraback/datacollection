
def translate(x):
	i = 0
	l = '/0'
	d = []
	while i < len(x):
		if x[i] != l:
			l = x[i]
			d.append((l, 1))
		else:
			d[-1] = (d[-1][0], d[-1][1] + 1)
		i += 1
	return d

t = input()
for k in xrange(t):
	n = input()
	s = []
	l = -1
	c = 0
	f = None
	for _ in xrange(n):
		s.append(translate(raw_input()))
		if f is None:
			l = len(s[0])
			f = s[0]
			mmin = [f[z][1] for z in xrange(l)]
			mmax = [f[z][1] for z in xrange(l)]
		elif c != -1:
			if len(s[-1]) != l:
				c = -1
			else:
				for i in xrange(l):
					if f[i][0] != s[-1][i][0]:
						c = -1
						break
					else:
						mmin[i] = min(mmin[i], s[-1][i][1])
						mmax[i] = max(mmax[i], s[-1][i][1])
	if c != -1:
		for i in xrange(l):
			z = 100000
			for j in xrange(mmin[i], mmax[i] + 1):
				w = 0
				for p in xrange(n):
					w += abs(s[p][i][1] - j)
				z = min(w, z)
			c += z

	print 'Case #{0}: {1}'.format(k + 1, 'Fegla Won' if c == -1 else c)
