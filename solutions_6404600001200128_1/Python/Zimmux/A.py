import fileinput
stdin = fileinput.input()

def solveCase():
	n = map(int,stdin.next().split())[0]
	ms = list(map(int,stdin.next().split()))

	y = sum(a-b for a,b in zip(ms,ms[1:]) if a>=b)
	rate = max(a-b for a,b in zip(ms,ms[1:]) if a>=b)
	z = sum(min(m,rate) for m in ms[:-1])
	
	return "{0} {1}".format(y,z)

for case in xrange(int(stdin.next())):
	print "Case #{0}: {1}".format(case+1,solveCase())
