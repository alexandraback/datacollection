T = int(raw_input())
for i in range(T):
	cardsUsed = []
	for j in range(17):
		cardsUsed.append(0)
	for k in range(2):
		whichRow = int(raw_input())
		for j in range(4):
			thisLine = raw_input().split()
			if j==whichRow-1:
				#print(thisLine)
				for num in thisLine:
					cardsUsed[int(num)] += 1
	numberOfResults = 0
	bestResult = -1
	#print(cardsUsed)
	for j in range(17):
		if cardsUsed[j] == 2:
			numberOfResults += 1
			bestResult = j

	if numberOfResults==0:
		print("Case #"+`i+1`+": Volunteer cheated!")
	if numberOfResults>=2:
		print("Case #"+`i+1`+": Bad magician!")
	if numberOfResults==1:
		print("Case #"+`i+1`+": "+`bestResult`)
