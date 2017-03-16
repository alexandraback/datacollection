f = open('A-small-attempt0.in', 'r')

output = ""



    

amountCases = int(f.readline())

for caseNumber in range(amountCases):
    possible = True
    netString = ""
    amountStrings = int(f.readline())
    strings = []
    lettersAmounts = []


    for a in range(amountStrings):

        
        lettersAmountAct = []
        lettersAmountAct.append(0)
        strings.append(f.readline().strip())
        netStringAct = strings[-1][0]



        for letter in strings[-1]:
            if letter != netStringAct[-1]:
                netStringAct += letter
                lettersAmountAct.append(1)
            else:
                lettersAmountAct[-1] += 1
        if netString == "":
            netString = netStringAct
        else:
            if netString != netStringAct:
                possible = False

                result = "Fegla Won"
            
        lettersAmounts.append(lettersAmountAct)

    "CALCULATION"
    
    if possible:
        result = 0
        for letterIndex in range(len(lettersAmounts[-1])):
            workList = [x[letterIndex] for x in lettersAmounts]  
            workList.sort()
            if workList[0] == workList[-1]:
                "OK with no steps"
                distance = 0
                pass
                
            else:
                "Which number has the least distances to it?"
                "Check out every possibele number:"
                distance = -1
                for n in range(workList[0],workList[-1]+1):
                    distanceAct = 0
                    for amount in workList:
                        distanceAct += abs(n-amount)
                    if distanceAct < distance or distance == -1:
                        distance = distanceAct
                result += distance
    result = str(result)
        

    

    
            
        
    
    


    output += "Case #" + str(caseNumber+1) + ": " + result + "\n"

f.close()

f = open('result.out', 'w')
f.write(output)
f.close()


