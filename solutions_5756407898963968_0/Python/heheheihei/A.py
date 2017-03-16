if __name__ == "__main__":
	outputFile = open("A.out", "w") 
	data = [[int(numStr) for numStr in line.split()] for line in open("A.in", "r")]
	#print data
	numOfCase = data[0][0]
	dataIndex = 1
	for caseIndex in range(numOfCase):
		firstLineIndex = data[dataIndex][0]
		firstLine = data[dataIndex + firstLineIndex]
		dataIndex += 5
		secondLineIndex = data[dataIndex][0]
		secondLine = data[dataIndex + secondLineIndex]
		dataIndex += 5
		commonElement = list(set(firstLine) & set(secondLine))
		if len(commonElement) == 0:
			result = "Volunteer cheated!"
		elif len(commonElement) == 1:
			result = str(commonElement[0])
		else:
			result = "Bad magician!"
		outputLine = "Case #%d: %s\n" % (caseIndex + 1, result)
		outputFile.write(outputLine)
	outputFile.close()
