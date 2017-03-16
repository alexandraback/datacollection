import math
from itertools import groupby

def median(l):
	l.sort()
	return l[len(l)//2]

def unique(seq):
    seen = set()
    seen_add = seen.add
    return [ x for x in seq if x not in seen and not seen_add(x)]

casesLen = int(input())

cases = []

for case in range(casesLen):
	numOfStrings = int(input())
	strings = []
	for j in range(numOfStrings):
		strings.append(input())
	feglaWon = False
	items = []
	chars = [k for k, g in groupby(strings[0])]
	for s in strings:
		i = 0
		counts = []
		for k, g in groupby(s):
			if len(chars) <= i or k != chars[i]:
				feglaWon = True
			counts.append(len(list(g)))
			i = i + 1
		items.append(counts)
	length = len(items[0])
	for i in items:
		if len(i) != length:
			feglaWon = True
	if feglaWon == False:
		rot = []
		for j in range(len(items[0])):
			row = []
			for i in range(len(items)):
				row.append(items[i][j])
			rot.append(row)
		moves = 0
		for l in rot:
			med = median(l)
			for i in l:
				moves = moves + abs(i-med)
		print("Case #{0}: {1}".format(case+1,moves))
	else:
		print("Case #{0}: {1}".format(case+1,"Fegla Won"))
