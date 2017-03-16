# -*- coding: utf-8 -*-
"""
Created on Fri Apr 17 20:47:19 2015

@author: guy
"""



for case in range(1,int(input().rstrip())+1):
    num = int(input().rstrip())
    line = list(map(int,input().split()))
    totalNumEaten = 0
    biggestRate = 0
    for i in range(len(line)-1):
        biggestRate = max(biggestRate,line[i]-line[i+1])
        totalNumEaten += max(0,line[i]-line[i+1])
    z = 0
    for i in range(len(line)-1):
        z += min(line[i],biggestRate)
    print("Case #{0}: {1} {2}".format(case,totalNumEaten,z))