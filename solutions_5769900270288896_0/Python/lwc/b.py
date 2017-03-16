from itertools import combinations
t = int(raw_input())
for i in range(t):
	r, c, n = map(int, raw_input().split())
	cons = [(x, y) for x in range(r) for y in range(c)]
	minn = 99999999
	for qq in combinations(cons, n):
		ww = 0
		for xx in combinations(qq, 2):
			if abs(xx[0][0]-xx[1][0]) + abs(xx[0][1]-xx[1][1]) == 1:
				ww += 1
		if ww < minn:
			minn = ww

	print ('Case #%d: ' % (i+1)) + str(minn) 
