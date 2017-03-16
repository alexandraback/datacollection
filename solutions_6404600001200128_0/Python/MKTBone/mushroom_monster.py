#!/usr/bin/python
import sys

# Mushroom Monster

lines = [l.rstrip() for l in sys.stdin.readlines()]
for x in xrange(int(lines.pop(0))):
    m = [int(c) for c in lines[2*x+1].split(' ')]
    ds = [m[i-1] - m[i] for i in xrange(1, len(m))]
    big_d = max(ds)
    a = sum([d for d in ds if d > 0])
    b = sum([big_d if big_d < i else i for i in m[:-1]])
    print "Case #%u: %u %u" % (x + 1, a, b)
