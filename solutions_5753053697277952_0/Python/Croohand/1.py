t = int(input())
for test in range(t):
	print('Case #%d: ' % (test + 1), end = '')
	n = int(input())
	a = list(map(int, input().split()))
	m1 = -1
	m2 = -1
	max1 = -1
	max2 = -1
	for i in range(n):
		if a[i] >= max1:
			m2 = m1
			max2 = max1
			m1 = i
			max1 = a[i]
		elif a[i] >= max2:
			max2 = a[i]
			m2 = i
	ans = []
	if max1 != max2:
		for i in range(n):
			if not i in (m1, m2):
				while a[i] > 0 and max1 > max2:
					max1 -= 1
					a[i] -= 1
					a[m1] -= 1
					ans.append(chr(65 + i) + chr(65 + m1))
	for i in range(n):
		for j in range(n):
			if i != j and not i in (m1, m2) and not j in (m1, m2):
				while a[i] > 0 and a[j] > 0:
					a[i] -= 1
					a[j] -= 1
					ans.append(chr(65 + i) + chr(65 + j))
	for i in range(n):
		if not i in (m1, m2):
			while (a[i] > 0):
				a[i] -= 1
				ans.append(chr(65 + i))
	while a[m1] > 0:
		a[m1] -= 1
		a[m2] -= 1
		ans.append(chr(65 + m1) + chr(65 + m2))
	for i in ans:
		print(i, end = ' ')
	print()