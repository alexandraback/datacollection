'''
Author: emmhaych
File Location: /home/emmhaych/Dev/CodeJam/2015/Round 1A/A/src/main.py
For license information please refer to LICENSE.txt in the root folder of this project
'''

''' Input/output file names '''
#fileName = 'test'                 # Test input file
fileName = 'A-small-attempt0'            # Small input file
#fileName = 'A-large-attempt0'            # Large input file

''' Program start location '''
def main():
    ''' Open input and output files '''
    inputFile = open('../inputFiles/' + fileName + '.in', 'r')
    outputFile = open('../outputFiles/' + fileName + '.out', 'w+')
    
    T = int(inputFile.readline())
    
    for currentT in range(T):
        N = int(inputFile.readline())
        
        plateStatus = list(map(int,inputFile.readline().rstrip().split())) 
        
        # First Solution (y)
        y = 0
        for currentTime in range(1, N):
            if(plateStatus[currentTime] < plateStatus[currentTime - 1]):
                y += plateStatus[currentTime - 1] - plateStatus[currentTime]
                
        # Second Solution (z)
        z = 0
        highestDrop = 0
        excess = 0
        for currentTime in range(1, N):
            if(plateStatus[currentTime] < plateStatus[currentTime - 1]):
                currentDrop = plateStatus[currentTime - 1] - plateStatus[currentTime]
                if highestDrop < currentDrop:
                    highestDrop = currentDrop
        for currentTime in range(N - 1):
            if(plateStatus[currentTime] < highestDrop):
                excess += highestDrop - plateStatus[currentTime]
        z = (highestDrop * (N - 1)) - excess
                   
        outputFile.write('Case #' + str(currentT + 1) + ': ' + str(y) + ' ' + str(z) + '\n')

if __name__ == '__main__':
    main()