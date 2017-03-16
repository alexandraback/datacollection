import sys




t = int(sys.stdin.readline())
for case in range(1, t+1):
	
	possible_answer = set(range(1,17))
	answer = int(sys.stdin.readline())
	grid   = [map(int, sys.stdin.readline().split()) for i in range(0,4)]
	#print grid[answer-1]
	possible_answer = possible_answer & set(grid[answer-1])
	#print possible_answer

	answer = int(sys.stdin.readline())
	grid   = [map(int, sys.stdin.readline().split()) for i in range(0,4)]
	#print grid[answer-1]
	possible_answer = possible_answer & set(grid[answer-1])
	#print possible_answer

	if len(possible_answer) == 0:
		print "Case #{0}: Volunteer cheated!".format(case)
	elif len(possible_answer) > 1:
		print "Case #{0}: Bad magician!".format(case)
	else:
		print "Case #{0}: {1}".format(case, list(possible_answer)[0])
	
