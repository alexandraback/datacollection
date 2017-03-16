#!/usr/bin/python

import sys

f = sys.stdin

T = int(f.readline())

def readPossibilities(row):
    for i in range(1, 5):
        p = map(int, f.readline().split())
        if i == row:
            res = p
    return res



for index in range(1, T+1):
    row1 = int(f.readline())
    poss1 = readPossibilities(row1)

    row2 = int(f.readline())
    poss2 = readPossibilities(row2)
    
    common = filter(lambda e: e in poss2, poss1)
    
    if len(common) == 1:
        ans = common[0]
    elif len(common) == 0:
        ans = "Volunteer cheated!"
    else:
        ans = "Bad magician!"
    
    print("Case #{}: {}".format(index, ans))
