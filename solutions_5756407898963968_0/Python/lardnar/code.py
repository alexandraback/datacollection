lines = [line.rstrip('\n') for line in open("A-small-attempt2.in")] #opens the file, splits into an array of lines
outputfile = open("output.txt", 'w')
outputfile.close()
for i in range(0,int(lines[0])):	#number of test cases
	datastart = 1
	offset = 10*i			#offset no. of lines in file
	rownum1 = int(lines[offset+datastart])
	rownum2 = int(lines[offset+datastart+5])
	row1 = lines[datastart+offset+rownum1].split()
	row2 = lines[datastart+offset+rownum2+5].split()
	valid = []
	for p in row1:
		for q in row2:
			if p == q:
				valid.append(p)
	if len(valid)==1:
		newline = "Case #"+str(i+1)+": "+valid[0]+"\n"
	elif len(valid)==0:
		newline = "Case #"+str(i+1)+": Volunteer cheated!\n"
	else:
		newline = "Case #"+str(i+1)+": Bad magician!\n"
	outputfile = open("output.txt", 'a')
	outputfile.write(newline)
	outputfile.close()
