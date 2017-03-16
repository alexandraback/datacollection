from fractions import gcd

def lcm(numlist):
	current = numlist[0]
	for item in numlist[1:]:
		current = current*item // gcd(current,item)
	return current

def periodicity(numlist):
	l = lcm(numlist)
	return sum([l // item for item in numlist])
	
def f(durationlist,length,position):
	period = periodicity(durationlist)
	betterposition = position % period
	if betterposition == 0:
		betterposition = period
	timelist = []
	for item in durationlist:
		timelist.append(0)
	numberserved = 0
	while True:
		for i in range(length):
			if timelist[i] == 0:
				numberserved += 1
				timelist[i] = durationlist[i]
				if numberserved == betterposition:
					return str(i+1)
		m = min(timelist)
		timelist = [(item - m) for item in timelist]
	
import sys

with open(sys.argv[1], "r") as fileIN:
	inputLines = fileIN.readlines()

inputLines = [line.strip() for line in inputLines]	

with open(sys.argv[2], "w") as fileOUT:
	numberOfCases = int(inputLines.pop(0))
	for num in range(numberOfCases):	
		length, position = [int(x) for x in inputLines.pop(0).rstrip().split(' ')]
		durationlist = [int(x) for x in inputLines.pop(0).rstrip().split(' ')]
		fileOUT.write('Case #' + str(num+1) + ': ' + f(durationlist,length,position) + '\n')
	