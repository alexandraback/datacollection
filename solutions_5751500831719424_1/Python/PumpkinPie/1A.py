from __future__ import division

import os
import os.path, time
import itertools



fo=open("A-large.in")
fw=open("A-large.txt","w")
'''fo=open("A-small-attempt3.in")
fw=open("A-small-attempt3.txt","w")'''
'''fo=open("test.txt")
fw=open("A-small-attem.txt","w")'''
c=int(fo.readline())
for p in range(0,c):
        Fegla=False
        n=int(fo.readline())
        strings=[]
        
        for i in range(0,n):
                strings.append(fo.readline().rstrip('\n'))
        #print strings
        ms=max(strings,key=len)
       
        actl=1
        word=ms[0]
        for j in range(0,len(ms)-1):
                if ms[j+1]!=ms[j]:
                        actl=actl+1
                        word=word+ms[j+1]
      
        
        Matrix = [[0 for x in xrange(actl)] for x in xrange(n)]
        for j in range(0,n):
                dis=strings[j]
                
                if dis[0]!=word[0]:
                        Fegla=True
                        break
                if dis[len(dis)-1]!=word[len(word)-1]:
                        Fegla=True
                        break
                if Fegla==True:
                        break
                m=0
                for k in range(0,len(word)):
                        c=word[k]
                        if dis[m]!=c:
                                Fegla=True
                                break
                        count=0
                        if m<len(dis):
                                while dis[m]==c:
                                        count=count+1
                                        
                                        m=m+1
                                        if m>len(dis)-1:
                                                break
                        Matrix[j][k]= count
        
        total=1000000               
        if Fegla==False:
                total=0
                for i in range(0,actl):
                        arr=[row[i] for row in Matrix]
                        arr=sorted(arr)
                        if arr[0]==0:
                                Fegla=True
                                break
                        old=10000
                        for j in range(0,len(arr)):
                                arrf=[arr[j] for x in range(len(arr))]
                                new=0
                                #print arr
                                #print arrf
                                for k in range(0,len(arr)):
                                        new=new+abs(arr[k]-arrf[k])
                                if new<old:
                                        old=new
                        total=total+old
                print total
                                        
        if Fegla==False:
                word=str(total)
        else:
                word="Fegla Won"
               
        
        fw.write("Case #"+ str(p+1)+": "+word+"\n")
                      
               
fw.close()

        
                





