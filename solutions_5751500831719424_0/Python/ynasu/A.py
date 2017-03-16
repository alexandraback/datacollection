#!/usr/bin/env python

def split(string):
    res = []
    last = ''
    for c in string:
        if c != last:
            last = c
            res.append([c, 1])
        else:
            res[-1][1] += 1
    return res

def solve(N, strings):
    items = [split(s) for s in strings]
    if len(set(tuple(s[0] for s in item) for item in items)) != 1:
        return 'Fegla Won'
    res = 0
    for i in xrange(len(items[0])):
        med = sorted(item[i][1] for item in items)[N / 2]
        res += sum(abs(item[i][1] - med) for item in items)
    return res

T = int(raw_input())
for x in xrange(1, T + 1):
    N = int(raw_input())
    strings = [raw_input() for i in xrange(N)]
    print 'Case #%d: %s' % (x, solve(N, strings))
