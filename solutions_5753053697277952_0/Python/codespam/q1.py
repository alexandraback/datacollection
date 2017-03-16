#!/usr/bin/env pypy

import sys

d = sys.stdin.readlines()

for i in range(int(d[0])):
	print 'Case #%d:' % (i + 1),

	ps = map(int, d[1 + i * 2 + 1].split())

	pds = dict((chr(ord('A') + j), p) for j, p in enumerate(ps))

	while any(pds.values()):
		m = sorted(pds, key=lambda j: -pds[j])

		r = m[0]
		#print 'rem',m[0]
		pds[m[0]] -= 1
		if any(pds[k] > sum(pds.values()) / 2 for k in pds):
			#print 'rem',m[1]
			r += m[1]
			pds[m[1]] -= 1

		print r,
		#print 'o', pds

		assert r
		assert not any(pds[k] > sum(pds.values()) / 2 for k in pds)

	print
