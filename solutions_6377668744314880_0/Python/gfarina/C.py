import sys

def vecprod(u, v):
	return u[0] * v[1] - u[1] * v[0]

def find_ans(points, i):
	pt = points[i]
	N = len(points)

	ans = -1
	for j in xrange(N):
		if j == i:
			continue

		other_pt = points[j]
		vector = (other_pt[0] - pt[0], other_pt[1] - pt[1])

		pos = 0
		neg = 0
		for k in xrange(N):
			k_pt = points[k]
			delta = (k_pt[0] - pt[0], k_pt[1] - pt[1])

			prod = vecprod(delta, vector)
			if prod > 0:
				pos += 1
			elif prod < 0:
				neg += 1

		if ans == -1 or min(pos, neg) < ans:
			ans = min(pos, neg)

	if ans == -1:
		return 0
	else:
		return ans


def testcase(t):
	N = input()

	points = []
	for i in xrange(N):
		points += [tuple(map(int, raw_input().split()))]

	print "Case #%d:" % t
	for i in xrange(N):
		print find_ans(points, i)

T = input()
for t in xrange(1, T + 1):
	testcase(t)