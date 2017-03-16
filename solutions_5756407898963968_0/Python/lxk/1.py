def read_rows(lines, curLine):
	rows = []
	for i in range(0, 4):
		row = [int(x) for x in lines[curLine + i].split(' ')]
		rows.append(row)

	return rows

fin = open('input.txt')
lines = fin.read().split("\n")

countTests = int(lines[0])

for testCase in range(1, countTests + 1):
	curLine = (testCase - 1) * 10 + 1

	row1 = int(lines[curLine])
	row2 = int(lines[curLine + 5])

	rows1 = read_rows(lines, curLine + 1)
	rows2 = read_rows(lines, curLine + 6)

	row_diff = set(rows1[row1 - 1]).intersection(rows2[row2 - 1])

	print "Case #" + str(testCase) + ":",
	if len(row_diff) == 1:
		print str(row_diff.pop())
	elif len(row_diff) == 0:
		print "Volunteer cheated!"
	else:
		print "Bad magician!"