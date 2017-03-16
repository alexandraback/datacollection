def solve(xs,N):
	#print "---"
	#print xs
	#print N
	ret = []
	total = sum(xs)
	while True:
		min = (total+1,None)
		max = (0,None)
		for i in xrange(N):
			if xs[i] < min[0]:
				min = (xs[i],i)
			if xs[i] > max[0]:
				max = (xs[i],i)

		assert min[1] is not None
		assert max[1] is not None
		if min[1] == max[1]:
			break

		ret.append([max[1]])
		total -= 1
		xs[max[1]] -= 1

		#print (xs,total,N)
		assert all(xs[i] <= total/2 for i in xrange(N))

	if total % 2 == 1:
		xs[0] -= 1
		total -= 1
		ret.append([0])
		k = 1
	else:
		k = 0

	assert all(xs[i] <= total/2 for i in xrange(N))

	assert total % 2 == 0
	while total > 0:
		(i,j) = (k % N, (k+1) % N)
		ret.append([i,j])
		total -= 2
		xs[i] -= 1
		xs[j] -= 1
		k += 2
		#print (xs,total,N)
		assert all(xs[i] <= total/2 for i in xrange(N))

	assert all(xs[i] == 0 for i in xrange(N))
	return ' '.join(''.join(chr(ord('A')+x) for x in pair) for pair in ret)

if __name__ == '__main__':
	T = int(raw_input())
	for t in xrange(T):
		N = int(raw_input())
		xs = map(int, raw_input().split())
		print "case #%d: %s" % (t+1,solve(xs,N))
