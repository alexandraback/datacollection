#!/usr/bin/env python
# -*- coding: utf-8 -*-

import numpy as np
import itertools as it
import pickle
import logging
import ipdb
import sys

reload(logging)
logging.basicConfig(format='%(asctime)s %(levelname)s %(message)s',
                    level=logging.DEBUG,
                    stream=sys.stdout)

def convert(n):
    return chr(65+n)


def solve(n, line):
    num = line.split(" ")
    num = np.array(map(int, num))

    sol = ""
    while (sum(num > 0) > 2):
        ev = np.argmax(num)
        num[ev] = num[ev] - 1
        char = convert(ev)
        sol = sol + " " + char

    while sum(num > 0) == 2:
        ev = np.argwhere(num > 0)
        char0 = convert(ev[0])
        num[ev[0]] = num[ev[0]] - 1
        ev1 = np.argmax(num)
        char1 = convert(ev[1])
        num[ev[1]] = num[ev[1]] - 1
        sol = sol + " " + char0 + char1

    return sol

if __name__ == "__main__":
    testcases = input()

    for caseNr in xrange(1, testcases+1):
        n = raw_input()
        line = raw_input()
        print("Case #%i: %s" % (caseNr, solve(n, line)))
