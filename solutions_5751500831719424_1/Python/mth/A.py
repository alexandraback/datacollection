#!/usr/bin/env python

FILE_NAME_BASE = 'A-large'
NUM_PROCESSES = 4
MEM_LIMIT_GB = 1.5 # per worker process
RECURSION_LIMIT = 1000

def parse(inp):
	num, = (int(x) for x in inp.readline().split())
	strings = tuple(
		inp.readline().strip()
		for _ in xrange(num)
		)
	return strings,

def solve(strings):
	ind = [0] * len(strings)
	moves = 0
	ends = 0
	while ends == 0:
		ch = None
		rep = []
		for n, s in enumerate(strings):
			i = ind[n]
			if ch is None:
				ch = s[i]
			elif ch != s[i]:
				return 'Fegla Won'
			while i < len(s) and ch == s[i]:
				i += 1
			rep.append(i - ind[n])
			ind[n] = i
			if i == len(s):
				ends += 1
		moves += min(
			sum(abs(r - target) for r in rep)
			for target in xrange(min(rep), max(rep) + 1)
			)
	return moves if ends == len(strings) else 'Fegla Won'

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
