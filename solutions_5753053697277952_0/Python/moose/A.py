#!/usr/bin/env python
# -*- coding: utf-8 -*-

"""Solution for problem A of Google Code Jam 2016, Subround C."""

__author__ = "Martin Thoma"
__email__ = "info@martin-thoma.de"

import math
from copy import deepcopy


def has_majority_or_neg(pm):
    total = sum([el[1] for el in pm])
    majority = int(math.ceil((total + 1) / 2.0))
    return any([True for el in pm if (el[1] >= majority or el[1] < 0)])


def solve(n, party_members):
    """Solve problem A."""
    pm = {}
    remaining = 0
    for i, char in enumerate(range(ord('A'), ord('A') + len(party_members))):
        pm[chr(char)] = party_members[i]
        remaining += party_members[i]
    evacuation_plan = []
    m = pm.items()
    m = [[el[0], el[1]] for el in m]
    while remaining > 0:
        m = sorted(m, key=lambda n: n[1], reverse=True)

        # Evacuate two from the leading party
        m1 = deepcopy(m)
        m1[0][1] -= 2
        if has_majority_or_neg(m1):
            m1 = deepcopy(m)
            m1[0][1] -= 1
            m1[1][1] -= 1
            if has_majority_or_neg(m1):
                m1 = deepcopy(m)
                m1[0][1] -= 1
                m = m1
                evacuation_plan.append(m[0][0])
                remaining -= 1
            else:
                m = m1
                evacuation_plan.append(m[0][0] + m[1][0])
                remaining -= 2
        else:
            m = m1
            evacuation_plan.append(2 * m[0][0])
            remaining -= 2
    return " ".join(evacuation_plan)


if __name__ == "__main__":
    testcases = input()

    for caseNr in xrange(1, testcases + 1):
        n = input()
        party_members = [int(el) for el in raw_input().split(" ")]
        print("Case #%i: %s" % (caseNr, solve(n, party_members)))
