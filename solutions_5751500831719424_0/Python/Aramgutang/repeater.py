#!/usr/bin/env python
import sys

def collapse(prev, next):
	if not prev:
		return next
	elif next != prev[-1]:
		return prev + next
	else:
		return prev

def to_counts(string):
	last_letter = ''
	counts = []
	for letter in string:
		if last_letter and letter == last_letter:
			counts[-1] += 1
		else:
			last_letter = letter
			counts += [1]
	return counts
		
with open(sys.argv[1]) as f:
	for case_number in range(1, int(f.readline()) + 1):
		strings = []
		for i in range(int(f.readline())):
			strings += [f.readline().strip()]
		if len(set(strings)) == 1:
			moves = 0
		elif len(set(map(lambda string: reduce(collapse, string), strings))) > 1:
			moves = 'Fegla Won'
		else:
			counts = zip(*map(to_counts, strings))
			moves = 0
			for count in counts:
				median = sorted(count)[len(count) // 2]
				for value in count:
					moves += abs(median - value)
		print 'Case #%s: %s' % (case_number, moves)