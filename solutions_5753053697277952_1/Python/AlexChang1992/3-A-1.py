import numpy as np

def solve(P):
	l = len(P)
	ans = []
	while max(P) > 0:
		maxP = max(P)
		argMaxP = P.index(maxP)
		if P[argMaxP] >= 2:
			P[argMaxP] -= 2
			s = sum(P)
			flag = False
			for i in xrange(l):
				if P[i] > s/2:
					flag = True
					break
			if flag:
				ans.append(chr(ord('A')+i)+chr(ord('A')+argMaxP))
				P[argMaxP] += 1
				P[i] -= 1
			else:
				ans.append(chr(ord('A')+argMaxP)*2)
		else:
			P[argMaxP] -= 1
			s = sum(P)
			flag = False
			for i in xrange(l):
				if P[i] > s/2:
					flag = True
					break
			if flag:
				ans.append(chr(ord('A')+i)+chr(ord('A')+argMaxP))
				P[i] -= 1
			else:
				ans.append(chr(ord('A')+argMaxP))

	return ans


T = int(raw_input())
for i in xrange(T):
	N = int(raw_input())
	P = raw_input().split()
	P = [int(j) for j in P]

	ans = solve(P)

	print "Case #%d: " %(i+1) + ' '.join(ans)
