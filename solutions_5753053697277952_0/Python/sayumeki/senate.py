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
import copy

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
        linesInCase = 1
        
        for j in range(0, linesInCase):
            caseInput.append(lines[ln].strip())
            caseInput.append(lines[ln+1].strip())
            ln += 2
        #ln += 1 #skip blank line in input
        
        case = formatCaseInput(caseInput)
        output = getCaseOutput(case)
        
        print "Case #" + str(i+1) + ": " + output
        outFile.write("Case #" + str(i+1) + ": " + output + '\n')
        
    outFile.close()
        

def formatCaseInput(caseInput):
    line = caseInput[1]
    splitln = line.split(" ")

    case2 = [];
    for val in splitln:
        case2.append(int(val));

    case = case2
    #print case
    return case

def whileNotEmpty(case):
    for val in case:
        if val != 0:
            return True;
    return False;

def nonzeroValues(case):
    case2 = [];
    for val in case:
        if val != 0:
            case2.append(val);
    return case2;

def caseWithFirstCountRemoved(case, count):
    index = 0;
    letter = '?';
    newCase = [];
    while index < len(case):
        if case[index] == count and letter == '?':
            letter = chr(ord('A') + index)
            newCase.append(case[index]-1);
        else:
            newCase.append(case[index]);

        index += 1;
    return [newCase, letter];

def isValidCase(case):
    total = 0;
    for val in case:
        total += val;

    for val in case:
        if val*2 > total:
            return False;
        if val < 0:
            return False;
    return True;

def getCaseOutput(case):
    val = doCase(case)
    return str(val)

def doCase(stuff):
    print stuff;

    letters = [];

    while whileNotEmpty(stuff):
        sortedCase = nonzeroValues(sorted(stuff));
        sortedCase.reverse();

        lettersRemoved = [];

        if len(sortedCase) == 2:
            ok = caseWithFirstCountRemoved(stuff, sortedCase[0]);
            stuff = ok[0];
            lettersRemoved.append(ok[1]);
            
            ok = caseWithFirstCountRemoved(stuff, sortedCase[1]);
            stuff = ok[0];
            lettersRemoved.append(ok[1]);
        elif len(sortedCase) == 1:
            print "something is very wrong";
        else:
            place1 = sortedCase[0];
            place2 = sortedCase[1];

            test1 = copy.deepcopy(stuff);
            ok = caseWithFirstCountRemoved(test1, place1);
            test1 = ok[0];
            lettersRemoved.append(ok[1]);
            ok = caseWithFirstCountRemoved(test1, place1-1);
            test1 = ok[0];
            lettersRemoved.append(ok[1]);

            if isValidCase(test1) == False:
                lettersRemoved = [];
                test1 = copy.deepcopy(stuff);
                ok = caseWithFirstCountRemoved(test1, place1);
                test1 = ok[0];
                lettersRemoved.append(ok[1]);
                ok = caseWithFirstCountRemoved(test1, place2);
                test1 = ok[0];
                lettersRemoved.append(ok[1]);

                if isValidCase(test1) == False:
                    lettersRemoved = [];
                    test1 = copy.deepcopy(stuff);
                    ok = caseWithFirstCountRemoved(test1, place1);
                    lettersRemoved.append(ok[1]);

                    stuff = ok[0];

                else:
                    stuff = test1;
            else:
                stuff = test1;

        strn = "";
        for letter in lettersRemoved:
            strn += letter;
        letters.append(strn);

    return " ".join(letters);
    
runSolution(inputFile)
