
def readFile(fileName):
    f = open(fileName)
    caseList = []
    index = 0
    for line in f:
        index += 1
        content = line.split()
        if index == 1:
            print content[0],'test cases are read.'
        elif len(content) > 1:
            caseList.append([])
            for i in range(len(content)):
                caseList[-1].append(int(content[i]))
    f.close()
    return caseList

def solveCase(case):
    answer1 = 0
    answer2 = 0
    maxDiff = -1
    for i in range(len(case)-1):
        if case[i+1] <= case[i]:
            diff = case[i]-case[i+1]
            answer1 += diff
            if diff > maxDiff:
                maxDiff = diff
    speed = maxDiff
    for i in range(len(case)-1):
        answer2 += min(speed, case[i])
    return answer1, answer2

def solveAll(caseList):
    output = ''
    for j in range(len(caseList)):
        case = caseList[j]
        answer1, answer2 = solveCase(case)
        output +=  'Case #{0}: {1} {2}\n'.format(j+1,answer1,answer2)
    return output[:-1]

def writeOutput(fileName,output):
    f = open(fileName, 'w')
    f.write(output)

##inputFile = 'test.txt'
##outputFile = 'test_output.txt'

inputFile = 'A.txt'
outputFile = 'A_output.txt'

##inputFile = 'Ab.txt'
##outputFile = 'Ab_output.txt'

caseList = readFile(inputFile)
##print caseList

output = solveAll(caseList)
##print output

writeOutput(outputFile, output)

print 'Done!'
