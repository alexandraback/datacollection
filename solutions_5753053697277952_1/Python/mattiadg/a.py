# -*- coding: utf-8 -*-
"""
Created on Sun May  8 08:50:28 2016

@author: mattia
"""
import numpy as np

def solve(N, P):
    parties = P
    tot = np.sum(parties)
    result = ""
    
    while tot > 0:
        first = np.argmax(parties)
        parties[first] -= 1
        tot -= 1
        result += chr(65 + first)
        if np.any(parties > (tot / 2)):
            second = np.argmax(parties)
            parties[second] -= 1
            tot -= 1
            result += chr(65 + second)
        result += " "
    return result

with open('A-large.in', 'r') as fin, open('../submission/a.out', 'w') as fout:
    T = int(fin.readline())
    for case in range(1,T+1):
        N = int(fin.readline())
        line = fin.readline().split()
        Ps = np.array(list(map(int, line)))
        
        fout.write('Case #' + str(case) + ': ' + solve(N, Ps) + "\n")