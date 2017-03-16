from collections import defaultdict

def comp(c,xs):
	if len(xs) <= 3:
		return 0
	p1 = xs[c]
	best = len(xs) + 1000
	for i in range(len(xs)):
		if i==c:
			continue
		p2 = xs[i]
		below = 0
		above = 0
		for j in range(len(xs)):
			#if j==c or j==i:
			#	continue
			p0 = xs[j]
			dist = (p2[1]-p1[1])*p0[0] - (p2[0]-p1[0])*p0[1] + p2[0]*p1[1] - p2[1]*p1[0]
			if j==i or j==c:
				assert dist == 0
			if dist<0:
				below += 1
			elif dist>0:
				above += 1
		localbest = min(below,above)
		best = min(best,localbest)
	return best



with open('in.txt','rb') as fin, open('output.txt','w') as fout:
	case = 1

	it = iter(fin.readlines())
	_ = next(it) # cases

	for line in it:
		print ("\n")
		print ("case " + str(case))

		N = int(line.split(" ")[0])
		xs = []
		for i in range(N):
			line=next(it)
			x,y = [int(c) for c in line.split(" ")]
			xs.append((x,y))
		assert N == len(xs)
		print (xs)

		fout.write("Case #" + str(case) + ":\n")
		for i in range(len(xs)):
			res = comp(i,xs)
			fout.write(str(res) + "\n")

		case += 1