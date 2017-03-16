import re
import math

fr = open("input.txt", 'r')
fw = open("output.txt", 'w')

lines = fr.readlines()

numTests = lines[0].strip()
curTest = 0
curLine = 1

def getLine():
	global curLine
	global lines
	curLine += 1
	return lines[curLine-1]
	
def getMult():
	return getLine().strip().split()

def getMultInt():
	return map(int, getMult())
	
def getMultFloat():
	return map(float, getMult())

	
while curTest < int(numTests):
	B, N = getMultInt()
	mins = list(getMultInt())
	
	minIdx = 0
	
	dic = dict()
	
	while minIdx < B:
		dic[minIdx] = mins[minIdx]
		minIdx += 1
		
	sortedDic = sorted(dic, key=lambda key: dic[key])
	
	barberIdx = float(N)
#5 1000000000
#25 25 25 25 25
	if barberIdx < mins[sortedDic[0]]:
		ans = 1
	else:
		curIdx = 0
		while barberIdx >= mins[sortedDic[0]]:
			curTotal = 0
			lastTime = 0
			prevSum = 0.0
			first = True
			curIdx = 0
			
			for v in sortedDic:
				if first or lastTime == float(mins[v]):
					additional = 0.0
				else:
					additional = int(float(mins[v]) / float(lastTime) * prevSum)
				first = False
				newTotal = 1.0 + additional
				
				curTotal += newTotal
				lastTime = float(mins[v])
				prevSum = float(newTotal)
				
				if newTotal > barberIdx:
					break
			
				barberIdx -= newTotal
				curIdx += 1

			if curTotal < barberIdx:
				barberIdx -= curTotal * int(barberIdx / curTotal)
				
		if (barberIdx > 0.0):
			ans = 1
		else:
			ans = int(curIdx)
	
	print(ans)
		

	fw.write("Case #%d: %d\n" % (curTest+1, ans))
	curTest += 1
					
fr.close()
fw.close()