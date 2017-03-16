def patternForString(s):
	pattern = []
	mults = []
	for c in s:
		if c not in pattern or c != pattern[-1]:
			pattern.append(c)
			mults.append(1)
		else:
			mults[-1] += 1
	return pattern, mults

def repeater(strings):
	pattern, mults0 = patternForString(strings[0])
	mults = {}
	
	for i in range(len(pattern)):
		mults[i] = [mults0[i]]

	for s in strings[1:]:
		p, m = patternForString(s)

		if p != pattern:
			return "Fegla Won"

		for i in range(len(p)):
			mults[i].append(m[i])

	moves, moves2 = 0, 0

	for i in range(len(pattern)):
		sm = sorted(mults[i])
		med = sm[len(sm) / 2]
		moves += sum([abs(x - med) for x in sm])

	# for i in range(len(pattern)):
	# 	minSum = float('inf')
	# 	for j in range(1, max(mults[i])+1):
	# 		minSum = min(minSum, sum([abs(x - j) for x in mults[i]]))
	# 	moves2 += minSum

	# if moves != moves2:
	# 	print moves, moves2

	return moves

from sys import stdin

input = stdin.read().split('\n')
line = 0

for t in range(int(input[0])):
	line += 1
	N = int(input[line])

	print "Case #{0}: {1}".format(t+1, repeater(input[line + 1 : line + N + 1]))

	line += N