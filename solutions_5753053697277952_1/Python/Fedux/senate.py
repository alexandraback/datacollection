#!/usr/bin/env python
# -*- coding: UTF-8 -*-

from __future__ import division
from fileparser import FileParser


def index2party(index):
    return chr(ord("A") + index)


def check(senators):
    tot = sum(senators)
    for i, x in enumerate(senators):
        if x*2 > tot and tot > 0:
            #print "Party {} has {} / {}".format(index2party(i), x, tot)
            return False
    return True


def solve(senators):
    res = []
    while sum(senators) > 0:
        e2 = None
        e1 = senators.index(max(senators))
        senators[e1] -= 1

        if not check(senators):
            e2 = senators.index(max(senators))
            senators[e2] -= 1

        assert check(senators), senators

        if e2 is None:
            res.append(index2party(e1))
        else:
            res.append(index2party(e1) + index2party(e2))
    return res


def main():
    inputfile = FileParser()
    T = inputfile.read_int()
    for test in range(1, T + 1):
        N = inputfile.read_int()

        senators = inputfile.read_integers()

        result = solve(senators)

        print "Case #{}: {}".format(test, " ".join(result))


if __name__ == '__main__':
    main()
