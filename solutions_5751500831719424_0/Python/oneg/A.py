#!/usr/bin/env python
# coding: utf-8

#########################################################################
#########################################################################

"""
   File Name: gcj.py
      Author: Wan Ji
      E-mail: wanji@live.com
  Created on: Sat Apr 12 14:59:24 2014 CST
"""
DESCRIPTION = """
"""

import os
import sys
import argparse


def perr(msg):
    """ Print error message.
    """

    sys.stderr.write("%s" % msg)
    sys.stderr.flush()


def pinfo(msg):
    """ Print information message.
    """

    sys.stdout.write("%s" % msg)
    sys.stdout.flush()


def runcmd(cmd):
    """ Run command.
    """

    perr("%s\n" % cmd)
    os.system(cmd)


def getargs():
    """ Parse program arguments.
    """

    parser = argparse.ArgumentParser(description=DESCRIPTION,
                                     formatter_class=
                                     argparse.RawTextHelpFormatter)
    parser.add_argument('infile', type=str, help='input file')
    parser.add_argument('outfile', type=str, nargs='?', default=None,
                        help='output file')

    return parser.parse_args()


def calc_steps(v_cnt):
    """
    return steps
    """
    smallest = sys.maxint
    for i in v_cnt:
        steps = 0
        for j in v_cnt:
            steps += abs(i-j)
        smallest = min(smallest, steps)
    return smallest


def decodestr(line):
    """
    retval:
        list of (char, cnt)
    """
    lst = []
    cur = line[0]
    cnt = 0
    for ch in line[1:]:
        cnt += 1
        if cur != ch:
            lst.append((cur, cnt))
            cnt = 0
            cur = ch
    lst.append((cur, cnt+1))
    return lst


def main(args):
    """ Main entry.
    """

    if None == args.outfile:
        outfile = sys.stdout
    else:
        outfile = open(args.outfile, "w")

    with open(args.infile) as infile:
        T = int(infile.readline())
        for i in range(1, T + 1):
            N = int(infile.readline())
            v_str = [decodestr(list(infile.readline().strip()))
                     for j in range(N)]
            v_len = [len(stri) for stri in v_str]

            if len(set(v_len)) != 1:
                outfile.write("Case #%d: Fegla Won\n" % (i, ))
                continue

            totalsteps = 0
            for j in range(v_len[0]):
                v_chr = [v_str[k][j][0] for k in range(N)]
                v_cnt = [v_str[k][j][1] for k in range(N)]
                if len(set(v_chr)) != 1:
                    totalsteps = -1
                    break
                totalsteps += calc_steps(v_cnt)

            if totalsteps < 0:
                outfile.write("Case #%d: Fegla Won\n" % (i, ))
            else:
                outfile.write("Case #%d: %d\n" % (i, totalsteps))

    if None != args.outfile:
        outfile.close()

if __name__ == '__main__':
    main(getargs())
