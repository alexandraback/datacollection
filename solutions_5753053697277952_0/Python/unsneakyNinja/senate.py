#!/usr/bin/python
import sys

def doStuff(string, array):
    max1 = 0
    max1pos = 0
    max2 = 0
    max2pos = 0
    for i in range(len(array)):
        if int(array[i]) > max1:
            max1 = int(array[i])
            max1pos = i
    for i in range(len(array)):
        if i != max1pos:
            if int(array[i]) > max2:
                max2 = int(array[i])
                max2pos = i
    #print "Maxes {0} {1}".format(max1, max2)
    retstring = ''
    for i in range(max1 - max2):
        retstring += chr(max1pos + ord('A')) + " "
    #retstring += (chr(max1pos + ord('A'))  + " " for i in range(max1 - max2))
    for i in range(int(string)):
        if i != max1pos and i != max2pos:
            for j in range(int(array[i])):
                retstring += chr(i + ord('A')) + " "
    for i in range(max2):
            retstring += chr(max1pos + ord('A')) + chr(max2pos + ord('A')) + " "
    return retstring



inputfile = open(sys.argv[1])
outputfilename = sys.argv[2] if len(sys.argv) > 2 else 'output.txt'
outputfile = open(outputfilename, 'w')
numlines = int(inputfile.readline())
for i in range(numlines):
    outputfile.write("Case #" + str(i+1) + ": "
            +doStuff(inputfile.readline().rstrip(),
                inputfile.readline().rstrip().split(" ")) + "\n")

