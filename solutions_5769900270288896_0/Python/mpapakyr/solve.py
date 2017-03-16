#! /usr/bin/python

import os, sys, copy

def debug(msg):
    if len(sys.argv) > 1 and sys.argv[1] == '-d':
        sys.stderr.write('%s' % msg)
        sys.stderr.write('\n')

def solve_1(dim, N):
        if dim % 2 == 0:
            free = dim / 2
            mult_1 = 1
            if N <= free:
                return 0
            elif N <= free + mult_1:
                return N - free
            else:
                return 1 + 2 * (N - free - mult_1)
        else:
            free = dim / 2 + 1
            mult_1 = 0
            if N <= free:
                return 0
            elif N <= free + mult_1:
                return N - free
            else:
                return 2 * (N - free - mult_1)
            
def solve_even(R, C, N):        
    if R % 2 == 0:
        free = R * C / 2
        mult_2 = 2
        mult_3 = R + C - 2 - 2
        debug('free=%s, mult_2=%s, mult_3=%s' % (free, mult_2, mult_3))
        if N <= free:
            debug('free')
            return 0
        elif N <= free + mult_2:
            debug('mult_2')
            return 2 * (N - free)
        elif N <= free + mult_2 + mult_3:
            debug('mult_3')
            return 2 * mult_2 + 3 * (N - free - mult_2)
        elif N > free + mult_2 + mult_3:
            debug('mult_4')
            return 2 * mult_2 + 3 * mult_3 + 4 * (N - free - mult_2 - mult_3)
        
def solve_odd_1(R, C, N):
        debug('odd1')
        free = R * C / 2
        mult_2 = 4
        mult_3 = R + 1 - 4 + 2*(C/2-1)
        debug('free=%s, mult_2=%s, mult_3=%s' % (free, mult_2, mult_3))
        if N <= free:
            debug('free')
            return 0
        elif N <= free + mult_2:
            debug('mult_2')
            return 2 * (N - free)
        elif N <= free + mult_2 + mult_3:
            debug('mult_3')
            return 2 * mult_2 + 3 * (N - free - mult_2)
        elif N > free + mult_2 + mult_3:
            debug('mult_4')
            return 2 * mult_2 + 3 * mult_3 + 4 * (N - free - mult_2 - mult_3)

def solve_odd_2(R, C, N):
        debug('odd2')
        free = R * C / 2 + 1
        mult_2 = 0
        mult_3 = R - 1 + C - 1
        debug('free=%s, mult_2=%s, mult_3=%s' % (free, mult_2, mult_3))
        if N <= free:
            debug('free')
            return 0
        elif N <= free + mult_2:
            debug('mult_2')
            return 2 * (N - free)
        elif N <= free + mult_2 + mult_3:
            debug('mult_3')
            return 2 * mult_2 + 3 * (N - free - mult_2)
        elif N > free + mult_2 + mult_3:
            debug('mult_4')
            return 2 * mult_2 + 3 * mult_3 + 4 * (N - free - mult_2 - mult_3)

T = int(sys.stdin.readline())
# For each test case
for t in range(1, T+1):
    debug('Case ********** %s' % t)
    [R, C, N] =  [int(x) for x in sys.stdin.readline().strip().split(' ')]
    if min([R, C]) == 1:
        ret = solve_1(max([R, C]), N)
    else:
        if R % 2 == 1:
            R, C = C, R
        if R % 2 == 0:
            ret = solve_even(R, C, N)
        else:
            ret_1 = solve_odd_1(R, C, N)
            ret_2 = solve_odd_2(R, C, N)
            ret = min([ret_1, ret_2])
    sys.stdout.write('Case #%s: %s\n' % (t, ret))
