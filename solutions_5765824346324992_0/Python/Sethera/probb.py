#!/usr/bin/env python
import sys
import math
from Queue import PriorityQueue

cases = []
with open(sys.argv[1]) as f:
    casecount = int(f.readline())
    for _ in xrange(0, casecount):
        b, n = map(int, f.readline().split(" "))
        m_arr = map(int, f.readline().split(" "))

        cases.append((b,n,m_arr))

# ganked this lcm impl from
# http://stackoverflow.com/questions/147515/least-common-multiple-for-3-or-more-numbers
def gcd(a, b):
    """Return greatest common divisor using Euclid's Algorithm."""
    while b:
        a, b = b, a % b
    return a

def lcm(a, b):
    """Return lowest common multiple."""
    return a * b // gcd(a, b)

def lcmm(*args):
    """Return lcm of args."""
    return reduce(lcm, args)

caseno = 1
for b, n, m_arr in cases:
    # print b, n, m_arr
    even_cycle_time = lcmm(*m_arr)
    people_in_cycle = sum(even_cycle_time / m for m in m_arr)

    # print people_in_cycle

    n = (n - 1) % people_in_cycle
    n += 1

    q = PriorityQueue()

    for i in xrange(0, b):
        q.put((0, i))

    for x in xrange(0, n):
        wait_time, barber_no = q.get()
        q.put((wait_time+m_arr[barber_no], barber_no))

    print "Case #%s: %s" % (caseno, barber_no+1)
    caseno += 1
