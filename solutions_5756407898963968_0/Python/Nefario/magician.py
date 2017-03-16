#!/usr/bin/python
import sys
import math

def main():
	firstGuess = 0
	firstGame = []
	secondGuess = 0
	secondGame = []
	f = open(sys.argv[1], 'r')
	for lineNum, line in enumerate(f):
		line = line.rstrip('\n')
		if lineNum == 0:
			continue

		if lineNum % 10 == 1:
			# first guess
			firstGuess = int(line)

		elif lineNum % 10 in [2, 3, 4, 5]:
			# first game
			firstGame.append(line.split(' '))

		elif lineNum % 10 == 6:
			# second guess
			secondGuess = int(line)

		elif lineNum % 10 in [7, 8, 9, 0]:
			secondGame.append(line.split(' '))

		# Evaluate and reset
		if lineNum % 10 == 0:
			# print "First Guess: {}".format(firstGuess)
			# print "First Game: {}".format(firstGame)
			# print "Second Guess: {}".format(secondGuess)
			# print "Second Game: {}".format(secondGame)
			intersectingCards = filter(lambda x: x in firstGame[(firstGuess - 1)], secondGame[secondGuess - 1])
			if len(intersectingCards) == 1:
				print "Case #{}: {}".format((lineNum/10), intersectingCards[0])
			elif len(intersectingCards) > 1:
				print "Case #{}: {}".format((lineNum/10), "Bad magician!")
			if len(intersectingCards) == 0:
				print "Case #{}: {}".format((lineNum/10), "Volunteer cheated!")

			firstGuess = 0
			firstGame = []
			secondGuess = 0
			secondGame = []


if __name__ == "__main__":
	main()