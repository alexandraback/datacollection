def good(x):
	m = sum(p)-1
	for k in xrange(n):
		if k == x:
			if p[k]-1 > m/2:
				return False
		else:
			if p[k] > m/2:
				return False
	return True



T = int(raw_input())  
#n, m = [int(s) for s in input().split(" ")]  # read a list of integers, 2 in this case
for k in range (T):
	n = int(raw_input())
	p = [int(s) for s in raw_input().split(" ")]

	res = []
	while sum(p) != 0:
		x = p.index(max(p))
		p[x] -= 1

		g = max(p)
		y = p.index(g)
		while not(good(y)):
			if g in p[y+1:]:
				y = y + 1 + p[y+1:].index(g)
			else:
				y = -1
				break
		s = chr(65+x)
		if y >= 0:
			p[y] -= 1
			s += chr(65+y)
		res.append(s)

	ret = ' '.join(res)



	print "Case #{}: {}".format(k+1, ret)







