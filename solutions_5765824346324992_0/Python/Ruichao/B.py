f = open("B.in","r")
g = open("Bout.txt","w")
t = int(f.readline())

def gcd(a,b):
	if a == 0:
		return b
	return gcd(b%a,a)

for i in xrange(1,t+1):
	st = f.readline().split()
	stc = f.readline().split()
	cur = int(stc[0])
	for j in xrange(1,len(stc)):
		cur = cur*int(stc[j])/gcd(cur,int(stc[j]))
	ttt = 0
	for j in xrange(len(stc)):
		ttt += cur / int(stc[j])
	tmp = int(st[1])%ttt
	d = [0 for j in xrange(len(stc))]
	mini = int(stc[0])
	mininum = 0
	for j in xrange(len(stc)):
		if int(stc[j]) <= mini:
			mini = int(stc[j])
			mininum = j
	for j in xrange(tmp):
		mini = d[0]
		mininum = 0
		for k in xrange(1,len(stc)):
			if d[k] < mini:
				mini = d[k]
				mininum = k
		d[mininum] += int(stc[mininum])
	g.write("Case #%d: %d\n" % (i,mininum+1))