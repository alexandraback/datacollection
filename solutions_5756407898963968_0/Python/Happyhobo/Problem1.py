def read_words(afile):
    words = []
    for line in afile:
            words.append(line.strip())
    return words



filename = open('Tim.txt' , 'r')
T = filename.readline() #num test cases
aList = read_words(filename) # array where each element is a line of text

for i in range(int(T)):
    guess1 = aList[10*i]
    pCorrect = [] # potentially correct
    guessedLine = aList[i*10 + int(aList[i*10]) ]
    convert = guessedLine.split()
    for j in range(4):
        pCorrect.append( convert[j] )
        
    guess2 = aList[10*i + 5]
    FinalCorrect = []
    guessedLine2 = aList[i*10+5 + int(aList[i*10+5]) ]
    convert2 = guessedLine2.split()
    for j in range(4):
        for k in range(4):        
            if (convert2[j] == pCorrect[k]):
                FinalCorrect.append( convert2[j] )
    
    if ( len(FinalCorrect) == 1):
        print "Case #"+str(i+1)+": "+FinalCorrect[0]
    elif ( len(FinalCorrect) == 0):
        print "Case #"+str(i+1)+": Volunteer cheated!"
    else:
        print "Case #"+str(i+1)+": Bad magician!"