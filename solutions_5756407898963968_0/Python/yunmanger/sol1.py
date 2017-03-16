def sol1(a, b):
    a, b = set(a), set(b)
    r = a & b
    if len(r) > 1:
        return 'Bad magician!'
    if len(r) == 0:
        return 'Volunteer cheated!'
    return r.pop()

import sys
readline = sys.stdin.readline

tn = int(readline())
for i in xrange(1, tn + 1):
    an = int(readline()) - 1
    for j in xrange(4):
        line = readline()
        if j == an:
            a = line.split()
        
    bn = int(readline()) - 1
    for j in xrange(4):
        line = readline()
        if j == bn:
             b = line.split()
    print 'Case #{}: {}'.format(i, sol1(a, b))
