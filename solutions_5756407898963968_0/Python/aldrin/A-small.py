GRID_SIZE = 4

import sys

def readGrid(f):
    grid = []
    for i in range(GRID_SIZE):
        line = f.readline()
        grid.append(line.rstrip().split(' '))
    return grid

def main():

    # Read file and number of test cases
    f = open(sys.argv[1], 'r')
    testcases = int(f.readline())


    for i in range(1, testcases + 1):
        # Read first choice and first row to compare
        firstchoice = int(f.readline())
        grid = readGrid(f)
        firstline = grid[firstchoice-1]
        
        # Read second choice and second row to compare
        secondchoice = int(f.readline())
        grid = readGrid(f)
        secondline = grid[secondchoice-1]

        matches = 0
        card = 0
        for x in firstline:
            for y in secondline:
                if x == y:
                    # Found a match
                    matches += 1
                    card = x

        if matches > 1:
            print "Case #" + str(i) + ": Bad magician!"

        elif matches == 1:
            print "Case #" + str(i) + ": " + card

        else:
            print "Case #" + str(i) + ": Volunteer cheated!"





main()


