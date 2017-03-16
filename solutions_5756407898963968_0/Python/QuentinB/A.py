
import sys
import time
import operator
import math
import re

timeit = 1
debugv = 0
startTime = 0

outFile = open('output.txt', 'w')
inFile = sys.stdin
inFile = open('A-small-attempt0.in', 'r')

def main():
	T = int(inFile.readline())
	startTime = time.clock()
	for case in range(1,T+1):
		out("Case #{}: ".format(case))
		doCase(case)
		out("\n")

		



def out(m):
	outFile.write(m)
	sys.stdout.write(m)

def cobin(k,n):
	#debug(str(k)+" parmi "+str(n)+"\n")
	return math.factorial(n)//(math.factorial(n-k)*math.factorial(k))


def doCase(case):
	s1 = int(inFile.readline())
	L1 = []
	for i in range(4):
		if i + 1 == s1:
			L1 = [x for x in inFile.readline().split()]
		else:
			inFile.readline()

	s2 = int(inFile.readline())
	L2 = []
	i = 0

	ret = False
	for i in range(4):
		L2.append([x for x in inFile.readline().split()])
	
	intersect = []
	for t in L1:
		if t in L2[s2 - 1]:
			intersect.append(t)

	if len(intersect) == 0:
		out("Volunteer cheated!")
		return

	if len(intersect) == 1:
		out(str(intersect[0]))
		return

	out("Bad magician!")

			

	




	#out(str(count))






def debug(m):
	if debugv:
		sys.stdout.write(m)

if __name__ == '__main__':
	if len(sys.argv) > 1:
		if re.search('d', sys.argv[1]):
			debugv = 1
		if re.search('i', sys.argv[1]):
			inFile = sys.stdin

	main()
	if timeit:
		sys.stderr.write("Completed in {} seconds.\n".format(time.clock() - startTime)) 