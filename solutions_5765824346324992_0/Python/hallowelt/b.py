#!/usr/bin/python

import sys

def served(barbers, minutes):
    return sum(1+(minutes-1)/b for b in barbers)

def find_time(barbers, toserve):
    mintime = 1
    maxtime = toserve*barbers[0] + 1
    while mintime < maxtime:
        guess = (mintime + maxtime) / 2
        guesstime = served(barbers, guess)
        if guesstime < toserve:
            mintime = guess + 1
        elif guesstime > toserve:
            maxtime = guess - 1
        else:
            if served(barbers, guess + 1) == toserve:
                mintime = guess + 1
                #maxtime = guess - 1
            else:
                mintime = maxtime = guess
                break
    answer = mintime
    for time in range(max(mintime - 3, 0), mintime + 1):
        if served(barbers, time) == toserve:
            answer = time
        elif served(barbers, time) > toserve and served(barbers, time - 1) < toserve:
            answer = time - 1
    return answer

def find_place(barbers, place):
    admittime = find_time(barbers, place - 1)
    barbernum = place - served(barbers, admittime )
    for i,barber in enumerate([0] + barbers):
        if i == 0:
            continue
        if admittime % barber == 0:
            barbernum -= 1
            if barbernum == 0:
                return i
    return None

cases = int(sys.stdin.readline())

for casenum in range(1, cases+1):
    b, n = map(int, sys.stdin.readline().split())
    barbers = list(map(int, sys.stdin.readline().split()))
    print "Case #%s: %s" % (casenum, find_place(barbers, n))
