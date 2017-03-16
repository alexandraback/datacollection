
def isgood(a):
	return max(a)*2 <= sum(a)

data = open("A-small.in").readlines()
n = int(data[0])
answ = []
par = [chr(ord('A') + i) for i in xrange(26)]

j = 1
for i in xrange(n):
	m = int(data[j])
	a = map(int, data[j+1].split(' '))
	j += 2
	plan = []
	#print a
	while True:
		if a[0] >= a[1]:
			mx1, mx2 = 0, 1
		else:
			mx1, mx2 = 1, 0
		for p in xrange(2, len(a)):
			if a[p] > a[mx1]:
				mx1, mx2 = p, mx1
			elif a[p] > a[mx2]:
				mx2 = p
		#print mx1, mx2, 
		if a[mx1] == a[mx2]:
			b = a[:]
			b[mx1] -= 1
			b[mx2] -= 1
			if isgood(b):
				plan.append(par[mx1] + par[mx2])
				a[mx1] -= 1
				a[mx2] -= 1
			else:
				plan.append(par[mx1])
				a[mx1] -= 1
		else:
			plan.append(par[mx1] * 2)
			a[mx1] -= 2
		brk = True
		for p in a:
			if p > 0:
				brk = False
		if brk:
			break
	answ.append(" ".join(plan))
	#print " ".join(plan)

with open("A-small.out", 'w') as f:
	for i, v in enumerate(answ):
		f.write("Case #{}: {}\n".format(i+1, v))
