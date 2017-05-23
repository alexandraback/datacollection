#!python3

inputFile = open("input.txt", "r")
outputFile = open("output.txt", "w")

testCases = int(inputFile.readline())

for testCase in range(1, testCases + 1):

    totalParties = int(inputFile.readline())

    partiesList = []
    totalMembers = 0

    print("Case #", testCase, ": ", sep="", end="", file=outputFile)

    inputStr = inputFile.readline()
    inputStr = inputStr.strip()
    inputList = inputStr.split()

    for partyIndex in range(0, totalParties):
        partyMember = int(inputList[partyIndex])
        totalMembers += partyMember
        partiesList.append([partyMember, chr(ord('A') + partyIndex)])

    while totalMembers > 0:

        partiesList.sort(reverse=True)

        if partiesList[0][0] == 1:
            count = 0
            for i in partiesList:
                if i[0] == 1:
                    count += 1
            if (count % 2) == 1:
                print(partiesList[0][1], sep="", end=" ", file=outputFile)
                partiesList[0] = [partiesList[0][0] - 1, partiesList[0][1]]
                totalMembers -= 1
                continue


        print(partiesList[0][1], partiesList[1][1], sep="", end=" ", file=outputFile)
        partiesList[0] = [partiesList[0][0] - 1, partiesList[0][1]]
        partiesList[1] = [partiesList[1][0] - 1, partiesList[1][1]]
        totalMembers -= 2

    print(' ', file=outputFile)

inputFile.close()
outputFile.close()
