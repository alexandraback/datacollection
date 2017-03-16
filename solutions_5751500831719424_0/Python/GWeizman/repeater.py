# Google Code Jam 2014 - The Repeater
# Guy Weizman

import sys

__author__ = 'Guy Weizman'


if len(sys.argv) != 2:
    print 'Syntax: python repeater.py FILE_PATH [Without .in]'
    exit()


file = sys.argv[1]

readFile = open(file + '.in', 'r')
writeFile = open(file + '.out', 'w')

def countWord(word):
    letters = list(word)
    count = 1
    firstLetter = letters[0]
    del letters[0]
    retVal = list()
    for letter in letters:
        if letter is not firstLetter:
            retVal.append((firstLetter, count))
            firstLetter = letter
            count = 1
        else:
            count += 1
    retVal.append((firstLetter, count))
    return retVal

def findNum(strings):
    def countChange(sizes):
        def findNextSmallest(sizes, smallest):
            pos = 0
            for size in sizes:
                if size != smallest:
                    return (size, pos)
                pos += 1
        def findNextLargest(sizes, largest):
            pos = 0
            for size in reversed(sizes):
                if size != largest:
                    return (size, len(sizes) - 1 - pos)
                pos += 1
        # Take care of trivial cases
        if (len(sizes) == 2):
            return abs(sizes[1] - sizes[0])
        if (sizes[0] == sizes[-1]):
            return 0
        if (sizes[0] < sizes[1]):
            diff = sizes[1] - sizes[0]
            sizes[0] = sizes[0] + diff
            return countChange(sizes) + diff
        if (sizes[-1] > sizes[-2]):
            diff = sizes[-1] - sizes[-2]
            sizes[-1] = sizes[-1] - diff
            return countChange(sizes) + diff
        # Either we change smallest block or largest block
        nextSmallest = findNextSmallest(sizes, sizes[0])
        nextLargest = findNextLargest(sizes, sizes[-1])
        if (nextSmallest[1] < len(sizes) - 1 - nextLargest[1]):
            diff = nextSmallest[0] - sizes[0]
            for i in range(nextSmallest[1]):
                sizes[i] += diff
            return diff * nextSmallest[1] + countChange(sizes)
        diff = nextLargest[0] - sizes[-1]
        for i in range(nextLargest[1] + 1, len(sizes)):
            sizes[i] += diff
        return (-diff) * (len(sizes) - 1 - nextLargest[1]) + countChange(sizes)

    length = len(strings[0])
    for string in strings:
        if len(string) != length:
            return "Fegla Won"
    retVal = 0
    for i in range(length):
        sizes = list()
        letter = strings[0][i][0]
        for string in strings:
            sizes.append(string[i][1])
            if (string[i][0] != letter):
                return "Fegla Won"
        retVal += countChange(sorted(sizes))
    return retVal

testCases = int(readFile.readline())

for i in range(testCases):
    lines = int(readFile.readline())
    strings = [countWord(readFile.readline().rstrip()) for j in range(lines)]
    print "Case #" + str(i + 1) + ": " + str(findNum(strings))
