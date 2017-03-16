import re
import math

inp=open("A-large.in","r")
outp=open("Al_oupt.txt","w")
lines = inp.readlines()
lines=[re.sub('\n','',line) for line in lines]

def red(s):
    let=''
    i=0
    ans=''
    while i<len(s):
        if let!=s[i]:
            let=s[i]
            ans+=s[i]
        i+=1
    return ans

def count(s,red):
    l=[0]
    i=0
    j=0
    while i<len(red) and j<len(s):
        if s[j]==red[i]:
            l[i]+=1
            j+=1
        else:
            i+=1
            l.append(0)
    return l

def dif(l,x):
    return sum(map(lambda i:abs(x-i),l))

def ans(l):
    reduced=red(l[0])
    for i in range(1,len(l)):
        if red(l[i])!=reduced:
            return "Fegla Won"
    array=[count(i,reduced) for i in l]
    b=[]
    for i in range(len(reduced)):
        st=[]
        for j in range(len(array)):
            st.append(array[j][i])
        b.append(st)
    return sum(map(lambda l:min([dif(l,x) for x in range(102)],),b))

k=int(lines.pop(0))

for i in range(k):
    a=int(lines.pop(0))
    l=[]
    for j in range(a):
        l.append(lines.pop(0))
    outp.write("Case #"+str(i+1)+": "+str(ans(l))+"\n")
outp.close()
