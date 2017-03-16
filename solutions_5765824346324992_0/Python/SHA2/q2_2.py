'''
Created on Apr 17, 2015

@author: Incognito
'''
import math
def gcd(a, b):
    while b:      
        a, b = b, a % b
    return a

def lcm(a, b):
    return a * b / gcd(a, b)

T=int(raw_input())
for j in range(T):
    total,position=map(int,raw_input().split(" "))
    list=map(int,raw_input().split(" "))
#     print total,position,list
    mylcm=1
    list2=[x for x in list]
    for i in range(total):
        mylcm=lcm(list[i],mylcm)
    for i in range(total):
        list[i]=mylcm/list[i]
    s=sum(list)
#     print "lcm",mylcm
#     print "s",s
    m=position % s
    time=0
    all=0
    index=0
#     print ",,",m
    if m == 0:
        mymax=0
        for i in range(total):
            if mymax<=list[i]:
                index=i
                mymax=list[i]
        index+=1
    else:
        while all!=m:
            for i in range(total):
                if time%list2[i]==0:
                    all+=1
                    index=i
                    if all==m:
                        break
            time+=1
    #     res=m % total
        index+=1
#     if res==0:
#         res=total
    print "Case #"+`j+1`+":",index
#     print mylcm
        
