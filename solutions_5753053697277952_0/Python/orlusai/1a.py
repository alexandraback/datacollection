letters = "ABCDEFGHIJKLMNOPQRSTUVWXYZ"

inFile = open("A-small-attempt0.in")
outFile = open("1.out", "w")

cases = int(inFile.readline().rstrip())
cnt = 1

while cnt<= cases:
    inFile.readline()
    inside = [int(val) for val in inFile.readline().rstrip().split()]
    print("Case #" + str(cnt) + ":", end="", file=outFile)
    while(sum(inside)>0):
        maxPartyNum = max(inside)
        maxPartyID = inside.index(maxPartyNum)
        maxPartyLetter = letters[maxPartyID]

        inside[maxPartyID] -= 1

        numInside = sum(inside)
        if(numInside > 0 and max(val/numInside for val in inside) > 0.5):
            maxPartyNum = max(inside)
            maxPartyID = inside.index(maxPartyNum)
            inside[maxPartyID] -= 1
            maxPartyLetter += letters[maxPartyID]

        numInside = sum(inside)
        if(numInside > 0 and max(val/numInside for val in inside) > 0.5):
            print("Ooo...")
            input()

        print(" " + maxPartyLetter, end="", file=outFile)

    if(cnt<cases):
        print("", file=outFile)

    cnt += 1

outFile.close()
