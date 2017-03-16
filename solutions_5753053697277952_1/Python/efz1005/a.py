from Queue import Queue
from heapq import heappush, heappop

class PriorityQueue(Queue):
    # Initialize the queue representation
    def _init(self, maxsize):
        self.maxsize = maxsize
        self.queue = []

    # Put a new item in the queue
    def _put(self, item):
        return heappush(self.queue, item)

    # Get an item from the queue
    def _get(self):
        return heappop(self.queue)


T = input()

L = map(chr, range(65, 91))

for qw in xrange(1, T+1):
	print "Case #%d: " % qw,

	N = input()
	senator_number = [-int(x) for x in raw_input().split(" ")]

	Q = PriorityQueue()
	for i in xrange(len(senator_number)):
		Q.put([senator_number[i], L[i]])

	total = -sum(senator_number)

	outp = ""

	while not Q.empty():
		item = Q.get()
		outp += item[1]
		item[0] += 1
		total -= 1

		"""if item[0] != 0 and item[0] > total / 2:
			outp += item[1]
			item[0] += 1
			total -= 1"""
		if item[0] != 0:
			Q.put(item)

		if len(outp) == 2 or total in [0,2]:
			print outp,
			outp = ""
	print 