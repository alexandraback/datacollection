import math

fin = open('A-small-attempt0.in', 'r')
fout = open('out.txt', 'w')

T = int(fin.readline())

for t in xrange(T):
	N = int(fin.readline())
	m = fin.readline().split()
	res1 = 0
	res2 = 0
	curr = m[0]
	maximo = 0
	
	for i in xrange(N-1):
		dif = int(m[i])-int(m[i+1])
		if dif>0:
			maximo = max(maximo, dif)
			res1 += dif
	
	for i in xrange(N-1):
		res2 += min(int(m[i]),maximo)
	
	fout.write("Case #%d: %s %s\n" %(t+1, res1, res2))

fin.close()
fout.close()