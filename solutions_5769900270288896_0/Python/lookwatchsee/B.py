#!/usr/bin/python

T=input()
def cal(R,C,p):
	m=[[False]* C for _ in xrange(R)]
	for e in p: m[e/C][e%C]=True
	cnt=0
	for i in xrange(R):
		for j in xrange(C):
			if not m[i][j]: continue
			right=j+1
			down=i+1
			if right<C and m[i][right]: cnt+=1
			if down<R and m[down][j]: cnt+=1
	return cnt

def gen_C(m,n,p,v):
	if n==0: 
		v.append(p)
		return
	if m+1<=n:
		v.append( p+range(m,-1,-1))
		return
	p.append(m)
	gen_C(m-1,n-1,p,v)
	del p[-1]
	gen_C(m-1,n,p,v)
	
for t in xrange(1,T+1):
	R,C,N = map(int, raw_input().split())
	v=[]
	gen_C(R*C-1, N, [], v)
#	print v
	l=[cal(R,C,e) for e in v if len(e)>0]
#	print l
	if len(l)==0: ans=0
	else: ans= min(l)
	print "Case #%d:"%t,ans	
