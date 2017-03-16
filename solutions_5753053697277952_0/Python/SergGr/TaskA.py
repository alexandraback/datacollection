import threading
import sys
from  collections import Counter
# Increase max stack size from 8MB to 512MB
# resource.setrlimit(resource.RLIMIT_STACK, (2**29,-1))
sys.setrecursionlimit(10 ** 6)

inputFileName = "test.in"
inputFileName = "A-small-attempt0.in"
inputFileName = "A-small-attempt1.in"
# inputFileName = "A-small-attempt2.in"
# inputFileName = "A-small-attempt3.in"
# inputFileName = "A-large.in"
outputFileName = inputFileName[:-3] + ".out"


# "ZERO", "ONE", "TWO", "THREE", "FOUR", "FIVE", "SIX", "SEVEN", "EIGHT", "NINE"
#

def calcSingleTest(f):
    line = f.readline()
    N = int(line)
    line = f.readline()
    sens0 = map(int, line.split())
    print sens0
    chars = map(lambda c: chr(ord('A') + c), xrange(N))
    sens = (zip(sens0, chars))
    sens = list(sorted(sens, key=lambda (c, l): -c))
    print sens

    (c1, l1) = sens[0]
    (c2, l2) = sens[1]
    rest = sens[2:]
    print rest
    res = []

    for x in xrange(c1 - c2):
        res.append(l1)

    for (c, l) in rest:
        while c > 1:
            res.append(l + l)
            c -= 2
        if c == 1:
            res.append(l)

    for x in xrange(c2):
        res.append(l1 + l2)

    print "Res = " + str(res)
    return ' '.join(res)


with open(inputFileName) as inpF:
    with open(outputFileName, 'w') as outF:
        line = inpF.readline()
        testsCount = int(line)
        for i in xrange(1, testsCount + 1):
            print '--------------------------------------------'
            res = calcSingleTest(inpF)
            outF.write('Case #{0}: {1}\n'.format(i, res))
