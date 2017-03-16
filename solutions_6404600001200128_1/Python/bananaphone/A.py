T = int(raw_input())


def doprob():
	N = int(raw_input())
	read = raw_input()
	read = [int(k) for k in read.split()]
	count = 0
	large = 0
	for i in xrange(N-1):
		if read[i] > read[i+1]:
			if (read[i] - read[i+1]) > large:
				large = read[i] - read[i+1]
			count += read[i] - read[i+1]
	count2 = 0
	for i in xrange(N-1):
		if read[i] >= large:
			count2 += large
		else:
			count2 += read[i]
	return str(count) + " " + str(count2)


for qq in xrange(T):
	print "Case #" + str(qq+1) + ": " + str(doprob())