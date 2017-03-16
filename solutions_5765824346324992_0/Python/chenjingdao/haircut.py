def gcd(a,b):
	while b>0:
		t=b
		b=a%b
		a=t
	return a

def lcd(a,b):
	return a*b/gcd(a,b)


f = open('b.in', 'r')
nTestCase = int(f.readline()[0:-1])
for numCase in range(0,nTestCase):
	l = f.readline()[0:-1].split(' ')
	B=int(l[0])
	N=int(l[1])
	M=[0]*B
	l = f.readline()[0:-1].split(' ')
	div=1
	for i in range(0,B):
		M[i]=int(l[i])
		div=lcd(div,M[i])
	count=0
	for i in range(0,B):
		count+=div/M[i]
	N=((N-1)%count)+1
	time=[0]*B
	customer=0
	flag=True
#	print div,N
	while flag:
		minTime=time[0]
		minIndex=0
		for j in range(1,B):
			if time[j]<minTime:
				minTime=time[j]
				minIndex=j
#		print minTime,customer,minIndex,N
		time[minIndex]+=M[minIndex]
		customer+=1
		if customer==N:
			barber=minIndex+1
			break
	print "Case #"+str(numCase+1)+": "+str(barber)


