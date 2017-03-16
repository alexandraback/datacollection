import sys

file="A"
file = sys.argv[1]

lines = open(file).readlines()
N = int(lines[0])

currentLine = 1

for case in range(N):
	row1 = int(lines[currentLine]) - 1
	currentLine += 1
	cards1 = []
	for i in range(4):
		cards1.append(map(int, lines[currentLine].split()))
		currentLine += 1		
	row2 = int(lines[currentLine]) - 1
	currentLine += 1
	cards2 = []
	for i in range(4):
		cards2.append(map(int, lines[currentLine].split()))
		currentLine += 1
	validcards = []
	for card in cards1[row1]:
		if card in cards2[row2]:
			validcards.append(card)
	if len(validcards)  == 0:
		print "Case #{}: Volunteer cheated!".format(case + 1)
	elif len(validcards) == 1:
			print "Case #{}: {}".format(case + 1, validcards[0])
	elif len(validcards)  > 1:
		print "Case #{}: Bad magician!".format(case + 1)
