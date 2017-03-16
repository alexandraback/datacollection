T = int(raw_input())
for t in range(T):
	N = int(raw_input())
	nums = [int(i) for i in raw_input().split()]
	ans1 = 0
	for i in range(1, N):
		if nums[i] < nums[i-1]:
			ans1 += nums[i-1]-nums[i]
	max_ = 0
	for i in range(1, N):
		if nums[i] < nums[i-1]:
			if nums[i-1] - nums[i] > max_:
				max_ = nums[i-1] - nums[i]
	ans2 = 0
	#print max_	
	for i in range(N-1):
		if nums[i] >= max_:
			ans2+= max_
		else:
			ans2+= nums[i]
	print "Case #"+str(t+1)+":", ans1, ans2
