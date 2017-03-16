T = int(raw_input())

for t in xrange(T):
	raw_input()
	S = map(int, raw_input().split(' '))

	a = 0
	b = 0
	m = 0

	for i in xrange(1, len(S)):
		if(S[i] < S[i-1]):
			m = max(S[i-1] - S[i], m)
			a += S[i-1] - S[i]

	r = m
	if m % 10 == 0:
		r = m / 10

	for i in xrange(1, len(S)):
		b += min(S[i-1], m)


	print "Case #%d: %d %d" %(t+1, a, b)
