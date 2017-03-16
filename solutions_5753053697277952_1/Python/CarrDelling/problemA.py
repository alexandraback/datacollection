#!/usr/bin/env python

################################################################################
#
# Google Code Jam - 2016
#
# Round 1C - Problem A -
#
# Joaquin Derrac - carrdelling@gmail.com
#
################################################################################

import sys
import string

alphabet = string.ascii_uppercase

def solve(N, people):

    current = []
    output =[]
    for i in xrange(N):
         current.append([alphabet[i], people[i]])

    while current:

        current.sort(key=lambda x:x[1], reverse=True)

        if len(current) == 1:
            if current[0][1] > 1:
                output.append([current[0][0], current[0][0]])
                current[0][1] -= 2
            else:
                output.append([current[0][0], ''])
                current[0][1] -= 1
        elif len(current) == 3:
            output.append([current[0][0], ''])
            current[0][1] -= 1
        else:
            output.append([current[0][0], current[1][0]])
            current[0][1] -= 1
            current[1][1] -= 1

        if len(current) > 1 and current[1][1] == 0:
            if current[0][1] == 0:
                current = current[2:]
            else:
                current = [current[0]] + current[2:]
        elif current[0][1] == 0:
            current = current[1:]

    joined = [''.join(x) for x in output]
    output = ' '.join(joined)

    return output


input_path = sys.argv[1]

with open(input_path) as input_file:

    n_cases = int(input_file.readline().strip())

    for case in xrange(1, n_cases+1):
        parties = int(input_file.readline().strip())
        people = map(int, input_file.readline().strip().split())
        solution = solve(parties, people)
        print 'Case #{0}: {1}'.format(case, solution)
