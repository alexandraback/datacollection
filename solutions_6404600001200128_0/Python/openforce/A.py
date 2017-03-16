import sys

def runTests():
	pass

def method1(n, in_arr):

	total1 = 0
	i0 = int(in_arr[0])
	last = i0

	for i in xrange(1,n):
		current = int(in_arr[i])
		if(current < last):
			diff = last - current
			total1 += diff
			
		last = current
	return total1

def method2(n, in_arr):
	i0 = float(in_arr[0])
	last = i0
	rate = -1.0

	for i in xrange(1,n):
		current = float(in_arr[i])
		if(current <= last):
			rate_maybe = float((last - current)/10.0)
			if (rate_maybe > rate):
				rate = rate_maybe

		last = current

	total1 = 0
	i0 = float(in_arr[0])
	last = i0
	rate_per_10 = rate * 10

	for i in xrange(1,n):
		current = int(in_arr[i])
		if(last > rate_per_10):
			total1 += rate_per_10

		else:
			total1 += last

		last = current
			

	
	return total1

if __name__ == '__main__':

	testing = False
	
	if(len(sys.argv) < 2):
		testing = True
		runTests()
		f = open('testa', 'r')
	else:
		f = open(sys.argv[1], 'r')

	testCases = int(f.next())
	
	for caseNum in xrange(1, testCases + 1):
	
		N = int(f.next())

		input = f.next().split()


		num1 = method1(N, input)
		num2 = method2(N, input)




		print('Case #%d: %d %d' % (caseNum, num1, num2))
