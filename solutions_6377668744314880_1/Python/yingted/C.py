#!/usr/bin/env python
import numpy as np
import fractions
import scipy.stats
import sys
def rank(a):
	return np.round(scipy.stats.rankdata(a, method='min')).astype(np.int) - 1
def dip(a, o, b):
	a = a - o
	b = b - o
	return a[0] * b[1] - b[0] * a[1] < 0
def tophull(a):
	assert ((-1000000 <= a) & (a <= 1000000)).all()
	a = a[np.lexsort((a[:, 1], a[:, 0]))]
	if len(a) < 3:
		return a
	h = [np.array((a[0][0], a[0][0] - 1)), a[0]]
	for i in xrange(1, len(a)):
		r = a[i]
		while True:
			p, q = h[-2:]
			if dip(p, q, r) and len(h) > 2:
				h.pop()
			else:
				break
		h.append(r)
	return np.array(h[1:])
def hull(a):
	assert ((-1000000 <= a) & (a <= 1000000)).all()
	b = np.concatenate((tophull(a), -1 * tophull(-1 * a)))
	_, indices = np.unique(b.view((np.void, 2 * b.dtype.itemsize)), return_index=True)
	return b[indices]
def main():
	gcd = np.frompyfunc(fractions.gcd, 2, 1)
	for t in xrange(1, 1 + int(raw_input())):
		print 'Case #%d:' % t
		print >> sys.stderr, 'input', t
		a = np.array([map(int, raw_input().split()) for _ in xrange(int(raw_input()))])
		print >> sys.stderr, 'getting normals'
		b = a
		diff = []
		while len(b):
			_h = hull(b)
			h = list(_h)
			for h1, h2 in zip(h + h[:0], h[-1:] + h):
				diff.append(np.array(h2) - np.array(h1))
			b = np.array(list(set(map(tuple, b)) - set(map(tuple, _h))))
		diff = np.array(diff)
		print >> sys.stderr, 'getting gcds'
		g = np.abs(gcd(diff[:, 0], diff[:, 1])).reshape((len(diff), 1))
		g = np.repeat(g, 2, axis=1)
		c = diff
		assert not (c[diff != 0] % g[diff != 0]).any()
		print >> sys.stderr, 'dividing'
		c[diff != 0] /= g[diff != 0]
		d = np.unique(c.reshape((-1, 2)).view((np.void, c.dtype.itemsize * 2))).view(c.dtype).reshape((-1, 2))
		print >> sys.stderr, 'getting dot products', len(d)
		out = [[len(a) - 1] * len(a)]
		for n in d:
			if n.any():
				dots = np.dot(a, [-n[1], n[0]])
				out.append(rank(dots))
		out = np.array(out)
		ans = out.min(axis=0)
		for x in ans:
			print x
if __name__ == '__main__':
	main()
