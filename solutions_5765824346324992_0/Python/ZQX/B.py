import heapq

def gcd(*numbers):
    """Return the greatest common divisor of the given integers"""
    from fractions import gcd
    return reduce(gcd, numbers)
  
def lcm(*numbers):
    """Return lowest common multiple."""    
    def lcm(a, b):
        return (a * b) // gcd(a, b)
    return reduce(lcm, numbers, 1)

def readFile(fileName):
    f = open(fileName)
    caseList = []
    index = 0
    for line in f:
        index += 1
        content = line.split()
        if index == 1:
            print content[0],'test cases are read.'
        elif index %2 == 0:
            N = int(content[1])
        else:
            temp = []
            for i in range(len(content)):
                temp.append(int(content[i]))
            caseList.append((N,temp))
    f.close()
    return caseList

class Barber(object):
    def __init__(self, num, time):
        self.num = num
        self.time = time
        self.totaltime = 0
    def __lt__(self, other):
        if self.totaltime > other.totaltime:
            return False
        elif self.totaltime < other.totaltime:
            return True
        return self.num < other.num
    def update(self):
        self.totaltime += self.time
    def __str__(self):
        return '(' + str(self.num) + ', ' + str(self.time) + ', ' + str(self.totaltime) + ')'

def printList(bList):
    ans = ''
    for b in bList:
        ans = ans + str(b) +', '
    print ans[:-2]

def solveCase(case):
    N = case[0]
    barberList = case[1]
    bList = []
    tempLCM = 1
    for i in range(len(barberList)):
        bList.append(Barber(i+1, barberList[i]))
        tempLCM = lcm(tempLCM,barberList[i])
##    print 'lcm:',tempLCM
    temp = 0
    for i in range(len(barberList)):
        temp += tempLCM / barberList[i]
##    print 'total lcm:',temp
    
    heapq.heapify(bList)
    for i in range((N-1)%temp):
        nextB = heapq.heappop(bList)
        nextB.update()
##        print i, nextB
        heapq.heappush(bList, nextB)
##        print nextB, type(nextB)
##    printList(bList)
    answer = heapq.heappop(bList)
    return str(answer)

def solveAll(caseList):
    output = ''
    for j in range(len(caseList)):
        case = caseList[j]
        answer = solveCase(case)
        output +=  'Case #{0}: {1}\n'.format(j+1,answer[1])
    return output[:-1]

def writeOutput(fileName,output):
    f = open(fileName, 'w')
    f.write(output)

##inputFile = 'test.txt'
##outputFile = 'test_output.txt'

inputFile = 'B.txt'
outputFile = 'B_output.txt'

##inputFile = 'Bb.txt'
##outputFile = 'Bb_output.txt'

caseList = readFile(inputFile)
##print caseList
##print solveCase(caseList[0])

output = solveAll(caseList)
##print output

writeOutput(outputFile, output)

print 'Done!'
