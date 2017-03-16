import numpy as np
import sys

#fin = sys.arg[1]
fin = "./A-large.in"
#fin = "A-small-attempt0.in"
#fin = "test.in"

with open(fin) as f:
    lines = f.readlines()

for case, ln in enumerate(range(1, len(lines), 2)):

    d = lines[ln]
    mush = map(int, lines[ln+1].split())

    total1 = 0
    total2 = 0

    min_diff = 100000
    last = mush[0]
    for m in mush[1:]:
        if m < last:
            total1 += (last - m)
        diff = (m - last)
        if diff < min_diff:
            min_diff = diff
        last = m

    min_diff = abs(min_diff)
    for m in mush[:-1]:
        if m > min_diff:
            total2 += min_diff
        else:
            total2 += m

    print "Case #%d: %d %d" % (case + 1, total1, total2)





