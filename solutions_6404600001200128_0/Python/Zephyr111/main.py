import sys

def getInputs():
    if len(sys.argv)-1 > 0:
        filename = sys.argv[1]
        with open(filename) as f:
            lineCount = int(f.readline())
            inputVal = []
            for l in xrange(lineCount):
                elemCount = int(f.readline())
                inputVal.append(map(int, f.readline().split()))
            return inputVal

def solve(caseVal):
    r1 = 0
    r2 = 0
    maxi = 0
    for i in xrange(len(caseVal)-1):
        r1 += max(caseVal[i] - caseVal[i+1], 0)
        maxi = max(caseVal[i] - caseVal[i+1], maxi)
    for i in xrange(len(caseVal)-1):
        r2 += min(max(caseVal[i], 0), maxi)
    return (r1, r2)

# with: 0 <= caseId < N
def writeOutput(caseId, result):
    print 'Case #%d: %d %d' % (caseId+1, result[0], result[1])

for caseId, caseVal in enumerate(getInputs()):
    writeOutput(caseId, solve(caseVal))
