import sys

def map(func, l):
	return [func(i) for i in l]


def parseCase(instrm):
	numItems = int(instrm.readline().strip())
	items = []
	for i in range(numItems):
		items.append(instrm.readline().strip())
	
	return items

def str2num(str, template):
	nums = []
	sidx = 0
	for char in template:
		count = 0
		while (sidx < len(str)):
			if (str[sidx]==char):
				count += 1
				sidx += 1
			else:
				break
		if (count == 0):
			return None
		nums.append(count)
	if (sidx != len(str)):
		return None
	return nums

def strToTemplate(firstStr):
	initChar = '@'
	uniqueChars = ""
	for char in firstStr:
		if char != initChar:
			uniqueChars += char
			initChar = char
	return uniqueChars
	
def solveCase(input):
	#convert to numbers
	initChar = '@'
	uniqueChars = ""
	firstStr = input[0]
	for char in firstStr:
		if char != initChar:
			uniqueChars += char
			initChar = char
	nums = []
	for s in input:
		tryNum = str2num(s, uniqueChars)
		if tryNum is None:
			return "Fegla Won"
		else:
			nums.append(tryNum)
	#for num in nums:
	#	print(num)
	totCost = 0
	for i in range(len(uniqueChars)):
		min = nums[0][i]
		max = min
		for j in range(1,len(nums)):
			if (nums[j][i] > max):
				max = nums[j][i]
			if (nums[j][i] < min):
				min = nums[j][i]
		minCost = None
		for bestNum in range(min, max+1):
			currCost = 0
			for j in range(len(nums)):
				currCost += abs(nums[j][i]-bestNum)
			if ((minCost is None) or minCost > currCost):
				minCost = currCost
			#print("curr bestNum: " + str(bestNum) + " currCost: " + str(currCost))
		#print("curr idx: " + str(i) + " curr minCost: " + str(minCost))
		totCost += minCost
	#if (totCost != diffSum(nums[0], nums[1])):
	#	print("Hey, bug in the algo!")
	return totCost

def diffSum(a1, a2):
	diffSum = 0
	for i in range(len(a1)):
		diffSum += abs(a2[i] - a1[i])
	return diffSum
	#print("diffSum: " + str(diffSum))
	
	
if __name__=="__main__":
	instrm = open(sys.argv[1])
	cases = int(instrm.readline().strip())
	for i in range(cases):
		input = parseCase(instrm)
		#print(input)
		# result = str(solveCase(input))
		# if (result != "Fegla Won"):
			# templates = map(strToTemplate, input)
			# t0 = templates[0]
			# match = True
			# for t in range(1, len(templates)):
				# if (templates[t] != t0):
					# match = False
					# break
			# if (not match):
				# print(input[0])
				# print(input[1])
				# print(result)
				# print("stupid error...")
		# #if (result == "Fegla Won"):
		#	templates = map(strToTemplate, input)
		#	t0 = templates[0]
		#	match = True
		#	for t in range(1, len(templates)):
		#		if (templates[t] != t0):
		#			match = False
		#			break
		#	if (match):
		#		print("Hey, stupid error in str2nums")
		#	print(strToTemplate(input[0]))
		#	print(strToTemplate(input[1]))
		print("Case #" + str(i+1) +": "+str(solveCase(input)))
	instrm.close()