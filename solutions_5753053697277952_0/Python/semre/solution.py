from collections import defaultdict
import copy
def adjmatrix():
	for i in xrange(N):
		line = ''
		for j in xrange(N):
			if j in tree[i]:
				line += '1'
			else:
				line += '0'
		print line


T = int(raw_input())
for t in xrange(1, T+1):
	print "Case #{}:".format(t),

	N, M = map(int, raw_input().split())
	MAX = 2 ** (N-2)
	if MAX < M: print 'IMPOSSIBLE'; continue

	print 'POSSIBLE'
	tree = defaultdict(set)
	for i in xrange(N-1):
		for j in xrange(i+1, N):
			tree[i].add(j)

	left = MAX - M
	curr = 0
	while left:
		if 2 ** (N - curr - 3) <= left:
			for i in copy.copy(tree[curr]):
				if curr+1 != i:
					tree[curr].discard(i)
			left -= 2 ** (N - curr - 3)
			curr += 1

		else:
			b = bin(left)[2:][::-1]
			for i in xrange(len(b)):
				if b[i] == '1':
					tree[curr].discard(N - i - 1)
			left = 0

	adjmatrix()
