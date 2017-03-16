import fractions
def gcd(values):
	return reduce(fractions.gcd, values)	
def lcm(values):
	return reduce(lambda x,y: x*y/gcd([x,y]), values)
def peeps(m):
	l=lcm(m)
	return sum([l/i for i in m])

# inp=open('in.in','r')
f=open('out.out', 'w')
# t=int(inp.readline().strip('\n'))
t=input()
for tc in range(1,t+1):
	b,p=map(int, raw_input().split())
	m=map(int, raw_input().split())

	k=peeps(m)
	n = p%k
	print n
	if n==0:n=k

	t=0
	while n>0:
		for i,v in enumerate(m):
			if t%v==0:
				n-=1
			if n==0:
				ans = i+1
				break
		t+=1
		print n

	f.write("Case #"+str(tc)+": "+str(ans)+"\n")
	print "Case #%i: %s" % (tc, ans)
