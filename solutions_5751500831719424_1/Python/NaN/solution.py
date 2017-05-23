import sys

if len(sys.argv) == 1:
    print("No input file provided.")
    sys.exit()
else:
    filename = sys.argv[1]
    try:
        fileobject = open(filename, 'r')
    except:
        print("Failed to open given file.")
        sys.exit()
    try:
        firstLine = fileobject.readline()
    except:
        print("Failed to read first line.")
        sys.exit()
    datasetSize = int(firstLine)
    if not datasetSize:
        print("Unable to parse dataset size.")
        sys.exit()
    lineNr = 1
    for i in range(datasetSize):
        lineNr = lineNr + 1
        try:
            lineText = fileobject.readline()
        except:
            print("Failed to read line ", lineNr)
            sys.exit()
        stringCount = int(lineText[0:-1])
        strings = []
        for j in range(stringCount):
            lineNr = lineNr + 1
            try:
                lineText = fileobject.readline()
            except:
                print("Failed to read line ", lineNr)
                sys.exit()
            if lineText[-1] == "\n":
                textToParse = lineText[0:-1]
            else:
                textToParse = lineText
            strings.append(textToParse)
        stringsData = []
        for string in strings:
            oldCharacter = ""
            stringData = []
            for character in string:
                if character == oldCharacter:
                    stringData[-1]["length"] += 1
                else:
                    stringData.append({"character": character,
                                       "length": 1})
                    oldCharacter = character
            stringsData.append(stringData)
        possible = True
        # Check if sequences of different characters have same length in all strings,
        # else it's impossible to win.
        commonLength = len(stringsData[0])
        for j in range(1, len(stringsData)):
            if len(stringsData[j]) != commonLength:
                possible = False
                break
        if possible:
            # Check if all other strings have the same character sequence like the first one.
            for j in range(commonLength):
                character = stringsData[0][j]["character"]
                for stringData in stringsData:
                    if stringData[j]["character"] != character:
                        possible = False
                        break
                if not possible:
                    break
        if possible:
            # It's possible, calculate the minimum number of moves necessary.
            movesTotal = 0
            for j in range(commonLength):
                seqLengthMin = 0
                seqLengthMax = 0
                for stringData in stringsData:
                    # Get minimum and maximum of sequence of that character at that position.
                    if seqLengthMin == 0:
                        seqLengthMin = stringData[j]["length"]
                    elif stringData[j]["length"] < seqLengthMin:
                        seqLengthMin = stringData[j]["length"]
                    if stringData[j]["length"] > seqLengthMax:
                        seqLengthMax = stringData[j]["length"]
                charMoveMin = -1
                for currLength in range(seqLengthMin, seqLengthMax + 1):
                    charMoveCurrent = 0
                    for stringData in stringsData:
                        charMoveCurrent += abs(stringData[j]["length"] - currLength)
                    if charMoveMin == -1:
                        charMoveMin = charMoveCurrent
                    elif charMoveCurrent < charMoveMin:
                        charMoveMin = charMoveCurrent
                movesTotal += charMoveMin
            output = movesTotal
        else:
            output = "Fegla Won"
        if i == 0:
            startCharacter = ""
        else:
            startCharacter = "\n"
        print(startCharacter, "Case #", i+1, ": ", output, end="", sep="")
