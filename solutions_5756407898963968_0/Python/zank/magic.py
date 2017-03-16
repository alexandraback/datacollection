def read_grid():
	grid = {}
	for j in range(4):
		if j not in grid: grid[j] = {}
		numbers = [int(x) for x in input().split(' ')]
		for k in range(4):
			grid[j][k] = numbers[k]
	return grid

n = int(input())
for i in range(n):
	row_a = int(input())
	grid_a = read_grid()
	row_b = int(input())
	grid_b = read_grid()

	cards_a = grid_a[row_a - 1]
	cards_b = grid_b[row_b - 1]

	cards = []

	for card_ai in cards_a:
		card_a = cards_a[card_ai]
		is_in = False
		for card_bi in cards_b:
			card_b = cards_b[card_bi]
			if card_a == card_b:
				is_in = True
				break
		if is_in:
			cards.append(card_a)

	if len(cards) == 1:
		result = str(cards[0])
	elif len(cards) > 1:
		result = 'Bad magician!'
	else:
		result = 'Volunteer cheated!'

	print('Case #' + str(i + 1) + ': ' + result)