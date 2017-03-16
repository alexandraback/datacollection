inf = open('input.txt', 'r')
ouf = open('output.txt', 'w')

t = int(inf.readline())
for q in range(t):
	n = int(inf.readline())
	l = list(map(int, inf.readline().split()))
	y = 0
	z = 0
	max1 = 0
	for i in range(n - 1):
		if l[i] > l[i + 1]:
			y += l[i] - l[i + 1]
			if l[i] - l[i + 1] > max1:
				max1 = l[i] - l[i + 1]
	if max1 == 0:
		z = 0
	else:
		for i in range(n - 1):
			z += min(max1, l[i])
	print('Case #', q + 1, ': ', y, ' ', z, sep = '', file = ouf)
ouf.close()
