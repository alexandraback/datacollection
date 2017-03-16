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

def convex_hull(points):
    points = sorted(set(points))
 
    if len(points) <= 1:
        return points
 
    def cross(o, a, b):
        return (a[0] - o[0]) * (b[1] - o[1]) - (a[1] - o[1]) * (b[0] - o[0])
 
    lower = []
    for p in points:
        while len(lower) >= 2 and cross(lower[-2], lower[-1], p) <= 0:
            lower.pop()
        lower.append(p)
 
    upper = []
    for p in reversed(points):
        while len(upper) >= 2 and cross(upper[-2], upper[-1], p) <= 0:
            upper.pop()
        upper.append(p)
 
    return lower[:-1] + upper[:-1]
 

#---------------------------------------------------------------------
# Main
ncases = int(lines[0])
lines  = lines[1:]
for ncase in xrange(ncases):
 	n_points = int(lines[0])
	lines = lines[1:]
	points = []
 	for k in xrange(n_points):
		p = [int(x) for x in lines[0].split()]
		points += [tuple(p)]
		lines = lines[1:]

	sols = []
	for k in xrange(n_points):
		other_points   = points[:k] + points[k+1:]
		p0             = points[k]
		current_points = [p0]
		n_remove = 0
		for p in other_points:
			current_points += [p]
			convex_points = convex_hull(current_points)
			if not (p0 in convex_points):
				remove_flag = 1
				for k in xrange(len(convex_points)):
					p1 = convex_points[k]
					p2 = convex_points[(k+1)%len(convex_points)]
					d1 = (p2[0]-p1[0], p2[1]-p1[1]) 
					d2 = (p2[0]-p0[0], p2[1]-p0[1]) 
					det = d1[0]*d2[1] - d1[1]*d2[0]
					if abs(det) == 0:
						remove_flag = 0
						break
				if remove_flag == 1:
					current_points = current_points[:-1]
					n_remove += 1

		sols += [n_remove]

	sol_text = ''
	for x in sols:
		sol_text = '%s\n%d'%(sol_text, x)

	# -------------------------------------------------
  	res = 'Case #%d: %s'%(ncase+1, sol_text)
  	ofile.write('%s\n'%(res))
  	print res

#---------------------------------------------------------------------

ofile.close()

print '\n Run time = ' + str((time.time() - tStart))     
