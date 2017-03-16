#!/usr/bin/python

import sys

INPUT = sys.stdin
INPUT = open(sys.argv[1],'r')

def getline():
    return INPUT.readline()[:-1]

class Bunch:
    def __init__( self, **kwds ):
        self.__dict__ = kwds


pause_after_trace = False
def mtrace(*strs):
    return
    atrace(*strs)

def atrace(*strs):
    f = sys.stderr
    print >> f, '..',
    for str in strs:
        print >> f, str,
    print >> f
    if pause_after_trace:
        response = raw_input('? ')
        if response == 'q':
            sys.exit(1)

def memoize(f):
    memos = {}
    def memoized_f( *args ):
        try:
            result = memos[args]
            mtrace(args, ": got result from memo")
        except KeyError:
            result = f(*args)
            mtrace(args, ": got result by calling")
            memos[args] = result
        return result
    return memoized_f

# ------------------------------------------------------------------------------

n_cases = int(getline())
mtrace(n_cases,'cases:')
for case_num in range(1,n_cases+1):
    mtrace()
    atrace( 'Case #', case_num )

    N = int(getline())
    m_ = map(int, getline().split())
    mtrace('N =', N)
    mtrace('m_ =', m_)
    assert len(m_) == N

    def solve():
        # Figure out the minimum number of mushrooms that Kaylin could have eaten using two different methods of computation: 

        # 1. Assume Kaylin could eat any number of mushroom pieces at any time. 
        mtrace('method 1:')
        n_eaten_1 = 0
        for (before,after) in zip(m_[0:-1], m_[1:]):
            mtrace('    ', before, '->', after)
            if after < before:
                eaten = before - after
                mtrace('        must have eaten at least', eaten)
                n_eaten_1 += eaten
            else:
                # B must have put mushrooms on plate
                pass

        # 2. Assume that, starting with the first time we look at the plate, Kaylin eats mushrooms at a constant rate whenever there are mushrooms on her plate. 
        mtrace('method 2:')
        mtrace('pass 1:')
        rate = -1
        for (before,after) in zip(m_[0:-1], m_[1:]):
            mtrace('    ', before, '->', after)
            if after < before:
                eaten = before - after
                rate = max(rate,eaten)
        if rate == -1:
            n_eaten_2 = 0
            return (n_eaten_1,n_eaten_2)

        mtrace('rate =', rate)

        # The max decrease seen was rate
        # So she'll eat that many per 10 minutes as long as there are some on plate
        mtrace('pass 2:')
        n_eaten_2 = 0
        for (before,after) in zip(m_[0:-1], m_[1:]):
            mtrace('    ', before, '->', after)
            if before <= rate:
                mtrace('        ate', before)
                n_eaten_2 += before
            else:
                mtrace('        ate', rate)
                n_eaten_2 += rate
                
        return (n_eaten_1,n_eaten_2)

    (a,b) = solve()

    print 'Case #%d: %s %s' % (case_num, a, b)
    sys.stdout.flush()

assert INPUT.readline() == ''

# vim: sw=4 ts=4 expandtab
