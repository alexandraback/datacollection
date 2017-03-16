#!/usr/bin/python

import sys, Queue

def newCount(barbers, place, waits):
	speed = float(0)
	for i in waits:
		speed += float(1)/float(i)

	time = max(0, int((place - 2 - barbers)/speed) - 3)

	times = Queue.PriorityQueue()
	available = {}

	for i in xrange(barbers):
		place -= (time + waits[i] - 1)/ waits[i]
		nextTime = (time + waits[i] - 1)/waits[i] * waits[i]

		nextList = available.get(nextTime)
		if nextList == None:
			nextList = []
			available[nextTime] = nextList
			times.put(nextTime)
		nextList.append(i)

	time
	place
	available

	while times.qsize() > 0:
		time = times.get()
		for i in sorted(available[time]):
			nextTime = time + waits[i]
			nextList = available.get(nextTime)
			if nextList == None:
				nextList = []
				available[nextTime] = nextList
				times.put(nextTime)
			nextList.append(i)

			place -= 1
			if place == 0:
				return str(i+1)

		# advance time
	return 0

def count(barbers, place, waits):
	if place > 10:
		return newCount(barbers, place, waits)

	times = Queue.PriorityQueue()
	times.put(0)
	available = {}
	available[0] = range(barbers)

	while times.qsize() > 0:
		time = times.get()
		for i in sorted(available[time]):
			nextTime = time + waits[i]
			nextList = available.get(nextTime)
			if nextList == None:
				nextList = []
				available[nextTime] = nextList
				times.put(nextTime)
			nextList.append(i)

			place -= 1
			if place == 0:
				return str(i+1)

		# advance time
	return 0

if __name__ == "__main__":
	lines = int(sys.stdin.readline())
	for i in range(lines):
		#print i
		barbers, place = map(int, sys.stdin.readline().strip().split())
		waits = map(int, sys.stdin.readline().strip().split())

		#if i != 2:
		#	continue
		print "Case #{0}: {1}".format(str(i+1), count(barbers, place, waits))
