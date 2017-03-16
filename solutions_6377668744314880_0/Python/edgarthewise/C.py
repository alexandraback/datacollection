from sys import stdin
def getWords():
    return stdin.readline().strip().split()

def getInts():
    return [int(i) for i in getWords()]

def getInt():
	i = getInts()
	assert len(i)==1
	return i[0]

def orientation(a, b, c):
	return cmp(a[0]*b[1] + b[0]*c[1] + c[0]*a[1],
			   a[1]*b[0] + b[1]*c[0] + c[1]*a[0])

from collections import Counter

def getCutNumbers(X):
	N=len(X)

	if N == 0:
		return []

	if sorted(X)[0] == sorted(X)[-1]:
		return [0]*N

	minCut = [N+1] * N

	for i in xrange(N):
		for j in xrange(N):
			if X[i] != X[j]:
				sideOfK = Counter(
					[orientation(X[i],X[j],X[k]) for k in xrange(N)])
				minCut[i] = min(minCut[i], sideOfK[-1], sideOfK[1])

	return minCut

def main():

	T = getInt()

	for caseNo in xrange(1,T+1):

		N = getInt()
		X = []
		for i in xrange(N):
			X.append(tuple(getInts()))
		
		print "Case #%d:"%caseNo
		for numCut in getCutNumbers(X):
			print numCut

main()
