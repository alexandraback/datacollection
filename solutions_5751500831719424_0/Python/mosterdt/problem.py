def TR(inputfile, outputfile):
    print "bezig"
    inputdata = open(inputfile, "r")
    outputdata = open(outputfile, "w")
    T = int(inputdata.readline())
    for case in range(T):
        #read input
        TT = int(inputdata.readline())
        lijst = list()
        for geval in range(TT):
            lijst.append(converteerlijst(inputdata.readline().strip()))

        #probleem
        doenbaar = True
        totmoves = 0
        vorigelengte = len(lijst[0])
        for i in range(1,TT):
            if len(lijst[i]) != vorigelengte:
                doenbaar = False
                output = "Fegla Won"                
                break
        if doenbaar:
            
            for q in range(len(lijst[0])):
                vorigeletter = lijst[0][q][0]
                for i in range(len(lijst)):
                    if lijst[i][q][0] != vorigeletter:
                        doenbaar = False
                        output = "Fegla Won"                
                        break
        if doenbaar:
            getallen = list()
            for q in range(len(lijst[0])):
                getallen = list()
                for i in range(len(lijst)):
                    getallen.append(lijst[i][q][1])
                totmoves += minmoves(getallen)
            
            output = str(totmoves)

        print case,"----------------",output
        outputdata.write("Case #" + str(case+1) + ": " + output + "\n")
    inputdata.close()
    outputdata.close()
    print "done"

def minmoves(lstgetallen):
    kleinstemoves = None
    for i in lstgetallen:
        
        moves = 0
        for j in lstgetallen:
            moves += abs(i-j)
        if moves < kleinstemoves or kleinstemoves == None:
            kleinstemoves = moves
    return kleinstemoves

def converteerlijst(lijst):
    nieuwelijst = list()
    vorigeletter = None
    aantalletters = -1
    for letter in range(len(lijst)):
        if lijst[letter] != vorigeletter:
            nieuwelijst.append([lijst[letter][0],1])
            vorigeletter = lijst[letter]
            aantalletters += 1
        elif lijst[letter] == vorigeletter:
            nieuwelijst[aantalletters][1] += 1
    
    return nieuwelijst
