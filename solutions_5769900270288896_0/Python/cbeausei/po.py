fin=open("C:/users/Clement/Desktop/bla.txt","r")
fout=open("C:/users/Clement/Desktop/output.txt","w")

s=fin.read().split("\n")
z=int(s[0])

for i in range(z):
	t=s[i+1].split(" ")
	n=int(t[2])
	r=int(t[0])
	c=int(t[1])
	a=r//2
	b=r-a
	x=c//2
	y=c-x
	m=y*b+x*a
	v=0
	aa=0
	if r==3:
		if n//c==0:aa=(n-1)
		if n//c==1:aa=(c-1)+(n-c-1)
		if n//c==2:aa=2*(c-1)+(n-2*c-1)+2*(n-2*c)
	bb=0
	if c==3:
		if n//r==0:bb=(n-1)
		if n//r==1:bb=(r-1)+(n-r-1)
		if n//r==2:bb=2*(r-1)+(n-2*r-1)+2*(n-2*r)
	if r==2:
		if n>c:
			k=n-c
			if k<=2:v=2*k
			else:
				v=4+3*(k-2)
	elif c==2:
		if n>r:
			k=n-r
			if k<=2:v=2*k
			else:
				v=4+3*(k-2)
	else:
		nn=n
		if n<=m:v=0
		else:
			n-=m
			d=a+x
			if (c%2)==0:d+=b
			else:d+=a
			if (r%2)==0:d+=y
			else:d+=x
			e=0
			if (r%2)==0:e+=2
			if (c%2)==0:e+=2
			if ((r%2)==0) and ((c%2)==0):e-=1
			d-=e
			if n<=e:
				v=2*n
			elif n<=d:
				v+=2*e+3*(n-e)
			else:
				v+=2*e+3*(d-e)
				n-=d
				v+=4*n
		w=0
		n=nn
		p=r*c-m
		if n<=p:w=0
		else:
			n-=p
			d=a+x
			if (c%2)==0:d+=b
			else:d+=a
			if (r%2)==0:d+=y
			else:d+=x
			e=0
			if (r%2)==0:e+=2
			if (c%2)==0:e+=2
			if ((r%2)==0) and ((c%2)==0):e-=1
			d-=e
			d=2*r+2*c-2-d
			e=4-e
			if n<=e:
				w=2*n
			elif n<=d:
				w+=2*e+3*(n-e)
			else:
				w+=2*e+3*(d-e)
				n-=d
				w+=4*n
		if w<v:v=w
	if aa!=0 and aa<v:v=aa
	if bb!=0 and bb<v:v=bb
	print(v)
	fout.write("Case #"+str(i+1)+": "+str(v)+"\n")