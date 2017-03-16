#!/usr/bin/env python


#f = open('magic-trick.in')
f = open('A-small-attempt0.in','r')
lines = f.readlines()
f.close()
tests = int(lines.pop(0).strip())

for test in range(tests):
    r1 = int(lines.pop(0).strip())
    c1 = []
    c2 = []
    for i in range(4):
        c1.append(lines.pop(0).strip().split(" "))
    r2 = int(lines.pop(0).strip())
    for i in range(4):
        c2.append(lines.pop(0).strip().split(" "))
    res = set(c1[r1-1]) & set(c2[r2-1])
    if (len(res)) == 1:
        print("Case #%s: %s" % (test+1, res.pop()))
    elif (len(res)) > 1:
        print("Case #%s: Bad magician!" % (test+1, ))
    elif (len(res)) == 0:
        print("Case #%s: Volunteer cheated!" % (test+1, ))