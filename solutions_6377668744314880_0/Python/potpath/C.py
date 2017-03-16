# From https://en.wikibooks.org/wiki/Algorithm_Implementation/Geometry/Convex_hull/Monotone_chain#Python
def convex_hull(points):
	points = sorted(set(points))

	def cross(o, a, b):
		return (a[0] - o[0]) * (b[1] - o[1]) - (a[1] - o[1]) * (b[0] - o[0])

	lower = []
	for p in points:
		while len(lower) >= 2 and cross(lower[-2], lower[-1], p) <= 0:
			lower.pop()
		lower.append(p)

	upper = []
	for p in reversed(points):
		while len(upper) >= 2 and cross(upper[-2], upper[-1], p) <= 0:
			upper.pop()
		upper.append(p)

	return lower[:-1] + upper[:-1]


def is_boundary(point, ch):
	a, b = point
	nch = len(ch)
	for i in range(nch):
		x1, y1 = ch[i]
		x2, y2 = ch[(i + 1) % nch]
		if (x1 == x2 == a) or (x1 != x2 and (y2 - y1) * (a - x1) // (x2 - x1) + y1 == b):
			return True
			break
	return False


from itertools import combinations

for t in range(1, int(input()) + 1):
	N = int(input())
	ms = []
	for i in range(N):
		ms.append(tuple(map(int, input().split())))
	print('Case #%d:' % t)
	if N < 4:
		for _ in ms:
			print(0)
	else:
		ch = convex_hull(ms)
		for m in ms:
			if is_boundary(m, ch):
				print(0)
			else:
				flag = False
				for i in range(1, N - 3):
					for comb in combinations(ms, N - i):
						if m in comb and is_boundary(m, convex_hull(comb)):
							print(i)
							flag = True
							break
					if flag:
						break
				else:
					print(N - 3)