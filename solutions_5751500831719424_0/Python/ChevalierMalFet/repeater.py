inputFile = open('A-small-attempt0.in', 'r')
outputFile = open('A-small-attempt0.out', 'w')

numTests = int(inputFile.readline())

# Only going to work for the two case for now
# Thinking maybe DP for the multistring case?
for i in range(numTests):
    numStrings = int(inputFile.readline())
    strings = []
    for j in range(numStrings):
        strings += [inputFile.readline()]

    s1 = strings[0]
    s2 = strings[1]

    i1 = 0
    i2 = 0

    count = 0
    print s1, s2
    while i1 < len(s1) and i2 < len(s2):
        if s1[i1] == s2[i2]:
            i1 += 1
            i2 += 1
        elif i1 == 0 and i2 == 0:
            count = -1
            break
        elif s1[i1] == s2[i2-1]:
            s1 = s1[:i1] + s1[i1+1:]
            count += 1
        elif s1[i1-1] == s2[i2]:
            s1 = s1[:i1] + s1[i1-1] + s1[i1:]
            count += 1
        else:
            count = -1
            break

    outputFile.write('Case #' + str(i+1) + ': ')
    if count == -1:
        outputFile.write('Fegla Won\n')
    else:
        outputFile.write(str(count)+'\n')

inputFile.close()
outputFile.close()
