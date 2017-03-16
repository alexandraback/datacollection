import sys

from itertools import combinations

def getRow(index, R, C):
    a,b = divmod(index, R)
    return a

def getColumn(index, R, C):
    a,b = divmod(index, R)
    return b


# TODO: Write the function to get the noise for the apartment given the empty cells


for tc in range(1, 1 + int(sys.stdin.readline())):
    line = sys.stdin.readline().strip()
    vals = line.split(" ")
    R, C, N = map(int, vals)

    size = R*C
    empty = R*C - N

    #the cell index is on the range 0 to size

    # Select empty cells among all the cells
    minunhappiness = float("inf")
    for comb in combinations(range(size), empty):
        emptycells = comb

        occupied = {x:1 for x in range(size)}
        for e in emptycells:
            occupied[e] = 0

        unhappiness = 0
        for i in xrange(size):
            # Get the cell below
            row, column = divmod(i, C)
            if not occupied[i]:
                continue
            if row +1 < R:
                if occupied[C * (row+1) + column]:
                    unhappiness += 1

            if column + 1 < C:
                if occupied[C * (row) + column + 1]:
                    unhappiness += 1

            # Get the cell to the right
            # Check if they are

        minunhappiness = min(minunhappiness, unhappiness)

    res = "%d" % minunhappiness

    print "Case #%d: %s" % (tc, res)

