import os
import sys
import re
import math
from itertools import product, permutations, combinations, combinations_with_replacement

# Itertools Functions:
# product('ABCD', repeat=2)                   AA AB AC AD BA BB BC BD CA CB CC CD DA DB DC DD
# permutations('ABCD', 2)                     AB AC AD BA BC BD CA CB CD DA DB DC
# combinations('ABCD', 2)                     AB AC AD BC BD CD
# combinations_with_replacement('ABCD', 2)    AA AB AC AD BB BC BD CC CD DD

def memoize(f):
    """Simple dictionary-based memoization decorator"""
    cache = {}
    def _mem_fn(*args):
        if args not in cache:
            cache[args] = f(*args)
        return cache[args]

    _mem_fn.cache = cache
    return _mem_fn


def indicies(list, n):
    return [i for i, x in enumerate(list) if x == n]

def ind_to_senators(list):
    return ''.join(chr(n+65) for n in list)

def is_majority(senators):
    total_senators = sum(senators)
    return any(n > total_senators - senators[i] for i, n in enumerate(senators))

# -----------------------

num_cases = int(raw_input())
num_lines = 1

# Parties from A to Z
PARTIES = [chr(n) for n in range(65, 65+26)]

for case in range(1, num_cases + 1):
    # Declare variables for case
    out = None

    # Possible first "setup line" which might determine num_lines
    num_parties = int(raw_input().strip())

    senators = [int(n) for n in raw_input().strip().split()]

    evac_plan = []

    # Perform computation on case information
    while any(n != 0 for n in senators):
        most_sens = max(senators)

        # decide whether we double evac or not
        if senators.count(most_sens) == 1:
            i = senators.index(most_sens)
            # temp decrease and check majority
            tmp_senators = senators[:]
            tmp_senators[i] = tmp_senators[i] - 2
            if is_majority(tmp_senators):
                # there would be a majority, so only let 1 out
                evac = [i]
            else:
                evac = [i, i]
        else:
            evac = indicies(senators, most_sens)[:2]

            tmp_senators = senators[:]
            tmp_senators[evac[0]] = most_sens - 1
            tmp_senators[evac[1]] = most_sens - 1

            if is_majority(tmp_senators):
                # only evac 1 senator
                evac = [evac[0]]

        for i in evac:
            senators[i] = senators[i] - 1

        # assert not is_majority(senators)

        evac_plan.append(ind_to_senators(evac))

    out = ' '.join(evac_plan)

    print "Case #{}: {}".format(case, out)
