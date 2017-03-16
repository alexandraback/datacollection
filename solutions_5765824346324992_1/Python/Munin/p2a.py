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
  	data  = [int(x) for x in lines[0].split()]
  	Ms    = [int(x) for x in lines[1].split()]
  	lines = lines[2:]

  	B = data[0]
  	N = data[1]

 
  	if N <= B:
  		sol = N
  	else:
  		N -= B
      	time0 = 0
      	time1 = (N+1)*min(Ms)+10
      	timeX = int(0.5*(time0+time1))
      	while time1-time0 > 1:
     		nn = 0
      		for x in Ms:
      			nn += int(float(timeX)/x)
      		if nn > N:
      			time1 = timeX
      		elif nn < N:
      			time0 = timeX
      		else:
      			time1 = timeX
    		timeX = int(0.5*(time0+time1))
    
    	nn0 = 0
      	for x in Ms:
      		nn0 += int(float(time0)/x)
    	nn1 = 0
      	for x in Ms:
      		nn1 += int(float(time1)/x)
        
      	dn = N-nn0
    
    	sol = 0
       	for k,x in enumerate(Ms):
       		if time1%x == 0:
       			dn -= 1
       			if dn == 0:
    	   			sol = k+1
       				break

  	# -------------------------------------------------
  	res = 'Case #%d: %d'%(ncase+1, sol)
  	ofile.write('%s\n'%(res))
  	print res

#---------------------------------------------------------------------

ofile.close()

print '\n Run time = ' + str((time.time() - tStart))     
