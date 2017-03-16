def alphanum(n):
	return 'ABCDEFGHIJKLMNOPQRSTUVWXYZ'[n]
	
def evacstring(inputlist):
	evacs = []
	while sum(inputlist) > 1:
		if sum(inputlist) == 3:
			biggestnum = inputlist[0]
			biggestpos = 0
			for i in range(1,len(inputlist)):
				if inputlist[i] > biggestnum:
					biggestnum = inputlist[i]
					biggestpos = i
			evacs.append(alphanum(biggestpos))
			inputlist[biggestpos] -= 1		
		else:
			biggestnum = inputlist[0]
			biggestpos = 0
			tiepos = 'None'
			for i in range(1,len(inputlist)):
				if inputlist[i] == biggestnum:
					tiepos = i
				elif inputlist[i] > biggestnum:
					biggestnum = inputlist[i]
					biggestpos = i
					tiepos = 'None'
			if tiepos == 'None':
				evacs.append(alphanum(biggestpos))
				inputlist[biggestpos] -= 1
			else:
				evacs.append(alphanum(biggestpos)+alphanum(tiepos))
				inputlist[biggestpos] -= 1
				inputlist[tiepos] -= 1
	if sum(inputlist) == 1:
		evacs.append(alphanum(inputlist.index(1)))
	return ' '.join(evacs)
	
import sys
with open(sys.argv[1], "r") as fileIN:
	inputLines = fileIN.readlines()
		
with open(sys.argv[2], "w") as fileOUT:
	numberOfCases = int(inputLines.pop(0))
	for num in range(numberOfCases):
		numberOfParties = int(inputLines.pop(0))
		inputlist = [int(x) for x in inputLines.pop(0).rstrip().split(' ')] 
		fileOUT.write('Case #' + str(num+1) + ': ' + evacstring(inputlist) + '\n')
		