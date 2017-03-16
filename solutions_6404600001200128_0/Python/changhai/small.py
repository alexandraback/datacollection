#debug 
def pr(*a):
	return
	for x in a: print x,
	print

def method1(m):
	rt = 0
	for i in range(1, len(m)):
		if m[i] < m[i-1]:
			rt += m[i-1] - m[i]
	return rt

def method2(m):
	rate = 0
	for i in range(1, len(m)):
		if m[i] < m[i-1]:
			d = m[i-1] - m[i]
			r = d/10.0
			rate = max(rate, r)
	pr("rate", rate)
	rt = 0
	for i in range(len(m)-1):
		if m[i] > rate*10:
			rt += rate*10
		else:
			rt += m[i]
	return round(rt)

def solve(m):
	rt1 = method1(m)
	rt2 = method2(m)
	return (rt1, rt2)
	
import sys
f = open(sys.argv[1])
out_fname = sys.argv[1][:-2] + "out"
out = open(out_fname,"w")
T = int(f.readline().strip())

for tc in range(1, T+1):
	N = int(f.readline().strip())
	pr(N)
	m = [int(x) for x in f.readline().strip().split()]
	pr(m)
	rt = solve(m)
	pr("Case #%d: %d %d"%(tc, rt[0], rt[1]))
	pr("="*20)
	print >>out, "Case #%d: %d %d"%(tc, rt[0], rt[1])

out.close()