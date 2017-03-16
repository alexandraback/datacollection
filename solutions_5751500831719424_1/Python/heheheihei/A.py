#! /usr/bin/python

def calc(strList):
	c = strList[0][0]
	returnList = []
	for i in range(len(strList)):
		if strList[i][0] != c:
			break
		else:
			for j in range(len(strList[i])):
				if strList[i][j] != c:
					returnList.append(j)
					strList[i] = strList[i][j :]
					break
			else:
				returnList.append(len(strList[i]))
				strList[i] = ''
	else:
		return (returnList, strList)
	return ([], strList)

def getNumOfMove(charNumList):
	l = sorted(charNumList)
	centerNum = l[len(l) / 2]
	return sum([abs(n - centerNum) for n in l])

if __name__ == "__main__":
	outputFile = open("A.out", "w")
	#data = [[int(numStr) for numStr in line.split()] for line in open("A.in", "r")]
	data = [line[:-1] for line in open("A.in", "r")]
	numOfCase = int(data[0])
	dataIndex = 1
	for caseIndex in range(numOfCase):
		N = int(data[dataIndex])
		strList = data[dataIndex + 1 : dataIndex + N + 1]

		#check
		numOfMove = 0
		result = ''
		while True:
			#print strList
			lengthSet = set([len(s) for s in strList])
			if len(lengthSet) == 1 and 0 in lengthSet:
				result = str(numOfMove)
				break 
			elif len(lengthSet) > 1 and 0 in lengthSet:
				result = 'Fegla Won'
				break
			else:
				(firstCharNumList, strList) = calc(strList)
				if len(firstCharNumList) == 0:
					result = 'Fegla Won'
					break
				else:
					numOfMove += getNumOfMove(firstCharNumList)

		outputLine = "Case #%d: %s\n" % (caseIndex + 1, result)
		print outputLine
		outputFile.write(outputLine)
		dataIndex += (N + 1)
	outputFile.close()
