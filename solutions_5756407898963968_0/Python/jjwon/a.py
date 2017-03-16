#!/usr/bin/env python
#
# Problem: Magic Trick
# Language: Python
# Author: jjwon
# Usage: python thisfile.py < input.in > output.out


import fileinput

def main():
    numTestCase = 1
    gotNumOfTestCase = False
    gotRow1 = False
    gotGrid1 = False
    gotRow2 = False
    gotGrid2 = False
    grid1, grid2 = [], []
    for line in fileinput.input():
        if not gotNumOfTestCase:
            numOfTestCase = int(line)
            gotNumOfTestCase = True
        elif not gotRow1:
            row1Num = int(line)
            gotRow1 = True
        elif not gotGrid1:
            grid1.append(line.split())
            if len(grid1) == 4:
                gotGrid1 = True
        elif not gotRow2:
            row2Num = int(line)
            gotRow2 = True
        elif not gotGrid2:
            grid2.append(line.split())
            if len(grid2) == 4:
                gotGrid2 = True
                row1 = grid1[row1Num-1]
                row2 = grid2[row2Num-1]
                outputchecker = []
                for num in row1:
                    if num in row2:
                        outputchecker.append(int(num))
                if len(outputchecker) == 1:
                    print("Case #%d: %d" % (numTestCase, outputchecker[0]))
                elif len(outputchecker) == 0:
                    print("Case #%d: Volunteer cheated!" % numTestCase)
                else:
                    print("Case #%d: Bad magician!" % numTestCase)
                grid1, grid2 = [], []
                gotRow1 = False
                gotGrid1 = False
                gotRow2 = False
                gotGrid2 = False
                numTestCase += 1



if __name__ == "__main__":
    main()