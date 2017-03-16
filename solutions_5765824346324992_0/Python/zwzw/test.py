import sys
sys.stdin=open('input.txt', 'r'); sys.stdout=open('output.txt', 'w')

R=lambda:map(int,raw_input().split())
def gcd(x,y):
	while x and y:
		if x>y:
			x%=y
		else:
			y%=x
	return x+y
for _ in range(input()):
	n,k=R()
	t=R()
	if n>=k:
		ans=k
	else:
		lcm=reduce(lambda x,y: x*y/gcd(x,y), t, 1)
		q=[[] for i in range(n)]
		f=list(t)
		for i in range(n): q[i].append(i)
		cnt=n
		
		while 1:
			mi=min(f)
			i=f.index(mi)
			if mi==lcm:
				break
			q[i].append(cnt)
			f[i]+=t[i]
			cnt+=1
		k-=1
		r=k%cnt
		ans=-1
		#print q, cnt, k
		for i in range(n):
			for x in q[i]:
				if x==r:
					ans=i+1
					break
			if ans>-1:
				break

	print 'Case #%d: %s' % (_+1, ans)