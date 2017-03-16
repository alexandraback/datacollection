#!/usr/bin/env python

def getRow():
	selectedRow = input()
	selectedRow -= 1
	for _ in range(selectedRow): raw_input()
	row = raw_input().split()
	for _ in range(3-selectedRow): raw_input()
	return row

t = input()
for ti in xrange(t):
	row1 = getRow()
	row2 = getRow()
	# print row1, row2
	numbers = filter(lambda x: x in row2, row1)
	# print numbers
	if not numbers:
		ans = 'Volunteer cheated!'
	elif len(numbers) > 1:
		ans = 'Bad magician!'
	else:
		ans = numbers[0]

	print 'Case #' + str(ti+1) + ":", ans
