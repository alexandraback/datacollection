#!/usr/bin/python
""" template.py input-file > output-file"""

import sys
from numpy import *

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


def solve_one():
    """ XXX the real code comes here """
    first_row = input_ints()[0]
    first_matrix = []
    for _ in range(4):
        first_matrix.append(input_ints())
    first_poss = set(first_matrix[first_row-1])

    second_row = input_ints()[0]
    second_matrix = []
    for _ in range(4):
        second_matrix.append(input_ints())
    second_poss = set(second_matrix[second_row-1])
    
    solutions = first_poss.intersection(second_poss)

    if len(solutions) == 0:
        return 'Volunteer cheated!'
    elif len(solutions) > 1:
        return 'Bad magician!'
    else:
        return list(solutions)[0]


if __name__ == "__main__":
    assert(len(sys.argv) == 2)
    IN = open(sys.argv[1])

    T = input_ints()[0]
    
    for i in range(T):
        print "Case #%d:" % (i+1,), solve_one()
        sys.stderr.write("CASE #%d DONE\n" % (i+1,))
        sys.stderr.flush()


