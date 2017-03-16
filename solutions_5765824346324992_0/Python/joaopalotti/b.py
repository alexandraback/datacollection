import numpy as np
import sys

#fin = sys.arg[1]
#fin = "./B-large.in"
fin = "B-small-attempt1.in"
#fin = "test.in"

with open(fin) as f:
    lines = f.readlines()

for case, ln in enumerate(range(1, len(lines), 2)):

    _, n = map(int, lines[ln].split())
    bs = map(int, lines[ln+1].split())

    right = (n+1) * max(bs)
    #right = 100000 * 100000000000
    left = 0
    chosen = 1
    mid = 0
    goal = n

    #print "Case", case + 1
    while left <= right:
        mid = (left + right) / 2
        k = 0
        for b in bs:
            k += ( int(mid/b) + 1)

        #print left, right, mid

        # im in the left
        if k >= goal:
            right = mid - 1
        elif k < n:
            left = mid + 1
        #print k, n

    #print "here", mid, "k", k, "n", n
    adjust = False
    while k <= n:
        adjust = True
        k = 0
        for b in bs:
            k += ( int(mid/b) + 1)
        if k == n:
            mid -= 1
            continue
        else:
            break
    if adjust:
        mid += 1

    already = 0
    poss = []
    for i, b in enumerate(bs):
        already += ( int((mid-1)/b) + 1)
        if mid%b == 0:
            poss.append(i + 1)

    chosen = poss[ (n - already) - 1 ]

    print "Case #%d: %d" % (case + 1, chosen)





