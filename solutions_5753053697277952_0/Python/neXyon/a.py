#!/usr/bin/python3
# coding: utf-8

import sys
import numpy as np

def compute(party_members):
    result = []
    
    party_members = np.array(party_members)
    
    if np.sum(party_members) % 2 == 1:
        first = np.argmax(party_members)
        party_members[first] -= 1
        result.append((first,))
    
    while(np.sum(party_members) > 0):
        if np.max(party_members) > np.sum(party_members) / 2:
            print("WAAAH")
        
        first = np.argmax(party_members)
        party_members[first] -= 1

        second = np.argmax(party_members)
        party_members[second] -= 1
        
        result.append((first, second))
        
    result = ' '.join([''.join([chr(ord('A') + y) for y in x]) for x in result])
    
    return result

input_file = sys.stdin
output_file = sys.stdout

count = int(input_file.readline())

for i in range(count):
    input_line = input_file.readline()
    
    num_parties = int(input_line.strip())
    
    input_line = input_file.readline().strip()
    
    party_members = [int(x) for x in input_line.split(' ')]

    result = compute(party_members)
    
    result = 'Case #{0}: {1}\n'.format(i + 1, result)
    
    output_file.write(result)

