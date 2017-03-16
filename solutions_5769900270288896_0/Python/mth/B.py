#!/usr/bin/env python

#FILE_NAME_BASE = 'B-example'
FILE_NAME_BASE = 'B-small-attempt1'
NUM_PROCESSES = 0
MEM_LIMIT_GB = 1.5 # per worker process
RECURSION_LIMIT = 1000

def parse(inp):
	rows, cols, n = (int(x) for x in inp.readline().split())
	return rows, cols, n

def maxHappy(rows, cols):
	# How many rooms can be occupied while unhappiness remains 0?
	if rows % 2 == 0:
		return (rows / 2) * cols
	else:
		return (rows / 2) * cols + (cols + 1) / 2

def solve(rows, cols, n):
	if n <= maxHappy(rows, cols):
		return 0

	# Corners share 2 walls.
	if rows == 1 or cols == 1:
		l = max(rows, cols)
		unhappy = l - 1 - 2 * (l - n)
		assert unhappy > 0
		return unhappy
	if n == 3:
		assert rows == 2
		assert cols == 2
		return 2
	# All corners occupied.
	assert n >= 4, n
	n -= 4

	# Edges share 3 walls.
	if rows == 2 or cols == 2:
		l = max(rows, cols) - 2
		if n < l:
			# Move one out of a corner.
			assert n == l - 1
			return 2
		elif n == l:
			return 2 + 2
		unhappy = 2 # touching corners
		unhappy += l # walls on middle line
		unhappy += 2 * (l + 1) # walls across
		unhappy -= 3 * (2 * l - n) # empty rooms
		assert unhappy > 0
		return unhappy
	edges = (rows - 2) * 2 + (cols - 2) * 2
	unhappy = 2 * edges
	n -= edges

	# Inner appartments share 4 walls.
	rows -= 2
	cols -= 2
	if rows % 2 == 0:
		i = (rows / 2) * cols
		unhappy += cols + rows
	else:
		i = (rows / 2) * cols + (cols - 1) / 2
		unhappy += (cols / 2) * 2 + (rows / 2) * 2
	if n < i:
		# Edges are over-saturated.
		over = i - n
		unhappy -= 3 * over
		if over > max(rows, cols) * 2:
			unhappy += over - max(rows, cols) * 2
	else:
		unhappy += 4 * (n - i)
	return unhappy

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
