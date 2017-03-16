INPATH = r"C:\Users\Gil\Documents\jam\input.txt"
OUTPATH = r"C:\Users\Gil\Documents\jam\output.txt"

import math

GAME_LINES = 3

def getSmallStr(string):
    newStr = string[0]
    for i in string[1:]:
        if i == newStr[-1]:
            continue
        newStr += i

    return newStr
        

def solveGame(data):
    numOfStrings = int(data[0][0])
    firstString = data[1][0]
    secondString = data[2][0]
    
    if len(firstString) < len(secondString):
        firstString, secondString = secondString, firstString

    if getSmallStr(firstString) != getSmallStr(secondString):
        return "Fegla Won"          

    smallStr = getSmallStr(firstString)
    
    count = 0
    indexA = 0
    indexB = 0

    print firstString
    print secondString
    for letter in smallStr:
        curCountA = 0
        curCountB = 0

        startIndexA = indexA
        for i in firstString[startIndexA:]:
            if i == letter:
                curCountA += 1
                indexA += 1
            else:
                break

        startIndexB = indexB
        for i in secondString[startIndexB:]:
            if i == letter:
                curCountB += 1
                indexB += 1
            else:
                break

        count += int(math.fabs(curCountA-curCountB))
            
    return str(count)
    
    


data = open(INPATH,"r").readlines()
data = [x.replace("\n","") for x in data]
data = [[i for i in x.split(" ") ] for x in data]

numOfGames = int(data[0][0])

output = ""
curLine = 1

for i in range(numOfGames):
    currentNumOfStrings = int(data[curLine][0])
    output += "Case #%s: " % (i+1)
    output += solveGame(data[curLine:curLine + currentNumOfStrings + 1])
    output += "\n"
    curLine += (currentNumOfStrings + 1 )

output = output.rstrip("\n")

print output

open(OUTPATH,"w").write(output)


    
