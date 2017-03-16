n = 4
T = int(raw_input())
for i in range(T):
	result = ""
	volunteer_row = int(raw_input())
	numbers = []
	for row in range(1, n+1):
		if row == volunteer_row:
			numbers = set(raw_input().split())
		else:
			raw_input()
	volunteer_row = int(raw_input())
	for row in range(1, n+1):
		if row == volunteer_row:
			newNumbers = set(raw_input().split())
			match = numbers.intersection(newNumbers)
			if len(match) == 0:
				result = "Volunteer cheated!"
			elif len(match) == 1:
				result = str(match.pop())
			else:
				result = "Bad magician!"
		else:
			raw_input()
	print "Case #" + str(i+1) + ": " + result




