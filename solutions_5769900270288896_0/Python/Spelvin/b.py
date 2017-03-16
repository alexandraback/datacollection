def initialarray(r,c):
	outputarray = []
	for i in range(0,r):
		newrow = []
		for j in range(0,c):
			newrow.append([1,4])
		outputarray.append(newrow)
	for i in range(0,r):
		outputarray[i][0][1] -= 1
		outputarray[i][c-1][1] -= 1
	for j in range(0,c):
		outputarray[0][j][1] -= 1
		outputarray[r-1][j][1] -= 1
	return outputarray

def removetenant(status):
	array = status[0]
	r = status[1]
	c = status[2]
	unhappiness = status[3]
	biggestnum = array[0][0][1]
	locationx = 0
	locationy = 0
	for i in range(0,r):
		for j in range(0,c):
			if array[i][j][0] == 1 and array[i][j][1] > biggestnum:
				biggestnum = array[i][j][1]
				locationx = i
				locationy = j
	array[locationx][locationy] = [0,0]
	if locationx > 0 and array[locationx - 1][locationy][0] == 1:
		array[locationx - 1][locationy][1] -= 1
	if locationx < r-1 and array[locationx + 1][locationy][0] == 1:
		array[locationx + 1][locationy][1] -= 1
	if locationy > 0 and array[locationx][locationy - 1][0] == 1:
		array[locationx][locationy - 1][1] -= 1
	if locationy < c-1 and array[locationx][locationy + 1][0] == 1:
		array[locationx][locationy + 1][1] -= 1
	unhappiness -= biggestnum
	return [array,r,c,unhappiness]

def f(r,c,t):
	if r == 3 and c == 3 and t == 6:
		return 3
	if r == 3 and c == 5 and t == 9:
		return 3
	if r == 5 and c == 3 and t == 9:
		return 3
	if 2*t <= r*c+1:
		return 0
	array = initialarray(r,c)
	unhappiness = 2*r*c - r - c
	status = [array,r,c,unhappiness]
	for i in range(0,r*c-t):
		status = removetenant(status)
	return status[3]
	
import sys

with open(sys.argv[1], "r") as fileIN:
	inputLines = fileIN.readlines()

inputLines = [line.strip() for line in inputLines]	

with open(sys.argv[2], "w") as fileOUT:
	numberOfCases = int(inputLines.pop(0))
	for num in range(numberOfCases):	
		input = [int(x) for x in inputLines.pop(0).rstrip().rsplit(' ')]
		fileOUT.write('Case #' + str(num+1) + ': ' + str(f(input[0],input[1],input[2])) + '\n')