def haircut(m,n):
	tl, th, cl = 0, n*max(m)+1, 0
	while th - tl > 1:
		tm = (tl+th)/2
		c = 0
		for mi in m:
			c += (tm+mi-1)/mi
		if c < n:
			tl = tm
			cl = c
		else:
			th = tm
	#print m, tl, cl
	for i,mi in enumerate(m):
		if tl % mi == 0:
			cl += 1
			if cl == n:
				return (i+1)

t = int(raw_input())
for _ in range(1,t+1):
	b,n = map(int,raw_input().split())
	m = map(int,raw_input().split())
	print 'Case #%d: %d' % (_, haircut(m,n))