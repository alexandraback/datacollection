import sys

fin = open(sys.argv[1], 'r') if len(sys.argv) > 1 else sys.stdin

alpha = list('ABCDEFGHIJKLMNOPQRSTUVWXYZ')

T = int(fin.readline())

for t in range(1, T + 1):
	N = int(fin.readline())
	P = dict((alpha[k], v) for k, v in enumerate(map(int, fin.readline().split(' '))))
	
	S = []
	
	while len(P) > 2:
		g = max(P, key = lambda k: P[k[0]])
		
		if (P[g] > 1):
			P[g] -= 1
		else:
			del P[g]

		S.append(g)
	
	k = list(P.keys())
	
	if (P[k[0]] > P[k[1]]):
		g = k[0]
		l = k[1]
	else:
		g = k[1]
		l = k[0]
		
	while P[g] > P[l]:
		S.append(g)
		P[g] -= 1
	
	for i in range(P[g]):
		S.append(l + g)
	
	print('Case #{0}: {1}'.format(t, ' '.join(S)))