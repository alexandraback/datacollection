#!/usr/bin/python

import sys, math

def strSig(string):
	compressed = string[0]
	counts = [1]

	for i in range(1, len(string)):
		ch = string[i]

		if ch == string[i-1]:
			counts[len(counts)-1] += 1
		else:
			compressed += ch
			counts.append(1)

	return (compressed, counts)

def sumDiffMedians(countsList):
	total = 0

	for counts in zip(*countsList):
		count = list(counts)
		count.sort()

		median = count[len(count)/2]

		for num in count:
			total += abs(median - num)
	
	return total

def testCase(case, strings):
	compressedList = []
	countsList = []

	for string in strings:
		comp, count = strSig(string)
		compressedList.append(comp)
		countsList.append(count)

	if (compressedList.count(compressedList[0]) != len(compressedList)):
		print "Case #{}: Fegla won".format(str(case))
	else:
		print "Case #{}: {}".format(str(case), str(sumDiffMedians(countsList)))


if __name__ == "__main__":
	testCases = int(sys.stdin.readline())

	for i in range(1, testCases + 1):
		numStrings = int(sys.stdin.readline())

		strings = []
		for j in range(numStrings):
			strings.append(sys.stdin.readline().strip())

		testCase(i, strings)

else:
	print "not main"
