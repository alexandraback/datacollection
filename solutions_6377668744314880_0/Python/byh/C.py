'''
Created on Apr 17, 2015

@author: billyanhuang
'''
import math

#fin = open('C.in', 'r')
#fout = open('C.out', 'w')
fin = open('C-small-attempt2.in', 'r')
fout = open('C-small-attempt2.out', 'w')

T = int(fin.readline())
for i in range(T):
    fout.write("Case #" + str(i+1) + ": \n")
    
    N = int(fin.readline())
    X = []
    Y = []
    for j in range(N):
        inp = fin.readline().split()
        X.append(int(inp[0]))
        Y.append(int(inp[1]))
        
    for j in range(N):
        angles = []
        for k in range(N):
            if k != j:
                angle = math.atan2(Y[k]-Y[j], X[k]-X[j])
                angles.append(angle/math.pi)
                angles.append(angle/math.pi + 2)
        angles.sort()
        
        minv = -1
        begin = 0
        end = 0
        while (begin < N-1) and (begin < len(angles)):
            while (end < len(angles)) and (angles[end] < angles[begin] + 1 - 0.00001):
                end += 1
            if ((end - begin) < minv) or (minv < 0):
                minv = end - begin
            begin += 1
        
        if minv < 0:
            minv = 1
        fout.write(str(minv-1) + "\n")
    
                