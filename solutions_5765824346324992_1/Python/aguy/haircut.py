# -*- coding: utf-8 -*-
"""
Created on Fri Apr 17 21:25:56 2015

@author: guy
"""

def totalPeople(time,barbers,b):
    return sum((time//barbers[i]+1) for i in range(b))
    
def answer(barbers,b,n):
    if n <= b:
        return n
    time = 1
    while totalPeople(time,barbers,b) < n:
        time *= 2
    lower = time//2
    upper = time
    while (upper-lower) > 1:
        middle = (upper+lower)//2
        if totalPeople(middle,barbers,b) < n:
            lower = middle
        else:
            upper = middle
    if totalPeople(lower,barbers,b) >= n:
        finalTime = lower
    else:
        finalTime = upper
    #print(finalTime)
    gap = n-totalPeople(finalTime-1,barbers,b)
    for i in range(b):
        if finalTime%barbers[i] == 0:
            gap -= 1
            if gap == 0:
                return i+1
                
                
def lcm(x, y):
   # credit to http://www.programiz.com/python-programming/examples/lcm

   # choose the greater number
   if x > y:
       greater = x
   else:
       greater = y

   while(True):
       if((greater % x == 0) and (greater % y == 0)):
           lcm = greater
           break
       greater += 1

   return lcm
                
def bruteForce(barbers,b,n):
    LCM = 1
    for barber in barbers:
        LCM = lcm(LCM,barber)
        #print(LCM)
    totalFree = sum(LCM//barber for barber in barbers)
    #print(LCM)'''
    n %= totalFree
    n += totalFree
    if n == 0:
        return b
    currentTimeBarber = [0]*b
    while True:
        for i in range(b):
            if currentTimeBarber[i] == 0:
                currentTimeBarber[i] += barbers[i]
                n-=1
                if n == 0:
                    return i+1
            currentTimeBarber[i] -= 1
    
                
for case in range(1,int(input().rstrip())+1):
    b,n = map(int,input().split())
    barbers = list(map(int,input().split()))
    #if bruteForce(barbers,b,n) != answer(barbers,b,n):
    #    print(barbers,n, bruteForce(barbers,b,n), answer(barbers,b,n))
    #print(case)
    print("Case #{0}: {1}".format(case,answer(barbers,b,n)))
        