import math
from operator import itemgetter

n = int(input())

def pgcd(a,b) :  
   while a%b != 0 : 
      a, b = b, a%b 
   return b

def ppcm (a,b):
    return (a * b) // pgcd(a,b)

def alg (b,v,m):
   # print("m=",m)
   # print("v=",v)
    pcm = m[0]
    for i in range(1,b):
        pcm = ppcm(pcm, m[i])

    nmod = 0
    for i in range(b):
        nmod += pcm // m[i] 

   # print("pcm=",pcm)
    #print("nmod=",nmod)
    v = ((v-1) % nmod) +1
    #print("v=",v)

    data = [[0,i] for i in range(b)]

    while v != 1:
        data[0][0] = m[data[0][1]]
        v -= 1

        data.sort(key=itemgetter(0,1))
        x = data[0][0]
        for i in range(b):
            data[i][0] -= x
            


    return data[0][1]
    



for i in range(n):
    b,n = [int(x) for x in input().split()]
    m   = [int(x) for x in input().split()]
    print ("Case #",i+1,": ",alg(b,n,m)+1,sep="")
    
