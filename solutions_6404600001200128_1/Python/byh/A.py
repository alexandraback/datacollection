'''
Created on Apr 17, 2015

@author: billyanhuang
'''
from numpy import diff
fin = open('A-large.in', 'r')
fout = open('A-large.out', 'w')

T = int(fin.readline())
for i in range(T):
    N = int(fin.readline())
    inp = fin.readline().split()
    ver1 = 0
    rate = 0
    a = int(inp[0])
    for j in range(1, N):
        b = int(inp[j])
        if a > b:
            dif = a - b
            ver1 += dif
            if dif > rate:
                rate = dif
        a = int(inp[j])
    ver2 = 0
    for j in range(N-1):
        ver2 += min(rate, int(inp[j]))
    fout.write("Case #" + str(i+1) + ": " + str(ver1) + " " + str(ver2) + "\n")