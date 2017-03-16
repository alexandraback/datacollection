for c in xrange(1,input()+1):
	N=input()
	P=map(lambda x:int(x),raw_input().strip().split())
	
	evac = []
	
	while sum(P) != 0:
		mx = max(P)
		index = P.index(mx)
		
		if P.count(mx) == 2:
			P[index] -=1
			
			t = chr(65+index)
			
			index = P.index(mx)
			P[index] -= 1
			
			evac.append(t+chr(65+index))
		else:
			P[index] -= 1
			evac.append(chr(65+index))
	
	print "Case #%d: %s" % (c," ".join(evac))