cases = int(raw_input())
for case in range(1, cases + 1):
	answer = int(raw_input())
	for i in range(1, 5):
		line = raw_input()
		if i == answer:
			valid = set(map(int, line.split()))
	answer = int(raw_input())
	for i in range(1, 5):
                line = raw_input()
                if i == answer:
                        valid = valid & set(map(int, line.split()))
	if len(valid) == 0:
		print "Case #%d: Volunteer cheated!" % case
	elif len(valid) > 1:
		print "Case #%d: Bad magician!" % case
	else:
		print "Case #%d: %d" % (case, list(valid)[0])
   
		
