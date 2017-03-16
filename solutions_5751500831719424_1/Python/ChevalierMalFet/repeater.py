inputFile = open('A-large.in', 'r')
outputFile = open('A-large.out', 'w')

numTests = int(inputFile.readline())

for i in range(numTests):
    numStrings = int(inputFile.readline())
    strings = []
    for j in range(numStrings):
        strings += [inputFile.readline().strip()]

    baseline = strings[0][0]
    for j in range(1, len(strings[0])):
        if strings[0][j] != baseline[-1]:
            baseline += strings[0][j]

    letterCounts = [[] for j in range(len(baseline))]
    isBroken = False
    for string in strings:
        currLetter = baseline[0]
        currIndex = 0
        currStringIndex = 0
        while currIndex < len(baseline):
            count = 0
            currLetter = baseline[currIndex]
            while (currStringIndex < len(string) and
                   string[currStringIndex] == currLetter):
                count += 1
                currStringIndex += 1
            if count == 0:
                isBroken = True
                break
            else:
                letterCounts[currIndex] += [count]
                currIndex += 1
        if currStringIndex != len(string):
            isBroken = True

    
    # For each letter count, use the median and distance from all to median
    count = 0
    if not isBroken:
        for countList in letterCounts:
            countList.sort()
            median = countList[len(countList)/2]
            for j in countList:
                count += abs(j-median)
    

    outputFile.write('Case #' + str(i+1) + ': ')
    if isBroken:
        outputFile.write('Fegla Won\n')
    else:
        outputFile.write(str(count)+'\n')

inputFile.close()
outputFile.close()
