def maxind(arr):
	max=0
	max_i=-1
	for i in range(len(arr)):
		if arr[i]>max:
			max=arr[i]
			max_i=i
	return max_i

def maj(np):
	m=max(np)
	c=0
	for i in np:
		if i>0:
			c+=1
	if m>sum(np)/c or c==1:
		return True
	return False

fin=open('a_large.in','r')
fout=open('a_large.out','w')

T=int(fin.readline())

for t in range(T):
	s=""
	n=int(fin.readline())
	np=[]
	temp=fin.readline().split()
	for i in temp:
		np.append(int(i))
	sp=sum(np)
	l=[]
	while sp>0:
		i=maxind(np)
		l.append(i)
		np[i]-=1
		sp-=1
	l=l[::-1]
	np0=[0 for i in range(n)]
	while len(l)>1:
		s+=chr(l[0]+65)
		np0[l[0]]+=1
		l=l[1:]
		if maj(np0):
			np0[l[0]]+=1
			s+=chr(l[0]+65)
			l=l[1:]
		s+=" "
	if len(l)==1:
		s+=chr(l[0]+65)
		s+=" "
	s=s[:-1]
	fout.write("Case #%d: %s\n" % (t+1,s[::-1]))
fin.close()
fout.close()