#!/usr/bin/python

import sys

def solve(B, n, M):
	spd = sum((1./t for t in M))
	time = max(0,int((n-2.)/spd) - max(M))
	# print B, n, M
	# print (n-2.)/spd, time

	toserve = n - sum((time/t for t in M))
	wtime = [(time/t)*t for t in M]

	while True:
		minwtime = min(wtime)
		index = wtime.index(minwtime)
		wtime[index] = wtime[index] + M[index]
		toserve = toserve - 1
		if toserve == 0:
			# VERIFY
			served = 0
			ztime = wtime[index] - M[index]
			for i in range(B):
				if wtime[i] % M[i] != 0:
					print "fuck 1"
				served += wtime[i]/M[i]
				if i < index:
					if wtime[i] <= ztime:
						print "fuck 3"
					if wtime[i] > ztime + M[i]:
						print "fuck 4", wtime[i] - (ztime + M[i])
				elif i == index:
					if wtime[i] != ztime + M[i]:
						print "fuck 5"
				elif i > index:
					if wtime[i] < ztime:
						print "fuck 6"
					if wtime[i] >= ztime + M[i]:
						print "fuck 7", wtime[i] - (ztime + M[i])
				else:
					print "fuck what"
			if served != n:
				print "fuck 2"
			return index


if __name__ == "__main__":
	T = int(sys.stdin.readline())

	for t in range(T):
		B, n = map(int, sys.stdin.readline().split())
		M = map(int, sys.stdin.readline().split())
		print "Case #{}: {}".format(t+1, solve(B, n, M) + 1)