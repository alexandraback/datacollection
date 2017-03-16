def solve():
	a = int(raw_input())
	for i in xrange(4):
		x = map(int, raw_input().split())
		if i+1 == a:
			d1 = set(x)
	a = int(raw_input())
	for i in xrange(4):
		x = map(int, raw_input().split())
		if i+1 == a:
			d2 = set(x)

	d3 = d1 & d2
	if len(d3) == 1:
		return str(d3.pop())
	elif len(d3) == 0:
		return 'Volunteer cheated!'
	else:
		return 'Bad magician!'

tc = int(raw_input())
for ti in xrange(tc):
	s = {}
	print "Case #%d: %s" % (ti+1,solve())