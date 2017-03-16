from math import ceil
from collections import Counter

f = open('A-small-attempt2.in', 'r')
o = open('out.txt', 'w')
T = f.readline()
T = int(T)
for t in range(1, T+1):
    s = f.readline()
    s = s[:-1]
    
    N = map(int, s)
    
    s = f.readline()
    s = s[:-1]
    s = s.split()
    P = map(int, s)

    ans = ""    

    total = sum(P)
    


    while total > 2: 
        m = max(P)
        ind = P.index(m)        
        P[ind] -= 1
        total -= 1
        ans += chr(65+ind)
        
        half = total/2.0
        for j in range(len(P)):
            if P[j] > half:
                m = max(P)
                ind = P.index(m)        
                P[ind] -= 1
                total -= 1
                ans += chr(65+ind)

        ans += " "

        half = total/2.0
        for j in P:
            if j > half:
                print j, t, P                
        
    for i in range(2):
        m = max(P)
        ind = P.index(m)
        P[ind] -= 1
        ans += chr(65+ind)
    
     
                     
    outline = "Case #%d: " % (t) + ans + "\n" 
    o.write(outline)

o.close()
