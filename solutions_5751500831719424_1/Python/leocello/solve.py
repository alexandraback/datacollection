fileIn = open ("C:/Testes/Google/Round1B/A/A-large.in","r");
fileOut = open ("C:/Testes/Google/Round1B/A/A-large.out","w");

def removeRep(strings):
	newStrings = []
	for i in range(0,len(strings)):
		lastLetter = ''
		newStrings.append([])
		for j in range(0,len(strings[i])):
			if strings[i][j] != lastLetter:
				newStrings[i].append(strings[i][j])
				lastLetter = strings[i][j]
	return newStrings
	
def compareStrings(strings):
	firstString = strings[0]
	for i in range(1,len(strings)):
		if firstString != strings[i]:
			return bool(0)
	return bool(1)
	
def countLetters(strings):
	letters = []
	stringsR = removeRep(strings)
	for i in range(0, len(stringsR)):
		a = 0
		letters.append([])
		for j in range(0, len(stringsR[i])):
			num = 0
			while a < len(strings[i]):
				if strings[i][a] == stringsR[i][j]:
					a += 1
					num	+= 1
				else:
					break
			letters[i].append(num)
	return letters

def equalizeStrings(strings):
	num = 0
	letters = countLetters(strings)
	for j in range(0,len(letters[0])):
		less = -1
		for i in range(0,len(letters)):
			numb = letters[i][j]
			actions = 0
			for k in range(0,len(letters)):
				if numb > letters[k][j]:
					actions += numb - letters[k][j]
				else:
					actions += letters[k][j] - numb
			if less == -1 or less > actions:
				less = actions
		num += less
	return num

lines = []
for line in fileIn:
	lines.append(line)

numCases = int(lines[0])
lines.pop(0)

i = 0
for n in range(0, numCases):
	numStrings = int(lines[i])
	i+=1
	strings = []
	for m in range(0,numStrings):
		strings.append(lines[i].strip())
		i+=1
	
	if compareStrings(removeRep(strings)):
		actions = equalizeStrings(strings)
		fileOut.write('Case #'+str(n+1)+': '+str(actions)+'\n')
	else:
		fileOut.write('Case #'+str(n+1)+': Fegla Won\n')
	

fileIn.close()
fileOut.close()
