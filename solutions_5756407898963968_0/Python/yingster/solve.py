#!/usr/bin/env python
import numpy as np
import sys

def solve(a,b):
    dupi = []
    for x in b:
        if x in a:
            dupi.append(x)
    if len(dupi)==0:
        return "Volunteer cheated!"
    if len(dupi)==1:
        return str(dupi[0])
    else:
        return "Bad magician!"

def get_line():
    row = int(sys.stdin.readline())
    for _ in range(row-1):
        sys.stdin.readline()
    set = map(int,sys.stdin.readline().strip().split())
    for _ in range(3-row+1):
        sys.stdin.readline()
    return set

numcase = int(sys.stdin.readline())
for casenum in range(1,numcase+1):
    set_a = get_line()
    set_b = get_line()
    print 'Case #' + repr(casenum)+': '+solve(set_a,set_b)
    
