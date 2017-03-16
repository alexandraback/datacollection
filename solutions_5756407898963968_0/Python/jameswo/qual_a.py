input = open("A-small-attempt0.in","r")
inputlist = input.readlines()
input.close()
length = len(inputlist)
numberofplays = int(inputlist[0])
output = open("A-small-attempt0.out","w+")
case = 1
casepointer = 1

while (case <= numberofplays):
    firstrowlist2 = []
    secondrowlist2 = []
    
    firstrowstring = inputlist[casepointer + int(inputlist[casepointer])]
    #firstrowstring = inputlist[firstrow]
    firstrowlist = firstrowstring.split(" ")
    for s in firstrowlist:
        firstrowlist2.append(int(s)) #firstrowlist2 is list of elements in firstrow
        
    secondrowstring = inputlist[casepointer + 5 + int(inputlist[casepointer+5])]
    #secondrowstring = inputlist[int(secondrow)]
    secondrowlist = secondrowstring.split(" ")
    for s in secondrowlist:
        secondrowlist2.append(int(s)) #secondrowlist2 is list of elements in secondrow
    matches = []
    for element1 in firstrowlist2:
        for element2 in secondrowlist2:
            if element1 == element2:
                matches.append(element1)
    
    
    if len(matches) == 0:
        output.write("Case #{0}: Volunteer cheated!\n".format(case))
        case += 1
        casepointer +=10
        continue
    
    if len(matches) >= 2:
        output.write("Case #{0}: Bad magician!\n".format(case))
        case += 1
        casepointer +=10
        continue
    
    output.write("Case #{0}: {1}\n".format(case, matches[0]))
               
    case += 1
    
    casepointer += 10

output.close()
