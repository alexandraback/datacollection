from collections import defaultdict

with open('in.txt','rb') as fin, open('output.txt','w') as fout:
	case = 1

	it = iter(fin.readlines())
	_ = next(it) # cases

	for line in it:
		print ("\n")
		print ("case " + str(case))
		N = int(line)
		line=next(it)
		xs = [int(c) for c in line.split(" ")]
		#print xs

		m1 = 0
		m2 = 0
		for i in range(N-1):
			if xs[i+1] - xs[i] < 0:
				m1 -= (xs[i+1] - xs[i])
			if xs[i+1] < xs[i]:
				m2 = max(m2,xs[i] - xs[i+1])

		m3 = 0
		for i in range(N-1):
			#how much can she eat of current one
			m3 += min(m2,xs[i])


		best = 1
		fout.write("Case #" + str(case) + ": " + str(m1) + " " + str(m3) +  "\n")
		case += 1