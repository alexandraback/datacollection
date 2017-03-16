T = int(raw_input())
for t in range(T):
	N = int(raw_input())
	P = [int(x) for x in raw_input().split()]
	evaq = []
	total = sum(P)
	while total > 0:
		max_party = P.index(max(P))
		P[max_party] -= 1
		evaq.append([max_party])
		max_party = P.index(max(P))
		if total - 1 > 0 and P[max_party] >= (total - 1) / 2 + 1:
			P[max_party] -= 1
			evaq[-1].append(max_party)
		total = sum(P)
	ans = []
	for e in evaq:
		if len(e) == 2:
			ans.append(chr(ord('A') + e[0]) + chr(ord('A') + e[1]))
		else:
			ans.append(chr(ord('A') + e[0]))
	string = ' '.join(ans)
	print 'Case #%d: %s' % (t+1, string)