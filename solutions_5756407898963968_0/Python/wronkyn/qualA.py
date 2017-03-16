#!/usr/bin/python

import sys

def testCase(case, rows, boards):
	selectedRows = []

	for i in range(2):
		selectedRows.append(list(boards[i][rows[i] - 1]))

	overlaps = []

	for i in selectedRows[0]:
		if (i in selectedRows[1]):
			overlaps.append(i)

	answer = ""
	if len(overlaps) == 0:
		answer = "Volunteer cheated!"
	elif len(overlaps) > 1:
		answer = "Bad magician!"
	else:
		answer = str(overlaps[0])

	#print overlaps
	print "Case #{}: {}".format(str(case), answer)

if __name__ == "__main__":
	testCases = int(sys.stdin.readline())

	for i in range(1, testCases + 1):
		rows = []
		boards = []

		for l in range(2):
			rows.append(int(sys.stdin.readline()))
			board = []
			for j in range(4):
				board.append([int(k) for k in sys.stdin.readline().split()])

			boards.append(board)

		testCase(i, rows, boards)
else:
	print "not main"
