import sys

def getNextChosenRow(inp):
    chosenRow = []
    rowNumber = int(inp.readline()) - 1
    for i in xrange(4):
        currRow = inp.readline()
        if i == rowNumber:
            chosenRow = map(lambda x: int(x), currRow[0:-1].split(" "))
    return chosenRow

def compareRows(row0, row1):
    correctCard = [card for card in row0 if card in row1]
    if len(correctCard) == 0:
        return "Volunteer cheated!"
    elif len(correctCard) == 1:
        return correctCard[0]
    else:
        return "Bad magician!"

inp = open("A-small-attempt0.in", 'r')
outp = open("A-small-attempt0.out", 'w')
T = int(inp.readline())

for testCase in xrange(T):
    chosenRow0 = getNextChosenRow(inp)
    chosenRow1 = getNextChosenRow(inp)
    outp.write("Case #{}: {}\n".format(testCase + 1, compareRows(chosenRow0, chosenRow1)))
outp.close()
