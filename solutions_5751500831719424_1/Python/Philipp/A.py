def solveA():
	fileIn = open("in.txt", "r")
	lines = [line.strip() for line in fileIn]
	fileIn.close()
	
	fileOut = open("out.txt", "w")
	
	
	T = int(lines[0])
	c = 0
	i = 1
	while c < T:
		count = int(lines[i])
		i += 1
		strings = lines[i:i+count]
		i += count
		c += 1
		result = "Case #%i: %s\n" % (c, solve(strings))
		print result
		fileOut.write(result)
	
	fileOut.close()
		
def solve(strings):
	result = 0
	pos = [0] * len(strings)
	while True:
		if allOnEnd(strings, pos):
			break
		counts = [0] * len(strings)
		if pos[0] >= len(strings[0]):
			return "Fegla Won"
		cur = strings[0][pos[0]]
		for i in range(len(strings)):
			if pos[i] >= len(strings[i]) or strings[i][pos[i]] != cur:
				return "Fegla Won"
			while (pos[i] < len(strings[i]) and strings[i][pos[i]] == cur):
				counts[i] += 1
				pos[i] += 1
		result += distance(counts)
		
	return str(result)
	
def distance(counts):
	ordered = sorted(counts)
	median = ordered[len(ordered)/2]
	result = 0
	for l in counts:
		result += abs(median - l)
	return result
	
def allOnEnd(strings, pos):
	for i in range(len(strings)):
		if (pos[i] < len(strings[i])):
			return False
	return True
	
solveA()