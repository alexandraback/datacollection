from __future__ import print_function
import fileinput
import math
import numpy as np;

inputs = fileinput.input();
numCases = int(inputs[0]);
for q in range(0,numCases):
	numRounds = int(inputs[q*2+1]);
	numOnPlates = inputs[q*2+2].split(' ');
	numOnPlates = np.array([int(i) for i in numOnPlates]);
	myDiff = np.diff(numOnPlates);
	case1 = -1*np.sum(myDiff[myDiff < 0]);
	case2Rate = np.min(myDiff)*-1
	case2 = np.zeros(numOnPlates.shape) + case2Rate
	case2 = np.minimum(case2, numOnPlates);
	case2 = int(np.sum(np.delete(case2, case2.size-1)));
	print("Case #", q+1, ": ", case1, " ", case2, sep='');

