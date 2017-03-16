#!/usr/bin/python
import sys
import math

[cases]=map(int,sys.stdin.readline().split());
for caseid in range(cases):
    [row1]=map(int,sys.stdin.readline().split());
    grid1=[];
    for i in range(4):
        grid1.append(map(int,sys.stdin.readline().split()));
    grid2=[];
    [row2]=map(int,sys.stdin.readline().split());
    for i in range(4):
        grid2.append(map(int,sys.stdin.readline().split()));
    set1=set(grid1[row1-1])
    set2=set(grid2[row2-1])
    set3=set1&set2
    if(len(set3)==0):
        result="Volunteer cheated!"
    elif(len(set3)==1):
        result=list(set3)[0]
    else:
        result="Bad magician!"
    print "Case #"+str(caseid+1)+":",result
