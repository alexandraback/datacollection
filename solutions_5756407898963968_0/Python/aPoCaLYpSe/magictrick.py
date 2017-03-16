import sys

def map(func, l):
	return [func(i) for i in l]


def parseCase(instrm):
	firstCol = int(instrm.readline().strip())
	firstMat = []
	for i in range(4):
		row = instrm.readline().strip().split(" ")
		firstMat.append(map(int, row))
	secCol = int(instrm.readline().strip())
	secMat = []
	for i in range(4):
		row = instrm.readline().strip().split(" ")
		secMat.append(map(int, row))
	return (firstCol, secCol, firstMat, secMat)

def solveCase(input):
	(firstRow, secRow, firstMat, secMat) = input
	firstRow = firstMat[firstRow-1]
	secRow = secMat[secRow-1]
	both = []
	for el in secRow:
		if (firstRow.count(el)>0):
			both.append(el)
	if (len(both) == 0):
		return "Volunteer cheated!"
	if (len(both) == 1):
		return both[0]
	else:
		return "Bad magician!"




if __name__=="__main__":
	instrm = open(sys.argv[1])
	cases = int(instrm.readline().strip())
	for i in range(cases):
		input = parseCase(instrm)
		print("Case #" + str(i+1) +": "+str(solveCase(input)))
	instrm.close()