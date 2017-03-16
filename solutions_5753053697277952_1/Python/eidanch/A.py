# -*- coding: utf-8 -*-
"""
Created on Sun May  8 12:04:32 2016

@author: Eidan Cohen
"""

import string

def validate_state(state):
    return all(x >= 0 and x <= sum(state) - x for x in state)
    
def next_state(state, first, second=None):
    lst = list(state)
    lst[first] -= 1
    if second is not None:
        lst[second] -= 1
    return tuple(lst)

def choose_senators(state):
    for i in range(len(state)):
        if state[i] == 0:
            continue
        for j in range(len(state)):
            if state[j] == 0:
                continue
            candidate = next_state(state, i, j)
            if validate_state(candidate):
                #print(candidate,i,j)
                return (candidate, i,j)
    for i in range(len(state)):
        if state[i] != 0:
            candidate = next_state(state, i)
            if validate_state(candidate):
                #print(candidate,i,None)
                return (candidate, i, None)
            

def solve(state):
    result = ""
    while sum(state) > 0:
        state, i, j = choose_senators(state)
        result += string.ascii_uppercase[i]
        if j is not None: 
            result += string.ascii_uppercase[j]
        result += " "
    return result.rstrip()
def main():
    t = int(input())
    for i in range(1,t+1):
        n = int(input())
        state = tuple(int(x) for x in input().split(" "))
        print('Case #{0}: {1}'.format(i, solve(state)))

if __name__ == '__main__':
    main()

