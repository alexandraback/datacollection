#!/usr/bin/python2
# -*- coding: utf-8 -*-

import sys
import os

def main():
    T = int(sys.stdin.readline())
    for i in xrange(1, T+1):
        ans = int(sys.stdin.readline())
        for j in xrange(1, 5):
            line = sys.stdin.readline()
            if j == ans:
                possible = set(map(int, line.split()))

        ans = int(sys.stdin.readline())
        for j in xrange(1, 5):
            line = sys.stdin.readline()
            if j == ans:
                possible.intersection_update(map(int, line.split()))

        if len(possible) == 1:
            print "Case #%d: %d" % (i, iter(possible).next())
        elif len(possible) == 0:
            print "Case #%d: Volunteer cheated!" % (i,)
        else:
            print "Case #%d: Bad magician!" % (i,)


if __name__ == '__main__':
    main()
