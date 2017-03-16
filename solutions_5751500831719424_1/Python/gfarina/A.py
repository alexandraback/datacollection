def shrink(s):
	out = ''
	for c in s:
		if len(out) == 0 or c != out[-1]:
			out += c
	return out

def calc(s):
	last = ''
	out = []
	for c in s:
		if c != last:
			last = c
			out.append(1)
		else:
			out[-1] += 1
	return out

def median(l):
    s = sorted(l)
    length = len(l)
    if length % 2 == 0:
        if (s[length/2] + s[length/2-1]) % 2 == 1:
        	val = (s[length/2] + s[length/2-1]) / 2
        	return [val, val+1]
        else:
        	val = (s[length/2] + s[length/2-1]) / 2
        	return [val]

    else:
    	return [ s[length/2] ]

def testcase(testnum):
	N = input()
	Ss = []
	Vs = []
	for i in xrange(N):
		s = raw_input()
		Ss.append(shrink(s))
		Vs.append(calc(s))

	for sx in Ss:
		if sx != Ss[0]:
			print "Case #%d: Fegla Won" % testnum
			return

	# Se sono qui va tutto bene
	comps = len(Ss[0])
	
	ans = 0
	for c in xrange(comps):
		comp = [v[c] for v in Vs]
		med = median(comp)

		mincost = 1000000000
		for mm in med:
			cost = sum([abs(x-mm) for x in comp])
			mincost = min(mincost, cost)

		ans += mincost

	print "Case #%d: %d" % (testnum, ans)

T = input()
for i in xrange(1,T+1):
	testcase(i)

