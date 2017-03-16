inp=open('in.in','r')
f=open('out.out', 'w')
t=int(inp.readline().strip('\n'))
# t=input()
for tc in range(1,t+1):
	n=int(inp.readline().strip('\n'))
	p=map(int, inp.readline().strip('\n').split())
	# n=input()
	# p=map(int, raw_input().split())
	ans1,ans2=0,0
	a=[0]

	for i in range(len(p)-1):
		if p[i]>p[i+1]: a.append(p[i]-p[i+1])
	rpts=max(a)

	for i in range(len(p)-2):
		if p[i] > p[i+1]: ans1+=(p[i]-p[i+1])
		ans2+=min(rpts, p[i])

	if p[-2] > p[-1]: ans1+=(p[-2]-p[-1])
	ans2+=min(rpts,p[-2])
	f.write("Case #"+str(tc)+": "+str(ans1)+" "+str(ans2)+"\n")
	print "Case #%i: %s %s" % (tc, ans1, ans2)
# inp.close()
# f.close()