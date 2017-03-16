#! /usr/bin/env python
#coding=utf-8
import string

f = open(r'e:\A-small-attempt3.in')
fw = open(r'e:\A-output2.txt','w')
def yasuo(stringa):
    stringb = ''
    char =stringa[:1]
    stringb +=char
    dict ={char:0}
    for i in range(len(stringa)):
        if(stringa[i]==char):
            dict[char] +=1
        else:
            char = stringa[i]
            dict [char]=1
            stringb +=char
    return (stringb,dict)

caseNum = string.atoi(f.readline())
for t in range(caseNum):
    length = string.atoi(f.readline())
    #print length,t
    list = []
    for i in range(length):
        list.append(f.readline().strip())
    compare ,dict0= yasuo(list[0])
    dictList=[]
    flag = True
    for i in list:
        stringb,dict= yasuo(i)
        if(stringb!=compare):
            fw.write('Case #%d: Fegla Won\n'%(t+1))
            flag = False
        else:
            dictList.append(dict)
    if(flag):
        dictCompare={}
        for i in range(len(compare)):
            list =[]
            for j in dictList:
                list.append(j[compare[i]])
            list.sort()
            dictCompare[compare[i]]=list[(len(list))/2]
        result =0
        for i in range(len(compare)):
                for j in dictList:
                    if j[compare[i]]>dictCompare[compare[i]]:
                        result += j[compare[i]]-dictCompare[compare[i]]
                    else:
                        result += dictCompare[compare[i]]-j[compare[i]]
        fw.write('Case #%d: '%(t+1))
        fw.write('%d\n'%result)
        
            
    
        
    
f.close()
fw.close()
