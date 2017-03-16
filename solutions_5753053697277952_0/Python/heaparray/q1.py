import math
import fractions

inFilePath =  'C:\\Users\\Orr\\Desktop\\CodeJam\\1C\\A-small.in'
outFilePath = 'C:\\Users\\Orr\\Desktop\\CodeJam\\1C\\A-small.out'
seperator = ' '

def parseFile(inFileName):
    inFile = open(inFileName)
    T = parseNum(inFile.readline())
    ProblemArr = []
    for k in range(T):
        N = parseNum(inFile.readline())
        parArr = parseVec(inFile.readline())
        ProblemArr.append(ProblemSet(parArr))
    inFile.close()
    return ProblemArr


class ProblemSet():
    def __init__(self,parArr):
        self.parArr = parArr

def solvePS(ps):
    parArr = ps.parArr
    out = []
    s = sum(parArr)
    while s > 0:
        maxInd = findMaxInd(parArr)
        if s==1 or s == 3:
            out.append(toChar(maxInd[0]))
            parArr[maxInd[0]] -= 1
            s -= 1
        elif len(maxInd) > 1:
            out.append(toChar(maxInd[0])+toChar(maxInd[1]))
            parArr[maxInd[0]] -= 1
            parArr[maxInd[1]] -= 1
            s -= 2
        else:
            out.append(toChar(maxInd[0]))
            parArr[maxInd[0]] -= 1
            s -= 1
    return ' '.join(out)

def toChar(ind):
    return chr(97+ind).upper()
        
def findMaxInd(arr):
    ind = []
    maxA = 0
    for i in range(len(arr)):
        if arr[i] > maxA:
            ind = [i]
            maxA = arr[i]
        elif arr[i] == maxA:
            ind.append(i)
    
    return ind
   
def parseNum(line):
    return int(line)

def parseVec(line):
    vecValues = line.split(seperator)
    return [int(value) for value in vecValues]

def psOutFormat(iterNum,res):
    return 'Case #{0}: {1}\n'.format(iterNum+1,res)
        
def writeToFile(results,outFileStr):
    outFile = open(outFileStr,'w')
    try:
        resultArr = [psOutFormat(i,results[i]) for i in range(len(results))]
        outFile.writelines(resultArr)
    finally:
        outFile.close()
    
def solveProblemSet():
    ps = parseFile(inFilePath)
    results = []
    for i in range(len(ps)):
        results.append(solvePS(ps[i]))
    writeToFile(results,outFilePath)
    print('done!')


solveProblemSet()
#ps = ProblemSet([24,97,2])
#print(solvePS(ps))
