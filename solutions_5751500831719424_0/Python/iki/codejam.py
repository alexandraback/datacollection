""" Code runner for Google Codejam

Adds multiple cases processing to coderun.py

:Source: https://github.com/iki/codejam-seed

"""
__docformat__ = 'restructuredtext en'

import coderun
__all__ = coderun.__all__

from coderun import * # export *
from itertools import izip, count

def format_cases(solutions):
    return '\n'.join('Case #%d: %s' % (c, format(s)) for s,c in izip(solutions, count(1)))

def solve_cases(cases):
    #_solve = log.debug and solve_wrap or solve
    #return [_solve(*case) for case in cases]
    return [solve_wrap(*case) for case in cases]

def solve_wrap(*args):
    try:
        r = solve(*args)
    except:
        log.info('CASE: %s -> ERROR' % (
            [a for a in args if not a in common_args and isinstance(a, (int, bool, str, type(None)))],))
        raise
    else:
        log.info('CASE: %s -> %s' % (
             [a for a in args if not a in common_args and isinstance(a, (int, bool, str, type(None)))], r))
        return r

def parse_cases_expanded(fi):
    if parse_header is None:
        cases, common_args = int(fi.next().strip()), ()
    else:
        cases, common_args = parse_header(fi)

    globals().update(common_args=common_args)

    if cases < min_cases:
        raise AssertionError, 'Not enough cases: %d < %d' % (cases, min_cases)

    c = cases
    while c:
        c -= 1
        log.info('FILE: %s: case %d/%d' % (getattr(fi, 'name', type(fi).__name__), cases-c, cases))
        yield parse(fi, *common_args)

def parse_cases(fi):
    return [parse_cases_expanded(fi)]

def main(solve, parse, format=str, parse_header=None, min_cases=1, *args, **kwargs):
    globals().update(solve=solve, parse=parse, format=format,
        parse_header=parse_header, min_cases=min_cases, common_args=())
    return coderun.main(solve_cases, parse_cases, format_cases, *args, **kwargs)
