T=input()
for t in xrange(1,T+1):
	N=input()
	L=map(int,raw_input().split())
	print "Case #%d:"%t,
	count_1=0
	m=0
	for x in xrange(N-1):
		if(L[x]>L[x+1]):
			count_1+=abs(L[x+1]-L[x])
			m=max(m,L[x]-L[x+1])
	count_2=0
	for x in L[:-1]:
		if(x>m):
			count_2+=m
		else:
			count_2+=x
	print count_1,count_2
	
