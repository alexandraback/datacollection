#!/usr/bin/env python
import sys
import math

cases = []
with open(sys.argv[1]) as f:
    casecount = int(f.readline())
    for _ in xrange(0, casecount):
        f.readline() # ignored
        m_arr = map(int, f.readline().split(" "))

        cases.append(m_arr)

caseno = 1
for m_arr in cases:
    method_1_value = 0
    method_2_rate = 0
    for i in xrange(1, len(m_arr)):
        if m_arr[i] < m_arr[i-1]:
            difference = m_arr[i-1] - m_arr[i]
            method_1_value += difference

            if difference > method_2_rate:
                method_2_rate = difference
            
    method_2_value = 0

    for i in xrange(0, len(m_arr)-1):
        method_2_value += min(m_arr[i], method_2_rate)

    print "Case #%s: %s %s" % (caseno, method_1_value, method_2_value)
    caseno += 1
