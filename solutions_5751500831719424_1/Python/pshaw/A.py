import sys

filename = "A-large"

# return tuple (chars, counts)
def process_string(string):
	print string
	chars = []
	counts = []
	current_char = None
	current_count = 0
	for char in string:
		if char == "\n":
			continue

		if char == current_char:
			current_count += 1
		else:
			if current_char != None:
				chars.append(current_char)
				counts.append(current_count)
			current_char = char
			current_count = 1

	chars.append(current_char)
	counts.append(current_count)
	return (chars, counts)

def solve_case(strings):
	all_counts = []
	prev_chars = None
	for string in strings:
		(chars, counts) = process_string(string)
		if prev_chars != None and chars != prev_chars:
			return -1
		prev_chars = chars
		all_counts.append(counts)

	char_counts = zip(*all_counts)

	moves = 0
	print char_counts
	for char_count in char_counts:
		min_char_moves = 100*100
		for i in range(min(char_count), max(char_count)+1):
			char_moves = 0
			for count in char_count:
				char_moves += abs(count - i)
			if char_moves < min_char_moves:
				min_char_moves = char_moves
		moves += min_char_moves
		print min_char_moves
	return moves


def readInt(inFile):
	return int(inFile.readline())

def readFloats(inFile):
	return [int(n) for n in inFile.readline().split(" ")]

def readInts(inFile):
	return [int(n) for n in inFile.readline().split(" ")]

with open(filename + ".in", 'r') as inFile:
	output_data = []

	# parse input
	T = readInt(inFile)
	for t in range(T):
		N = readInt(inFile)
		strings = []
		for n in range(N):
			print("CASE " + str(n))
			strings.append(inFile.readline())
		moves = solve_case(strings)
		if moves < 0:
			output_data.append("Case #%s: Fegla Won" % (t+1))
		else:			
			output_data.append("Case #%s: %s" % (t+1, moves))

	if len(output_data) > 0:
		with open(filename + ".out", 'w') as outFile:
			outFile.write("\n".join(output_data))
	else:
		print("no output")




