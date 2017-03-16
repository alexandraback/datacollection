#!/usr/bin/python2

"""
  Google Code Jam 2015
  Philfifi  --  http://www.pluc.fr
  All rigths reserved
"""

from math import sqrt
from decimal import *
getcontext().prec = 100

#import psyco
#psyco.full()

_debug = 0

def nb_cadre2(R, C):
    N_all_happy = 0
    if R % 2 == 0:
        N_all_happy = (R/2) * C
    else:
        N_all_happy = (R + 1) * C/2
        if C % 2 == 0:
            pass
        else:
            N_all_happy += R/2

    return N_all_happy

def nb_cadre(R, C):
    if R == 1 and C == 1:
        return 1

    C_pair = C/2 * 2
    R_pair = R/2 * 2

    N_all_happy = C_pair * R_pair /2

    if C%2 == 1:
        N_all_happy += (R+1)/2
    if R%2 == 1:
        N_all_happy += C/2

    return N_all_happy


def solve_case(case_no,   R, C, N):
    print "-------------- New case", case_no
    print R, C, N


    nb = R*C

    nb_max = R*(C-1) + C*(R-1)

    print "max unhappiness", nb_max
    if N == 0:
        return 0
    if N == nb:
        return nb_max

    N_all_happy = nb_cadre(R, C)
    print "N_all_happy", N_all_happy

    if N <= N_all_happy:
        return 0

    if R>=3 and C>=3:
        nb_4 = nb_cadre(R-2, C-2)
    else:
        nb_4 = 0

    if min(R,C)>=3 and max(R,C)>=4:
        if (R % 2 == 0 and C % 2 == 0 or
            R % 2 == 1 and C % 2 == 1):
            nb_3 = 2*( (R-2)/2 + (C-2)/2 )
        else:
            nb_3 = 2*( (R-2)/2 + (C-2)/2 ) + 1

    elif min(R,C) == 2:
        nb_3 = max(R,C) - 2
    else:
        nb_3 = 0

    if min(R, C) == 1:
        if max(R, C) == 2:
            nb_2 = 0
        else:
            nb_2 = max(R, C) / 2
            if max(R, C) % 2 == 0:
                nb_2 -= 1
    else:
        if R%2 == 1 and C % 2 == 1:
            nb_2 = 4
        else:
            nb_2 = 2

    nb_1 = 0
    if min(R, C) == 1 and max(R, C) % 2 == 0:
        nb_1 = 1


    print "nb_4", nb_4
    print "nb_3", nb_3
    print "nb_2", nb_2
    print "nb_1", nb_1


    unhappyness2 = None
    if R%2==1 and C%2==1:
        # impair impair
        assert nb_2 == 4

        nb_to_add = N - N_all_happy

        nb_cost_3 = 2*(R+C) - nb_2 - nb_3

        a = min(nb_to_add, nb_cost_3)
        unhappyness2 = 3 * a
        nb_to_add -= a

        if nb_to_add != 0:
            unhappyness2 += 4*nb_to_add





    unhappyness = nb_max
    to_remove = nb - N

    r = min(to_remove, nb_4)
    unhappyness -= r * 4
    to_remove -= r

    if to_remove == 0:
        if unhappyness2 is not None:
            return min(unhappyness2, unhappyness)
        else:
            return unhappyness

    r = min(to_remove, nb_3)
    unhappyness -= r * 3
    to_remove -= r

    if to_remove == 0:
        if unhappyness2 is not None:
            return min(unhappyness2, unhappyness)
        else:
            return unhappyness

    r = min(to_remove, nb_2)
    unhappyness -= r * 2
    to_remove -= r

    if to_remove == 0:
        if unhappyness2 is not None:
            return min(unhappyness2, unhappyness)
        else:
            return unhappyness

    r = min(to_remove, nb_1)
    unhappyness -= r
    to_remove -= r

    assert to_remove == 0

    if unhappyness2 is not None:
        return min(unhappyness2, unhappyness)
    else:
        return unhappyness


def main(argv):

    f_out_name = argv[1].split(".")[0] + ".out"
    f_out = open(f_out_name, "w")

    fd = open(argv[1])
    nb_cases = int(fd.readline())


    for case_no in range(1, nb_cases+1):

        R, C, N = [int(item) for item in fd.readline().split()]


        n1 = solve_case(case_no, R, C, N)
        print "rep", n1
        # Have read all stuff for this case:
        f_out.write( "Case #%d: %d\n" % (case_no,
                                         n1
                                         )
                     )
        f_out.flush()

    f_out.close()

    for line in open(f_out_name):
        print line,



import sys
if __name__ == "__main__":
#    for i in range(1, 16):
#        for j in range(i, 16):
#            solve_case(1, i, j, 200)
    main(sys.argv)
