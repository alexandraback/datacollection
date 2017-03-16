#!/usr/bin/env python3
T = int(input())

for case in range(1, T+1):
    print('Case #{}: '.format(case), end='')
    a = int(input())
    first = set()
    for i in range(4):
        l = {int(x) for x in input().split()}
        if i+1 == a:
            first = l
    b = int(input())
    second = set()
    for i in range(4):
        l = {int(x) for x in input().split()}
        if i+1 == b:
            second = l
    s = first & second
    if len(s) == 0:
        print('Volunteer cheated!')
    elif len(s) == 1:
        print(s.pop())
    else:
        print('Bad magician!')
