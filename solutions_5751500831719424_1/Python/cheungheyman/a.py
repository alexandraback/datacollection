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
	target_str = charss[0]
	is_valid = True
	for str in charss:
		if target_str != str:
			is_valid = False
			break 
	if not is_valid: 
		print "Case #%d: %s" % (case, "Fegla Won")
		continue
	for j in range(len(cntss[0])):
		min_answer = 9999999
		for k in range(101):
			tmp_ans = 0
			for i in range(len(cntss)):
				cnt_a = cntss[i][j]
				tmp_ans += abs(cnt_a - k)
		#		print "tmp", i, k, cnt_a, tmp_ans
			if min_answer > tmp_ans:
				min_answer = tmp_ans
		answer += min_answer
	print "Case #%d: %d" % (case, answer)
