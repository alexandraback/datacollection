import math
import re

def solve(l):
	s = 0
	m = 0
	for i in range(len(l)-1):
		a = max(l[i]-l[i+1],0)
		m = max(m, a)
		s += a
	t = 0
	for i in range(len(l)-1):
		t += min(l[i],m)
	return str(s)+" "+str(t)

inp = open("A-large.in","r")
out = open("A-large","w")
lines = inp.readlines()
for i in range(1,len(lines)/2+1):
	l = [int(x) for x in re.split(" ",lines[2*i])]
	out.write("Case #"+str(i)+": "+solve(l)+"\n")
out.close()
inp.close()

