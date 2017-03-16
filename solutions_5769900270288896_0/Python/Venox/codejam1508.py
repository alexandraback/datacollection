# -*- coding: utf-8 -*-
"""
Created on Sat Apr 11 09:30:45 2015

@author: liujingjie
"""

import numpy as np


def judge(r,c,n):
    if n<=(r*c+1)/2:
        return 0
    total=(r-1)*c+(c-1)*r
    if n==r*c:
        return total
    rest=r*c-n
    if r==1 or c==1:
        return total-rest*2
    if rest<=((r-2)*(c-2)+1)/2:
        return total-4*rest
    if r*c==15 and rest<=4:
        return total-8-3*(rest-2)
    if r*c%2==1:
        if n<=(r*c+1)/2+r+c-2:
            return 3*(n-(r*c+1)/2)
        else:   
            return 3*(r+c-2)+4*(n-((r*c+1)/2+r+c-2))
    

    if n<=(r*c+1)/2+2:
        return 2*(n-(r*c+1)/2)
    elif  n<=(r*c+1)/2+r+c-2:
        return 4+3*(n-((r*c+1)/2+2))
    else:
        return 4+3*(r+c-4)+4*(n-((r*c+1)/2+r+c-2))
        
        
    

            
        
    
        
def reader(name):
    pf=open(name,'r')
    wf=open("ans",'w')
    t=int(pf.readline())
    for qq in xrange(t):

        ps=[int(x) for x in pf.readline().split(" ")]
        ans=judge(ps[0],ps[1],ps[2])
        anstr= "Case #"+str(qq+1)+": "+str(ans)
        print anstr
        anstr+='\n'
        wf.write(anstr)
    
    pf.close()
    wf.close()
    
    
reader('B-small-attempt1.in')