# -*- coding: utf-8 -*-
"""
Created on Fri Apr 17 23:01:16 2015

@author: guy
"""

#import numpy as np

def lineSideAbove(point1,point2,pointSide):
    #credit http://stackoverflow.com/questions/1560492/how-to-tell-whether-a-point-is-to-the-right-or-left-side-of-a-line
    x =  (point2[0]-point1[0])*(pointSide[1]-point1[1]) - (pointSide[0]-point1[0])*(point2[1]-point1[1])
    if x > 0: return 1
    return 0
    
def lineSideBelow(point1,point2,pointSide):
    #credit http://stackoverflow.com/questions/1560492/how-to-tell-whether-a-point-is-to-the-right-or-left-side-of-a-line
    x =  (point2[0]-point1[0])*(pointSide[1]-point1[1]) - (pointSide[0]-point1[0])*(point2[1]-point1[1])
    if x < 0: return 1
    return 0
    
for case in range(1,int(input().rstrip())+1):
    n = int(input().rstrip())
    points = []
    for i in range(n):
        points.append(list(map(int,input().split())))
    print("Case #{0}:".format(case))
    if n == 1:
        print(0)
    else:
        for i in range(n):
            #i is index of main point
            best = n
            for a in range(n):
                if points[i] != points[a]:
                    best = min(best,sum(lineSideAbove(points[i],points[a],point) for point in points))
                    best = min(best,sum(lineSideBelow(points[i],points[a],point) for point in points))
            print(best)
            
                
        