#!/usr/bin/python
""" template.py input-file > output-file"""

import sys
import numpy as np

sys.setrecursionlimit(10000)

def input_words():
    line = IN.readline()
    return line.strip().split()

def input_ints():
    return map(int, input_words())

def input_floats():
    return map(float, input_words())

def format_sequence(s, formatter='%s'):
    return " ".join(map(lambda x: formatter % (x,), s))


def analyze_string(t):
    prev_c = t[0]

    dedup = ''
    mults = []
    curr_mult = 1

    for i in range(1, len(t)):
        c = t[i]
        if c == prev_c:
            curr_mult += 1
        else:
            dedup += prev_c
            mults.append(curr_mult)
            curr_mult = 1
        prev_c = c
            
    dedup += prev_c
    mults.append(curr_mult)

    return dedup, mults
    

def solve_one():
    """ XXX the real code comes here """
    N = input_ints()[0]

    alls, dedups, mults = [], [], []
    for _ in range(N):
        s = input_words()[0]
        d, m = analyze_string(s)
        alls.append(s)
        dedups.append(d)
        mults.append(m)

    if len(set(dedups)) > 1:
        return 'Fegla Won'

    x = np.array(zip(*mults))

#    print mults
#    print x

    cost = 0
    for row in x:
        cost += min([np.abs(row - t).sum() for t in range(min(row), max(row) + 1)])

    return cost


if __name__ == "__main__":
    assert(len(sys.argv) == 2)
    IN = open(sys.argv[1])

    T = input_ints()[0]
    
    for i in range(T):
        print "Case #%d:" % (i+1,), solve_one()
        sys.stderr.write("CASE #%d DONE\n" % (i+1,))
        sys.stderr.flush()


