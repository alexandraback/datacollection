T = int(input())
for tc in range(T):
	ans = []
	rows = [[] for i in range(16)]

	for i in range(2):
		ans.append(int(input())-1)
		for row in range(4):
			for x in input().split():
				rows[int(x)-1].append(row)

	cnt, res = 0, 0
	for i in range(16):
		if ans == rows[i]:
			cnt += 1
			res = i

	print('Case #{}: '.format(tc+1), end='')
	if cnt == 0:
		print('Volunteer cheated!')
	elif cnt > 1:
		print('Bad magician!')
	else:
		print(res+1)