import sys

def runTests():
	pass

def findSeat():
	pass

if __name__ == '__main__':

	testing = False
	
	if(len(sys.argv) < 2):
		testing = True
		runTests()
		f = open('testb', 'r')
	else:
		f = open(sys.argv[1], 'r')

	testCases = int(f.next())
	
	for caseNum in xrange(1, testCases + 1):
		

		l1 = f.next().split()
		B = int(l1[0])
		N = int(l1[1])

		Marr = f.next().strip().split()

		seats = []
		for i in xrange(B):
			seats.append(0)

		barb_num = -1
		stop = -1
		hist = []

		for i in xrange(N):
			foundSeat = False
			while(not foundSeat):
				for j in xrange(B):
					if(seats[j] == 0):
						seats[j] = int(Marr[j])
						barb_num = j+1
						hist.append(barb_num)
						foundSeat = True
						break

				if(not foundSeat):
					mini = min(seats)
					for j in xrange(B):
						seats[j] = seats[j] - mini

					if(max(seats) == 0):
						stop = i
						break
			if(stop > 0):
				break

		if(stop > 0):
			barb_num = hist[(N % stop) - 1]



		print('Case #%d: %d' % (caseNum, barb_num))
