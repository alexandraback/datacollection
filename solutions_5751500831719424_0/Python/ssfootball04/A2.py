import fileinput

f=fileinput.input()
T=int(f.readline())
g=open('output','w')

def solve(K):
	A=[]
	for st in K:
		s,t=st[0],st[0]
		j,l=1,1
		x=[]
		while(j<len(st)):
			if(st[j]==t):
				l=l+1	
			else:
				x.append(l)
				l=1
				t=st[j]
				s=s+t
			j=j+1
		A.append((s,x))

	chk,check=A[0][0],1	
	for st in A:
		if(st[0]!=chk):		
			check=0
			break
	if(check==0):
		return("Fegla Won")
	else:
		sm=0		
		for i in range(len(A[0][1])):
			a=[]
			for st in A:
				a.append(st[1][i])
			a.sort()
			an=a[((len(a)+1)/2)-1]
			swp=0
			for j in a:
				swp=swp+abs(j-an)
			sm=sm+swp
		return str(sm)			

for l in range(T):
	N=int(f.readline())
	K=[]
	k=0
	while(k!=N):
		line=f.readline()	
		K.append(line)
		k=k+1	
	ans=solve(K)
	g.write( 'Case #'+str(l+1)+': '+ans+"\n")
