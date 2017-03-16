# Mod out N by lcm of sessionTimes
# Barber has sessionTime and nextAvailableTime and ID
# Priority queue with B barbers
# At each step, pop minimum (defined by ID and nextAvailableTime)
# add sessionTime to nextAvailableTime, requeue

import Queue

class Barber:
	def __init__(self, num, sessionTime, nextAvailableTime):
		self.num = num
		self.sessionTime = sessionTime
		self.nextAvailableTime = nextAvailableTime

	def __lt__(self, otherBarber):
		if self.nextAvailableTime < otherBarber.nextAvailableTime:
			return True
		elif self.nextAvailableTime == otherBarber.nextAvailableTime:
			return self.num < otherBarber.num
		else:
			return False

def makeBarberList(sessionTimes):
	barberList = []
	for i in range(len(sessionTimes)):
		barberList.append(Barber(i + 1, sessionTimes[i], 0))
	return barberList

def getBarber(n, barberList):
	q = Queue.PriorityQueue(len(barberList))
	for i in range(len(barberList)):
		q.put_nowait(barberList[i])
	for j in range(n - 1):
		barber = q.get_nowait()
		barber.nextAvailableTime += barber.sessionTime
		q.put_nowait(barber)
	myBarber = q.get_nowait()
	return myBarber.num

def gcd(a, b):
	while b:
		a, b = b, a % b
	return a

def lcm(a, b):
	return a * b / gcd(a, b)

# returns customers before reset
def getResetNumber(sessionTimes):
	resetTime = reduce(lcm, sessionTimes)
	return sum(map(lambda x: resetTime/x, sessionTimes))

fin = open("B-small-attempt1.in", 'r')
fout = open("out.txt", 'w')

cases = int(fin.readline())
for case in range(cases):
	numBarbers, myPosition = map(int, str.split(fin.readline()))
	sessionTimes = map(int, str.split(fin.readline()))
	resetNumber = getResetNumber(sessionTimes)
	myResetPosition = ((myPosition - 1) % resetNumber) + 1
	result = getBarber(int(myResetPosition), makeBarberList(sessionTimes))
	fout.write("Case #" + str(case + 1) + ": " + str(result) + "\n")

fin.close()
fout.close()