f = open("A.in","r")
g = open("Aout.txt","w")
t = int(f.readline())
for i in xrange(1,t+1):
	st = f.readline().split()
	stc = f.readline().split()
	maxi = 0
	ans = 0
	res = 0
	for j in xrange(1,len(stc)):
		if int(stc[j-1])-int(stc[j]) > 0:
			ans += int(stc[j-1])-int(stc[j])
			maxi = max(maxi,int(stc[j-1])-int(stc[j]))
	for j in xrange(len(stc)-1):
		res += min(int(stc[j]),maxi)

	g.write("Case #%d: %d %d\n" % (i,ans,res))