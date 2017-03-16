#debug 
def pr(*a):
	return
	for x in a: print x,
	print

def product(a, b, c):
	return (b[0]-a[0])*(c[1]-a[1]) - (c[0]-a[0])*(b[1]-a[1])

def find(xy, i):
	if len(xy) <= 3: return 0
	a = xy[i]
	mcut = 1000000
	for b in xy:
		if a==b: continue
		neg = 0
		pos = 0
		for c in xy:
			if c==a or c==b: continue
			p = product(a,b,c)
			if p > 0: pos += 1
			if p < 0: neg += 1
		mcut = min(mcut, neg, pos)
	return mcut

def solve(xy, N):
	mm = []
	for i in range(N):
		mm.append(find(xy, i))
	pr(mm)
	return mm
	
	
import sys
f = open(sys.argv[1])
out_fname = sys.argv[1][:-2] + "out"
out = open(out_fname,"w")
T = int(f.readline().strip())

for tc in range(1, T+1):
	N = int(f.readline().strip())
	pr(N)
	xy = []
	for i in range(N):
		x, y = f.readline().strip().split()
		xy.append((int(x), int(y)))
	pr(xy)
	rt = solve(xy, N)
	pr("Case #%d: %s"%(tc, str(rt)))
	pr("="*20)
	print >>out, "Case #%d:"%(tc)
	for x in rt:
		print >>out, x

out.close()