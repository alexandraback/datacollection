T = int(raw_input())

for c in xrange(T):
	n1=0
	n2=0
	N = int(raw_input())
	mushr = map(int,raw_input().strip().split())
	
	prev = mushr[0]
	high = 0
	for m in mushr:
		diff = prev - m
		if diff > 0:
			if high < diff:
				high = diff
			n1 += diff
		prev = m
	
	for m in mushr[:-1]:
		if m < high:
			n2 += m
		else:
			n2 += high
	print 'Case #'+str(c+1)+':', n1,n2
