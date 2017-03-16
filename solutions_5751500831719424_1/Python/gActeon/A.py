print 'A'

import itertools

tests = open('tests.txt')
results = open('results.txt', 'w')

T = int(tests.readline())

# [int(x) for x in tests.readline().split()]

for t in xrange(1, T + 1):
	N = int(tests.readline())
	lines = []
	shortLines = []
	sizes = []
	for n in xrange(N):
		line = tests.readline().strip()
		lines.append(line)
		shortLines.append(''.join(ch for ch, _ in itertools.groupby(line)))
		sizes.append([len(list(g)) for _, g in itertools.groupby(line)])

	if shortLines.count(shortLines[0]) == len(shortLines):
		count = 0
		for i in xrange(len(sizes[0])):
			cur = [s[i] for s in sizes]

			min = 2000000000
			for op in xrange(101):
				sum = 0
				for c in cur:
					sum += abs(op - c)
				if sum < min:
					min = sum

			count += min

		results.write('Case #' + str(t) + ': ' + str(count) + '\n')
	else:
		results.write('Case #' + str(t) + ': Fegla Won\n')
