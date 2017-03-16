n = int(raw_input())
for case in range(1, n + 1):
	answer = 0
	strs = []
	m = int(raw_input())
	for i in range(m):
		strs.append(raw_input().strip())
	charss = []
	cntss = []
	for line in strs:
		prev = '@'
		cnt = 0
		chars = ''
		cnts = []
		for x in line:
			if x != prev:
				chars += prev
				cnts.append(cnt)
				prev = x
				cnt = 1
			else:
				cnt += 1
		chars += prev
		cnts.append(cnt)
		charss.append(chars)
		cntss.append(cnts)
	if charss[0] != charss[1]:
		print "Case #%d: %s" % (case, "Fegla Won")
		continue
	for i in range(len(cntss[0])):
		cnt_a = cntss[0][i]
		cnt_b = cntss[1][i]
		answer += abs(cnt_a - cnt_b) 
	print "Case #%d: %d" % (case, answer)
