T = input()

for t in range(1, T + 1):
	N = input()
	nums = map(int, raw_input().split())
	s = sum(nums)
	for i in range(len(nums)):
		nums[i] = [nums[i], i]
	print ('Case #%d:' % t),
	ans = []
	while s > 2:
		nums.sort()
		if nums[-1][0] != nums[-2][0] or nums[-1][0] == 1:
			if nums[-1][0] > nums[-2][0] + 1:
				ans.append(chr(ord('A') + nums[-1][1]) * 2)
				nums[-1][0] -= 2
				s -= 2
			else:
				ans.append(chr(ord('A') + nums[-1][1]))
				nums[-1][0] -= 1
				s -= 1
		else:
			ans.append(chr(ord('A') + nums[-1][1]) + chr(ord('A') + nums[-2][1]))
			nums[-1][0] -= 1
			nums[-2][0] -= 1
			s -= 2
	nums.sort()
	ans.append(chr(ord('A') + nums[-1][1]) + chr(ord('A') + nums[-2][1]))
	print ' '.join(ans)

