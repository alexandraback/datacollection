#!/usr/bin/python2.7

for case in range(input()):
	N = input()
	data = map(int, raw_input().split())

	maxi = 0
	sol_y = 0
	for i in xrange(1, N):
		if (data[i] < data[i-1]):
			resta = data[i-1]-data[i]
			if (resta > maxi):
				maxi = resta
			sol_y += resta
	
	sol_z = 0
	for i in xrange(0, N-1):
		if (data[i] >= maxi):
			sol_z += maxi
		else:
			sol_z += data[i]

	print 'Case #%s: %s %s' % ((case + 1), sol_y, sol_z)

