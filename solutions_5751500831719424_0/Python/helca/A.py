import sys #from sys import * ???

def f(s1, s2):
	x = 0

	r1 = s1[0]
	r2 = s2[0]

	c1 = [1]
	c2 = [1]

	i1 = 0
	i2 = 0


	for k in range(1,len(s1)):
		if s1[k] == s1[k-1]:
			c1[i1] += 1
		else:
			r1 += s1[k]
			c1.append(1)
			i1 += 1

	for l in range(1,len(s2)):
		if s2[l] == s2[l-1]:
			c2[i2] += 1
		else:
			r2 += s2[l]
			c2.append(1)
			i2 += 1

	if r1 != r2:
		return 'Fegla Won'

	else:
		d = 0
		for i in range(len(c1)):
			d += abs(c1[i] - c2[i])
		return d

T = int(sys.stdin.readline())

for tc in range(T):
	N = int(sys.stdin.readline())
	s1 = sys.stdin.readline()
	s2 = sys.stdin.readline()
	output = f(s1, s2)
	print "Case #" + str(tc + 1) + ": " + str(output)