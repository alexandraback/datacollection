t = input()
for tt in xrange(t):
	z1 = input() - 1
	a1 = [map(int, raw_input().split()) for i in range(4)]
	z2 = input() - 1
	a2 = [map(int, raw_input().split()) for i in range(4)]
	z = set(a1[z1]) & set(a2[z2])
	print "Case #%d:"%(tt + 1),
	if len(z) == 0:
		print "Volunteer cheated!"
	elif len(z) == 1:
		print list(z)[0]
	else:
		print "Bad magician!"
