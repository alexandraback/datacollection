#!/usr/bin/env python3

def read():
    return [[int(x) for x in input().split()] for i in range(4)]

T = int(input())
for test in range(T):
    num1 = int(input()) - 1
    set1 = set(read()[num1])
    num2 = int(input()) - 1
    set2 = set(read()[num2])
    possible = set1 & set2
    if len(possible) == 1:
        answer = min(possible)
    elif len(possible) > 1:
        answer = "Bad magician!"
    else:
        answer = "Volunteer cheated!"    
    print("Case #{}:".format(test+1), answer)

    
