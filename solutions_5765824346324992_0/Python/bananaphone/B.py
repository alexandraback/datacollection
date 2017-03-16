import Queue

T = int(raw_input())

def gcd(a,b):
	if b == 0:
		return a
	return gcd(b, a%b)

def lcm(a,b):
	return (a*b)/gcd(a,b)

def mylcm(L):
	start = L[0]
	for i in xrange(1, len(L)):
		start = lcm(start, L[i])
	return start

def resolve(L):
	r = mylcm(L)
	return sum([r/i for i in L])

def doprob():
	BN = raw_input()
	B, N = tuple([int(K) for K in BN.split()])
	read = raw_input()
	read = [int(k) for k in read.split()]
	Q = Queue.PriorityQueue()
	for i in xrange(len(read)):
		Q.put((0,i))
#	print N, read, resolve(read)
	N = N%resolve(read)
	if N == 0:
		read.reverse()
		return len(read) - read.index(min(read))
#	print N
	for i in xrange(N-1):
		T = Q.get()
		Q.put((T[0]+read[T[1]], T[1]))
	T = Q.get()
	return T[1]+1

for qq in xrange(T):
	print "Case #" + str(qq+1) + ": " + str(doprob())