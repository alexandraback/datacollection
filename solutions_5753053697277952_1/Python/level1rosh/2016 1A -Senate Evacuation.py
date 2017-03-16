import string
inputName = 'A-large'

# Number to letter dict
num2alpha = dict(zip(range(0, 26), string.ascii_uppercase))

# Take input
infile = open(inputName + '.in', 'r')
lines = infile.readlines()
infile.close()

outfile = open(inputName + '-out.txt', 'w')

numTests = int(lines[0])
counter = 1
testNum = 1

while testNum <= numTests:
    # Parse input
    numParties = int(lines[counter])
    partyPop = [int(x) for x in lines[counter+1].split()]
    counter += 2
    result = ''

    # print(partyPop)

    # While there are still people inside, evac more
    while sum(partyPop) > 0:
        # Two options: evac 2 of the biggest party or one of each of the two biggest.
        # Find two biggest parties
        maxPartyCount = 0
        secondPartyCount = 0
        maxPartyIndex = 0
        secondPartyIndex = 0
        for x in range(len(partyPop)):
            if partyPop[x] >= maxPartyCount:
                secondPartyCount = maxPartyCount
                secondPartyIndex = maxPartyIndex
                maxPartyCount = partyPop[x]
                maxPartyIndex = x
            elif partyPop[x] >= secondPartyCount:
                secondPartyCount = partyPop[x]
                secondPartyIndex = x

            # partyPop[x] = 0


        # print("Two biggest parties are %s and %s of size %s and %s" % (maxPartyIndex, secondPartyIndex, maxPartyCount, secondPartyCount))

        # If two biggest parties same size, remove one of each
        if maxPartyCount == secondPartyCount and sum(partyPop) != 3:
            result += num2alpha[maxPartyIndex] + num2alpha[secondPartyIndex]
            partyPop[maxPartyIndex] -= 1
            partyPop[secondPartyIndex] -= 1
        elif partyPop[maxPartyIndex] >= 2 and sum(partyPop) - 2 >= 2*secondPartyCount:
            # Otherwise remove two from biggest party
            result += num2alpha[maxPartyIndex]*2
            partyPop[maxPartyIndex] -= 2
        else:
            # Just remove one from the biggest party to prevent [0 0 1] case from [1 1 1]
            result += num2alpha[maxPartyIndex]
            partyPop[maxPartyIndex] -= 1

        if sum(partyPop) != 0:
            result += ' '

        # print(result)
        # print(partyPop)

    # print(result)
    # print("-------------------------")
    # Write output
    outfile.write('Case #' + str(testNum) + ': ' + result)
    if testNum < numTests:
        outfile.write('\n')

    testNum += 1

outfile.close()
