#!/usr/bin/env python
import sys

LETTERS = 'ABCDEFGHIJKLMNOPQRSTUVWXYZ'

def solve(input):
	return ' '.join(solveHelper([int(i) for i in input.split(' ')]))

def solveHelper(input):
	finished = False
	output = []
	while not finished:
		most = []
		m = max(input)
		s = 0
		present = 0
		for i in range(len(input)):
			s += input[i]
			if input[i] > 0:
				present += 1
			if input[i] == m:
				most.append(i)
		if m > s/2:
			print input
			print m
			print s
			print 'BAD'
		if m == 0:
			return output
		if len(most) == 2 and present == 2:
			a = most[0]
			b = most[1]
			input[a] -= 1
			input[b] -= 1
			new = LETTERS[a] + LETTERS[b]
			output.append(new)
		else:
			a = most[0]
			input[a] -= 1
			new = LETTERS[a]
			output.append(new)

for arg in sys.argv:
    filename = arg
f = open(filename, 'r')
lines = f.read().split('\n')
numCases = int(lines[0])
cases = lines[1:]
for i in range(numCases):
	print 'Case #' + str(i + 1) + ': ' + str(solve(cases[i*2+1]))