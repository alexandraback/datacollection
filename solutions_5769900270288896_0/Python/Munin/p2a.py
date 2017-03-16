#!/usr/bin/env python
import os
import sys
import time

tStart = time.time()

#---------------------------------------------------------------------

ifilename = 'input.in'
ofilename = 'results.out'

args = sys.argv
if len(args) > 1:
  ifilename = args[1]
if len(args) > 2:
  ofilename = args[2]

#---------------------------------------------------------------------

ifile = open(ifilename,'r')
data  = ifile.read()
ifile.close()
lines = data.splitlines()

ofile = open(ofilename, 'w')

#---------------------------------------------------------------------
# Functions


#---------------------------------------------------------------------
# Main
ncases = int(lines[0])
lines  = lines[1:]
for ncase in xrange(ncases):
	line   = lines[0].split()
	lines  = lines[1:]

	R = int(line[0])
	C = int(line[1])
	N = int(line[2])

	if N <= int((R*C+1)/2):
		res = 0
	else:
		best_case = -1
		x = [0 for x in xrange(R*C)]
		for k in xrange(2**(R*C)):
			x[0]+=1
			n = 0
			while n < len(x):
				if x[n] > 1:
					x[n] = 0
					n += 1
					if n < len(x):
						x[n] += 1
					else:
						break
				else:
					break
			if sum(x) == N:
				n_cases = 0
				for r in xrange(R-1):
					for c in xrange(C):
						if x[r*C + c] > 0 and x[(r+1)*C + c] > 0:
							n_cases += 1
				for c in xrange(C-1):
					for r in xrange(R):
						if x[r*C + c] > 0 and x[r*C + c+1] > 0:
							n_cases += 1

				if best_case < 0 or best_case > n_cases:
					best_case = n_cases 

		res = best_case

#	print R,C,N, res

	# -------------------------------------------------
  	res = 'Case #%d: %d'%(ncase+1, res)
  	ofile.write('%s\n'%(res))
  	print res

#---------------------------------------------------------------------

ofile.close()

print '\n Run time = ' + str((time.time() - tStart))     
