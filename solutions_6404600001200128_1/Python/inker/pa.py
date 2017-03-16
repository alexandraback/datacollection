for case_no in range(int(raw_input())):
	n = int(raw_input())
	s = map(int, raw_input().split())
	ans = 0
	pre = -1
	for i in s:
		# Case 1
		if pre == -1:
			pre = i
		elif i > pre:
			pre = i
		else:
			ans += pre - i
			pre = i
	
	ans2 = 0
	rate = max(max(s[i] - s[i+1], 0) for i in range(len(s)-1))
	#print rate
	#rate = rate/10 + (rate%10 != 0)
	rate = float(rate)/10
	#print rate
	pre = -1
	for i in s:
		if pre == -1:
			pre = i
		else:
			pre -= rate*10
			ans2 += rate*10
			assert pre <= i
			if pre < 0:
				ans2 += pre
			pre = i

	print "Case #%d: %d %d" % (case_no+1, ans, ans2)
