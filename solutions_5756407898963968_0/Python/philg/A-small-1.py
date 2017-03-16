#!/usr/bin/python

import sys

PROBLEM=int(sys.stdin.readline())

for i in range(PROBLEM):
    boards=[[],[]]
    status='.'
    chosenRow=[]
    matches=[]
    for round in range(2):
        chosenRow.append(int(sys.stdin.readline())-1)
        for rowNo in range(4):
            boards[round].append([int(card) for card in sys.stdin.readline().split(" ")])
    for card1 in boards[0][chosenRow[0]]:
        for card2 in boards[1][chosenRow[1]]:
            if card1 == card2:
                matches.append(card1)
    if len(matches) == 0:
        print("Case #%s: Volunteer cheated!"%(i+1))
    elif len(matches) == 1:
        print("Case #%s: %s"%((i+1),matches[0]))
    elif len(matches) >= 2:
        print("Case #%s: Bad magician!"%(i+1))

