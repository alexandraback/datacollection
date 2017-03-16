from __future__ import print_function
import fileinput
import math
import numpy as np;
from fractions import gcd

def lcm2(a,b):
	return a*b/ gcd(a,b);

def lcm(aList):
	curLcd = lcm2(aList[0], aList[1]);
	for i in range(2, len(aList)):
		curLcd = lcm2(curLcd, aList[i]);
	return curLcd

inputs = fileinput.input();
numCases = int(inputs[0]);
for q in range(0,numCases):
	BandN = inputs[q*2+1].split(' ');
	B = int(BandN[0]);
	N = int(BandN[1]);
	Ms = inputs[q*2+2].split(' ');
	Ms = np.array([int(i) for i in Ms]);
	curTime = np.zeros(B);
	curBarber= 0;
	if B == 1:
		print("Case #", q+1, ": 1", sep='');
	else:
		myLcm = lcm(Ms);
		totalServed = np.sum(np.divide(np.zeros(B)+myLcm, Ms));
		if N > 2* totalServed:
			if myLcm != 1:
				N = N%totalServed; 
				N+= totalServed;
		#	else:
		#		curBarber = ((N-1)%B)
		#		N=0;
		#	if (N==0):
		#		curBarber = B-1;

		i=0
		while i < N:
			i+=1;
			curMin = np.min(curTime);
			curTime = curTime - curMin;
			available = np.argmin(curTime);

			curTime[available] = Ms[available]
			curBarber = available;



		print("Case #", q+1, ": ", curBarber+1, sep='');
