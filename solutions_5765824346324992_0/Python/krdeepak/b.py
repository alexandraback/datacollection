import sys
import os
import heapq

def gcd(*numbers):
    """Return the greatest common divisor of the given integers"""
    from fractions import gcd
    return reduce(gcd, numbers)
 
# Least common multiple is not in standard libraries? It's in gmpy, but this is simple enough:
 
def lcm(*numbers):
    """Return lowest common multiple."""    
    def lcm(a, b):
        return (a * b) // gcd(a, b)
    return reduce(lcm, numbers, 1)

T = int(sys.stdin.readline())

for t in xrange(T):
	B, N = map(int, sys.stdin.readline().strip().split())
	M = map(int, sys.stdin.readline().strip().split())

	lcmval = lcm(*M)
	#print lcmval

	discard = 0
	for m in M:
		discard += lcmval/m

	#print discard
	N = N%discard
	if N == 0:
		N = discard

	h = []
	for i in xrange(B):
		heapq.heappush(h, (0, i))

	for i in xrange(N-1):
		btime, bid = heapq.heappop(h)
		heapq.heappush(h, (btime+M[bid], bid))
		#print h

	ftime, fid = heapq.heappop(h)

	sys.stdout.write('Case #{0}: {1}\n'.format(t+1, fid+1))		

