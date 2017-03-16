import sys

def getInputs():
    if len(sys.argv)-1 > 0:
        filename = sys.argv[1]
        with open(filename) as f:
            lineCount = int(f.readline())
            inputVal = []
            for l in xrange(lineCount):
                B, N = map(int, f.readline().split())
                inputVal.append((N, map(int, f.readline().split())))
            return inputVal

def processedCustomerBeforeTime(M, t): # t exclu
    return sum((t+m-1) // m for m in M)

def solve(caseVal): # complexity B*log(N)
    N = caseVal[0]
    M = caseVal[1]
    B = len(M)
    tmin = 0
    tmax = 2000000000 * 200000 # max(N) * max(Mk)
    while tmin+1 < tmax:
        tmid = (tmin+tmax) // 2
        Nfound = processedCustomerBeforeTime(M, tmid)
        if Nfound >= N:
            tmax = tmid
        else:
            tmin = tmid
    #print "tmin:", tmin
    #print "tmax:", tmax
    #print "Nfound:", Nfound
    Nremaining = N - processedCustomerBeforeTime(M, tmin)
    assert(N - processedCustomerBeforeTime(M, tmin+1) < Nremaining)
    tmp = [i for i in xrange(len(M)) if tmin % M[i] == 0]
    assert(Nremaining >= 1)
    assert(Nremaining <= len(tmp))
    return tmp[Nremaining-1] + 1

# with: 0 <= caseId < N
def writeOutput(caseId, result):
    print 'Case #%d: %d' % (caseId+1, result)

for caseId, caseVal in enumerate(getInputs()):
    writeOutput(caseId, solve(caseVal))
