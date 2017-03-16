import math
import re

e = 10**-15

def angle((x0,y0),(x,y)):
	return math.atan2(y-y0,x-x0)

def solve(l):
	ans = ""
	for i in l:
		angs = [angle(i,j) for j in l if j!=i]
		m = len(angs)
		angs.sort()
		p = 0
		q = 0
		while p<len(angs):
			ang0 = angs[p]
			ang1 = angs[p] + math.pi
			pnext = p
			while pnext<len(angs) and abs(angs[pnext] - ang0)<e:
				pnext += 1
			if ang1 > math.pi:
				q = 0
				ang1 -= 2 * math.pi
			while q<len(angs) and angs[q] < ang1 - e:
				q += 1
			if pnext<=q:
				mnew = q-pnext
			else:
				mnew = len(angs)-pnext+q
			m = min(m,mnew)
			p = pnext
		ans+=str(m)+"\n"
	return ans

inp = open("C-small-attempt2.in","r")
out = open("C-small","w")
lines = inp.readlines()
n = 0
for i in range(int(lines[n][:-1])):
	n += 1
	l = []
	for j in range(int(lines[n][:-1])):
		n += 1
		l.append([int(x) for x in re.split(" ",lines[n])])
	out.write("Case #"+str(i+1)+":\n"+solve(l))
out.close()
inp.close()