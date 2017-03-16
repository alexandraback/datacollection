#!/usr/bin/env python
import os
import sys
import time

tStart = time.time()

#---------------------------------------------------------------------

ifilename = 'p01_input01.txt'
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

ncases = int(lines[0])
nl = 1
for n in xrange(ncases):
  r1    = int(lines[nl]); 
  row1  = [int(x) for x in lines[nl+r1].split()]
  nl   += 5
  r2    = int(lines[nl])
  row2  = [int(x) for x in lines[nl+r2].split()]
  nl   += 5

  common = []
  for x in row1:
    if x in row2:
      common += [x]
  
  if len(common) == 0:
    res = 'Volunteer cheated!'
  elif len(common) == 1:
    res = '%d'%(common[0])
  else:
    res = 'Bad magician!'
    
  res = 'Case #%d: %s'%(n+1,res)
  ofile.write('%s\n'%(res))
  print res

#---------------------------------------------------------------------

ofile.close()

print '\n Run time = ' + str((time.time() - tStart))     

