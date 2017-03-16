for t in range(1, int(input()) + 1):
	N = int(input())
	ms = list(map(int, input().split()))
	ans1 = 0
	ans2 = 0
	max_diff = 0
	for i in range(1, N):
		diff = max(0, ms[i - 1] - ms[i])
		ans1 += diff
		max_diff = max(max_diff, diff)
	for i in range(N - 1):
		ans2 += min(max_diff, ms[i])
	print('Case #%d: %d %d' % (t, ans1, ans2))