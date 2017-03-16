#MMM, Google Code Jam Problem 1, Magic

infile = open("A-small-attempt0.in", "r")
outfile = open("output.txt", "w")

numtests = int(infile.readline())

for T in range(numtests):

	rows = list()

	for A in range(2):
		rownum = int(infile.readline()) - 1
		for R in range(4):
			currRow=infile.readline()
			if R == int(rownum):
				rows.append(map(int, currRow.split(' ')))

				
	answers = list()
	for N in rows[0]:
		if N in rows[1]:
			answers.append(N)

	print rows[0]
	print rows[1]

	outfile.write("Case #"+str(T+1)+": ")

	if len(answers) < 1:
		print >>outfile, ("Volunteer cheated!")
	elif len(answers) == 1:
		print >>outfile, answers[0]
	else: print >>outfile, ("Bad magician!")