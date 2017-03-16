def dataParser(fileDir):
    inputfile = open(fileDir,'rU')
    nbrOfCases = int(inputfile.readline())
    cases = [None for i in range(nbrOfCases)]
    for i in range(nbrOfCases):
        inputfile.readline()
        tmp = inputfile.readline().split();
        cases[i] = [int(x) for x in tmp]
    inputfile.close()
    return cases

cases = dataParser('test.in')
outputFile = open('out.txt','w')
print cases
for i in range(len(cases)):
    x = cases[i]
    output = []
    while True:
        if max(x)>0:
            m = [k for k in range(len(x)) if x[k]==max(x)]
            if len(m)<=1 or (len(m)>2 and x[m[0]]==1):
                output.append(str(chr(m[0] + ord('A'))))
                x[m[0]] -= 1
            else:
                output.append(str(chr(m[0]+ord('A')))+str(chr(m[1]+ord('A'))))
                x[m[0]]-=1
                x[m[1]]-=1
        else:
            break
    outputFile.write('Case #' + str(i + 1) + ':')
    for k in range(len(output)):
        outputFile.write(' '+output[k])
    outputFile.write('\n')
outputFile.close()
