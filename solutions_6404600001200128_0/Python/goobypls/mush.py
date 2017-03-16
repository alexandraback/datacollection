#!/usr/bin/env python3

def doprob():
	input()
	shrooms = list(map(int, input().split()))
	posdeltas = [x-y for x, y in zip(shrooms, shrooms[1:]) if x > y]
	anytime = sum(posdeltas)
	if not posdeltas:
		return anytime, 0
	
	eat = 0
	rate = max(posdeltas)
	plate = shrooms[0]
	for s in shrooms[1:]:
		eating = rate if plate >= rate else plate;
		eat += eating
		plate = s
		
	return anytime, eat
		

ncases = int(input())
for caseno in range(1, ncases+1):
	a, b = doprob()
	print("Case #%d: %d %d" % (caseno, a, b))
