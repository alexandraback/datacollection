#!/usr/bin/env python

def read_int():
    return int(raw_input())

def read_ints():
    return map(int, raw_input().split())

def read_grid():
    return [read_ints() for _ in xrange(4)]

t = read_int()

for caseno in xrange(1, t+1):
    ans1 = read_int() - 1
    arr1 = read_grid()
    ans2 = read_int() - 1
    arr2 = read_grid()
    opts = set(arr1[ans1]).intersection(arr2[ans2])
    result = opts.pop() if len(opts) == 1 else \
        ("Bad magician!" if len(opts) > 1 else "Volunteer cheated!")
    print "Case #%d: %s" % (caseno, result)
