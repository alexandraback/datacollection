import sys

pattern = "Case #{0}: {1}"

def getRow(f, r):
	return [f.readline().rstrip("\n").split() for i in xrange(4)][r-1]

def solve(f):
	r = int(f.readline())
	s1 = getRow(f, r)
	r = int(f.readline()) 
	s2 = getRow(f,r)
	s = []
	for i in s1:
		if i in s2:
			s.append(i)
	if not s:
		return "Volunteer cheated!"
	if len(s) > 1:
		return "Bad magician!"
	else:
		return s[0]





if __name__=="__main__":
	with open(sys.argv[1]) as f:
		ntests = int(f.readline())
		for i in xrange(1,ntests+1):
			s = solve(f)
			print pattern.format(str(i),str(s))
