with open('A-small-attempt1.in') as f:
	cases = int(f.readline())
	for i in range(cases):
		row1 = int(f.readline())
		for j in range(row1):
			t = f.readline()

		row1data = [int(x) for x in t.split()]

		for j in range(4 - row1):
			t = f.readline()

		row2 = int(f.readline())
		for j in range(row2):
			t = f.readline()

		row2data = [int(x) for x in t.split()]

		for j in range(4 - row2): 
			t = f.readline()

		res = [];

		for j in range(4):
			for k in range(4):
				if row1data[j] == row2data[k]:
					res = res + [row1data[j]]

		if len(res) == 0:
			print "Case #%d: Volunteer cheated!" % (i+1)
		elif len(res) > 1:
			print "Case #%d: Bad magician!" % (i+1)
		else:
			print "Case #%d: %d" % (i+1, res[0])