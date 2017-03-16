import math
import time
start_time = time.time()

f = open("A.txt",'r')
ntests = int(f.readline())

g = open("output.txt",'w')

for i in range(ntests):
    ##1
    line1 = int(f.readline())

    p=""
    for j in range(4):
        p = f.readline()

        if j+1==line1:
            tp = p
            
    tp = tp.split()


    ##2
    line2 = int(f.readline())

    q=""
    for j in range(4):
        q = f.readline()
        
        if j+1==line2:
            tq = q
            
    tq = tq.split()


    ##main

##    for j in range(4):
##        p[j] = int(p[j])
##        q[j] = int(q[j])


    guess = []    
    for j in range(16):
        if str(j+1) in tp and str(j+1) in tq:
            guess.append(j+1)

    
            
    
    if len(guess)==0:
        s = "Volunteer cheated!"
    elif len(guess)==1:
        s = guess[0]
    else: s = "Bad magician!"

    g.write("Case #{}: {}\n".format(i+1,s))
    
f.close()
g.close()

print (time.time() - start_time, "secs")
