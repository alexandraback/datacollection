#!/usr/bin/env python3

def doprob():
	B, N = map(int, input().split())
	barbs = list(map(int, input().split()))

	def served(time):
		return sum(time//b if time%b==0 else time//b+1 for b in barbs)

	lo = 0
	hi = 1000000000000000000000
	while hi - lo > 1:
		mid = (hi + lo) // 2
		if served(mid) < N:
			lo = mid+1
		else:
			hi = mid
	
	#print(N, lo, served(lo), lo+1, served(lo+1))

	while served(lo) == served(lo+1):
		lo -= 1
	while served(lo) >= N:
		lo -= 1
	pos = N - served(lo)
	for i, b in enumerate(barbs):
		if lo % b == 0:
			if pos == 1:
				return i+1
			pos -= 1
	print(lo, served(lo), lo+1, served(lo+1))

ncases = int(input())
for caseno in range(1, ncases+1):
    print("Case #%d: %d" % (caseno, doprob()))
