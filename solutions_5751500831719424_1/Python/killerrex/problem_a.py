#!/usr/bin/env python3
# coding=utf-8

"""
Problem 1 for Google CodeJam 2014, Round 1B

Author: A. Ayala
killerrex@gmail.com
"""

import sys
import re



class FeglaString(object):
    """
    String from Fegla
    """
    def __init__(self, txt):
        """
        Reduce to a set of letters and multiplicity
        """
        self.keys = [txt[0]]
        self.times = [1]

        for c in txt[1:]:
            if c == self.keys[-1]:
                self.times[-1] += 1
            else:
                self.keys.append(c)
                self.times.append(1)

    def compatible(self, other):
        """
        2 strings are compatible if they have the same letters in the same order
        no matter their multiplicity
        """
        return self.keys == other.keys

    def max_common(self, nmax):
        """
        Return the maximum of the multipliers
        """
        for k in range(len(self.times)):
            nmax[k] = max(nmax[k], self.times[k])
        return nmax


def moves(deltas):
    """
    Return the needed number of moves as the sum of the absolute values
    """
    return sum(abs(x) for x in deltas)


def solution(lst):
    """
    Solve for the lst of strings
    """
    lst = [FeglaString(s) for s in lst]

    # Check compatibility
    if not all(lst[0].compatible(s) for s in lst):
        return "Fegla Won"

    n_letters = len(lst[0].keys)
    # Calculate the maximum value for each letter
    nmax = [0]*n_letters
    for l in lst:
        nmax = l.max_common(nmax)

    # Each letter is independent of the others
    total = 0
    for k in range(n_letters):
        values = [l.times[k] for l in lst]
        m = nmax[k]
        # Initial value of the deltas: Just equal to the biggest one
        deltas = [m - v for v in values]
        T = moves(deltas)
        while m > 0:
            # Try to reduce the number of moves
            m -= 1
            deltas = [m - v for v in values]
            if any(d+v == 0 for d, v in zip(deltas,values)):
                # Cannot reduce more, one of the letters disappear
                break
            # Ok, valid set
            T = min(T, moves(deltas))
        total += T
    return str(total)


def solve(fd):
    """
    Solve all the cases from fd
    """

    t = int(fd.readline().strip())
    for k in range(t):
        # Read the number of cells
        n = int(fd.readline().strip())
        lst = [fd.readline().strip() for l in range(n)]
        res = solution(lst)
        print("Case #{}: {}".format(k+1, res))

if __name__ == '__main__':
    if len(sys.argv) < 2:
        infile = sys.stdin
    else:
        infile = open(sys.argv[1], 'r')

    solve(infile)

    infile.close()