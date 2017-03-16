def solve():
	r, c, n = (int(x) for x in input().split())
	ans = 10 ** 10
	for i in range(2 ** (r * c)):
		s = bin(i)[2:]
		cnt = s.count('1')
		if cnt != n:
			continue
		s = s.zfill(r * c)
		field = [s[i:i + c] for i in range(0, r * c, c)]
		cur = 0
		for i in range(r):
			for j in range(c):
				if field[i][j] == '1':
					if i + 1 < r:
						cur += 1 if field[i + 1][j] == '1' else 0
					if j + 1 < c:
						cur += 1 if field[i][j + 1] == '1' else 0
		ans = min(ans, cur)
	return ans

t = int(input())
for i in range(t):
	print('Case #{}: {}'.format(i + 1, solve()))
