for t in range(input()):
	
	b,n = map(int,raw_input().split())
	m = map(int,raw_input().split())
	
	for i in range(10):
		m = m+m
	
	def found(res):
		L=1
		H=10**30
		while L<=H:
			M=(L+H)/2
			done=0
			for i in range(res):
				done += (M+m[i]-1)/m[i]
			for i in range(res,b):
				done += (M-1+m[i]-1)/m[i]
			if done < n :
				L = M+1
			else:
				H = M-1
		return H+1
	
	out = [ 10**15, b+1 ]
	for ans in range(1,b+1):
		x = found(ans)
		if out[0] > x :
			out[0] = x
			out[1] = ans
	
	print 'Case #%d: %d' % ( t+1, out[1] )