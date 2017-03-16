import math
import re

def solve(n,b):
	h = sum(map(lambda x:1.0/x,b))
	t = math.floor((n-1)/h)-max(b)
	c = int(sum(map(lambda x:math.ceil(t*1.0/x),b)))
	while c<n:
		r = map(lambda x: (-int(t))%x,b)
		m = 100000
		l = []
		for i in range(len(b)):
			if r[i]==m:
				l.append(i)
			elif r[i]<m:
				m = r[i]
				l = [i]
		t += m+1
		cold = c
		c  += len(l)
	return l[n-cold-1]+1

inp = open("B-small-attempt1.in","r")
out = open("B-small","w")
lines = inp.readlines()
for i in range(len(lines)/2):
	n = int(re.split(" ",lines[2*i+1])[1])
	b = [int(x) for x in re.split(" ",lines[2*i+2])]
	out.write("Case #"+str(i+1)+": "+str(solve(n,b))+"\n")
out.close()
inp.close()

