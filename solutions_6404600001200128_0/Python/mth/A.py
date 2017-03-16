#!/usr/bin/env python

FILE_NAME_BASE = 'A-small-attempt0'
NUM_PROCESSES = 0
MEM_LIMIT_GB = 1.5 # per worker process
RECURSION_LIMIT = 1000

def parse(inp):
	numSamples = int(inp.readline())
	samples = tuple(int(x) for x in inp.readline().split())
	assert len(samples) == numSamples
	return samples,

def solve(samples):
	min1 = sum(
		max(samples[i] - samples[i + 1], 0)
		for i in xrange(len(samples) - 1)
		)

	maxDelta = max(
		samples[i] - samples[i + 1]
		for i in xrange(len(samples) - 1)
		)
	min2 = sum(
		min(samples[i], maxDelta)
		for i in xrange(len(samples) - 1)
		)

	return '%d %d' % (min1, min2)

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
