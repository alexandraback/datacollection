for t in range(input()):
	b,n = map(int,raw_input().split())
	
	mm = map(int,raw_input().split())
	
	for i in range(10):
		mm = mm+mm
	
	def checker(res):
		
		HA=10**30
		LA=1
		while LA<=HA:
			M=(LA+HA)/2
			dd=0
			for i in range(res):
				dd += (M+mm[i]-1)/mm[i]
			for i in range(res,b):
				dd += (M-1+mm[i]-1)/mm[i]
			if dd < n :
				LA = M+1
			else:
				HA = M-1
		return HA+1
		
	
	op = [ 10**15, b+1 ]
	for answer in range(1,b+1):
		x = checker(answer)
		if op[0] > x :
			op[0] = x
			op[1] = answer
	
	print 'Case #%d: %d' % ( t+1, op[1] )