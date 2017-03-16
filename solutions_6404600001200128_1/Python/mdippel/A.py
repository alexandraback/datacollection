#! /usr/bin/env python

import sys, getopt

##################
## default reading
def writeOutput(output, fname):
	f = open(fname, 'w')
	for s in output:
		f.write(s)

def parseCommandLine(argv):
	inputfile = ''
	outputfile = ''
	try:
		opts, args = getopt.getopt(argv,"hi:o:",["ifile=","ofile="])
	except getopt.GetoptError:
		print "getting arguments error"
		print 'test.py -i <inputfile> -o <outputfile>'
		sys.exit(2)
	for opt, arg in opts:
		if opt == '-h':
			print 'test.py -i <inputfile> -o <outputfile>'
			sys.exit()
		elif opt in ("-i", "--ifile"):
			inputfile = arg
		elif opt in ("-o", "--ofile"):
			outputfile = arg
	return inputfile, outputfile

## end default reading
#######################

def processInput(fname):
	# yields test cases
	with open(fname, "r") as ins:
		T = int(ins.readline())
		for i in range(T):
			N = int(ins.readline())
			nums = map(int, ins.readline().split())
			assert len(nums) == N
			yield (N, nums)
	return

def minate_anyTime(nums):
	total = 0
	for i in range(len(nums)-1):
		if nums[i] > nums[i+1]:
			total += nums[i] - nums[i+1]
	return total

def minate_givenRate(nums, rate):
	total = 0
	for i in range(len(nums) - 1):
		total += min(nums[i], rate)
	return total

def max_consec_dif(nums):
	maxdiff = 0
	for i in range(len(nums)-1):
		if nums[i] > nums[i+1] and nums[i] - nums[i+1] > maxdiff:
			maxdiff = nums[i] - nums[i+1]
	return maxdiff

def ALGORITHM(test_case):
	# test_case = N, nums
	N, nums = test_case
	case1 = minate_anyTime(nums)

	max_ate_between = max_consec_dif(nums)

	case2 = minate_givenRate(nums, max_ate_between)
	return str(case1) + " " + str(case2)


def runAlgorithm(argv):
	inputfile, outputfile = parseCommandLine(argv)
	if inputfile == '' or outputfile == '':
		print 'test.py -i <inputfile> -o <outputfile>'
		sys.exit(2)

	results = []
	for test_case in processInput(inputfile):
		results.append(ALGORITHM(test_case))

	for i in range(len(results)):
		results[i] = "Case #" + str(i+1) + ": " + results[i] + "\n"

	writeOutput(results, outputfile)

if __name__ == "__main__":

	runAlgorithm(sys.argv[1:])
