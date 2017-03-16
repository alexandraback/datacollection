import sys

def main():
    inputFileName = sys.argv[1]
    outputFileName = sys.argv[2]
    with open(inputFileName, 'r') as inputFile:
        with open(outputFileName, 'w') as outputFile:
            numTestCases = int(inputFile.readline())
            for testNum in range(numTestCases):
                if testNum > 0:
                    outputFile.write("\n")

                checks = int(inputFile.readline())
                mushrooms = inputFile.readline().split()
                mushrooms = [int(m) for m in mushrooms]
                
                hare, tortoise = calcStep(mushrooms), calcSlowAndSteady(mushrooms)
                
                outputFile.write("Case #%d: %d %d" % (testNum+1, hare, tortoise))

def calcStep(mushrooms):
    eaten = 0
    for i in range(1,len(mushrooms)):
        if mushrooms[i] < mushrooms [i-1]:
            eaten += mushrooms[i-1] - mushrooms[i]
    return eaten

def calcDifferentials(mushrooms):
    diff = []
    for i in range(1,len(mushrooms)):
        diff += [mushrooms[i-1]-mushrooms[i]]
    return diff

def calcMinSpeed(mushrooms):
    # units: mushrooms/ 10 seconds
    return max(calcDifferentials(mushrooms))

def calcSlowAndSteady(mushrooms):
    speed = calcMinSpeed(mushrooms)
    eaten = 0
    for m in mushrooms[:-1]:
        if m < speed:
            eaten += m
        else:
            eaten += speed
    return eaten

main()