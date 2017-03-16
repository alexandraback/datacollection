
infile = open("input.in")
lines = infile.read().split('\n')
numCases = int(lines[0])
lines = lines[1:]
#print numCases

infile.close()
outputFile = open('output.out','w')
def findCommonNumber(a,b):
    results = []
    for i in range(len(a)):
        for j in range(len(b)):
            if(a[i] == b[j]):
                results.append(a[i])
    return results


for i in range(numCases):
    data = lines[i*10:i*10+10]
    firstRow = int(data[0])
    secondRow = int(data[5])
    firstSetRow = map(int, data[firstRow].split(' '))
    secondSetRow = map(int, data[secondRow+5].split(' '))
    results = findCommonNumber(firstSetRow, secondSetRow)
    if (len(results) == 1):
        outputFile.write("Case #" + str(i+1) + ": " + str(results[0])+"\n")
    elif (len(results) == 0):
        outputFile.write("Case #" + str(i+1) + ": Volunteer cheated!"+"\n")
    else:
        outputFile.write("Case #" + str(i+1) + ": Bad magician!"+"\n")

outputFile.close()
