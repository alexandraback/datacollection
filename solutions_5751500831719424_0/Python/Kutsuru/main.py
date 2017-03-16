#! /usr/bin/env python2
# -*- coding: utf-8 -*-

import sys
import numpy as np

def compress(dstr):
    res = []

    previous_char = None
    count = 1

    for i in range(len(dstr)):
        if previous_char == dstr[i]:
            count += 1

            continue
        else:
            if previous_char:
                res.append((previous_char, count))
            previous_char = dstr[i]
            count = 1

    return res

def compute_distance(dstr1, dstr2):
    if len(dstr1) != len(dstr2):
        return -1

    distance = 0

    for i in range(len(dstr1)):
        char1, count1 = dstr1[i]
        char2, count2 = dstr2[i]

        if char1 != char2:
            return -1

        distance += abs(count1 - count2)

    return distance

def bary_distance(cbary, dstr):
    distance = 0

    for i in range(len(dstr)):
        char, count = dstr[i]

        distance += abs(cbary[i] - count)

    return distance

def parse_input(filename):
    """
    Parse the input according to the following format
    """
    input_file = open(filename, "r")

    tc_number = int(input_file.readline())
    tc_list = []

    for i in range(tc_number):
        tc = {}
        N = int(input_file.readline())
        tc['x'] = i + 1
        tc['N'] = N
        dstrs = []
        for i in range(N):
            dstrs.append(input_file.readline())

        tc['dstrs'] = dstrs
        tc_list.append(tc)

    return tc_list

def solve(tc):
    N = tc.get('N')
    mdist = np.zeros((N, N))
    dstrs = tc.get('dstrs')
    cbary = []
    try:
        cbary = bary(dstrs)
    except ValueError:
        print "Case #%i: Fegla Won" % tc.get('x')
        return

    lbary = []
    for dstr in dstrs:
        lbary.append(bary_distance(cbary, compress(dstr)))

    print "Case #%i: %i" % (tc.get('x'), sum(lbary))

    return

def bary(dstrs):
    clist = []
    for dstr in dstrs:
        cdstr = compress(dstr)

        clist.append(np.array([x[1] for x in cdstr]))

    try:
        res = sum(clist) / float(len(dstrs))
        return map(round, res)
    except ValueError:
        raise

def main(argv):
    """
    """
    filename = argv[0]
    tc_list = parse_input(filename)

    for tc in tc_list:
        solve(tc)


if __name__ == "__main__":
    main(sys.argv[1:])
