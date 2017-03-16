testcases = int(raw_input().strip())

def getNoise(table, R, C):
	tot = 0
	for r in xrange(R):
		for c in xrange(C):
			pos = 0
			if (table >> (r*C+c))%2 == 1:
				top = (table >> ((r-1)*C+c))%2 if r > 0 else 0
				left = (table >> (r*C+c-1))%2 if c > 0 else 0
				right = (table >> (r*C+c+1))%2 if c < C-1 else 0
				bott = (table >> ((r+1)*C+c))%2 if r < R-1 else 0
				pos = top+left+right+bott
			tot = tot + pos
	return tot/2


def countOnes(num):
	count = 0
	while num>0:
		count += num%2
		num = num/2
	return count


def bruteForce2(R,C,N):
	best = 2**31
	for i in xrange(2**(R*C)):
		if countOnes(i) == N:
			best = min(best, getNoise(i,R,C))
	return best



for testcase in xrange(testcases):
	R, C, N = map(int,raw_input().split())		
	
	res = bruteForce2(R, C, N)		


	print "Case #%d:" % (1+testcase), res
