import os
import sys
import math

inf = open('input.in')
inp = inf.read().split('\n')
inf.close()

T = int(inp.pop(0))
outf = open('output','w')
for i in range(T):
    N = int(inp.pop(0))
    P = [int(x) for x in inp.pop(0).split(' ')]
    outf.write('Case #%d:'%(i+1))
    while sum(P) > 0:
        outf.write(' ')
        for j in range(N):
            if P[j] == max(P):
                break
        P[j] -= 1
        outf.write(chr(j+65))
        for j in range(N):
            if P[j] > sum(P)/2.0:
                outf.write(chr(j+65))
                P[j] -= 1
                break
    outf.write('\n')

outf.close()