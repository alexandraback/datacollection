filename = 'A-small-attempt1.in'
f = open(filename,'r')
T = int(f.readline())
for i in range(1,T+1):
	print "Case #%d:" % i,
	N = int(f.readline())
	p = map(int,f.readline().rstrip().split())
	ans = list()
	while sum(p):
		i = p.index(max(p))
		p[i] -= 1
		if sum(p)==0 or sum(p) == 2:
			ans.append(chr(i+ord('A')))
			continue
		j = p.index(max(p))
		p[j] -= 1
		ans.append(chr(i+ord('A'))+chr(j+ord('A')))
	for i in ans:
		print i,
	print
