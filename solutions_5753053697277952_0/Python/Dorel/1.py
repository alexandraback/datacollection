from string import uppercase

def top(p):
	if p[0]>p[1] :
		mx1,mx2,i1,i2=p[0],p[1],0,1
	else :
		mx1,mx2,i1,i2=p[1],p[0],1,0
	for i in xrange(len(p)-2):
		if p[i+2]>mx1 :	
			mx1,mx2,i1,i2=p[i+2],mx1,i+2,i1
		elif p[i+2]>mx2 :
			mx2,i2=p[i+2],i+2	
	return uppercase[i1],uppercase[i2],i1,i2
	
	
T=int(raw_input())
for test in xrange(1,T+1):
	N=int(raw_input())
	p=[int(x) for x in raw_input().split()]
	ans,S='',sum(p)
	while (S>0) :
		s1,s2,i1,i2=top(p)
		if ((2*p[i1]>S and 2*p[i2]<S) or p[i2]==0) : 
			ans+=' '+s1
			p[i1]=p[i1]-1
			S-=1
		else :   
			p[i1],p[i2]=p[i1]-1,p[i2]-1
			S-=2
			if 2*max(p)<S+1 : ans+=' '+s1+s2
			else :
				p[i2]=p[i2]+1
				S+=1 
				ans+=' '+s1
			
	print "Case #%d:"%test,ans	 
