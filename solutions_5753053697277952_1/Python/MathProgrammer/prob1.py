from sys import*

f=open("A-large.in","r+")
g=open("output.txt","w+")

alph="ABCDEFGHIJKLMNOPQRSTUVWXYZ"

T=int(f.readline())

for i in range(1,T+1):
	y=[]
	
	N=int(f.readline())
	
	li=[int(i) for i in f.readline().split()]
	
	max1=-1
	ind1=-1
	max2=-1
	ind2=-1
	
	for j in range(N):
		if li[j]>=max1:
			(max1,max2)=(li[j],max1)
			(ind1,ind2)=(j,ind1)
		elif li[j]>=max2:
			ind2=j
			max2=li[j]
	
	#print(max1,ind1,max2,ind2)
	
	while max1>=max2+2:
		max1-=2
		li[ind1]-=2
		y.append(alph[ind1]*2)
	
	while max1==max2+1:
		max1-=1
		li[ind1]-=1
		y.append(alph[ind1])
	
	#print(y,li)
	
	for j in range(N):
		if j!=ind1 and j!=ind2:
			while li[j]>=2:
				li[j]-=2
				y.append(alph[j]*2)
			while li[j]>0:
				li[j]-=1
				y.append(alph[j])
	
	while li[ind1]>0:
		li[ind1]-=1
		li[ind2]-=1
		y.append(alph[ind1]+alph[ind2])
	
	
	g.write("Case #{}: ".format(i))
	for j in y:
		g.write(" {}".format(j))
	g.write("\n")


f.close()
g.close()