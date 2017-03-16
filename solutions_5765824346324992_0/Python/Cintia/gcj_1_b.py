import math

fin = open('B-small-attempt3.in', 'r')
fout = open('out.txt', 'w')

T = int(fin.readline())

for t in xrange(T):
	B, N = fin.readline().split()
	m = fin.readline().split()
	maximo = 0
	outfl = 0
	res = 0
	
	for i in xrange(int(B)):
		maximo = max(maximo, int(m[i]))
		
	maxT = maximo*int(N)
	minT=0
	trial = 2*maxT
	
	while outfl<=0:
		curr0 = 0
		curr1 = 0
		trial = int((maxT+minT)/2)
		for i in xrange(int(B)):
			curr1 += int(trial/int(m[i]))+1
			curr0 += int((trial-1)/int(m[i]))+1
		if curr0>int(N):
			maxT = trial
		elif curr1<int(N):
			minT = trial
		else:
			outfl=1
			
	if curr0==int(N):
		trial-=1
		while res==0:
			for i in xrange(int(B)):
				if trial%int(m[int(B)-i-1]) == 0:
					res = int(B)-i
					break
			trial-=1
	else:
		while res==0:
			for i in xrange(int(B)):
				if trial%int(m[i]) == 0:
					curr0+=1
					if curr0==int(N):
						res = 1+i
						break
			trial+=1
			
	fout.write("Case #%d: %s\n" %(t+1, res))

fin.close()
fout.close()