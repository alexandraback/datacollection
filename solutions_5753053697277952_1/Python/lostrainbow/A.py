# -*- coding: utf-8 -*-
"""
Created on Thu Apr  7 19:21:59 2016

@author: Benben
"""

import heapq

def myplan(remain):
    res=' '
    cur=heapq.heappop(remain)
    res+=cur[1]
    cur[0]+=1
    if cur[0]!=0:
        heapq.heappush(remain,cur)
    if remain:
        cur=heapq.heappop(remain)
        res+=cur[1]
        cur[0]+=1
        if cur[0]!=0:
            heapq.heappush(remain,cur)
    return res
    
def preplan(remain):
    res=' '
    cur=heapq.heappop(remain)
    res+=cur[1]
    cur[0]+=1
    if cur[0]!=0:
        heapq.heappush(remain,cur)
    return res
    
        
    


def sol(IF):
    N=int(IF.readline())
    temp=IF.readline().split()
    remain=[]
    plan=''
    remainN=0
    for i in range(N):
        heapq.heappush(remain,[0-int(temp[i]),chr(65+i)])
        remainN+=int(temp[i])
    if remainN%2==1:
        plan+=preplan(remain)
    while remain:
        plan+=myplan(remain)
    return plan
        
    
    
          



IF=open('A-large.in','r')
OF=open('A-large-output','w')
CaseN=int(IF.readline())
for i in range(1, CaseN+1):
    pretext='Case #{}:'.format(i)
    ans=sol(IF)
    if i<CaseN:
        ans=ans+'\n'
    OF.write(pretext+ans)
    
    
    
IF.close()
OF.close()


            
            