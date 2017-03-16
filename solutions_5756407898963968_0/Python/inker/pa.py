

t = int(raw_input());


for cases in range(1, t+1):
	n = int(raw_input());
	arr1 = []
	for x in range(0, 4):
		arr1.append(map(int, raw_input().split(' ')))

	n2 = int(raw_input());
	arr2 = []
	for x in range(0, 4):
		arr2.append(map(int, raw_input().split(' ')))
	
	cnt = 0
	for tar in arr1[n-1]:
		if tar in arr2[n2-1]:
			cnt = cnt + 1
			ans = tar
	
	print "Case #{0}: {1}".format(cases, ans if cnt == 1 else ("Bad magician!" if cnt > 1 else "Volunteer cheated!"))


