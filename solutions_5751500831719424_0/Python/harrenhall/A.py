#!/usr/bin/python

def appl(co,ii,N):
    #print 'lala', repr(co),ii,N
    su = 0
    for i in range(N):
        su += abs(co[i] - ii)
    #print su
    return su

def median(co,N):
    #print repr(co)
    co.sort()
    maxi = co[N-1]
    bestfound = 123456789
    for i in range(maxi+1):
        found = appl(co,i,N)
        if(found < bestfound):
            
            bestfound = found
            
    #print bestfound
    return bestfound

def doit():
    N=input()
    st = []
    for n in range(N):
        st.append(raw_input())
        
    #print repr(st)
    
    su=0
    while len(st[0]) > 0:
        nextc = st[0][0]
        co = []
        for n in range(N):
            coi = 0
            #print repr(st[n]), nextc
            while len(st[n]) > 0:
                if st[n][0] != nextc:
                    break
                coi +=1
                st[n] = st[n][1:]
            co.append(coi)
        #print repr(co)
        for n in range(N):
            if co[n] == 0:
                print "Fegla Won"
                return
        med = median(co,N)   
        #print 'laaa', med  
        su += med
    
    for n in range(N):
        if len(st[n]) > 0:
            print "Fegla Won"
            return
            
    print su

cases = input()
for case in range(1, cases+1):
    
    print ("Case #" + str(case) + ":"),
    
    doit()
    
        
