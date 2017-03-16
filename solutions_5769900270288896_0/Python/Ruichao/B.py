



fa = open("B.in","r")
g = open("Bout.txt","w")
t = int(fa.readline())
f = [0 for j in xrange(20)]
loc = [0 for j in xrange(20)]
tmp = 1
for j in xrange(20):
	f[j] = tmp
	tmp *= 2
ans = 1000000
m = []
def dfs(cur,start,tot,ended,val,rr,cc):
	global f
	global ans
	global loc
	global m
	if cur > tot:
		for sj in xrange(20):
			if (val & f[sj]) != 0:
				m[loc[sj][0]][loc[sj][1]] = True
		tmp = 0
		for sj in xrange(rr):
			for sk in xrange(cc):
				if m[sj][sk]:
					if sj != 0 and m[sj-1][sk]:
						tmp += 1
					if sk != 0 and m[sj][sk-1]:
						tmp += 1
		ans = min(tmp,ans)
		m = [[False for u in xrange(cc)] for v in xrange(rr)]
		return

	for si in xrange(start,ended):
		dfs(cur+1,si+1,tot,ended,val+f[si],rr,cc)


for i in xrange(1,t+1):
	ans = 1000000
	st = fa.readline().split()
	r = int(st[0])
	c = int(st[1])
	n = int(st[2])
	if r > c:
		r,c = c,r
	x = (c+1)/2
	y = c/2

	leastlimit = 0
	for j in xrange(r*c):
		loc[j] = [j/c,j%c]
	m = [[False for u in xrange(c)] for v in xrange(r)]
	for j in xrange(r):
		if j % 2 == 0:
			leastlimit += x
		else:
			leastlimit += y
	if n <= leastlimit:
		ans = 0
	else:
		dfs(1,0,n,r*c,0,r,c)
		
	g.write("Case #%d: %d\n" % (i,ans))