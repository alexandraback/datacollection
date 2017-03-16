import sys


class Problem:
    def __init__(self, inputFileName, outputFileName):
        self.inputFile = open( inputFileName, "r" )
        self.outputFile = open( outputFileName, "w" )
        self.numSamples = int(self.inputFile.readline().replace("\n",""))
        self.resultList = []
        self.outputLines= []
    def printResult( self ):
        for i in range(0, self.numSamples):
            line = "Case #%d: %s"%(i+1,self.resultList[i])
            print line
            self.outputLines.append( line )

    def saveResult( self ):
        for line in self.outputLines:
            self.outputFile.write( line+"\n" )

    def getResult( self, first, second ):
        matchCount = 0
        theNumber = 0

        for elem in first:
            if elem in second:
                matchCount += 1
                theNumber = elem

        if matchCount == 1:
            return theNumber
        elif matchCount > 1:
            return "Bad magician!"
        else:
            return "Volunteer cheated!"
        
    def solve( self ):
        for i in range(0, self.numSamples):
            (first, second) = self.readSample()
            result = self.getResult( first, second )
            self.resultList.append( result )
        
        self.printResult()
        #self.testSampleOutput()
        self.saveResult()
        
    def readSample( self ):
        choose = int( self.inputFile.readline().replace("\n",""))
        row = []
        for i in range(0, 4):
            row.append(self.inputFile.readline().replace("\n","").split(' '))


        firstset = row[choose - 1]

        choose = int( self.inputFile.readline().replace("\n",""))
        row = []
        for i in range(0, 4):
            row.append(self.inputFile.readline().replace("\n","").split(' '))

        secondset = row[choose - 1]

        return ( firstset, secondset )

    def testSampleOutput( self ):
        sampleOutputFile = open( "output_sample.txt" )
        sampleResult = []

        result = True
        idx = 0
        for line in sampleOutputFile:
            line = line.replace("\n", "")
            result &= (line == self.outputLines[ idx ])
            idx += 1

        print result
    
def main():
    problem = Problem( sys.argv[1], "output.txt" )
    problem.solve()
    

    

if __name__ == "__main__":
    main()
