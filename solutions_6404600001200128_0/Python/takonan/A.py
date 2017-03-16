import sys, math

def main(fin, fout):
	T = int(fin.readline())
	for t in range(T):
		N = int(fin.readline().strip())
		mList = [int(x) for x in fin.readline().strip().split()]
		# print N
		# print mList

		# Method 1: Only add if the next element is less than current
		first = 0
		maxD = 0
		delt = 0
		for i in range(N-1):
			if mList[i+1] < mList[i]:
				delt = mList[i] - mList[i+1]
				first += delt
				if delt > maxD:
					maxD = delt

		# print first
		# print "Max diff: %d" % (delt)

		# Method 2: Find the max difference
		second = 0
		for i in range(N-1):
			second += min(mList[i], maxD)
		print second

		fout.write("Case #%d: %d %d\n" % (t+1, first, second))

	return

if __name__ == '__main__':
	fin = open(sys.argv[1], "r")
	fout = open(sys.argv[2], "w")
	main(fin, fout)
