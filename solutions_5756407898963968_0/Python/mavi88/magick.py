T = int(raw_input())

for t in range(T):
	ans1 = int(raw_input())
	col1 = list()
	for l in range(4):
		line = map(int, raw_input().strip().split())
		if l == ans1-1:
			col1 = line
	ans2 = int(raw_input())
	col2 = list()
	for l in range(4):
		line = map(int, raw_input().strip().split())
		if l == ans2-1:
			col2 = line
	
	card = -1
	count = 0
	for c in col1:
		if c in col2:
			card = c
			count+=1
	res = ""
	if count == 0:
		res = "Volunteer cheated!"
	elif count == 1:
		res = str(card)
	else:
		res = "Bad magician!"
	print "Case #" + str(t+1) + ": " + res