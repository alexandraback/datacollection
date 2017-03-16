T = int(raw_input())
for set in range(T):
	ans = int(raw_input())
	for i in range(4):
		if i == ans-1:
			first_set = map(int, raw_input().split())
		else:
			raw_input()
	ans = int(raw_input())
	for i in range(4):
		if i == ans-1:
			second_set = map(int, raw_input().split())
		else:
			raw_input()
	check = 0
	for card in first_set:
		if card in second_set:
			correct = card
			check += 1
	print "Case #" + str(set+1) + ":",
	if check == 1:
		print correct 
	elif check > 1:
		print "Bad magician!"
	elif check == 0:
		print "Volunteer cheated!"