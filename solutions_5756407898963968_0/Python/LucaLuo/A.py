import math

def magician(row1, cards1, row2, cards2):
	card = None
	for card1 in cards1[row1 - 1]:
		for card2 in cards2[row2 - 1]:
			if not card and int(card1) == int(card2):
				card = card1
			elif card and int(card1) == int(card2):
				return "Bad magician!"
	if card:
		return card
	else:
		return "Volunteer cheated!"

File = open("A-small-attempt0.in", "r")
T = int(File.readline())

for i in range(T):
	row1 = int(File.readline())
	cards1 = []
	for j in range(4):
		cards1.append(File.readline().split())
	row2 = int(File.readline())
	cards2 = []
	for j in range(4):
		cards2.append(File.readline().split())
	print ("Case #%d: " % (i + 1))+ magician(row1, cards1, row2, cards2)
	





# for line in File:
# 	f.append(line.split())
# for i in range(int(f[0][0])):
# 	name = f[i+1][0]
# 	n = int(f[i+1][1])
# 	print "Case #%d:" %(i+1), solve(name, n)