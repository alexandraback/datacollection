
linearray = []

fp = open('A-large.in','r')
for line in fp:
	linearray.append(line.rstrip('\n'))
fp.close()

T = int(linearray[0])
op = open('output.txt','w')
i = 1
t = 0
while (t<T):
	N = int(linearray[i])
	i += 1
	t += 1
	sarray = []
	for j in range(0,N):
		sarray.append(linearray[i])
		i+=1
	
	norepeat = []
	repenum = []
	for s in sarray:
		repenum.append([])
		lastcidx = 0

		norepeat.append([])
		norepeat[-1].append(s[0])
		for j in range(1,len(s)):
			if (s[j] != norepeat[-1][-1]):
				norepeat[-1].append(s[j])
				repenum[-1].append(j-lastcidx)
				lastcidx = j
		repenum[-1].append(len(s)-lastcidx)
	#print norepeat
	#print repenum
	fwon = False
	for j in range(1,len(norepeat)):
		if norepeat[j] != norepeat[j-1]:
			fwon = True
			break
	
	if (fwon):
		op.write("Case #%s: Fegla Won\n" % (t))
		continue

	ttcost = 0
	for j in range(0,len(norepeat[0])):
		avg = 0
		for k in range(0,len(sarray)):
			avg += repenum[k][j]
		avg = avg/len(sarray)
		#print avg,
		mincost = 10000
		for target in range(avg,avg+2):
			tmpcost = 0
			for k in range(0,len(sarray)):
				tmpcost = tmpcost + abs(repenum[k][j] - target)
			if tmpcost < mincost:
				mincost = tmpcost
		ttcost += mincost
	#print
	op.write("Case #%s: %s\n" % (t,ttcost))
op.close()