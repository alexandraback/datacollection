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

def makeid(strings):
    ind = [0] * len(strings)
    u = ""
    cost = 0
    while 1:
        #~ print ind
        for i,s in zip(ind,strings):
            if i >= len(s):
                return cost

        allok = True
        for i,s in zip(ind,strings):
            if s[i] != strings[0][ind[0]]:
                allok = False
                break
        #~ print allok, strings[0][ind[0]]
        if allok:
            u += strings[0][ind[0]]
            ind = [x+1 for x in ind]
        else:
            costx = len(strings)
            for k in range(len(strings)):
                s = strings[k]
                i = ind[k]
                #~ print s, i, s[i] == s[i-1]
                if s[i] == s[i-1]:
                    ind[k] += 1
                    costx -= 1

            cost += min(costx,len(strings)-costx)
            #~ print cost
    return cost

for t in range(T):
    N = readint()
    strings = []
    for i in range(N):
        strings.append(sys.stdin.readline().strip() + "$")
    
    suniq = []
    for s in strings:
        suniq.append(uniq(s))
    
    print ("Case #%d:" % (t+1)),
    #~ print >> sys.stderr, t

    nope = False
    for su in suniq:
        if su != suniq[0]:
            nope = True
    if nope:
        print "Fegla Won"
        continue
    
    print makeid(strings)
