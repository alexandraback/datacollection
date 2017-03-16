for t in range(1, int(input()) + 1):
	B, N = map(int, input().split())
	ms = list(map(int, input().split()))
	l = 0
	r = max(ms) * (N - 1)
	while True:
		mid = (l + r) // 2
		cum = 0
		divisible = 0
		for m in ms:
			divisible += mid % m == 0
			cum += mid // m + 1
		if cum - divisible < N <= cum:
			break
		elif cum < N:
			l = mid + 1
		else:
			r = mid - 1
	mid = (l + r) // 2
	divisible = 0
	for m in ms:
		divisible += mid % m == 0
	cnt = N - cum + divisible
	for i, m in enumerate(ms, 1):
		if mid % m == 0:
			cnt -= 1
			if cnt == 0:
				print('Case #%d: %d' % (t, i))
				break