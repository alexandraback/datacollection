import os

infilename = "A-large.in"
in_file = open(infilename)

numcases = int(in_file.readline())
totalout = ""

for casenum in range(numcases):

    numStrings = int(in_file.readline())
    strings = []
    for i in range(numStrings):
        curString = in_file.readline().strip()
        curPair = [curString[0], 1]
        sepString = []
        for j in range(1, len(curString)):
            if curString[j] == curPair[0]:
                curPair[1] += 1
            else:
                sepString.append(curPair)
                curPair = [curString[j], 1]
        sepString.append(curPair)
        strings.append(sepString)

    stillGood = True
    for i in range(numStrings):
        if len(strings[i]) != len(strings[0]):
            stillGood = False
            break

    if stillGood:
        for j in range(len(strings[0])):
            if stillGood:
                for i in range(numStrings):
                    if strings[i][j][0] != strings[0][j][0]:
                        stillGood = False
                        break
    actions = 0
    if stillGood:
        for j in range(len(strings[0])):
            curLetterLengths = []
            for i in range(numStrings):
                curLetterLengths.append(strings[i][j][1])
            curLetterLenghts = sorted(curLetterLengths)
            optimalLength = curLetterLenghts[int(len(curLetterLengths)/2)]
            for letterLength in curLetterLenghts:
                actions += abs(letterLength - optimalLength)
            
                
    if stillGood:
        result = str(actions)
    else:
        result = "Fegla Won"
            
    outstr = "Case #" + str(casenum + 1) + ": " + result
    totalout += outstr + "\n"
    print(outstr)

writetofile = False
if "small" in infilename:
    outprefix = "small"
    writetofile = True
elif "large" in infilename:
    outprefix = "large"
    writetofile = True
#writetofile = False

if writetofile:
    filenum = 0
    while True:
        outfilename = outprefix + str(filenum) + ".out"
        filenum += 1
        if not os.path.isfile(outfilename):
            break
    out_file = open(outfilename, 'w+')
    out_file.write(totalout)
    out_file.close()

in_file.close()
