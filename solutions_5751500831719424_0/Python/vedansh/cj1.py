t=input()
for i in xrange(t):
	flag=1
	n=input()
	a=[]
	for j in xrange(n):
		a.append(raw_input())
	b=[]
	c=[]
	for j in xrange(n):
		s=a[j][0]
		p=a[j][0]
		d=[]
		q=0
		d.append(1)
		for k in xrange(1,len(a[j])):
			if p != a[j][k] :
				s=s+a[j][k]
				p=a[j][k]
				q=q+1
				d.append(1)
			else:
				d[q]=d[q]+1
		c.append(d)
		b.append(s)
	k=b[0]
	for j in xrange(1,n):
		if k != b[j]:
			flag=0
			break
	if flag == 0:
		print "Case #%d: Fegla Won" %(i+1)
		continue
	q=0
	for j in xrange(len(c[0])):
		q=q+abs(c[0][j]-c[1][j])
	print "Case #%d: %d" %(i+1,q)
			
