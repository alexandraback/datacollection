#!/usr/bin/env python
import sys

case_num = 1
def printres(result):
    global case_num
    print "Case #%s: %s" % (case_num, result)
    case_num += 1

def readline(): 
    return sys.stdin.readline().rstrip('\n')
def splitline(f):
    return map(f, readline().split())

def can_be_served(time, btimes, N):
    count = 0
    for t in btimes:
        count += (time / t) + 1
    return count >= N

def calcplace(limit, times, N):
    last_served = 0
    for t in times:
        last_served += (limit - 1) / t + 1
    
    remaining = N - last_served
    for i in range(len(times)):
        if (limit % times[i]) == 0:
            remaining -= 1
        if remaining == 0:
            return i+1

def solve():
    B, N = splitline(int)
    times = splitline(int)

    maxlimit = 10**20
    minlimit = 0
    while (maxlimit > minlimit):
        average = (maxlimit + minlimit) / 2
        if can_be_served(average, times, N):
            maxlimit = average
        else:
            minlimit = average + 1
    
    place = calcplace(maxlimit, times, N)
    printres(place)

def main():
    for i in range(int(readline())): solve()

if __name__ == '__main__': 
    main()

