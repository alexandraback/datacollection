
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
inFile = open('A-test.in', 'r')
inFile = open('C:/Users/quentin/Downloads/A-small-attempt0.in', 'r')
inFile = open('C:/Users/quentin/Downloads/A-large.in', 'r')

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
import string
L = string.ascii_uppercase
def haveToContinue(P):
	m = max(P)
	c = 0
	for i in P:
		if i == m:
			c += 1
	if c == 2: 
		return True
	return False

def doCase(case):
	N = int(inFile.readline())
	P = [int(x) for x in inFile.readline().split()]

	while True:
		i, x = max(enumerate(P), key=operator.itemgetter(1))
		if x == 0:
			break
		out(L[i])
		P[i] -= 1
		if haveToContinue(P):
			out(' ')
			continue
		i, x = max(enumerate(P), key=operator.itemgetter(1))
		if x == 0:
			break
		out(L[i])
		P[i] -= 1
		out(' ')



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