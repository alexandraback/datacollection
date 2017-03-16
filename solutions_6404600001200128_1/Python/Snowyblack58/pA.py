def first(case):
	tmp = case.split()
	nums = []
	for i in range(len(tmp)):
		nums.append(int(tmp[i]))
	eaten = 0
	for n in range(len(nums) - 1):
		if nums[n] - nums[n+1] > 0:
			eaten += int(nums[n]) - int(nums[n+1])
	return eaten

def second(case):
	tmp = case.split()
	nums = []
	for i in range(len(tmp)):
		nums.append(int(tmp[i]))
	eaten = 0
	rate = getRate(nums)
	for n in range(len(nums) - 1):
		if nums[n] > rate:
			eaten += rate
		else:
			eaten += nums[n]
	return eaten


def getRate(nums):
	rate = 0
	for n in range(len(nums) - 1):
		if nums[n] - nums[n+1] > rate:
			rate = nums[n] - nums[n+1]
	return rate


def main():
	file1 = open('A-large.in','r')
	file2 = open('outfile.txt','w')
	caseNumber = int(file1.readline())
	cases = file1.read().split('\n')
	for x in range(0, caseNumber * 2, 2):
		file2.write("Case #" + str((x+2)//2) + ": " + str(first(cases[x+1])) + ' ' + str(second(cases[x+1])) + "\n")
main()