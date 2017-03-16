#!/usr/bin/env python

def findCard(guesses, cards, case):
	firstGuessRow = cards[0][guesses[0]-1]
	secondGuessRow = cards[1][guesses[1]-1]

	numValueIsEqual = 0
	foundValue = 0
	for first in firstGuessRow:
		if first in secondGuessRow:
			foundValue = first
			numValueIsEqual += 1

	value = str(foundValue)
	if numValueIsEqual > 1:
		value = "Bad magician!"
	elif foundValue == 0:
		value = "Volunteer cheated!"

	print("Case #%d: %s" % (case, value))

	
numCases = int(input())

for case in range(0, numCases):
	guesses = [0,0]
	cards = [0,0]
	cards[0] = [[0 for x in range(4)] for x in range(4)]
	cards[1] = [[0 for x in range(4)] for x in range(4)]
	for x in range(0, 2):
		guesses[x] = input()
		for y in range(0, 4):
			cards[x][y] = [int(i) for i in raw_input().strip().split()]
	findCard(guesses, cards, case+1)
	