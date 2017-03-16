#! /usr/bin/env python

import sys, getopt
import itertools
from heapq import *
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
			R, C, N = map(int, ins.readline().split())
			yield (R,C,N)
	return

def ALGORITHM(test_case):

	pq = []                         # list of entries arranged in a heap
	entry_finder = {}               # mapping of tasks to entries
	REMOVED = '<removed-task>'      # placeholder for a removed task
	counter = itertools.count()     # unique sequence count

	def add_task(task, priority=0):
		'Add a new task or update the priority of an existing task'
		if task in entry_finder:
			remove_task(task)
		count = next(counter)
		entry = [priority, count, task]
		entry_finder[task] = entry
		heappush(pq, entry)

	def task_pri(task):
		if task in entry_finder:
			entry = entry_finder[task]
			return entry[0]
		return 100

	def remove_task(task):
		'Mark an existing task as REMOVED.  Raise KeyError if not found.'
		entry = entry_finder.pop(task)
		entry[-1] = REMOVED


	def pop_task():
		'Remove and return the lowest priority task. Raise KeyError if empty.'
		while pq:
			priority, count, task = heappop(pq)
			if task is not REMOVED:
				del entry_finder[task]
				return (task, priority)
		raise KeyError('pop from an empty priority queue')

	R, C, N = test_case
	if N <= 1:
		return str(0)

	if R*C % 2 == 0 and R*C / 2 >= N:
		return str(0)

	if R*C % 2 == 1 and (R*C + 1) / 2 >= N:
		return str(0)


	edge_count = R*(C-1) + C*(R-1)


	## our approach is to remove R*C - N
	## to maximize our reduction in unhappiness
	#print test_case
	G = []
	for i in range(1, R+1):
		for j in range(1, C+1):
			degree = (i > 1) + (i < R) + (j > 1) + (j < C)
			add_task((i,j), 4 - degree)

	for i in range(R*C - N):
		node, p = pop_task()
		#print node, p
		degree = 4 - p
		#print degree, node
		edge_count -= degree
		del_neighbors = degree
		x, y = node
		if x > 1:
			old_p = task_pri((x-1,y))
			if old_p < 5:
				add_task((x-1, y), old_p + 1)
				del_neighbors -= 1

		if x < R:
			old_p = task_pri((x+1,y))
			if old_p < 5:
				add_task((x+1, y), old_p + 1)
				del_neighbors -= 1

		if y > 1:
			old_p = task_pri((x,y-1))
			if old_p < 5:
				add_task((x, y-1), old_p + 1)
				del_neighbors -= 1

		if y < C:
			old_p = task_pri((x,y+1))
			if old_p < 5:
				add_task((x, y+1), old_p + 1)
				del_neighbors -= 1

		#print del_neighbors
		assert del_neighbors == 0, pq

	return str(edge_count)


def tests():
	R, C, N = 1, 10, 5
	assert ALGORITHM((R,C,N)) == '0'

	R, C, N = 1, 10, 6
	assert ALGORITHM((R,C,N)) == '1'

	R, C, N = 1, 10, 7
	assert ALGORITHM((R,C,N)) == '3'

	R, C, N = 2, 2, 0
	assert ALGORITHM((R,C,N)) == '0'

	R, C, N = 2, 2, 1
	assert ALGORITHM((R,C,N)) == '0'

	R, C, N = 2, 2, 2
	assert ALGORITHM((R,C,N)) == '0'

	R, C, N = 2, 2, 3
	assert ALGORITHM((R,C,N)) == '2'

	R, C, N = 2, 2, 4
	assert ALGORITHM((R,C,N)) == '4'

	R, C, N = 3, 3, 0
	assert ALGORITHM((R,C,N)) == '0'

	R, C, N = 3, 3, 1
	assert ALGORITHM((R,C,N)) == '0'

	R, C, N = 3, 3, 2
	assert ALGORITHM((R,C,N)) == '0'

	R, C, N = 3, 3, 3
	assert ALGORITHM((R,C,N)) == '0'

	R, C, N = 3, 3, 4
	assert ALGORITHM((R,C,N)) == '0'

	R, C, N = 3, 3, 5
	assert ALGORITHM((R,C,N)) == '0'

	R, C, N = 3, 3, 6
	assert ALGORITHM((R,C,N)) == '4'

	R, C, N = 3, 3, 7
	assert ALGORITHM((R,C,N)) == '6'

	R, C, N = 3, 3, 8
	assert ALGORITHM((R,C,N)) == '8'

	R, C, N = 3, 3, 9
	assert ALGORITHM((R,C,N)) == '12'

	R, C, N = 2, 6, 7
	assert ALGORITHM((R,C,N)) == '2'



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
	tests()
	runAlgorithm(sys.argv[1:])
