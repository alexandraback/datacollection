#!/usr/bin/env python
import numpy as np
import sys
import pdb
import math

sys.setrecursionlimit(1500)


def solve(strings):
    indexs = len(strings[0])
    changes = 0
    for i in range(indexs):
        myletter = strings[0][i][0]
        myblock = []
        for string in strings:
            if len(string)!=indexs:
                return "Fegla Won"
            currentblock = string[i]            
            if currentblock[0] != myletter:
                return "Fegla Won"
            else:
                myblock.append(len(currentblock))
        best = 99999999999999
        for i in range(min(myblock), max(myblock)+1):
            currentmove = 0 
            for currentlen in myblock:
                currentmove += abs(currentlen-i)
            if currentmove < best:
                best = currentmove
        changes += best

    return changes
            
        

def processstring(string):
    string = list(string)
    returnstring = []
    i = -1
    current = ""
    while len(string)>0:
        new = string.pop()
        if new == current:
            returnstring[i]+=new
        else:
            current = new
            returnstring.append(new)
            i += 1
    return returnstring
numcase = int(sys.stdin.readline())
for casenum in range(1,numcase+1):
    line = sys.stdin.readline().split()
    N = int(line[0])
    strings = []
    for _ in range(N):
        strings.append(processstring(sys.stdin.readline().strip()))
    print 'Case #' + repr(casenum)+': '+ str(solve(strings))
    
