import sys

def ItoC(x):
    return chr(ord('A') + x)

inputStrings = open('A-small-attempt0.in', 'r').read().splitlines()
caseNum = int(inputStrings[0])
outString = ""

lineNum = 1
for case in range(1,caseNum+1):
    outString += "Case #" + str(case) + ": "

    partyCount = int(inputStrings[lineNum])
    lineNum += 1
    partySenators =  list(map(int, inputStrings[lineNum].split(' ')))
    lineNum += 1

    while(sum(partySenators) > 0):
        largestPartyIndex = partySenators.index(max(partySenators))
        partySenators[largestPartyIndex] -= 1
        outString += ItoC(largestPartyIndex)

        majority = sum(partySenators)/2
        if(max(partySenators) > majority):
            largestPartyIndex = partySenators.index(max(partySenators))
            partySenators[largestPartyIndex] -= 1

            majority = sum(partySenators)/2
            if(max(partySenators) > majority):
                partySenators[largestPartyIndex] += 1
            else:
                outString += ItoC(largestPartyIndex)
        outString += ' '
        
    outString += '\n'

fileOut = open('A-small-attempt0.out', 'w')
fileOut.write(outString)
fileOut.close()