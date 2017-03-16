import os

letters = ["A", "B", "C", "D", "E", "F", "G", "H", "I", "J", "K", "L", "M", "N", "O", "P", "Q",
    "R", "S", "T", "U", "V", "W", "X", "Y", "Z"]

def main():
    #generate()
    h = CodeJamHelper("A-large")

    n = h.nextInt()

    for x in range(n):
        nParties = h.nextInt();
        partyCounts = h.nextLineOfInts();
        h.output(process(nParties, partyCounts))


def process(nParties, partyCounts):
    if nParties == 2:
        #special case for two parties, just evac in tandem until there are no more
        return " ".join(["AB" for x in range(partyCounts[0])])

    evac = []
    while anyLeft(partyCounts):
        evacPerson = findWhichToEvac(nParties, partyCounts)
        partyCounts[evacPerson] = partyCounts[evacPerson] - 1
        evac.append(evacPerson)
    evacLetters = [letters[x] for x in evac]
    end = evacLetters[-2:]
    evacLetters = evacLetters[:-2]
    evacLetters.append("".join(end))
    return " ".join(evacLetters)

def findWhichToEvac(nParties, partyCounts):
    highest = 0
    party = -1
    for x in range(nParties):
        if(partyCounts[x] > highest):
            highest = partyCounts[x]
            party = x
    return party

def anyLeft(partyCounts):
    for item in partyCounts:
        if item != 0:
            return True
    return False



class CodeJamHelper:
    """Helper for the common things I do during Google Code Jam"""
    def __init__(self, baseFileName):
        self.ensureDirectory("./output")
        self.inFile = open("./input/" + baseFileName + ".in", "r")
        self.outFile = open("./output/" + baseFileName + ".out", "w")
        self.caseNum = 1

    def ensureDirectory(self, path):
        if not os.path.exists(path):
            os.makedirs(path)

    def output(self, value):
        print "Case #" + str(self.caseNum) + ": " + str(value)
        self.outFile.write( "Case #" + str(self.caseNum) + ": " + str(value) + "\n")
        self.caseNum = self.caseNum + 1

    def nextLine(self):
        return self.inFile.readline()[:-1] #strip the new line, it's bad

    def nextInt(self):
        return int(self.nextLine())

    def nextLineOfInts(self, delim=" "):
        line = self.nextLine()
        return [int(x) for x in line.split(delim)]

    def nextLineOfFloats(self, delim=" "):
        line = self.nextLine()
        return [float(x) for x in line.split(delim)]

    def nextDelimitedLine(self, delim=" "):
        return self.nextLine().split(delim)

    def nextDelimitedMatrix(self, x, y, delim=" "):
        matrix = []
        for _ in range(len(x)):
            line = self.nextLine()
            line = [item for item in line.split(delim)]
            if(len(line) != y):
                print "problem, matrix does not match specified dimensions"
            matrix.append(line)
        return matrix

    def nextCharMatrix(self, x, y):
        matrix = []
        for _ in range(len(x)):
            line = self.nextLine()
            line = [item for item in line]
            if(len(line) != y):
                print "problem, matrix does not match specified dimensions"
            matrix.append(line)
        return matrix

    def getStringMatrix(self, matrix, space=True):
        out = ""
        for line in matrix:
            out = out + "\n"
            for item in line:
                out = out + str(item)
                if(space):
                    out = out + " "
            if(space):
                out = out[:-1]
        return out

if __name__ == "__main__":
    main()
