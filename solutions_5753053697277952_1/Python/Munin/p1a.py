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
  N  = lines[0]
  S  = [int(x) for x in lines[1].split()]
  lines = lines[2:]


  solution = ''
  while sum(S) > 0:

  	max_value = max(S)
  	max_pos   = [k for k,x in enumerate(S) if int(max_value==x)]

  	if len(max_pos)%2 == 1:
  		solution += chr( max_pos[0] + ord('A') )
  		solution += ' '
  		S[max_pos[0]] -= 1
  		del max_pos[0]

  	while len(max_pos) > 0:
  		solution += chr( max_pos[0] + ord('A') ) 
  		solution += chr( max_pos[1] + ord('A') ) 
  		solution += ' '
  		S[max_pos[0]] -= 1
  		S[max_pos[1]] -= 1
  		del max_pos[0]
  		del max_pos[0]


  # -------------------------------------------------
  res = 'Case #%d: %s'%(ncase+1, solution)
  ofile.write('%s\n'%(res))
  print res

#---------------------------------------------------------------------

ofile.close()

print '\n Run time = ' + str((time.time() - tStart))     
