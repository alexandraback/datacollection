#!env python3

from codejam import *
import lcs


def distance(s1, s2):
	return lcs.lcs_mat(s1, s2)[-1][-1]

def simplify(s):
	r = ''
	prev = ''
	for c in s:
		if c != prev:
			r += c
			prev = c
	return r

@codejam
def solve():
	N = int(stdin.readline())
	strings = []
	for s in range(N):
		strings.append(stdin.readline().rstrip('\n'))

	#print(strings)
	simple = simplify(strings[0])
	for s in strings:
		if simple != simplify(s): return 'Fegla Won'

	mapping = [[0] * N for i in range(N)]
	for i in range(N):
		for j in range(N):
			s1 = strings[i]
			s2 = strings[j]
			mapping[i][j] = len(s1) + len(s2) - 2*distance(s1, s2)

	#print(mapping)
	# wrong when N > 2
	return min(map(sum, mapping))

	

