#!/usr/bin/env python

import re
import sys
from itertools import izip
from numpy import median


def repeater(strings):
    split_result = []
    ngroup = 0
    step = 0

    for i in strings:
        s = [m.group(0) for m in re.finditer(r"(\w)\1*", i)]
        if ngroup == 0:
            ngroup = len(s)
        elif ngroup != len(s):
            return 'Fegla Won'

        split_result.append(s)

    for i in izip(*split_result):
        if any(i[0][0] not in i[x] for x in xrange(1, len(i))):
            return 'Fegla Won'
        m = int((median([len(x) for x in i])))
        for j in (len(x) for x in i):
            step += abs(j - m)

    return step


def main():
    with open(sys.argv[1], 'r') as fi:
        n_case = int(fi.readline())

        r_case = 0
        while r_case < n_case:
            r_case += 1

            n = int(fi.readline())
            strings = []
            for i in xrange(n):
                strings.append(fi.readline().strip())
            result = repeater(strings)
            print('Case #{0}: {1}'.format(r_case, result))

if __name__ == '__main__':
    main()
