#!/usr/bin/python

import sys

f = open(sys.argv[1])
o = open(sys.argv[2], 'w')
cases = int(f.readline())
for i in xrange(cases):
    first = int(f.readline())
    for j in range(4):
        row = map(int, f.readline().split())
        if j+1 == first:
            first_row = set(row)
    second = int(f.readline())
    for j in range(4):
        row = map(int, f.readline().split())
        if j+1 == second:
            second_row = set(row) 
    intersect = first_row.intersection(second_row)
    if len(intersect) == 1:
        o.write('Case #' + str(i+1) + ': ' + str(intersect.pop()) + '\n')
        continue
    elif len(intersect) == 0:
        o.write('Case #' + str(i+1) + ': Volunteer cheated!\n')
        continue
    elif len(intersect) >= 2:
        o.write('Case #' + str(i+1) + ': Bad magician!\n')
        continue
o.close()
print "Done, output written"
 
