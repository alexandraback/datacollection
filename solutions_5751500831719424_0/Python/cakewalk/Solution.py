from sys import stdin
readline = stdin.readline

T = int(readline())
for t in xrange(1, T+1):
	N = int(readline())
	A = [readline().strip() for i in xrange(N)]
	B = []
	C = []
	for i in xrange(N):
		l = []
		m = []
		l.append(ord(A[i][0]))
		m.append(1)
		for c in xrange(1, len(A[i])):
			if A[i][c] == A[i][c-1]:
				m[-1] += 1
			else:
				l.append(ord(A[i][c]))
				m.append(1)
		B.append(l)
		C.append(m)
	
	flag = True
	for i in xrange(1, N):
		if B[i] != B[i-1]:
			flag = False
			break
	
	if flag == False:
		print 'Case #%d: Fegla Won' % (t)
		continue
	
	ans = 0
	for i in xrange(len(B[0])):
		l = [C[j][i] for j in xrange(N)]
		l.sort()
		med = l[len(l)/2]
		for j in xrange(N):
			if l[j] > med:
				ans+= (l[j] - med)
			else:
				ans += (med-l[j])
	
	print 'Case #%d: %d' % (t, ans)
