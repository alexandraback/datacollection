from math import ceil
inf = open('input.txt', 'r')
ouf = open('output.txt', 'w')

t = int(inf.readline())
for q in range(t):
	b, n = map(int, inf.readline().split())
	m = list(map(int, inf.readline().split()))
	l = 0
	r = 10**18
	while l + 1 < r:
		x = 0
		m1 = (l + r)//2
		for i in range(b):
			x += ceil(m1/m[i])
		if x < n:
			l = m1
		else:
			r = m1
	x = 0
	y = 0
	for i in range(b):
		x += ceil(l/m[i])
		y += ceil(r/m[i])
	k = n - x
	j = 0
	for i in range(b):
		if l % m[i] == 0:
			j += 1
			if j == k:
				print('Case #', q + 1, ': ', i + 1, sep = '', file = ouf)
				break

	



ouf.close()
