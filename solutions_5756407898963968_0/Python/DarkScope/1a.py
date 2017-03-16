import os
import sys
T=int(raw_input())
ele1=[]
ele2=[]
for i in range(T):
    ele1=[]
    ele2=[]
    p_1=0
    p_2=0
    p_1=int(raw_input())
    for j in range(4):
        ele1.append(raw_input().split(' '))
    p_2=int(raw_input())
    for j in range(4):
        ele2.append(raw_input().split(' '))
    ans=[]
    for ele in ele1[p_1-1]:
        if ele in ele2[p_2-1]:
            ans.append(ele)
    if len(ans)==1:
        print "Case #%d: %s"%(i+1,ans[0])
    elif len(ans)>1:
        print "Case #%d: Bad magician!"%(i+1)
    else:
        print "Case #%d: Volunteer cheated!"%(i+1)

    
