# -*- coding: utf-8 -*-

# just copy a whole bunch of these just in case
import time
import sys, traceback, ast
import fileinput
import os
import re
import httplib
import codecs
import HTMLParser
import math
import operator

inputFile = "A-small-attempt0.in"

outputFile = "output.txt"
outFile = open(outputFile, mode='w')

def runSolution(inFile):
    
    lines = open(inFile, mode='r').readlines()
    ln = 0 #ln = line number
    
    cases = int(lines[ln])
    ln += 1
    for i in range(0, cases):
        caseInput = []
        linesInCase = 2
        
        for j in range(0, linesInCase):
            caseInput.append(lines[ln].strip())
            ln += 1
        #ln += 1 #skip blank line in input
        
        case = formatCaseInput(caseInput)
        output = getCaseOutput(case)
        
        print "Case #" + str(i+1) + ": " + output
        outFile.write("Case #" + str(i+1) + ": " + output + '\n')
        
    outFile.close()
        

def formatCaseInput(caseInput):
    line = caseInput[1]
    splitln = line.split(" ")
    mushes = [];
    for thing in splitln:
        mushes.append(int(thing));

    case = []
    case.append(mushes)
    #print case
    return case

def getCaseOutput(case):
    val = doCase(case)
    return str(val)

def doCase(stuff):
    mush = stuff[0];
    #print str(mush)

    minMushA = 0;
    for i in range(1, len(mush)):
        prev = mush[i-1];
        now = mush[i];
        if (now < prev):
            minMushA += prev - now;

    minMushB = 0;
    sharpestDecline = 0;
    for i in range(1, len(mush)):
        prev = mush[i-1];
        now = mush[i];
        if (now < prev):
            decline = prev - now;
            if decline > sharpestDecline:
                sharpestDecline = decline;

    for i in range(1, len(mush)):
        prev = mush[i-1];
        if (prev >= sharpestDecline):
            minMushB += sharpestDecline;
        else:
            minMushB += prev;

    return str(minMushA) + " " + str(minMushB);
    
runSolution(inputFile)
