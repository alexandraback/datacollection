with open('A-small-attempt0.in') as f:
	T = int(f.readline())

	for case in xrange(T):
		n = int(f.readline())

		s = f.readline()
		template = s[0]
		for i in range(1,len(s)):
			if (s[i] != s[i-1]):
				template += s[i]

		count = [[0]*n for i in xrange(len(template))]

		ti = 0
		count[ti][0] = 1
		for i in range(1,len(s)):
			if (s[i] != s[i-1]):
				ti += 1
			count[ti][0] += 1

		feasible = True

		for si in range(1,n):
			s = f.readline()
			t = s[0]
			for i in range(1,len(s)):
				if (s[i] != s[i-1]):
					t += s[i]

			if template != t:
				feasible = False
				break

			ti = 0
			count[ti][si] = 1
			for i in range(1,len(s)):
				if (s[i] != s[i-1]):
					ti += 1
				count[ti][si] += 1

		if not feasible:
			print "Case #%d: Fegla Won" % (case+1)
		else:
			for i in xrange(len(template)):
				count[i].sort()

			score = 0

			for i in xrange(len(template)):
				median = count[i][n/2]
				for j in xrange(n):
					score += abs(count[i][j] - median)

			print "Case #%d: %d" % (case+1, score)