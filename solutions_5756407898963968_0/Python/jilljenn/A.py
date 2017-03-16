T = int(raw_input())
for i in range(T):
	a = int(raw_input())
	grid = []
	for _ in range(4):
		grid.append(map(int, raw_input().split()))
	s = set(grid[a - 1])
	a = int(raw_input())
	grid = []
	for _ in range(4):
		grid.append(map(int, raw_input().split()))
	s &= set(grid[a - 1])
	if len(s) > 1:
		r = 'Bad magician!'
	elif len(s) == 0:
		r = 'Volunteer cheated!'
	else:
		r = list(s)[0]
	print 'Case #%d: %s' % (i + 1, r)
