import math

T = int(raw_input())

for t in xrange(T):
	N = int(raw_input().split()[1])
	M = map(int, raw_input().split())
	R = 0

	A = [0 for i in xrange(len(M))]
	idx = 0;
	B = len(M)



	def ggt(x, y):
		while y != 0:
			x,y = y, x%y
		return x

	def kgv(x, y):
		return x * y / ggt(x, y)

	k = M[0];
	for v in M[1:]:
		k = kgv(k, v)


	pk = 0;
	for v in M:
		if k % v != 0:
			print "err"
		pk += k / v


	# print "k", k, M
	# print "n", N-1, pk, (N-1) % (pk)


	if(pk < N-1):
		N = (N-1) % (pk) +1

	for i in xrange(N):
		for j in xrange(B):
			if A[B-j-1] <= A[idx]:
				idx = B-j-1
		A[idx] += M[idx]
		# print A, i, idx


	print "Case #%d: %d" %(t+1, idx + 1)
