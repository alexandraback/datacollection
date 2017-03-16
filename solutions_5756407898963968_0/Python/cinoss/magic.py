fname = "A-small-attempt0.in"
f = open(fname)
fo = open("fo.txt","w")
def readblock():
	i = int(f.readline())-1
	lines = (f.readline(),f.readline(),f.readline(),f.readline())
	return set(lines[i].strip().split())
for test in range(int(f.readline())):
	r = list(readblock() & readblock())
	print r
	print >>fo,"Case #%d:"%(test+1),
	if len(r) == 0:
		print >>fo, "Volunteer cheated!"
	elif len(r) == 1:
		print >>fo, r[0]
	else:
		print >>fo, "Bad magician!"
