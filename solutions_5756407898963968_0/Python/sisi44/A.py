def solve():
	#f = open("in.txt", 'r')
	f = open("A-small-attempt0.in.txt", 'r')
	T = int(f.readline())
	for t in range(T):
		r1 = int(f.readline())
		for i in range(4):
			line = f.readline()
			if r1 == i+1:
				l1 = [int(k) for k in line.split()]
		r2 = int(f.readline())
		for i in range(4):
			line = f.readline()
			if r2 == i+1:
				l2 = [int(k) for k in line.split()]
		res = 0
		for m in l1:
			if m in l2:
				res += 1
				number = m
		if res == 0:
			print "Case #%i:" % (t+1), "Volunteer cheated!"
		elif res == 1:
			print "Case #%i:" % (t+1), number
		else:
			print "Case #%i:" % (t+1), "Bad magician!"


solve()
