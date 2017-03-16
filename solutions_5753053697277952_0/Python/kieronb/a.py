#!/usr/bin/python

import sys
import logging

logging.basicConfig(stream=sys.stderr, level=logging.DEBUG)

def solve(counts, res):
    total = sum(counts)
    if total == 0:
        return res

    max_idx1 = get_max_idx(counts)
    counts[max_idx1] -= 1
    counts1 = counts[:]
    max_idx2 = get_max_idx(counts1)
    counts1[max_idx2] -= 1
    if all_less_than_half_sum(counts1):
        res.append(chr(ord('A') + max_idx1) + chr(ord('A') + max_idx2))
        return solve(counts1, res)
    else:
        res.append(chr(ord('A') + max_idx1))
        return solve(counts, res)

def get_max_idx(counts):
    max_i = -1
    max_n = 0
    for i, n in enumerate(counts):
        if n > max_n:
            max_n = n
            max_i = i
    return max_i

def all_less_than_half_sum(counts):
    half_sum = sum(counts) / 2.0
    for n in counts:
        if n > half_sum:
            return False
    return True

first = True
n = 0
for line in sys.stdin:
    if first:
        first = False
        party_count = True
    elif party_count:
        party_count = False
    else:
        party_count = True
        n = n + 1
        counts = map(int, line.split(' '))
        ans = solve(counts, [])
        print "Case #%d: %s" % (n, ' '.join(ans))
