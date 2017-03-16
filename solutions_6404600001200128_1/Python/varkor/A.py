inputData = open("A.in", "r")
outputData = open("A.out", "w")
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
	mushrooms = list(map(int, line.split(" ")))
	prev = None
	min1 = 0
	min2 = 0
	rate = 0
	for n in mushrooms:
		if prev != None:
			rate = max(prev - n, rate)
		prev = n
	prev = None
	for (j, m) in enumerate(mushrooms):
		if prev != None and prev > m:
			min1 += prev - m
		if j < len(mushrooms) - 1:
			min2 += min(rate, m)
		prev = m
	case(number // 2 + 1, str(min1) + " " + str(min2))


outputData.write("\n".join(outputLines))
inputData.close()
outputData.close()