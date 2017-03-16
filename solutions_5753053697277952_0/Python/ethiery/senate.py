for T in range(1, int(input())+1):
	N = int(input())
	Pis = list(map(int, input().split()))
	sol = []
	total = 0
	parties = []
	for i in range(len(Pis)):
		parties.append([chr(ord('A')+i), Pis[i]])
		total += Pis[i]

	while total > 0:
		parties.sort(key=lambda p: p[1], reverse=True)
		#print(parties)
		parties[0][1] -= 1
		total -= 1
		if len(parties) > 1 and parties[1][1]*2 > total:
			parties[1][1] -= 1
			total -= 1
			sol.append('{}{}'.format(parties[0][0], parties[1][0]))
		else:
			sol.append('{}'.format(parties[0][0]))


	print('Case #{}: {}'.format(T, ' '.join(sol)))