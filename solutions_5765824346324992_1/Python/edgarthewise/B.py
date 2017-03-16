from sys import stdin, stdout, exit
import numpy as np
from numpy import *

def getWords():
    return stdin.readline().strip().split()

def getInts():
    return array([int(i) for i in getWords()], dtype=int)

def getInt():
	i = getInts()
	assert len(i)==1
	return i

T = getInt()

for caseNo in xrange(1,T+1):

	B, N = getInts()
	M = getInts()
	assert B==len(M)
	
	'''
	Gives the number of customers served (completed or in progress)
	(m minutes + epsilon) time after the open.
	'''
	def customersByMinute(m):
		return (1 + m // M).sum()
	
	# compute the time at which we are served
	lowLim = -1
	highLim = 1
	while customersByMinute(highLim) < N:
		highLim *= 2
	
	while highLim - lowLim > 1:
		midpoint = (highLim + lowLim)//2
		if customersByMinute(midpoint) < N:
			lowLim = midpoint
		else:
			highLim = midpoint
	minuteServed = highLim

	isBarberFree = (minuteServed % M == 0)
	#assert isBarberFree.sum() ==\
	#	customersByMinute(minuteServed) - customersByMinute(minuteServed - 1)
	#assert customersByMinute(minuteServed) >= N \
	#	and customersByMinute(minuteServed - 1) < N
	
	barberNo = where(isBarberFree)[0][N - customersByMinute(minuteServed - 1) - 1] + 1
	
	print "Case #%d: %d"%(caseNo, barberNo)
