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
	n_time = int(lines[0])	
  	data   = [int(x) for x in lines[1].split()]
	lines  = lines[2:]

	sol1   = 0
	max_dx = 0
	for k in xrange(1,n_time):
		dx = data[k-1] - data[k]
		if dx > 0:
			sol1 += dx
		if dx > max_dx:
			max_dx = dx

	sol2 = 0
	for k in xrange(0,n_time-1):
		d = data[k]
		sol2 += min(d, max_dx)

	# -------------------------------------------------
  	res = 'Case #%d: %d %d'%(ncase+1, sol1, sol2)
  	ofile.write('%s\n'%(res))
  	print res

#---------------------------------------------------------------------

ofile.close()

print '\n Run time = ' + str((time.time() - tStart))     
