from collections import defaultdict

def compact_str(s):
	compactedStr = []

	sLen = len(s)
	i = 0
	while i < sLen:
		ch = s[i]

		j = i + 1
		while j < sLen and s[j] == ch:
			j += 1

		compactedStr.append([ch, j - i])
		i = j

	return compactedStr

def str_distance(s1, s2):
	if len(s1) != len(s2):
		return -1

	distance = 0
	for i in range(0, len(s1)):
		[ch1, count1] = s1[i]
		[ch2, count2] = s2[i]

		if ch1 != ch2:
			return -1

		distance += abs(count1 - count2)

	return distance

def list_distance(l):
	l.sort()

	minDist = 99999999

	keys = list(set(l))
	for k in keys:
		dist = 0
		for i in l:
			dist += abs(i - k)

		if dist < minDist:
			minDist = dist

	return minDist


def min_distance(strings):
	strCount = len(strings)

	for i in range(0, strCount - 1):
		s = strings[i]
		for j in range(i + 1, strCount):
			distance = str_distance(s, strings[j])
			if distance < 0:
				return -1

	dist = 0
	for i in range(0, len(strings[0])):
		ch = [s[i][1] for s in strings]
		dist += list_distance(ch)

	return dist

fin = open('input.txt')
lines = fin.read().split("\n")

testsCount = int(lines[0])

curLine = 1
for testCase in range(1, testsCount + 1):
	strCount = int(lines[curLine])

	strings = [compact_str(lines[curLine + i + 1]) for i in range(0, strCount)]
	distance = min_distance(strings)

	print "Case #" + str(testCase) + ":",
	print ("Fegla Won" if distance < 0 else distance)

	curLine += strCount + 1
	pass