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
                print testNum

                line1 = inputFile.readline().split()
                R, C, N = int(line1[0]), int(line1[1]), int(line1[2])
                
                outputFile.write("Case #%d: %d" % (testNum+1, calcHappy(R,C,N)))

def calcHappy(R, C, N):
    if N == R*C:
        return totalWalls(R,C)
    if N <= (R*C+1)/2:
        return 0
    else: 
        empty = R*C-N
        if min(R, C) == 1: 
            return totalWalls(R,C) - empty * 2
        
        if min(R, C) == 2:
            length = max(R,C)
            if empty == length - 1:
                return totalWalls(R, C) - ( 3*empty - 1)
            return totalWalls(R, C) - (3 * empty)

        inR, inC = R-2, C-2
        innerRooms = inR*inC
        if innerRooms == 1:
            if N == 8:
                return totalWalls(R, C)  - 4
            if N == 7:
                return totalWalls(R, C)  - 6
            if N == 6: 
                return totalWalls(R, C)  - 9
        if (innerRooms+1)/2 >= empty:
            return  totalWalls(R, C)  - empty*4
        happy = 4*((innerRooms+1)/2)
        empty -= (innerRooms+1)/2

        edgeRooms = (R*2+(C-2)*2)/2
        if R%2 == 0 or C%2 == 0:
            edgeRooms += 2
        if empty < edgeRooms:
            happy += 3*empty
            return totalWalls(R, C) - happy
        return 1/0



def totalWalls(R, C):
    return R*(C-1) + C*(R-1)



main()