t = int(input ())
for test in range(t):
	n = int(input ())
	strings = []
	res = 0
	for s in range(n):
		strings.append(input())	
	pattern = ''
	fail = False
	array = []
	for i,s in enumerate(strings):
		array.append([])
		prev = s [0]
		tmp2 = ''
		tmp = 1
		for c in s[1:]:
			if (c != prev):
				tmp2 += prev
				array[i].append((tmp))
				tmp = 1
			else:
				tmp += 1
			prev = c
		if (prev != ''):
			tmp2 += prev
			array[i].append((tmp))

		if (pattern != '' and pattern != tmp2):
			fail = True
			break
		pattern = tmp2


	if (fail):
		print ("Case #%d: Fegla Won" % (test+1))
	else:
		res = 0
		for k in range(len(array[0])):
			hh = sorted([array[i][k] for i in range(len(array))])
			med = hh[len(hh)//2]
			
			for h in hh:
				res += abs(h-med)
	
		print ("Case #%d: %d" % (test+1, res))