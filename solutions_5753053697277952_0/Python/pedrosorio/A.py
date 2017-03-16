

def solve(N, p):
	mnp = min(p)
	sol = []
	more_than_min = True
	while more_than_min:
		more_than_min = False
		mxp = max(p)
		if mxp > mnp:
			more_than_min = True 
			i = p.index(mxp)
			sol.append(chr(ord('A') + i))
			p[i] -= 1
			if max(p) * 2 > sum(p):
				print sol, p
	if N == 2:
		while p[0] > 0:
			sol.append('AB')
			p[0] -= 1
			p[1] -= 1
			if max(p) * 2 > sum(p):
				print "FAIL", sol, p
	else:
		larger_than_1 = True
		while larger_than_1:
			larger_than_1 = False
			for i in xrange(N):
				if p[i] > 1:
					larger_than_1 = True
					sol.append(chr(ord('A') + i))
					p[i] -= 1
					if max(p) * 2 > sum(p):
						print "FAIL", sol, p
		for i in xrange(N-2):
			sol.append(chr(ord('A') + i))
			p[i] -= 1
			if max(p) * 2 > sum(p):
				print "FAIL", sol, p
		sol.append(chr(ord('A') + N-2) + chr(ord('A') + N-1))
		p[N-2] -= 1
		p[N-1] -= 1
		if max(p) * 2 > sum(p):
			print "FAIL", sol, p
	if sum(p) > 0:
		print "FAIL_END", sol, p
	return ' '.join(sol)

T = int(raw_input())
for case in range(1, T+1):
	N = int(raw_input())
	p = map(int, raw_input().split())
	print "Case #{}: {}".format(case, str(solve(N, p)))