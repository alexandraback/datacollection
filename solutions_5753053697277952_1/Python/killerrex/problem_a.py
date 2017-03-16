#!/usr/bin/env python3
# coding=utf-8

"""
    Solve Round 1C 2016 p.A

    Author: killerrex
"""

import sys
from collections import OrderedDict


def get_biggest(senators):
    p = 0
    name = None
    for c in senators:
        if senators[c] > p:
            p = senators[c]
            name = c
    return name


def check(senators):
    total = sum(senators.values())
    for p in senators.values():
        if 2*p > total:
            return False
    return True


def evac_plan(senators):
    """
    Extract always the max, take kare of not leaving just 1
    Args:
        senators:

    Returns:

    """
    plan = []
    while senators:
        # Search for the biggest one
        a = get_biggest(senators)
        senators[a] -= 1
        if senators[a] == 0:
            del senators[a]
        # Extract a second one only if it is not the (1, 1)
        # scenario
        if len(senators) == 2 and tuple(senators.values()) == (1, 1):
            b = ''
        else:
            b = get_biggest(senators)
            senators[b] -= 1
            if senators[b] == 0:
                del senators[b]
        plan.append(a+b)
        if not check(senators):
            raise ValueError("Fail")
    return plan


def solve(fd):
    """
    Solve for the values from a file

    Args:
        fd: File unit
    """
    # First line is the number of cases
    total = int(fd.readline().strip())

    for k in range(total):

        n = int(fd.readline().strip())
        values = fd.readline().strip().split()
        assert(len(values) == n)

        senators = OrderedDict()
        for l, p in enumerate(values):
            l += ord('A')
            senators[chr(l)] = int(p)
        plan = ' '.join(evac_plan(senators))
        print("Case #{}: {}".format(k+1, plan))


def start():
    if len(sys.argv) > 1:
        with open(sys.argv[1], 'r') as fd:
            solve(fd)
    else:
        solve(sys.stdin)

if __name__ == '__main__':
    start()
