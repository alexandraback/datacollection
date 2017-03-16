# -*- coding: utf-8 -*-
"""
Created on Sun May 08 11:11:35 2016

@author: Ghomam
"""

import sys

print sys.argv[1]
inp = open(sys.argv[1]).readlines()

#inp = ['1', '3', '3 2 2']

def raw_input():
    return inp.pop(0).strip()

# Read input data
T = int(raw_input())
tests = []
for i in xrange(T):
    N = int(raw_input().strip())
    S = [int(n) for n in raw_input().strip().split(' ')]
    time = (sum(S)+1)/2
    tests.append([N,S,time])

O = ['' for s in tests]
for i,(N,parties,time) in enumerate(tests):
    for t in xrange(time):
        O[i] += " " if t > 0 else ""
        for k in xrange(2):
            if k == 1 and sum(parties) % 2 == 0: continue
            j = parties.index(max(parties))
            parties[j] = max(0, parties[j]-1)
            a = chr(j+65)
            O[i] += a
        

# output
output = open('output.out', 'w')
for i,o in enumerate(O):
    out = 'Case #{}: {}'.format(i+1, o )
    print out
    if i > 0 : out = '\n'+out
    output.write(out)
output.close()