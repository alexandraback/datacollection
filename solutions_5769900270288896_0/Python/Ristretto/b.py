T=int(raw_input())

for i in range(T):
	uh = 0
	il = map(int, str(raw_input()).split(" "))
	R = il[0]
	C = il[1]
	N = il[2]

	min_uh = 2*R*C-R-C	#Max

	l=[]
	for j in range(R):
		l.append([0]*C)
	for j in range(2**(R*C)):
		bitsum=0
		bl = list(map(int, str(bin(j))[2:]))
		bl.reverse()
		for k in range(R*C-len(bl)):
			bl.append(0)
		bl.reverse()
		#print "DEBUG: bl: %s" %(bl)
		if sum(bl)==N:
			uh = 0
			for k in range(R*C):
				l[k/C][k%C] = bl[k]
			for ki in range(R):
				for kj in range(C):
					if R!=1:
						if ki==0:
							if(l[ki][kj] and l[ki+1][kj]): uh+=1
						elif ki==(R-1):
							if(l[ki][kj] and l[ki-1][kj]): uh+=1
						else:
							if(l[ki][kj] and l[ki+1][kj]): uh+=1
							if(l[ki][kj] and l[ki-1][kj]): uh+=1
					if C!=1:
						if kj==0:
							if(l[ki][kj] and l[ki][kj+1]): uh+=1
						elif kj==(C-1):
							if(l[ki][kj] and l[ki][kj-1]): uh+=1
						else:
							if(l[ki][kj] and l[ki][kj+1]): uh+=1
							if(l[ki][kj] and l[ki][kj-1]): uh+=1
			uh/=2
			#print "DEBUG: %s->%d" %(l,uh)
			if min_uh>uh:
				min_uh=uh

	print "Case #%d: %d" % (i+1, min_uh)
