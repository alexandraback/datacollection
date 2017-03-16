# -*- coding: utf-8 -*-
#
# Copyright 2013 Eric Shtivelberg
#

import sys

practice = False

problem = 'A-large'

lines = '''4
2
2 2
3
3 2 2
3
1 1 2
3
2 3 1'''.split('\n')

if not practice:
	# Open the input file
	input_file_name = problem + '.in'
	input_file = open(input_file_name)
	lines = map(str.strip, input_file.readlines())
	input_file.close()

	print 'Closed input file...'

def read_line(): return lines.pop(0)
def read_parts(): return lines.pop(0).split(' ')
def read_int(): return int(lines.pop(0))
def read_ints(): return map(int, lines.pop(0).split(' '))
def read_float(): return int(lines.pop(0))
def read_floats(): return map(float, lines.pop(0).split(' '))


# Write the output
if not practice:
	output_file_name = problem + '.out'
	output_file = open(output_file_name, 'w')
else:
	output_file = sys.stdout

########## Contest Specific ##########

# The output list
output = []

T = read_int()

for t in range(1, T+1):
	N = read_int()
	P = read_ints()
	senators_left = sum(P)

	steps = []
	while any(P):
		max_i = P.index(max(P))
		party1 = chr(65 + max_i)
		P[max_i] -= 1
		senators_left -= 1

		max_i2 = P.index(max(P))
		if P[max_i2] > 0 and senators_left != 2:
			P[max_i2] -= 1
			senators_left -= 1
			party2 = chr(65 + max_i2)
		else:
			party2 = ''

		steps.append(party1 + party2)
	# for i in xrange(N):
		# print chr(65+i), 

	output.append(' '.join(steps))


########## Contest Specific End ##########

cases = ['Case #{}: {}'.format(i+1, output[i]) for i in range(len(output))]
output_file.write('\n'.join(cases))

if not practice:
	output_file.close()
	print 'Closed output file...'
