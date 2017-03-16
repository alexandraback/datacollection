import sys

input = open(sys.argv[1], 'r')
t = int(input.readline()[:-1])
for x in range(1, t+1):
	row1 = int(input.readline()[:-1])
	firstRow = []
	for y in range(0, 4):
		line = input.readline()[:-1]
		if (y+1==row1):
			firstRow = line.split()
	row2 = int(input.readline()[:-1])
	secondRow = []
	for y in range(0, 4):
		line = input.readline()[:-1]
		if (y+1==row2):
			secondRow = line.split()
	count = 0
	card = ""
	for y in range(0, 4):
		for z in range(0, 4):
			if (firstRow[y]==secondRow[z]):
				count += 1
				card = firstRow[y]
	if count == 0:
		print "Case #" + str(x) + ": Volunteer cheated!" 
	elif count == 1:
		print "Case #" + str(x) + ": " + card
	else:
		print "Case #" + str(x)  + ": Bad magician!"