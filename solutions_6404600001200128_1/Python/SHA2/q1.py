'''
Created on Apr 17, 2015

@author: Incognito
'''
T=int(raw_input())
for j in range(T):
    total=int(raw_input())
    list=map(int,raw_input().split(" "))
    sum1=0
    for i in range(total-1):
        if list[i+1]<list[i]:
            sum1+=list[i]-list[i+1]
    max=0
    for i in range(total-1):
        if list[i+1]<list[i]:
            if max< list[i]-list[i+1]:
                max=list[i]-list[i+1]
    
    sum2=0
    for i in range(total-1):
        if list[i]<max:
            sum2+=list[i]
        else:
            sum2+=max
    print "Case #"+`j+1`+":",sum1,sum2