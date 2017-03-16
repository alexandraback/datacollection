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
        
def getCountsAdd(counts):
    minDist = 2**100

    for i in counts:
        curMinDist = 0
        for j in counts:
            curMinDist += int(math.fabs(i-j))
            if curMinDist > minDist:
                break

        if curMinDist < minDist:
            minDist = curMinDist
            
    return minDist

def solveGame(data):
    numOfStrings = int(data[0][0])
    strings = [""]*numOfStrings

    for i in range(numOfStrings):
        strings[i] = data[i+1][0]    
    
    smallStr = getSmallStr(strings[0])

    for string in strings[1:]:
        if getSmallStr(string) != smallStr:
            return "Fegla Won"          
     
    count = 0

    indexes = [0] * numOfStrings

    for letter in smallStr:
        curCounts = [0] * numOfStrings

        for strIdx in xrange(numOfStrings):
            startIndex = indexes[strIdx]

            for i in strings[strIdx][indexes[strIdx]:]:
                if i == letter:
                    curCounts[strIdx] += 1
                    indexes[strIdx] += 1
                else:
                    break

        count += getCountsAdd(curCounts)
            
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


    
