__author__ = 'leha'

from time import time
from math import pi

def nextCase():
    fileName = "A.in"
    fileName = "A-small-attempt2.in"
#    fileName = "A-small-practice.in"
#    fileName = "A-large-practice.in"
    input = open(fileName, 'r')
    T = int(input.readline())
    for i in range(T):
        N = int(input.readline())
        S = []
        for j in range(N):
            S += [input.readline().rstrip()]
        yield S

def solve(T):
	def remove(s):
		r = ""
		prev = None
		for c in s:
			if "" == r: r += c
			elif prev != c: r += c
			prev = c

		return r

	def distance(l, r):
		O = remove(l)

		d, lCurr, rCurr = 0, 0, 0

		for c in O:
			while lCurr < len(l) and rCurr < len(r) and l[lCurr] == c and r[rCurr] == c:
				lCurr += 1
				rCurr += 1

			while lCurr < len(l) and l[lCurr] == c:
				lCurr += 1
				d += 1

			while rCurr < len(r) and r[rCurr] == c:
				rCurr += 1
				d += 1

		return d

	if 1 != len(set([remove(s) for s in T])):
		return "Fegla Won"

	R = [sum([distance(root, s) for s in T]) for root in T]

	return min(R)


start = time()

i = 1
for T in nextCase():
    print("Case #%d: %s" % (i, solve(T)))
    i += 1

#print(time() - start)
__author__ = 'leha'
