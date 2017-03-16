def res(row1, row2, arena1, arena2):
	result = 0
	for i in arena1[row1]:
		if i in arena2[row2]:
			if result == 0:
				result = i
			else:
				return "Bad magician!"
	if result == 0:
		return "Volunteer cheated!"
	return str(result)

if __name__ == "__main__":
	T = int(raw_input())
	for t in xrange(T):
		row1 = int(raw_input()) - 1
		arena1 = [raw_input().split() for row in range(4)]
		row2 = int(raw_input()) - 1
		arena2 = [raw_input().split() for row in range(4)]
		print "Case #%d: %s" % (t+1, res(row1, row2, arena1, arena2))