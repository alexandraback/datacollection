#!/usr/bin/env python
import numpy as np
import fractions
import scipy.stats
import sys
def rank(a):
	return np.round(scipy.stats.rankdata(a, method='min')).astype(np.int) - 1
def main():
	gcd = np.frompyfunc(fractions.gcd, 2, 1)
	for t in xrange(1, 1 + int(raw_input())):
		print 'Case #%d:' % t
		print >> sys.stderr, 'input', t
		a = np.array([map(int, raw_input().split()) for _ in xrange(int(raw_input()))])
		print >> sys.stderr, 'getting normals'
		p = np.repeat(a.reshape((1, len(a), 2)), len(a), axis=0)
		q = np.repeat(a.reshape((len(a), 1, 2)), len(a), axis=1)
		diff = p - q
		c = diff
		g = np.abs(gcd(diff[:, :, 0], diff[:, :, 1])).reshape((len(a), len(a), 1))
		g = np.repeat(g, 2, axis=2)
		assert not (c[diff != 0] % g[diff != 0]).any()
		c[diff != 0] /= g[diff != 0]
		d = np.unique(c.reshape((-1, 2)).view((np.void, c.dtype.itemsize * 2))).view(c.dtype).reshape((-1, 2))
		print >> sys.stderr, 'getting dot products'
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
