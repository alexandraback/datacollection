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
	for k in xrange(len(c[0])):
		
		v=0
		for p in xrange(1,101):
			x=0
			for j in xrange(n):
				x=x+abs(c[j][k]-p)
			if p== 1:
				v=x
			elif x<v:
				v=x

		q=q+v
	print "Case #%d: %d" %(i+1,q)
			
