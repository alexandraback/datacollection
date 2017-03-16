from fractions import gcd

def lcm(x,y):
	return (x*y)/gcd(x,y)
T=input()
for t in xrange(1,T+1):
	B,N=map(int,raw_input().split())
	L=map(int,raw_input().split())
	print "Case #%d:"%t,
	if(B>=N):
		print N
		continue
	l=1
	for x in L:
		l=lcm(l,x)
	m=0
	for x in xrange(B-1):
		m=max(m,abs(L[x]-L[x+1]))
	if(m==0):
		if(N%B==0):
			print B
		else:
			print N%B
		continue
	S=[False]*B
	S1=[0]*B
	time=0
	Ans=[]
	maxi=1
	i=1
	dict1={}
	count=0
	for x in L:
		count+=l/x
	while(i<=N):
		for x in xrange(B):
			if(S[x]==False):
				S[x]=not S[x]
				S1[x]=i
				i+=1
				if(i==N+1):
					ans=x+1
					print ans
		if(i==N+1):
			break
		time+=1
		for x in xrange(B):
			if(time%L[x]==0):
				S[x]=False
				maxi=S1[x]
				dict1[S1[x]]=x+1
		if(time>=l):
			N=N%count
			if(N==0):
				N=count
			print dict1[N]
			i=N+1
