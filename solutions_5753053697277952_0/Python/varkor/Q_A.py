inputData = open("Q_A_input.txt", "r")
outputData = open("Q_A_output.txt", "w")
outputLines = []

def output (string):
	string = str(string)
	print(string)
	outputLines.append(string)

def case (x, y):
	output("Case #" + str(x) + ": " + str(y))

for (number, line) in enumerate(inputData.read().splitlines()[1:]):
	if number % 2 == 0:
		continue
	ps = list(map(int, line.split(" ")))
	s = sum(ps)
	instructions = []
	while s > 0:
		single = []
		i = ps.index(max(ps))
		single.append(i)
		ps[i] -= 1
		s -= 1
		if s > 0 and (len(filter(lambda x: x == 1, ps)) != 2 or len(filter(lambda x: x > 0, ps)) != 2):
			i = ps.index(max(ps))
			single.append(i)
			ps[i] -= 1
			s -= 1
		instructions.append("".join(map(lambda x: str(unichr(65 + x)), single)))
	case(number // 2 + 1, " ".join(instructions))

outputData.write("\n".join(outputLines))
inputData.close()
outputData.close()