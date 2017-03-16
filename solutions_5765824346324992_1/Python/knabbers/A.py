from collections import defaultdict

def comp(t,xs): # how many people served (not finished cutting though)?
	p = 0
	for x in xs:
		p += t/x + 1
	return p

with open('in.txt','rb') as fin, open('output.txt','w') as fout:
	case = 1

	it = iter(fin.readlines())
	_ = next(it) # cases

	for line in it:
		print ("\n")
		print ("case " + str(case))

		B, N = [int(c) for c in line.split(" ")]
		line=next(it)
		xs = [int(c) for c in line.split(" ")]
		#print xs

		down = 0 # times
		up = 1 # not inclusive

		while comp(up,xs) < N:
			up *= 2 # served >= N people (i.e. myself included)

		while up > down+1:
			m = (down + up)/2
			r = comp(m,xs)
			if r < N: # r is in and below down
				down = m
			else:
				up = m

		# how many people h
		down_served = comp(down,xs)
		up_served = comp(up,xs)
		ns = []
		for i in range(len(xs)):
			before = down/xs[i] + 1
			after = up/xs[i] + 1
			if before != after:
				ns.append(i) # index shitft!
		res = ns[(N-down_served-1)]+1



		best = 1
		fout.write("Case #" + str(case) + ": " + str(res) + "\n")
		case += 1