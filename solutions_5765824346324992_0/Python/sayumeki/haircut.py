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

inputFile = "B-small-attempt1.in"

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
    line = caseInput[0]
    splitln = line.split(" ")
    b = int(splitln[0])
    n = int(splitln[1])
    barbers = caseInput[1].split(" ")
    newBarbers = []
    for barb in barbers:
        newBarbers.append(int(barb));

    case = []
    case.append(b)
    case.append(n)
    case.append(newBarbers);
    #print case
    return case

def getCaseOutput(case):
    val = doCase(case)
    return str(val)

def doCase(stuff):
    lifeHacked = 0;

    barberTimes = stuff[2];
    n = stuff[1];
    #print "barbers : " + str(barberTimes);
    #print "people : " + str(n);

    barbers = [];
    for barb in barberTimes:
        barbers.append(0); #no wait for anyone
    
    curCustomer = 1;
    while True:
        for i in range(0, len(barbers)):
            if barbers[i] == 0:
                curCustomer += 1;
                if (curCustomer == n + 1): # this is you
                    return (i+1); 
                barbers[i] = barberTimes[i];

        timePassed = min(barbers);
        for i in range(0, len(barbers)): # elapse one minute
            barbers[i] -= timePassed;

        if max(barbers) == 0 and lifeHacked == 0:
            lifeHacked = 1;
            #modul = curCustomer;
            #while (curCustomer < n):
            #    curCustomer += modul;
            n = n % (curCustomer-1); # shaky as hell
            if (n == 0):
                n = curCustomer-1;
            curCustomer = 1;

    return "???"
    
runSolution(inputFile)
