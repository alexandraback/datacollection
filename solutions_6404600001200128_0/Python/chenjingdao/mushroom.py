f = open('a.in', 'r')
nTestCase = int(f.readline()[0:-1])
for numCase in range(0,nTestCase):
	N = int(f.readline()[0:-1])
	l = f.readline()[0:-1].split(' ')
	firstMethod=0
	secondMethod=0
	numMushrooms=int(l[0])
	for i in range(1,N):
		if int(l[i])<numMushrooms:
			firstMethod+=numMushrooms-int(l[i])
			secondMethod=max(secondMethod,0.1*(numMushrooms-int(l[i])))
		numMushrooms=int(l[i])
	count=0
	rate=int(secondMethod*10)
	for i in range(0,N-1):
		count+=min(int(l[i]),rate)
	print "Case #"+str(numCase+1)+": "+str(firstMethod)+" "+str(count)


