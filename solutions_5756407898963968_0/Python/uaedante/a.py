#!/usr/bin/python
import os, sys

fn = sys.stdin

total = int(fn.readline())

for case in range(1, total + 1):
    n1 = eval(fn.readline())
    for i in range(1, 5):
        xx = fn.readline().split()
        if i == n1:
            x = set(xx)
    n1 = eval(fn.readline())
    for i in range(1, 5):
        xx = fn.readline().split()
        if i == n1:
            y = set(xx)
    z = x.intersection(y)
    if len(z) == 0:
        print "Case #%d: Volunteer cheated!" % case
    elif len(z) > 1:
        print "Case #%d: Bad magician!" % (case)
    else:
        print "Case #%d: %d" % (case, eval(z.pop()))
        
