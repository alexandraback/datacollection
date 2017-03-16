#debug 
def pr(*a):
	#return
	for x in a: print x,
	print

def gongbei(M):
	bei = 1
	for x in M:
		g = gcd(bei, x)
		bei = bei * x /g
	mod = sum([bei/x for x in M])
	return bei, mod

def solve(B,N,M):
	bei, mod = gongbei(M)
	N %= mod
	
	if N == 0: N = mod
	if N <= B: return N
	pr("N,mod", N, mod)
	t = 0
	finish = B
	while 1:
		t += 1
		ava = []
		for i in range(B):
			if t%M[i] == 0:
				ava.append(i+1)
				finish += 1	
		#pr("t finish ava N",t,finish,len(ava), N)
		if N <= finish:
			f1 = finish - len(ava)
			ava.sort()
			pr("!!!", N-f1-1)
			return ava[N-f1-1]
			
		
	pr(gongbei(M), N)
	pass
	
import sys
from fractions import gcd
f = open(sys.argv[1])
out_fname = sys.argv[1][:-2] + "out"
out = open(out_fname,"w")
T = int(f.readline().strip())

for tc in range(1, T+1):
	B, N = f.readline().strip().split()
	B, N = int(B), int(N)
	M = [int(x) for x in f.readline().strip().split()]
	pr(B,N)
	pr(M)
	rt = solve(B,N,M)
	pr("Case #%d: %s"%(tc, str(rt)))
	pr("="*20)
	print >>out, "Case #%d: %s"%(tc, str(rt))

out.close()