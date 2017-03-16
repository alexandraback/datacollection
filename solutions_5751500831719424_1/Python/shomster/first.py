from collections import defaultdict

lines = open('A-large.in', 'r').read().splitlines()
line = iter(lines)

numCases = int(line.next())

outputFile = open('A-large.out', 'w')

def getOrderedChars(str):
	l = []
	counts = []
	for ch in str:
		if len(l) == 0 or ch != l[-1]:
			l.append(ch)
			counts.append(1)
		elif ch == l[-1]:
			counts[-1] += 1

	return l, counts

def getMedian(l):
	l_sorted = sorted(l)
	med = len(l) / 2
	return l_sorted[med]

def getAbsDiff(l1, l2):
	s = 0
	for j in range(len(l1)):
		s += abs(l1[j] - l2[j])
	return s


def getMedians(array_list):
	return map(lambda t: getMedian(t), zip(*array_list))

for i in range(numCases):
	# print "****"
	numStrings = int(line.next())
	# firstMatrix

	strings = []
	counts = []
	for j in range(numStrings):
		s = line.next().strip()
		stringchars, countschar = getOrderedChars(s)
		strings.append(stringchars)
		counts.append(countschar)

	# print "STRINGS", strings
	# print "COUNTS", counts
	median = getMedians(counts) 
	# print "MEDIAN", median

	strings_strs = map(lambda t: "".join(t), strings)

	possible = True

	if len(set(strings_strs)) == 1:
		total_moves = 0
		for cnt in counts:
			total_moves += getAbsDiff(cnt, median)	
	else:
		possible = False

	if possible:
		outputFile.write("Case #" + str(i + 1) + ": " + str(total_moves) + "\n")
	else:
		outputFile.write("Case #" + str(i + 1) + ": Fegla Won" + "\n")



