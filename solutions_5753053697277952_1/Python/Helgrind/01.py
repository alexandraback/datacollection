import numpy as np
from math import *

def solve(N, A):
	ret = []

	M = sum(A)
	while M > 0:
		m = max(A)
		majority = 1+M//2
		if m >= majority: print('ERROR', M, m, majority)
		I = [i for i, j in enumerate(A) if j == m]

		take = 1 if M == 3 else 2

		for i in I[:take]:
			A[i] -= 1
		ret.append( ''.join([chr(x+ord('A')) for x in I[:take]]) )

		M = sum(A)

	return ret

for t in range(int(input())):
	N = int(input())
	A = list(map(int, input().split()))
	print("Case #{}: {}".format(t+1, ' '.join(solve(N,A)) ))