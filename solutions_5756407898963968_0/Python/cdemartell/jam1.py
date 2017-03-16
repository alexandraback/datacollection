def solver (tempdata):
	for integer in range(0, int(tempdata)):
		row = inputfile.readline().rstrip("\n")
	stuff1 = row.split(" ")
	for integer in range(int(tempdata), 4):
		row = inputfile.readline().rstrip("\n")
	
	temperdata = inputfile.readline()
	for integer in range(0, int(temperdata)):
		row = inputfile.readline().rstrip("\n")
	stuff2 = row.split(" ")
	for integer in range(int(temperdata), 4):
		row = inputfile.readline().rstrip("\n")
		
	stuff3 = set(stuff1).intersection(set(stuff2))
	if len(stuff3) == 1:
		return list(stuff3)[0]
	elif len(stuff3) == 0:
		return "Volunteer cheated!"
	else:
		return "Bad magician!"

inputfile = open('A-small-attempt2.in')
outputfile = open('A-small-attempt2-done.txt', 'w')

numberofcases = inputfile.readline()     
for tempnumber in range(1, int(numberofcases)+1):
	tempdata = inputfile.readline().rstrip("\n")
	outputfile.write("Case #%i: %s\n" % (tempnumber, solver(tempdata)))
	
inputfile.close()
outputfile.close()