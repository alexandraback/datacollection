inputData = open("B.in", "r")
outputData = open("B.out", "w")
outputLines = []

def output (string):
	string = str(string)
	print(string)
	outputLines.append(string)

def case (x, y):
	output("Case #" + str(x) + ": " + str(y))

from fractions import gcd
from functools import reduce

def lcm (a, b):
	return a * b // gcd(a, b)

for (number, line) in enumerate(inputData.read().splitlines()[1:]):
	if number % 2 == 0:
		n = list(map(int, line.split(" ")))[1]
		continue
	times = list(map(int, line.split(" ")))
	if len(times) >= n:
		case(number // 2 + 1, str(n))
	else:
		lc = reduce(lambda x, y: lcm(x, y), times)
		order = []
		for x in range(0, lc):
			for k in range(0, len(times)):
				if x == 0 or x % times[k] == 0:
					order.append(k)
		case(number // 2 + 1, str(order[(n - 1) % len(order)] + 1))


outputData.write("\n".join(outputLines))
inputData.close()
outputData.close()