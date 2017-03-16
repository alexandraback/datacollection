#!/usr/bin/python

import sys

def Ni(): return tuple(map(int, sys.stdin.readline().split()))
def Ns(): return tuple(map(int, sys.stdin.readline().split()))

T = Ni()[0]
for t in range(1, T + 1):
    n = Ni()[0]
    w = []
    first = True

    answer = None
    lettercount = []
    for i in range(n):
        l = []
        s = sys.stdin.readline().strip()
        w.append(s)
        lcount = []
        for c in s:
            if len(l) == 0 or l[-1] !=c:
                l.append(c)
                lcount.append(1)
            else:
                lcount[-1] += 1

        lettercount.append(lcount)
        if first:
            letters = l
        else:
            if letters != l:
                answer = False
             
        first = False

    if answer == False:
        answer = "Fegla Won"
    else:
        answer = 0
        for i in range(len(lettercount[0])):
            col = [lettercount[j][i] for j in range(n)]
            col.sort()
            med = col[len(col)/2]
            #print "med", med
            #print "col", col
            answer += sum(abs(_v - med) for _v in col)

        #print letters
        #print w
        #print lettercount

    print "Case #%d: %s" % (t, answer)

