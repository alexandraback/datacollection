#!/usr/bin/python -u

# Solves Google Codejam "Magic Trick"
# http://code.google.com/codejam
# Sam Moore (matches)
# 2014-04-12

import sys
import os
from numpy import *

def readCards():
	row = int(sys.stdin.readline().strip(" \r\n"))-1
	for i in xrange(4):
		line = sys.stdin.readline().strip(" \r\n")
		if i == row:
			cards = map(int, line.split(" "))
	return cards

def main(argv):
	nCases = int(sys.stdin.readline().strip(" \r\n"))
	
	for c in xrange(1, nCases+1):
		# Solve case

				

		
		cards1 = readCards()
		cards2 = readCards()

		values = set(cards1).intersection(set(cards2))

		#print str(values)

		if len(values) == 1:
			result = str(list(values)[0])
		elif len(values) > 1:
			result = "Bad magician!"
		else:
			result = "Volunteer cheated!"

		print "Case #%d: %s" % (c, result)
	
	return 0

if __name__ == "__main__":
	sys.exit(main(sys.argv))
		
