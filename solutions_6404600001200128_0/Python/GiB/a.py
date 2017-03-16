# -*-coding:utf8 -*
from parsing import TextGen
infile = "a.in"
outfile = "a.out"

########################

def algo(inp):
	ntime = inp.int
	ltime = []
	mineat = 0
	lastmush = 0
	minrate = 0
	for _ in range(ntime):
		mush = inp.int
		ltime.append(mush)
		diff = lastmush-mush
		if diff > 0:
			mineat += diff
			minrate = max(diff,minrate)
		lastmush = mush
	maxeat = 0
	ltime.pop()
	for mush in ltime:
		maxeat += min(minrate,mush)
	return "%d %d" % (mineat,maxeat)
		


########################

inp = TextGen(infile)
cases = inp.int
with open(outfile,'w') as outdata:
	for case in range(1, cases+1):
		outdata.write("Case #%d: %s\n" % (case, algo(inp)))
