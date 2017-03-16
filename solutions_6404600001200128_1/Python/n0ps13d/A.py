fin = open('A-large.in', 'r')
fout = open('A.out', 'w')

cases = int(fin.readline().rstrip('\n'))
# print cases
for case in xrange(1, cases+1):
	answer = "Case #" + str(case) + ": "
	moments = int(fin.readline().rstrip('\n'))
	moment = [int(i) for i in fin.readline().rstrip('\n').split()]

	# print moment

	rate = 0
	total_one = 0

	for index in xrange(len(moment)-1):
		diff = moment[index] - moment[index+1]
		if diff > 0:
			total_one += diff
			if diff > rate:
				rate = diff

	total_two = 0

	for index in xrange(len(moment)-1):
		if moment[index] > rate:
			total_two += rate
		else:
			total_two += moment[index]

	answer += str(total_one) + " " + str(total_two)
	print answer
	fout.write(answer + '\n')

fin.close()
fout.close()