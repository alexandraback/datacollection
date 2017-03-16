T = int(raw_input())

def ncut(t,times):
	n=0
	if t<0:
		return 0
	for m in times:
		n += t/m + 1
	return n

def who(N,t,times):
	left = N - ncut(t-1,times)
	for i,m in enumerate(times):
		if t%m == 0:
			left-=1
			if left==0:
				return i+1

for c in xrange(T):
	B,N = map(int,raw_input().strip().split())
	times = map(int,raw_input().strip().split())
	if N <= B:
		print 'Case #'+str(c+1)+':',N
		continue
	stimes = times[:]
	stimes.sort()
	t2 = (N-B)*stimes[0]
	t1 = 1
	mid = (t1+t2)/2
	result = ncut(mid,times)
	while True:
		if t2-t1 == 1:
			mid = t2
			break
		mid = (t1+t2)/2
		result = ncut(mid,times)
		#print t1,t2,result,N
		if result < N:
			t1 = mid
		else:
			t2 = mid
	print 'Case #'+str(c+1)+':',who(N,mid,times)
