#!/usr/bin/python

import sys

def emit(text, *args):
    msg = text % args
    sys.stderr.write(msg)
    sys.stdout.write(msg)

def getline():
    return sys.stdin.readline().rstrip('\n')

ncases = int(getline())

rows = [1,2,3,4]

for casenr in range(1, ncases+1):
    a1 = int(getline())
    for i in rows:
        line = getline()
        if i == a1:
            cards = set([ int(s) for s in line.split() ])
    a2 = int(getline())
    for i in rows:
        line = getline()
        if i == a2:
            cards &= set([ int(s) for s in line.split() ])
    if not cards:
        answer = "Volunteer cheated!"
    elif len(cards) > 1:
        answer = "Bad magician!"
    else:
        answer = cards.pop()
    
    emit("Case #%d: %s\n", casenr, answer)
