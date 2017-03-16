def result(a, n):
	ans = 0
	for (i, x) in enumerate(a):
		take = min(n, x)
		ans += i * take
		n -= take
	return ans + n * 4

def solve():
	r, c, n = (int(x) for x in input().split())
	simple = (r * c + 1) // 2
	if n <= simple:
		return 0
	if c < r:
		c, r = r, c
	if r == 1 and c == 1:
		return 0
	if r == 1:
		n -= (c + 1) // 2
		ans = 0
		if n > 0:
			if c % 2 == 0:
				ans += 1
				n -= 1
		if n > 0:
			ans += n * 2
		return ans
	if r % 2 == 0 and c % 2 == 0:
		anger = [r * c // 2, 0, 2, (r // 2 - 1) * 2 + (c // 2 - 1) * 2]
		return result(anger, n)
	if r % 2 == 1 and c % 2 == 1:
		anger1 = [r * c // 2, 0, 4, (r // 2 - 1) * 2 + (c // 2 - 1) * 2]
		anger2 = [(r * c + 1) // 2, 0, 0, r // 2 * 2 + c // 2 * 2]
		return min(result(anger1, n), result(anger2, n))
	if c % 2 == 1:
		anger = [r * c // 2, 0, 2, (r // 2 - 1) * 2 + c // 2 * 2 - 1]
		return result(anger, n)
	anger = [r * c // 2, 0, 2, (c // 2 - 1) * 2 + r // 2 * 2 - 1]
	return result(anger, n)

t = int(input())
for i in range(t):
	print('Case #{}: {}'.format(i + 1, solve()))
