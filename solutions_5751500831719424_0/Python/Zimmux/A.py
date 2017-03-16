import fileinput
stdin = fileinput.input()

def remRuns(i):
	o = ''
	l = ''
	rs = []
	r = 0
	for c in i:
		if c!=l:
			o+=c
			l=c
			if r:
				rs += [r]
				r = 0
		r+=1
	if r:
		rs += [r]
	return o,rs

def solveCase():
	n = int(stdin.next())
	strs = [stdin.next() for _ in xrange(n)]
	homs,runs = zip(*[remRuns(s) for s in strs])
	canonic = homs[0]
	for m in homs:
		if m!=canonic:
			return "Fegla Won"
	edits = 0
	for i in xrange(len(canonic)):
		edits += min(sum(abs(mid-r[i]) for r in runs) for mid in xrange(200))
	return edits

for case in xrange(int(stdin.next())):
	print "Case #{0}: {1}".format(case+1,solveCase())
