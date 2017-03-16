import re

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
	totalNums = int(getLine())
	nums = list(getMultInt())
	
	interval = 0
	ans1 = 0
	ans2 = 0
	curNum = 0
	biggestDif = -1
	
	while curNum < totalNums:
		if curNum > 0:
			if nums[curNum] < nums[curNum - 1]:
				diff = nums[curNum - 1] - nums[curNum]
				ans1 += diff
				biggestDif = max(biggestDif, diff)
		curNum += 1
		
	curNum = 0
	
	while curNum < totalNums-1:
		ans2 += max(min(nums[curNum], biggestDif), 0)
		curNum += 1
	

	fw.write("Case #%d: %d %d\n" % (curTest+1, ans1, ans2))
	curTest += 1
					
fr.close()
fw.close()