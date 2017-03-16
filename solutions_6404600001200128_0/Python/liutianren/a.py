#!/usr/bin/python

import sys

if __name__ == "__main__":
	T = int(sys.stdin.readline())

	for t in range(T):
		n = int(sys.stdin.readline())
		mushroom = map(int, sys.stdin.readline().split())

		sum1 = 0
		for i in range(n-1):
			sum1 = sum1 + max(0,mushroom[i]-mushroom[i+1])

		minspd = 0
		for i in range(n-1):
			minspd = max(minspd, mushroom[i]-mushroom[i+1])
		sum2 = 0
		for i in range(n-1):
			sum2 = sum2 + max(0, min(minspd, mushroom[i]))

		print "Case #{}: {} {}".format(t+1, sum1, sum2)