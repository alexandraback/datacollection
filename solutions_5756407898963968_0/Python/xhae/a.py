T = int(raw_input())
for case in range(1, T + 1):
	first = int(raw_input())
	firstMat = [0] * 4
	for i in range(0, 4):
		firstMat[i] = map(int, raw_input().split())
	
	second = int(raw_input())
	secondMat = [0] * 4
	for i in range(0, 4):
		secondMat[i] = set(map(int, raw_input().split()))
	
	cnt = 0
	ans = 0

	for i in range(0, 4):
		if firstMat[first - 1][i] in secondMat[second - 1]:
			cnt += 1
			ans = firstMat[first - 1][i]
	

	print "Case #" + str(case) + ":",
	if cnt == 0:
		print "Volunteer cheated!"
	elif cnt == 1:
		print ans
	else:
		print "Bad magician!"
