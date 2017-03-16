'''
Author: emmhaych
File Location: /home/emmhaych/Dev/CodeJam/2015/Round 1A/C/src/main.py
For license information please refer to LICENSE.txt in the root folder of this project
'''
from threading import currentThread

''' Input/output file names '''
#fileName = 'test'                 # Test input file
fileName = 'C-small-attempt0'            # Small input file
#fileName = 'C-large-attempt0'            # Large input file

''' Program start location '''
def main():
    ''' Open input and output files '''
    inputFile = open('../inputFiles/' + fileName + '.in', 'r')
    outputFile = open('../outputFiles/' + fileName + '.out', 'w+')

    T = int(inputFile.readline())
    
    for currentT in range(1, T + 1):
        N = int(inputFile.readline()) # number of trees
        trees = []
        for currentTree in range(N):
            trees.append(list(map(int, inputFile.readline().strip().split())))
        finalResult = []
        for currentTree in range(N):
            result = N
            x = trees[currentTree][0]
            y = trees[currentTree][1]
            # > x
            num = 0
            for currentTree2 in range(N):
                if trees[currentTree2][0] > x:
                    num += 1
            if num < result:
                result = num
            # < x
            num = 0
            for currentTree2 in range(N):
                if trees[currentTree2][0] < x:
                    num += 1
            if num < result:
                result = num
            # > y
            num = 0
            for currentTree2 in range(N):
                if trees[currentTree2][1] > y:
                    num += 1
            if num < result:
                result = num
            # < y
            num = 0
            for currentTree2 in range(N):
                if trees[currentTree2][1] < y:
                    num += 1
            if num < result:
                result = num
            # <= x & <= y
            num = 0
            for currentTree2 in range(N):
                if (trees[currentTree2][0] <= x) and (trees[currentTree2][1] <= y) and (currentTree != currentTree2):
                    num += 1
            if num < result:
                result = num
            # <= x & >= y
            num = 0
            for currentTree2 in range(N):
                if (trees[currentTree2][0] <= x) and (trees[currentTree2][1] >= y) and (currentTree != currentTree2):
                    num += 1
            if num < result:
                result = num
            # >= x & <= y
            num = 0
            for currentTree2 in range(N):
                if (trees[currentTree2][0] >= x) and (trees[currentTree2][1] <= y) and (currentTree != currentTree2):
                    num += 1
            if num < result:
                result = num
            # >= x & >= y
            num = 0
            for currentTree2 in range(N):
                if (trees[currentTree2][0] >= x) and (trees[currentTree2][1] >= y) and (currentTree != currentTree2):
                    num += 1
            if num < result:
                result = num
                
            finalResult.append(result)
        outputFile.write('Case #' + str(currentT) + ': ' + '\n')
        for currentTree in range(N):
            outputFile.write(str(finalResult[currentTree]) + '\n')

if __name__ == '__main__':
    main()