T = int(input())
for testNo in range(T):
    howManyParties = input()
    howManyPolitics = list(map(int,input().split()))
    #map(int, howManyPolitics)
    total = sum(howManyPolitics)
    parties = {}
    results = []
    allChosen = []

    letter = ord('A') - 1
    for politic in howManyPolitics:
        letter += 1
        parties[chr(letter)] = int(politic)

    while total > 0:
        #print("Total: " + str(total))
        chosen = []
        total = 0
        for party in parties:
            total += parties[party]

        # choosing the first one
        firstOne = sorted(parties, key=parties.get)[-1]
        #print(parties[firstOne])
        chosen.append(firstOne)
        parties[firstOne] -= 1
        total -= 1

        # checking whether the second is possible
        secondOne = sorted(parties, key=parties.get)[-1]
        parties[secondOne] -= 1
        total -= 1

        maxPartySenators = 0
        
        for party in parties:
            if parties[party] > maxPartySenators:
                maxPartySenators = parties[party]

        if maxPartySenators <= total/2:
            chosen.append(secondOne)
            '''parties[secondOne] -= 1
            total -= 1'''

        else:
            parties[secondOne] += 1
            total += 1

        # passing the result
        allChosen.append(chosen)

    finalResult = ""
    for result in allChosen:
        for each in result:
            finalResult += each
        finalResult += " "

    print("Case #%i: %s" % (testNo+1, finalResult))