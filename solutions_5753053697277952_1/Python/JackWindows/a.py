#!/usr/bin/python

import sys
import numpy as np

if len(sys.argv) != 2:
	print "usage: ./a.py <input_file_name>"
	exit()

input_file_name = sys.argv[1]
if input_file_name[-3:] == ".in":
	output_file_name = input_file_name[:-3] + ".out"
else:
	output_file_name = input_file_name + ".out"

results = []
with open(input_file_name, 'r') as f:
	T = int(f.readline())
	for i in xrange(T):
		N = int(f.readline())
		S = f.readline()
		S = S[:-1]
		P = [int(s) for s in S.split(' ')]
		ret = ''
		while sum(P) > 0:
			max1 = max(P)
			max1index = P.index(max1)
			P[max1index] -= 1
			max2 = max(P)
			if sum(P) > 0 and float(max2) / sum(P) > 0.5:
				max2index = P.index(max2)
				P[max2index] -= 1
				ret += chr(ord('A') + max1index) + chr(ord('A') + max2index) + ' '
			else:
				ret += chr(ord('A') + max1index) + ' '
		ret = ret[:-1]
		results.append(ret)

with open(output_file_name, 'w') as f:
	for i in range(len(results)):
		output_string = "Case #%d: %s\n" % (i + 1, results[i])
		print output_string[:-1]
		f.write(output_string)
