tn = input()
pn = 0
while tn:
	pn += 1
	tn -= 1
	print 'Case #%d:'%pn,
	bs="Bad magician!"
	vc = "Volunteer cheated!"
	r1 = input()
	rows1 = [raw_input().split() for i in xrange(4)][r1-1]
	r2 = input()
	rows2 = [raw_input().split() for i in xrange(4)][r2-1]
	s = set(rows1)&set(rows2)
	if len(s) == 1:
		print s.pop()
	elif len(s) == 0:
		print vc
	else:
		print bs
