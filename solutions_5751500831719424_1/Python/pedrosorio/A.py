def get_chars(s):
	chars = [[], []]
	i = 0
	while i < len(s):
		c = s[i]
		ct = 1
		i += 1
		while i < len(s) and s[i] == c:
			ct += 1
			i += 1
		chars[0].append(c)
		chars[1].append(ct)
	chars[0] = "".join(chars[0])
	return chars

def find_distance_median(sorted_array):
	M = len(sorted_array)
	median = sorted_array[M/2]
	return sum([abs(v - median) for v in sorted_array])

T = int(raw_input())
for test in xrange(1, T+1):
	N = int(raw_input())
	words = [raw_input() for i in xrange(N)]
	chars = map(get_chars, words)
	sequence = chars[0][0]
	good = True
	for i in xrange(1,N):
		if chars[i][0] != sequence:
			good = False
			break
	if not good:
		print "Case #" + str(test) + ": Fegla Won"
	else:
		reorder = [sorted([chars[i][1][j] for i in xrange(N)]) for j in xrange(len(sequence))]
		moves = sum(map(find_distance_median, reorder))
		print "Case #" + str(test) + ": " + str(moves)