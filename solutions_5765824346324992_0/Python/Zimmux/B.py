import fileinput
stdin = fileinput.input()

def numEnteredBy(ms,t):
	if t<0:
		return 0
	return sum(1+int(t)/int(m) for m in ms)

def solveCase():
	b,n = map(int,stdin.next().split())
	ms = list(map(int,stdin.next().split()))
	doubling = True
	tLo = 0
	tHi = 2
	while doubling or tLo+1<tHi:
		tMid = (tLo+tHi)/2
		if numEnteredBy(ms,tMid)>=n:
			tHi = tMid
			doubling = False
		else:
			tLo = tMid
			if doubling:
				tHi *= 2
	t = tHi
	while True:
		nCutting = numEnteredBy(ms,t-1)
		synch = n-nCutting
		if synch<1:
			t -= 1
		else:
			break
	# pick #synch-th idle barber
	for i,m in enumerate(ms):
		if t%m==0:
			if synch == 1:
				return i+1
			synch -= 1

for case in xrange(int(stdin.next())):
	print "Case #{0}: {1}".format(case+1,solveCase())