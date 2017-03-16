T = int(raw_input())

def xprod(a,b):
	return a[0]*b[1] - a[1]*b[0]

def diff(a,b):
	return (a[0]-b[0], a[1]-b[1])

def upper_hull(L):
	sofar = []
	sofar.append(L[0])
	sofar.append(L[1])
	for i in xrange(2, len(L)):
		if len(sofar) < 2:
			sofar.append(L[i])
			continue
		m = len(sofar)-1
		while xprod(diff(L[i], sofar[m]), diff(sofar[m], sofar[m-1])) < 0:
			sofar.pop()
			m -= 1
			if m < 2:
				break
		sofar.append(L[i])
	return sofar

def lower_hull(L):
	sofar = []
	sofar.append(L[0])
	sofar.append(L[1])
	for i in xrange(2, len(L)):
		if len(sofar) < 2:
			sofar.append(L[i])
			continue
		m = len(sofar)-1
		while xprod(diff(L[i], sofar[m]), diff(sofar[m], sofar[m-1])) > 0:
			sofar.pop()
			m -= 1
			if m < 1:
				break
		sofar.append(L[i])
	return sofar

def convex_hull(L):
	L.sort()
	A = upper_hull(L)
	B = lower_hull(L)
	if tuple(A) == tuple(B):
		return A
	B.reverse()
	return A + B[1:-1]

from itertools import combinations

def doprob():
	N = int(raw_input())
	pts = []
	mydict = {}
	for i in xrange(N):
		read = raw_input()
		pts.append(tuple([int(K) for K in read.split()]))
		mydict[pts[-1]] = i
	log = [-1]*N
	if N <= 3:
		return ("\n" + str(0))*N
	count = 0
	for i in xrange(N):
		for X in combinations(pts, N-i):
			for pt in convex_hull(list(X)):
				tt = mydict[pt]
				if log[tt] == -1:
#					print pt
#					print X
#					print upper_hull(list(sorted(list(X)))) 
#					print lower_hull(list(sorted(list(X))))
#					print convex_hull(list(X))
#					print
					log[tt] = i
					count += 1
					if count == N:
						## RETURN ##
						return "".join(["\n" + str(log[j]) for j in xrange(N)])








for qq in xrange(T):
	print "Case #" + str(qq+1) + ":" + str(doprob())