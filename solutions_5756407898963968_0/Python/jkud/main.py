#!/usr/bin/env python

T = int(raw_input().strip())
for t in range(T):
    r1 = int(raw_input().strip())
    t1 = [[int(i) for i in raw_input().strip().split()] for _ in range(4)]
    r2 = int(raw_input().strip())
    t2 = [[int(i) for i in raw_input().strip().split()] for _ in range(4)]
    chosen = set(t1[r1-1]) & set(t2[r2-1])
    if len(chosen) == 1:
        print 'Case #%d: %d' % (t+1, list(chosen)[0])
    elif len(chosen) > 1:
        print 'Case #%d: Bad magician!' % (t+1)
    else:
        print 'Case #%d: Volunteer cheated!' % (t+1)
