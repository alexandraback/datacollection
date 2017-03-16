#1/usr/bin/py


import os
import sys
from talloc import total_blocks

fin = open("A-large.in", "r")
fout = open("a-large.out", "w")

T = int(fin.readline().strip())
for t in xrange(0,T):
    N = int(fin.readline().strip());
    m = [int(x) for x in fin.readline().strip().split(' ')];

    eaten = 0
    for i in xrange(0,N-1):
        if m[i+1] < m[i]:
            eaten += m[i] - m[i+1]

    # second method
    eaten_two = 0
    min_rate = 0
    tot = m[0]
    for i in xrange(0,N-1):
        if m[i+1] < m[i]:
            if min_rate < m[i] - m[i+1]:
               min_rate =  m[i] - m[i+1]

    for i in xrange(0,N-1):
        if m[i] < min_rate:
            eaten_two += m[i]
        else:
            eaten_two += min_rate


    print "Case #{}: {} {}".format(t+1, eaten, eaten_two)
    fout.write("Case #{}: {} {}\n".format(t+1, eaten, eaten_two))
