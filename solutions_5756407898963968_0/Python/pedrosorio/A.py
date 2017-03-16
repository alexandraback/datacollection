def get_possible():
	row = int(raw_input()) - 1
	res = []
	for i in xrange(4):
		cards = map(int, raw_input().split())
		if i == row:
			res = cards
	return res

def get_common(cards1, cards2):
	common = []
	for card in cards1:
		if card in cards2:
			common.append(card)
	return common

T = int(raw_input())
for case in xrange(1,T+1):
	pos1 = get_possible()
	pos2 = get_possible()
	common = get_common(pos1, pos2)
	if not common:
		answer = "Volunteer cheated!"
	elif len(common) == 1:
		answer = str(common[0])
	else:
		answer = "Bad magician!"
	print 'Case #' + str(case) + ': ' + answer