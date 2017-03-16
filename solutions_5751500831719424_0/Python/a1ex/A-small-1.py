import sys, string
from copy import copy, deepcopy
import gmpy
import time

def readlist():
	return [int(x) for x in sys.stdin.readline().strip().split(" ")]

def readint():
	return int(sys.stdin.readline())

T = readint()

def uniq(s):
    prev = "?"
    d = ""
    for c in s:
        if c != prev:
            d += c
        prev = c
    return d

def makeid(a,b):
    i = 0
    j = 0
    u = ""
    a += "?"
    b += "?"
    cost = 0
    while 1:
        if i >= len(a) and j >= len(b):
            cost += len(a) - i + len(b) - j
            break
        if a[i] == b[j]:
            u += a[i]
            i += 1
            j += 1
        else:
            if a[i] == a[i-1]:
                i += 1
                cost += 1
            else:
                j += 1
                cost += 1
    return cost

for t in range(T):
    N = readint()
    strings = []
    for i in range(N):
        strings.append(sys.stdin.readline().strip())
    
    s1 = strings[0]
    s2 = strings[1]
    sc1 = uniq(s1)
    sc2 = uniq(s2)
    
    print ("Case #%d:" % (t+1)),
    #~ print >> sys.stderr, t

    if sc1 != sc2:
        print "Fegla Won"
    else:
        print makeid(s1,s2)
        #~ print strings
    
