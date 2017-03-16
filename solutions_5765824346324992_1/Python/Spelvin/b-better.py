def numberserved(minutes,numlist):
	return sum([(minutes // num) + 1 for num in numlist]) 

def minutesright(minutes,numlist,position):
	return numberserved(minutes,numlist) >= position and numberserved(minutes-1,numlist) < position

def maxminutes(numlist,position):
	return (position * min(numlist)) + 1
	
def minutesearch(numlist,j,k,position):
	if j == k:
		return j
	if j + 1 == k:
		if minutesright(j,numlist,position):
			return j
		else:
			return k
	trial = (j + k) // 2
	if minutesright(trial,numlist,position):
		return trial
	elif numberserved(trial,numlist) >= position:
		return minutesearch(numlist,j,trial-1,position)
	else:
		return minutesearch(numlist,trial+1,k,position)
		
def minutes(numlist,position):
	return minutesearch(numlist,0,maxminutes(numlist,position),position)

def f(numlist,position,length):
	endtime = minutes(numlist,position)
	if endtime == 0:
		stationnumber = position
	else:
		stationnumber = position - numberserved(endtime-1,numlist)
	count = 0
	for i in range(length):
		if endtime % numlist[i] == 0:
			count += 1
			if count == stationnumber:
				return str(i+1)

import sys

with open(sys.argv[1], "r") as fileIN:
	inputLines = fileIN.readlines()

inputLines = [line.strip() for line in inputLines]	

with open(sys.argv[2], "w") as fileOUT:
	numberOfCases = int(inputLines.pop(0))
	for num in range(numberOfCases):	
		length, position = [int(x) for x in inputLines.pop(0).rstrip().split(' ')]
		durationlist = [int(x) for x in inputLines.pop(0).rstrip().split(' ')]
		fileOUT.write('Case #' + str(num+1) + ': ' + f(durationlist,position,length) + '\n')