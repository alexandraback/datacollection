import math
import heapq

def formatLine(line):
	s = line.split()
	s = [int(i) for i in s]

	return s

def solveTestCase(line):
	line = formatLine(line)

def peopleserved(barbers, time):
	served = 0
	for x in barbers:
		served += int(math.ceil(float(time)/x))

def perminute(barbers):
	served = 0
	for x in barbers:
		served += (1/float(x))

	return served




########
data = open("testfile.txt", 'r')
out = open("answer.txt", "w")
numberCases = int(data.readline())
#########

for i in range(numberCases):
	b, n = formatLine(data.readline())

	barbers = formatLine(data.readline())


	minTime = n/perminute(barbers) - max(barbers)

	heap = []
	count = 1
	served = 0
	for x in barbers:
		s = int(math.floor(minTime/x))
		served += s
		heapq.heappush(heap, (s*x, count, x))
		count += 1

	while served < n:
		time, number, x = heapq.heappop(heap)
		heapq.heappush(heap, (time+x, number, x))

		served += 1



	s = "Case #{0:d}: {1:d}\n".format(i+1,number)
	print s
	out.write(s)

