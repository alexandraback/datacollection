#!/usr/bin/env python
# encoding: utf-8

from contextlib import nested
from fractions import gcd

debug = True


def lcm(n1, n2):
    return n1 * n2 / gcd(n1, n2)


def solve(B, N, m):
    #print 'm: ', m
    g = m[0]
    for idx in range(1, len(m)):
        g = gcd(g, m[idx])
    for idx in range(len(m)):
        m[idx] /= g
    l = m[0]
    for idx in range(1, len(m)):
        l = lcm(l, m[idx])
    round_cust = 0
    for t in m:
        round_cust += l/t
    N %= round_cust
    if N == 0:
        N = round_cust
    #print 'm: ', m

    m_counter = [0]*B
    last_idx = -1
    while N > 0:
        #print m_counter
        min_time = 100000
        for idx in range(B):
            if m_counter[idx] == 0 and N > 0:
                m_counter[idx] = m[idx]
                N -= 1
                last_idx = idx
        min_time = min(m_counter)
        if min_time > 0 and min_time < 100000:
            for idx in range(B):
                m_counter[idx] -= min_time
    return last_idx + 1


if __name__ == '__main__':
    finame = 'B-small-attempt0.in'
    foname = 'B-small-attempt0.out'
    #finame = 'B-large.in'
    #foname = 'B-large.out'
    #if debug:
        #finame = 'B-small.in'
        #foname = 'B-small.out'

    with nested(open(finame), open(foname, 'w')) as (fi, fo):
        num_case = int(fi.readline().strip())
        for case_id in range(1, num_case + 1):
            B, N = map(int, fi.readline().strip().split(' '))
            mtime = map(int, fi.readline().strip().split(' '))

            ret = solve(B, N, mtime)

            output_str = 'Case #%d: %d' % (case_id, ret)
            print output_str
            fo.write(output_str + '\n')
