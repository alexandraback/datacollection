
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
inFile = open('test.in', 'r')
inFile = open('A-small-attempt0.in', 'r')
inFile = open('A-large.in', 'r')

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

count = 0

def lengthCurrent(Str, Sn):
	i = Sn
	current = Str[i]
	i+= 1
	while i < len(Str) and Str[i] == current:
		i += 1
	return i - Sn

def median(L):
	L2 = sorted(L)
	return L2[int(math.floor(len(L)/2.0))]
def sumToMed(L):
	med = median(L)
	s = 0
	for i in range(len(L)):
		s += abs(L[i] - med)
	return s

def doCase(case):
	N = int(inFile.readline())
	S = []
	for i in range(N):
		S.append(inFile.readline().replace('\n',''))
	Sn = []
	for i in range(N):
		Sn.append(0)
	score = 0

	while Sn[0] < len(S[0]):
		current = S[0][Sn[0]]
		#print("current: "+current)
		currentList = []
		for i in range(N):
			if Sn[i] >= len(S[i]) or S[i][Sn[i]] != current:
				out("Fegla Won")
				return
			l = lengthCurrent(S[i], Sn[i])
			currentList.append(l)
			Sn[i] += l
		score += sumToMed(currentList)
	for i in range(N):
		if Sn[i] < len(S[i]):
			out("Fegla Won")
			return
	out(str(score))






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