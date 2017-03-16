#!/usr/bin/python3
import sys, os

file_prefix = 'A-' + ['sample', 'small-attempt0', 'large'][1]
filein = open(file_prefix + '.in', 'r')
fileout = sys.stdout if 'sample' in file_prefix else open(file_prefix + '.out', 'w')
linein = lambda: filein.readline().strip()
lineout = lambda s, *args: fileout.write(s.format(*args) + '\n')

ncases = int(linein())

for case in range(ncases):
	N = int(linein())
	party_count = [int(x) for x in linein().split()]

	names = 'ABCDEFGHIJKLMNOPQRSTUVWXYZ'
	steps = []
	while True:
		if sum(party_count) == 0 or max(party_count) == 1:
			break

		max_len = max(party_count)

		people_to_exit = ''
		for i in range(len(party_count)):
			num_ppl = party_count[i]
			if num_ppl == max_len:
				people_to_exit += names[i]
				party_count[i] -= 1
			if len(people_to_exit) == 2:
				break

		steps.append(people_to_exit)


	remain_count = sum(party_count)
	if remain_count > 0:
		people_to_exit = ''
		for x in range(len(party_count)):
			if party_count[x] == 1:
				people_to_exit += names[x]
				remain_count -= 1
				if (remain_count % 2) == 0:
					steps.append(people_to_exit)
					people_to_exit = ''

	lineout("Case #{0}: {1}", case + 1, ' '.join(steps))
