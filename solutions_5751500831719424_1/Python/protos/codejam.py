tcn = int(raw_input())

def minimize(l):
	m = 1000000000000000000
	for i in l:
		s = 0
		for j in l:
			s += abs(i - j)
		if s < m:
			m = s
	return m

for tc in range(1, tcn + 1):
	n = int(raw_input())
	a = []
	for i in range(n):
		s = raw_input()
		l = []
		for j in s:
			if len(l) == 0 or l[-1][0] != j:
				l.append(j)
			else:
				l[-1] += j
		a.append(l)

	res = 0
	x = ''.join([j[0] for j in a[0]])
	for i in range(1, n):
		y = ''.join([j[0] for j in a[i]])
		if x != y:
			res = -1
			break

	if res == -1:
		print 'Case #%d: Fegla Won' % (tc)
	else:
		for i in range(len(a[0])):
			res += minimize([len(a[j][i]) for j in range(n)])
		print 'Case #%d: %d' % (tc, res)
