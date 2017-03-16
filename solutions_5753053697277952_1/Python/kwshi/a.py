#!/usr/bin/python
from sys import stdin

T = int(stdin.readline())

key = 'ABCDEFGHIJKLMNOPQRSTUVWXYZ'

for i in range(1, T+1):
	N = int(stdin.readline())
	parties = [int(c) for c in stdin.readline().split()]
	people = sum(parties)
	steps = []
	while people > 0:
		step_i = parties.index(max(parties))
		parties[step_i] -= 1
		people -= 1
		if people > 0 and people//max(parties) < 2:
			step_j = parties.index(max(parties))
			parties[step_j] -= 1
			people -= 1
			steps.append(key[step_i] + key[step_j])
		else:
			steps.append(key[step_i])
	print('Case #{}: {}'.format(i, ' '.join(steps)))
	


