with open("A-small-attempt0.in") as fi:
	with open("A-small-attempt0.out", "w") as fo:
		n = int(fi.readline())
		for i in range(n):
			
			cards = [[None] * 4] * 2
			row = [None] * 2
			choice = [None] * 2
			
			for j in range(2):
				choice[j] = int(fi.readline()) - 1
				for k in range(4):
					cards[j][k] = (int(n) for n in fi.readline().split())
				row[j] = set(cards[j][choice[j]])
				
			card = row[0].intersection(row[1])
			output = "Case #{0}: ".format(i+1)
			if len(card) < 1:
				output = output + "Volunteer cheated!"
			elif len(card) > 1:
				output = output + "Bad magician!"
			else:
				output = output + str(card.pop())
			print(output, file=fo)
