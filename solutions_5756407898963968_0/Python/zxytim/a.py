#!/usr/bin/env python2
# -*- coding: utf-8 -*-
# $File: a.py
# $Date: Sat Apr 12 09:58:10 2014 +0800
# $Author: Xinyu Zhou <zxytim[at]gmail[dot]com>

import sys

def get_set(fin):
    row = int(fin.readline().rstrip())
    ret = set()
    for i in range(1, 5):
        line = fin.readline()
        if i == row:
            ret = set(map(int, line.rstrip().split()))
    return ret

def main():
    if len(sys.argv) != 2:
        print 'Usage: {} <input>'.format(sys.argv[0])
        sys.exit(1)

    with open(sys.argv[1]) as fin:
        T = int(fin.readline().rstrip())
        for case_id in range(1, T + 1):
            a = get_set(fin)
            b = get_set(fin)
            c = a & b
            if len(c) == 0:
                ans = 'Volunteer cheated!'
            elif len(c) > 1:
                ans = 'Bad magician!'
            else:
                ans = list(c)[0]
            print 'Case #{}: {}'.format(case_id, ans)


if __name__ == '__main__':
    main()

# vim: foldmethod=marker
