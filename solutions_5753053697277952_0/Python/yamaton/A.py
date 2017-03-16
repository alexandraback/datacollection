"""
Google Code Jam
2016 Round 1C

Problem A.
    :author: yamaton
    :date: 2016-05-08
"""

import itertools as it
import functools
import operator
import collections
import math
import sys

PARTY = 'ABCDEFGHIJKLMNOPQRSTUVWXYZ'


def roundrobin(*iterables):
    """
    Similar to Riffle function in Mathematica

    >>> list(roundrobin('ABC', 'D', 'EF'))
    ['A', 'D', 'E', 'B', 'F', 'C']

    From itertools recipes which credits to George Sakkis
    http://docs.python.org/3/library/itertools.html
    """
    cycle = it.cycle
    islice = it.islice

    pending = len(iterables)
    nexts = cycle(iter(it).__next__ for it in iterables)
    while pending:
        try:
            for next in nexts:
                yield next()
        except StopIteration:
            pending -= 1
            nexts = cycle(islice(nexts, pending))


def take_every(n, seq):
    """Keep taking every n elements from iterable

    >>> take_every(3, list(range(10)))
    [[0, 1, 2], [3, 4, 5], [6, 7, 8], [9]]
    """
    ubound = math.ceil(len(seq) / n)
    return [seq[i*n: (i+1)*n] for i in range(ubound)]


def solve(xs):
    senators = reversed([c*n for (c, n) in zip(PARTY, xs)])
    rev_order = [''.join(chars) for chars in take_every(2, list(roundrobin(*senators)))]
    return list(reversed(rev_order))



def pp(*args, **kwargs):
    print(*args, file=sys.stderr, **kwargs)


def main():
    for _tc in range(1, int(input())+1):
        pp('\n--------- case #%d -------' % _tc)
        print("Case #%d: " % _tc, end='')
        n = int(input())
        xs = [int(s) for s in input().strip().split()]
        assert len(xs) == n

        result = solve(xs)
        pp()
        pp('xs =', xs)
        pp('result =', result)
        print(*result)




if __name__ == '__main__':
    main()
