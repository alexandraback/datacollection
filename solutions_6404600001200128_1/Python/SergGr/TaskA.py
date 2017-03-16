inputFileName = "test.in"
inputFileName = "A-small-attempt0.in"
#inputFileName = "A-small-attempt1.in"
#inputFileName = "A-small-attempt2.in"
#inputFileName = "A-small-attempt3.in"
inputFileName = "A-large.in"
outputFileName = inputFileName[:-3] + ".out"


def calcSingleTest(f):
    line = f.readline()
    N = int(line)
    line = f.readline()
    m = map(int, line.split())
    y = 0
    z = 0
    ma = 0
    for i in xrange(1, N):
        d = m[i - 1] - m[i]
        if d <= 0:
            continue
        if d > ma:
            ma = d
        y += d
        #        z += d

    copy = list(m)
    for i in xrange(1, N):
        if copy[i - 1] >= ma:
            z += ma
            copy[i - 1] -= ma
        else:
            z += copy[i - 1]
            copy[i - 1] = 0

        d = copy[i - 1] - m[i]
        if d <= 0:
            continue
        if d > ma:
            ma = d
        z += d
        #        z += d

    return y, z


with open(inputFileName) as inpF:
    with open(outputFileName, 'w') as outF:
        line = inpF.readline()
        testsCount = int(line)
        for i in xrange(1, testsCount + 1):
            print '--------------------------------------------'
            resX, resY = calcSingleTest(inpF)
            outF.write('Case #{0}: {1} {2}\n'.format(i, resX, resY))




