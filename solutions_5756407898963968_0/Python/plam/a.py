#!/usr/bin/python
import sys, collections

data = file(sys.argv[1]).read().splitlines()

T = int(data.pop(0))

for numcase in xrange(1,T+1):
    print 'Case #%d:' % numcase,
    A1 = int(data.pop(0))
    total = collections.defaultdict(int)
    grid1 = []
    for i in xrange(0,4):
        grid1.append(data.pop(0).split())
    for i in grid1[A1-1]:
        total[i] = total[i] + 1

    A2 = int(data.pop(0))
    grid2 = []
    for i in xrange(0,4):
        grid2.append(data.pop(0).split())
    for i in grid2[A2-1]:
        total[i] = total[i] + 1

    s = set()
    for i in total:
        if total[i] == 2:
            s.add(i)
    if len(s) == 1:
        print s.pop()
    elif len(s) == 0:
        print 'Volunteer cheated!'
    elif len(s) > 1:
        print 'Bad magician!'
    else:
        assert False

    

    

