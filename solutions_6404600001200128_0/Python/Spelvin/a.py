def f(numlist,length):
	biggestdif = 0
	total1 = 0
	for i in range(0,length-1):
		posdif = max(0,numlist[i]-numlist[i+1])
		total1 += posdif
		biggestdif = max(biggestdif,posdif)
	total2 = 0
	for i in range(0,length-1):
		total2 += min(biggestdif,numlist[i])
	return str(total1) + ' ' + str(total2)

import sys

with open(sys.argv[1], "r") as fileIN:
	inputLines = fileIN.readlines()

inputLines = [line.strip() for line in inputLines]	

with open(sys.argv[2], "w") as fileOUT:
	numberOfCases = int(inputLines.pop(0))
	for num in range(numberOfCases):	
		length = int(inputLines.pop(0))
		numlist = [int(x) for x in inputLines.pop(0).rstrip().split(' ')]
		fileOUT.write('Case #' + str(num+1) + ': ' + f(numlist,length) + '\n')