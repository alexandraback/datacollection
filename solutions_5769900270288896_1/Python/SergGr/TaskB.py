import itertools
import time
import operator
#import collections
from collections import Counter

inputFileName = "test.in"
inputFileName = "B-small-attempt0.in"
#inputFileName = "B-small-attempt1.in"
#inputFileName = "B-small-attempt2.in"
#inputFileName = "B-small-attempt3.in"
inputFileName = "B-large.in"
outputFileName = inputFileName[:-3] + ".out"

startTime = time.time()
print startTime

def calc(N, corners, sides):
    res = 0
    m = min(corners, N)
    if N > 0:
        N -= m
        res += 2 * m
    if N > 0:
        m = min(sides, N)
        res += 3 * m
        N -= m
    if N > 0:
        res += 4 * N
    return res


def calcSingleTest(f):
    line = f.readline()
    R = int(line.split()[0])
    C = int(line.split()[1])
    N0 = int(line.split()[2])
    N = int(line.split()[2])
    if N <= (R * C + 1) / 2:
        return 0

    if min(R, C) == 1:
        L = max(R, C)
        if L % 2 == 1:
            return 2 * (N - (L + 1) / 2)
        else:
            return 1 + 2 * (N - 1 - L / 2)

    if R % 2 != 0 and C % 2 == 0:
        R, C = C, R

    res = 0
    N -= (R * C + 1) / 2

    if R % 2 == 0 or C % 2 == 0:
        corners = 2
        sides = R + C - 4
        return calc(N, corners, sides)
    else:
        corners = 0
        sides = R + C - 2
        r1 = calc(N, corners, sides)
        N2 = N0
        N2 -= (R * C - 1) / 2
        corners2 = 4
        sides2 = 2 * int(R / 2) + 2 * int(C / 2) - 4
        r2 = calc(N2, corners2, sides2)
        return min(r1, r2)

        #    if R % 2 == 0 and C % 2 == 0:
        #        corners = 2
        #        sides = R + C - 4
        #    elif R % 2 != 0 and C % 2 != 0:
        #        corners = 0
        #    else:
        #        corners = 2

        #    sides = 2 * int(R / 2) + 2 * int(C / 2) - corners - 2

#    return res


with open(inputFileName) as inpF:
    with open(outputFileName, 'w') as outF:
        line = inpF.readline()
        testsCount = int(line)
        for i in xrange(1, testsCount + 1):
            print '--------  {0}/{1} {2} --------------------------'.format(i, testsCount, (time.time() - startTime))
            res = calcSingleTest(inpF)
            print '--------  {0}/{1} {2} --------------------------'.format(i, testsCount, (time.time() - startTime))
            print ' '
            outF.write('Case #{0}: {1}\n'.format(i, res))
            outF.flush()

print "Finished!!!! Total time = {0}".format((time.time() - startTime))