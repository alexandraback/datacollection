from __future__ import print_function
from __future__ import division
import sys
from itertools import groupby
from collections import defaultdict

import gcj_util
from gcj_util import (
    dprint,
    read_ints,
    read_floats,
    read_int,
)


IMPOSSIBLE = 'Fegla Won'


def get_min_actions(group):
    '''
    >>> get_min_actions([4, 3, 3, 1])
    3
    '''
    maxlen = max(group)
    min_actions = sum(group) - len(group)
    for pivot in range(1, maxlen + 1):
        actions = 0
        for n in group:
            actions += abs(n - pivot)

            if actions > min_actions:
                break

        if actions < min_actions:
            min_actions = actions

    return min_actions


def solve(N, xs):
    xs.sort()

    groups = defaultdict(list)
    group_chars = []

    s = xs[0]
    for i, (c, g) in enumerate(groupby(s, lambda c: c)):
        groups[i].append(len(list(g)))
        group_chars.append(c)

    ngroups = len(group_chars)

    for s in xs[1:]:
        for i, (c, g) in enumerate(groupby(s, lambda c: c)):
            if i >= ngroups:
                return IMPOSSIBLE

            if group_chars[i] != c:
                return IMPOSSIBLE

            groups[i].append(len(list(g)))

    return sum(map(get_min_actions, groups.itervalues()))

def read_case(fp):
    N = read_int(fp)
    xs = []
    for i in range(N):
        xs.append(fp.readline().strip())
    return N, xs


def write_result(fp, casenum, result):
    fp.write('Case #%d: %s\n' % (casenum, result))
    fp.flush()


def read_cases(fp):
    T = read_int(fp)
    for i in range(T):
        yield read_case(fp)


if __name__ == '__main__':
    if len(sys.argv) > 1:
        gcj_util.DEBUG = True

    in_fp = sys.stdin
    out_fp = sys.stdout
    for casenum, case in enumerate(read_cases(in_fp)):
        result = solve(*case)
        write_result(out_fp, casenum + 1, result)
