#!/usr/bin/python

import sys

cases = None
is_count = True
for i, line in enumerate(sys.stdin):
    line = line.strip()

    if cases is None:
        cases = int(line)
        continue

    if is_count:
        is_count = False
        continue
    else:
        is_count = True

    mushrooms = [int(m) for m in line.split()]

    max_diff = 0
    prev = None
    total_1 = 0
    for m in mushrooms:
        if prev == None:
            prev = m
            continue
        total_1 += max(0, prev - m)
        if prev > m:
            max_diff = max(max_diff, prev - m)
        prev = m

    prev = None
    total_2 = 0
    for m in mushrooms:
        if prev == None:
            prev = m
            continue
        total_2 += min(prev, max_diff)
        prev = m

    print 'Case #%d: %d %d' % (i / 2, total_1, total_2)
