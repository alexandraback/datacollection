#! /usr/bin/env python

import sys, getopt
from math import ceil as ceil
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
			B, N = map(int, ins.readline().split())
			cut_times = map(int, ins.readline().split())
			assert len(cut_times) == B
			yield (B, N, cut_times)
	return

def gcd(a, b):
    while b:      
        a, b = b, a % b
    return a

def lcm(a, b):
    return a * b // gcd(a, b)

def lcmm(args): 
    return reduce(lcm, args)

def try_T(cut_times, T):
	# how many have been seated by time T?
	seated = sum(map(lambda x: ceil(T / float(x)), cut_times))
	return seated

def bruteforce_range(cut_times, N, minR, maxR):
	#print minR, maxR
	T = (minR + maxR) / 2
	#print N, minR, maxR
	nextT = T+1
	result1 = try_T(cut_times, T)
	result2 = try_T(cut_times, nextT)
	if result1 < N and result2 >= N:
		for i in range(len(cut_times)):
			if T % cut_times[i] == 0:
				result1 += 1
				if result1 == N:
					return i
	else:
		if result2 < N:
			return bruteforce_range(cut_times, N, nextT, maxR)
		else:
			return bruteforce_range(cut_times, N, minR, T)

def TESTS():
	func = lambda L, M: sum(map(lambda x: M / x, L))
	A = [10,5]
	M = lcmm(A)
	assert M == 10
	assert func(A,M) == 3

	for i in range(1,10):
		assert ceil(i / float(10)) == 1, str(i) + " " + str(ceil(i / 10))
	A = [1,2,3,1]
	M = lcmm(A)
	assert M == 6

	assert try_T(A, 0) == 0
	assert try_T(A, 1) == 4, str(try_T(A, 1))
	assert try_T(A, 2) == 6
	assert try_T(A, 3) == 9
	assert try_T(A, 4) == 12
	assert try_T(A, 5) == 15
	assert try_T(A, 6) == 17
	B = 4
	ALGORITHMT = lambda a, b, c: ALGORITHM((a,b,c))
	assert ALGORITHMT(B, 1, A) == "1"
	assert ALGORITHMT(B, 2, A) == "2", ALGORITHMT(B, 2, A)
	assert ALGORITHMT(B, 3, A) == "3"
	assert ALGORITHMT(B, 4, A) == "4"
	assert ALGORITHMT(B, 5, A) == "1"
	assert ALGORITHMT(B, 6, A) == "4"
	assert ALGORITHMT(B, 7, A) == "1"
	assert ALGORITHMT(B, 8, A) == "2"
	assert ALGORITHMT(B, 9, A) == "4"
	assert ALGORITHMT(B, 10, A) == "1"
	assert ALGORITHMT(B, 11, A) == "3"
	assert ALGORITHMT(B, 12, A) == "4"
	assert ALGORITHMT(B, 13, A) == "1"
	assert ALGORITHMT(B, 14, A) == "2"
	assert ALGORITHMT(B, 15, A) == "4"
	assert ALGORITHMT(B, 16, A) == "1"
	assert ALGORITHMT(B, 17, A) == "4"
	assert ALGORITHMT(B, 18, A) == "1"
	assert ALGORITHMT(B, 19, A) == "2"
	assert ALGORITHMT(B, 20, A) == "3"
	assert ALGORITHMT(B, 21, A) == "4"


def ALGORITHM(test_case):
	#TESTS()
	# test_case = B, N, cut_times
	B, N, cut_times = test_case
	assert len(cut_times) == B

	M = lcmm(cut_times)

	max_people_during_period = map(lambda x: M / x, cut_times)

	period = sum(max_people_during_period)

	N = (N % period)
	#print N, M
	if N == 0:
		N = period
	if N == 1:
		return "1"

	barber_index = bruteforce_range(cut_times, N, 0, M+1)
	
	return str(barber_index+1)


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
	TESTS()
	runAlgorithm(sys.argv[1:])
