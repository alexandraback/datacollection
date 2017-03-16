#!/usr/bin/env python

FILE_NAME_BASE = 'B-small-attempt1'
NUM_PROCESSES = 4
MEM_LIMIT_GB = 1.5 # per worker process
RECURSION_LIMIT = 1000

def parse(inp):
	numBarbers, clientIndex = (int(x) for x in inp.readline().split())
	barberSpeed = tuple(int(x) for x in inp.readline().split())
	assert len(barberSpeed) == numBarbers
	return barberSpeed, clientIndex

def mult(seq):
	result = 1
	for n in seq:
		result *= n
	return result


def solve(speed, clientIndex):
	clientIndex -= 1 # make zero-based
	numBarbers = len(speed)

	def doneAt(t):
		'''number of clients complete at time t'''
		return sum(t / s for s in speed)

	# skip full repeat cycles
	repeat = mult(speed)
	clientIndex %= doneAt(repeat)

	t = 0
	while True:
		waiting = clientIndex - numBarbers - doneAt(t)
		if waiting < 0:
			break
		t += 1

	for i, s in reversed(tuple(enumerate(speed))):
		if t % s == 0:
			waiting += 1
			if waiting == 0:
				return i + 1
	assert False, t

def main():
	import sys
	sys.setrecursionlimit(RECURSION_LIMIT)

	import resource
	soft, hard = resource.getrlimit(resource.RLIMIT_AS)
	resource.setrlimit(resource.RLIMIT_AS, (MEM_LIMIT_GB * 1024 ** 3, hard))

	inp = open(FILE_NAME_BASE + '.in', 'r')
	numCases = int(inp.readline())
	if NUM_PROCESSES == 0:
		results = [
			solve(*parse(inp))
			for _ in range(numCases)
			]
	else:
		from multiprocessing import Pool
		pool = Pool(NUM_PROCESSES)
		results = [
			pool.apply_async(solve, parse(inp))
			for _ in range(numCases)
			]
	inp.close()
	out = open(FILE_NAME_BASE + '.out', 'w')
	for case, result in enumerate(results):
		value = result if NUM_PROCESSES == 0 else result.get()
		out.write('Case #%d: %s\n' % (case + 1, value))
		out.flush()
	out.close()

if __name__ == '__main__':
	main()
