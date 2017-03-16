import fileinput
stdin = fileinput.input()

import math

def det(p,q):
	return p[0]*q[1]-p[1]*q[0]

def solveCase():
	n = map(int,stdin.next().split())[0]
	xys = [ tuple(map(int,stdin.next().split())) for i in range(n) ]
	nums = []
	for xy in xys:
		cycle = sorted([(p[0]-xy[0],p[1]-xy[1]) for p in xys if p!=xy],key=lambda p:math.atan2(p[1],p[0]))
		cycle = cycle*3
		m = n
		hi = 0
		b = False
		lo = 0
		# print xy
		while lo<len(cycle):
			while hi<=lo or det(cycle[lo],cycle[hi])>0:
				hi += 1
				if hi>=len(cycle):
					if hi-lo>=n-1:
						m = 0
					b = True
					break
			if b:
				break
			while lo<hi and det(cycle[lo],cycle[hi])==0:
				lo += 1
			if hi>=lo+n-1:
				m = 0
			# print hi-lo
			if hi-lo<m:
				m = hi-lo
			lo += 1
		nums.append(m)
	return '\n'+'\n'.join(map(str,nums))

for case in xrange(int(stdin.next())):
	print "Case #{0}:{1}".format(case+1,solveCase())