numRuns=int(input())
for run in range(numRuns):
	len=int(input())
	dat=input().split()
	dat[0]=int(dat[0])
	eatA=0
	maxeat=0
	for i in range(len-1):
		dat[i+1]=int(dat[i+1])
		if dat[i+1]<dat[i]:
			eatA+=dat[i]-dat[i+1]
			maxeat=max(maxeat, dat[i]-dat[i+1])
	
	eatB=0
	for i in range(len-1):
		eatB+=min(maxeat, dat[i])
	print("Case #"+str(run+1)+": "+str(eatA)+" "+str(eatB))