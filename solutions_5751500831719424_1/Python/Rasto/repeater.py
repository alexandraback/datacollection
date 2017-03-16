import fileinput
from collections import Counter

def solve(n, a):
	b = []
	p = False
	for s in a:
		y, x = [], []
		pc = '?'
		i = 0
		for c in s:
			if c != pc:
				x.append(c)
				if i: y.append(i)
				i = 0
				pc = c
			i += 1
		y.append(i)
		if not p: p = x
		if p != x: return "Fegla Won"
		b.append(y)

	l = [[] for c in p]
	for i in range(len(p)):
		for y in b: l[i].append(y[i])

	z = 0
	for i, v in enumerate(l):
		m = float("inf")
		for x in range(min(v), max(v)+1):
			m = min(m, sum(abs(x-y[i]) for y in b))
		z += m
	return z

f = fileinput.input()
tt = int(f.readline())
for t in range(tt):
	n = int(f.readline())
	a = [list(f.readline().rstrip()) for _ in range(n)]
	print("Case #%d:" % (t+1), solve(n, a))