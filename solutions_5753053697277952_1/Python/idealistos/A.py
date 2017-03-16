import os


def getResultMultiLine():
    pass

def getResult(counts):
    if len(counts) == 2:
        return " ".join(["AB" for i in range(counts[0])])
    else:
        s = sum(counts)
        r = []
        while s > 2:
            m = 0
            iMax = None
            for (i, c) in enumerate(counts):
                if c > m:
                    m = c
                    iMax = i
            r.append(chr(ord("A") + iMax))
            counts[iMax] -= 1
            s -= 1
            assert(s == sum(counts))
            for i in range(len(counts)):
                assert(counts[i] <= s / 2)
        i2 = [i for (i, c) in enumerate(counts) if c > 0]
        r.append(chr(ord("A") + i2[0]) + chr(ord("A") + i2[1]))
        return " ".join(r)

if __name__ == "__main__":
    folder = "D:\\Programming\\Java\\CodeJam3\\src\\shutovich\\"
    nameParts = ["A-test", "A-small-attempt0", "A-large"]
    namePart = None
    for namePart1 in nameParts:
        if os.path.exists(folder + namePart1 + ".in"):
            namePart = namePart1
            print "Using " + namePart
    lines = [s[:len(s) - 1] for s in open(folder + namePart + ".in", "r")]
    count = int(lines[0])
    resultLines = []
    iLine = 1
    
    multiLineResult = False
    
    for iTry in range(count):
        iLastResult = len(resultLines)
        if multiLineResult:
            resultLines.append("Case #" + str(iTry + 1) + ":")
            resultLines += getResultMultiLine()
        else:
            p = int(lines[iLine])
            counts = map(int, lines[iLine + 1].split())
            resultLines.append("Case #" + str(iTry + 1) + ": " + getResult(counts))
        for j in range(iLastResult, len(resultLines)):
            print resultLines[j]
        iLine += 2
    with open(folder + namePart + ".out", "wt") as oFile:
        for resultLine in resultLines:
            oFile.write(resultLine + "\n")