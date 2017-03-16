import fileinput
stdin = fileinput.input()

def personAt(r,c,x,y,o):
	dv = 2**(r*x+y)
	return o>=dv and (o/dv)%2==1

def countWalls(r,c,o):
	return sum( 1
		for x in range(c-1) for y in range(r)
		if personAt(r,c,x,y,o) and personAt(r,c,x+1,y,o)
	) + sum( 1
		for x in range(c) for y in range(r-1)
		if personAt(r,c,x,y,o) and personAt(r,c,x,y+1,o)
	)

def solveCase():
	r,c,n = map(int,stdin.next().split())
	if not r<=c:
		r,c = c,r
	# r<=c
	best = 4*r*c
	o = 0
	for i in range(2**(r*c)):
		j = i
		k = 0
		while j>0:
			if j%2==1:
				k += 1
			j /= 2
		if k==n:
			best = min(countWalls(r,c,i),best)
	return best

for case in xrange(int(stdin.next())):
	print "Case #{0}: {1}".format(case+1,solveCase())