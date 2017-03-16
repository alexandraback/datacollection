from itertools import *


def ceildiv2(x):	
	if (x % 2 == 0):
		return x / 2
	else:
		return x / 2 + 1

def unhappiness(r, c, n):
	rc = r * c
	b = ceildiv2(rc)
	print b
	if (n <= b):
		return 0
	
	res = 2 * rc
	for s in combinations(set(range(1, rc + 1)), n):
		u = 0
		print s
		if (r == 1):
			for x in s:
				if (x + 1) in s:
					u += 1
		else:		
			for x in s:
				if ((x % r) <> 0) and ((x + 1) in s):
					u += 1	
				if ((x + r) in s):
					u += 1
				
		if (u < res):
			res = u
			
	return res
	'''res = 0	
	rem  = n - b
	if (r * c % 2 == 0):
		res += min(rem, 2) * 2
		rem -= 2
	if (rem > 0):
		res += rem  * 3
	print res
	return res'''
	
inf = open("b.in", 'r')
outf = open("b.out", 'w')

t = int(inf.readline())
	
for k in xrange(0, t):
	r, c, n = map(int, inf.readline().split())		
	outf.write("Case #" + str(k + 1) + ": ")	
	outf.write(str(unhappiness(r, c, n)) + "\n")
outf.close()
		
	
