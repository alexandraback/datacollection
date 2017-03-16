
testCaseIndex = 0

def gcd(a, b):
    while b:
        a, b = b, a % b
    return a

def lcm(a, b):
    return a * b / gcd(a, b)

def lcms(*args):
    return reduce(lcm, args)

def getIndexes(CM):
    indexes = []
    for index in range(len(CM)):
        if CM[index] == 0:
            indexes.append(index)

    return indexes

class TestCase:
    def __init__(self):
        global testCaseIndex
        testCaseIndex += 1

    def parseInput(self):
        self.B, self.N = [int(x) for x in raw_input().split(" ")]
        self.M = [int(x) for x in raw_input().split(" ")]
        #print self.B, self.M

    def generateOutput(self):
        if self.N <= len(self.M):
            self.Y = self.N
        else:
            lcm = lcms(*self.M)

            sizePerLCM = sum([lcm / x for x in self.M])

            #print lcm, sizePerLCM
            if self.N > sizePerLCM:
                self.N = self.N % sizePerLCM
                if self.N == 0:
                    self.N = sizePerLCM

            #print self.N
            if self.N <= len(self.M):
                self.Y = self.N
            else:
                self.N -= len(self.M)
                self.CM = self.M[:]
                while self.N > 0:
                    minWait = min(self.CM)
                    self.CM = [x - minWait for x in self.CM]
                    indexes = getIndexes(self.CM)
                    if self.N <= len(indexes):
                        self.Y = indexes[self.N - 1] + 1
                        break
                    else:
                        self.N -= len(indexes)
                        for index in indexes:
                            self.CM[index] = self.M[index]
        print "Case #%d: %s" % (testCaseIndex, self.Y)
        
def execTestCase():

    testcases = int(raw_input())
    for i in range(testcases):
        testCase = TestCase()
        testCase.parseInput()
        testCase.generateOutput()

execTestCase()