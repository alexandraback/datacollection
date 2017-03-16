#!/usr/bin/env python

import sys

T = int(sys.stdin.readline())

for case in range(1,T +1):
    row = int(sys.stdin.readline())
    for i in range(1,5):
        line = sys.stdin.readline()
        if i == row:
            candidates = [int(x) for x in line.split(" ")]
    row2 = int(sys.stdin.readline())
    for i in range(1,5):
        line = sys.stdin.readline()
        if i == row2:
            candidates2 = [int(x) for x in line.split(" ")]
    set1 = set(candidates)
    set2 = set(candidates2)
    intersect = set1.intersection(set2)
    count = len (intersect)
    if count > 1 :
        result = "Bad magician!"
    elif count == 1:
        result = intersect.pop()
    else:
        result = "Volunteer cheated!"

    print ("Case #{case}: {result}".format(case=case, result=result))
