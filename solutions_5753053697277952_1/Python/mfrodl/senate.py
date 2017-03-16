#!/usr/bin/python

from string import ascii_uppercase
import sys

t = int(raw_input())
for i in range(t):
    n = int(raw_input())
    counts = dict(zip(
        ascii_uppercase,
        map(int, raw_input().split())))
    sys.stdout.write('Case #{0}:'.format(i+1))
    while counts:
        sys.stdout.write(' ')
        biggest = max(counts, key=counts.get)
        counts[biggest] -= 1
        if counts[biggest] == 0:
            del counts[biggest]
        sys.stdout.write(biggest)
        if not counts or sum(counts.values()) == 2:
            continue
        biggest = max(counts, key=counts.get)
        counts[biggest] -= 1
        if counts[biggest] == 0:
            del counts[biggest]
        sys.stdout.write(biggest)
    sys.stdout.write('\n')
