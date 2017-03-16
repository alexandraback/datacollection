#!/usr/bin/env python
# encoding: utf-8

from contextlib import nested

debug = True


def solve(vals):
    ret1 = 0
    ret2 = 0
    max_gap = 0
    #num_intervals = len(vals) - 1
    for i in range(len(vals) - 1):
        if vals[i + 1] < vals[i]:
            gap = vals[i] - vals[i + 1]
            ret1 += gap
            if gap > max_gap:
                max_gap = gap
    speed = max_gap / 10.0
    for i in range(len(vals) - 1):
        if vals[i] < 10 * speed:
            ret2 += vals[i]
        else:
            ret2 += 10 * speed
    return ret1, ret2

if __name__ == '__main__':
    finame = 'A-small-attempt0.in'
    foname = 'A-small-attempt0.out'
    finame = 'A-large.in'
    foname = 'A-large.out'
    #if debug:
        #finame = 'A-small.in'
        #foname = 'A-small.out'

    with nested(open(finame), open(foname, 'w')) as (fi, fo):
        num_case = int(fi.readline().strip())
        for case_id in range(1, num_case + 1):
            N = int(fi.readline().strip())
            vals = map(int, fi.readline().strip().split(' '))

            ret1, ret2 = solve(vals)

            output_str = 'Case #%d: %d %d' % (case_id, ret1, ret2)
            print output_str
            fo.write(output_str + '\n')
