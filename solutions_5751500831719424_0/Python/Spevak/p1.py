import sys
        
if __name__ == "__main__":
    inFile = open(sys.argv[1], "r")
    outFile = open(sys.argv[2],"w")
    T = int(inFile.readline())
    for i in range(T):
        outFile.write("Case #" + str(i + 1) + ": ")
        N = int(inFile.readline())

        #basic character pattern (array of chars that differ from last)
        base = []

        #each element in repeatCounts is an array representing a string as a sequence of integers
        #the integer at an index is the number of times the character in base[index] is repeated in that string
        countsArray = []

        prevChar = None

        #treat first string as special case to build base array
        str1 = inFile.readline().strip('\n')
        counts = []
        for char in str1:
            if char != prevChar:
                base.append(char)
                counts.append(1)
                prevChar = char
            else:
                counts[len(counts)-1] += 1

        countsArray.append(counts)

        #now read the rest of the strings one at a time
        mismatch = False
        for j in range(N-1):
            s = inFile.readline().strip('\n')
            #don't need to do anything more than read the line if felga already won
            if mismatch:
                continue
            counts = []
            prevChar = None
            baseIndex = -1 #init to -1 so it will be incremented to 0 in first iteration of loop below
            for char in s:
                if char != prevChar:
                    baseIndex += 1
                    if baseIndex >= len(base):
                        mismatch = True
                        break
                    if char != base[baseIndex]:
                        mismatch = True
                        break
                    counts.append(1)
                    prevChar = char
                else:
                    counts[len(counts)-1] += 1
            if baseIndex != len(base) -1:
                mismatch = True

            countsArray.append(counts)
        #Felga won of any string doesn't match the base pattern
        if mismatch:
            outFile.write("Fegla Won\n")
            continue

        moveCount = 0
        for baseIndex in range(len(base)):
            countList = [counts[baseIndex] for counts in countsArray]
            countList = sorted(countList)
            #find median (if even size of list just take either of the "closest" integers)
            median = countList[len(countList)/2] #(integer division)
            for counts in countsArray:
                #move each string to the median
                moveCount += abs(counts[baseIndex] - median)

        outFile.write(str(moveCount) + '\n')
    
    inFile.close()
    outFile.close()
