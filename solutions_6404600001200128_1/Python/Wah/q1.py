
testCaseIndex = 0

class TestCase:
    def __init__(self):
        global testCaseIndex
        testCaseIndex += 1

    def parseInput(self):
        self.N = raw_input()
        self.N = int(self.N)
        self.M = [int(x) for x in raw_input().split(" ")]


    def generateOutput(self):

        self.ND = []
        for index in range(0, self.N - 1):
            if self.M[index + 1] - self.M[index] < 0:

                self.ND.append(self.M[index + 1] - self.M[index])

        self.D = []
        for index in range(0, self.N - 1):
            self.D.append(self.M[index + 1] - self.M[index])

            self.MRate = abs(min(self.D))

        self.SM = 0
        for index in range(0, self.N - 1):

            if self.M[index] >= self.MRate:
                self.SM += self.MRate
            else:
                self.SM += self.M[index]
        #print self.ND
        self.FM = abs(sum(self.ND))

        print "Case #%d: %d %d" % (testCaseIndex, self.FM, self.SM)
        
def execTestCase():

    testcases = int(raw_input())
    for i in range(testcases):
        testCase = TestCase()
        testCase.parseInput()
        testCase.generateOutput()


execTestCase()