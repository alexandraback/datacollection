from copy import copy
import math
infile = open('B-small-attempt0 (1).in','r')
outfile = open('output.txt', 'w')

T = int(infile.readline().strip())
out = ""
for tc in range(T):
    out += "Case #"+str(tc+1)+": "
    
    #solution here
    B,N = infile.readline().strip().split()
    B=int(B)
    N=int(N)
    M = infile.readline().strip().split()
    minbarber = 0
    for i in range(len(M)):
        M[i] = int(M[i])
        if M[minbarber] > M[i]:
            minbarber = i
       # print("minbarber",minbarber)
    if N < B:
        out += str(N)
    else:
        # binary search number of minutes
        upperbound = N * M[minbarber]
        lowerbound = 0
        midpoint = (upperbound + lowerbound) // 2
        while True:
           # input()
         #   print(upperbound,  midpoint, lowerbound)
            ntotal = 0
            ready = []
            for i in range(len(M)):
                ntotal += math.ceil(midpoint / M[i])
                if midpoint % M[i] == 0:
                    ready.append(i)
          #  print(ntotal,ready)
            if ntotal >= N:
           #     print("go lower")
                upperbound = midpoint-1
                midpoint = (upperbound + lowerbound)//2
            elif ntotal+len(ready) < N:
           #     print("go higher")
                lowerbound = midpoint+1
                midpoint = (upperbound + lowerbound)//2
            else:
             #   print(N,ntotal)
                out += str(ready[N-ntotal-1]+1)
             #   print("solved: ",str(ready[N-ntotal-1]+1))
                break
    out += "\n"
    
print(out)
outfile.write(out)
    
outfile.close()
infile.close()