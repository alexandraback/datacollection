import sys
import math
from decimal import *

filename = sys.argv[1]
f = open(filename, 'r')

numCases = int(f.readline())
alphabet = ['A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K', 'L', 'M', 'N', 'O', 'P', 'Q', 'R', 'S', 'T', 'U', 'V', 'W', 'X', 'Y', 'Z']

for t in range(numCases):
	N = int(f.readline())
	senators = zip(map(int, f.readline().split()), alphabet)
	senators.sort(key=lambda x: x[0], reverse=True)
	order = ''	
	if len(senators) == 2:
		order = 'AB ' * senators[0][0]
	else:
		while(senators[0][0] != senators[1][0]):
			order = order + senators[0][1] + ' '
			senators[0] = (senators[0][0] - 1, senators[0][1])
		for i in range(len(senators) - 2):
			order = order + (senators[i+2][1] + ' ') * senators[i+2][0]
		order = order + (senators[0][1] + senators[1][1] + ' ')*senators[0][0]

	print 'Case #{}: {}'.format(t+1, order.strip())
