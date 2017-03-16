def formatLine(line):
	s = line.split()
	s = [int(i) for i in s]

	return s

def solveTestCase(line):
	line = formatLine(line)





########
data = open("testfile.txt", 'r')
out = open("answer.txt", "w")
numberCases = int(data.readline())
#########

for i in range(numberCases):

	size = int(data.readline())
	n = formatLine(data.readline())
	minEaten = 0
	last  = n[0]

	maxChange = 0
	prev = n[0]
	minEatenb = 0
	for j in n[1:]:
		if j < prev:
			if maxChange < (prev-j):
				maxChange = prev-j
		prev = j


	for j in n[1:]:
		if j < last:
			minEaten += last - j
		last = j

	for j in n[:-1]:
		minEatenb += min(maxChange, j)

	s = "Case #{0:d}: {1:d} {2:d}\n".format(i+1, minEaten, minEatenb)
	print s
	out.write(s)

