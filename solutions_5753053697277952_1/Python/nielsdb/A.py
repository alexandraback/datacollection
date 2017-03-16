#!/usr/bin/env python
# -*- coding: utf-8 -*-

alphabet = ["A", "B", "C", "D", "E", "F", "G", "H", "I","J","K",
            "L", "M", "N",
            "O", "P", "Q", "R","S","T","U","V","W","X","Y","Z"]

def maxIndex(counts):
    max = 0
    index = -1
    for i in range(len(counts)):
        if(counts[i] > max):
            max = counts[i]
            index = i
    return index

def nonZeroIndices(counts):
    indices = []
    for i in range(len(counts)):
        if(counts[i] > 0):
            indices.append(i)
        if(len(indices) == 2):
            break
    if len(indices) == 2:
        return indices[0], indices[1]
    return indices[0], indices[0]

def partiesLeft(counts):
    rv = 0
    for i in range(len(counts)):
        if counts[i] != 0:
            rv+=1
    return rv
if __name__ == "__main__":
    testcases = int(raw_input())
    for caseNr in xrange(1, testcases+1):
        nbParties = int(raw_input())
        counts = map(int, raw_input().split(" "))
        solution = ""
        while sum(counts) > 0:
            if partiesLeft(counts) == 2 and sum(counts)%2==0:
                p1, p2 = nonZeroIndices(counts)
                counts[p1]-=1
                counts[p2]-=1
                solution+=alphabet[p1]+alphabet[p2]
            else:
                e = maxIndex(counts)
                counts[e]-=1
                solution += alphabet[e]
            solution +=" "
        solution = solution[:-1]
        print("Case #%i: %s" % (caseNr, solution))