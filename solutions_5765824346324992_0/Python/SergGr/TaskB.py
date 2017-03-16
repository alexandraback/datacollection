import itertools
import time
import operator
#import collections
from collections import Counter
from fractions import gcd

inputFileName = "test.in"
#inputFileName = "B-small-attempt0.in"
inputFileName = "B-small-attempt1.in"
#inputFileName = "B-small-attempt2.in"
#inputFileName = "B-small-attempt3.in"
#inputFileName = "B-large.in"
outputFileName = inputFileName[:-3] + ".out"

startTime = time.time()
print startTime


def my_gcd(li, start=0):
    if len(li) == start + 1:
        return li[start]
    elif len(li) == start + 2:
        return gcd(li[start], li[start + 1])
    else:
        return gcd(li[start], my_gcd(li, start + 1))


def calcSingleTest(f):
    line = f.readline()
    B = int(line.split()[0])
    N0 = int(line.split()[1])
    line = f.readline()
    bs0 = map(int, line.split())
    g = my_gcd(bs0)
    bs = map(lambda x: x / g, bs0)
    l = reduce(lambda x, y: x * y, bs, 1)
    cs = map(lambda x: l / x, bs)
    cl = sum(cs)
    print bs
    print cs
    print cl

    bb = []
    for i in xrange(B):
        bb.append(0)

    N = N0 % cl
    if N == 0:
        N = cl
    res = -1
    cnt = 0
    ma = min(bs) * N
    print ma
    t = 0
    while t < ma:
        mi = min(bb)
        for i in xrange(0, B):
            if bb[i] > 0:
                bb[i] -= mi
            if bb[i] == 0:
                bb[i] = bs[i]
                cnt += 1
                if cnt == N:
                    return i + 1
        t += mi

    raise RuntimeError("AAAAA " + str(ma) + " " + str(t))


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