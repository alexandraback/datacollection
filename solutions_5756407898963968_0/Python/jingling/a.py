#!/usr/bin/env python
# -*- coding: utf-8 -*-
import re
import sys
import os
import time
import itertools
import collections

def main():
    n = int(raw_input())
    for nn in range(n):
        a = int(raw_input())
        x = [raw_input().strip().split() for _ in range(4)]
        b = int(raw_input())
        y = [raw_input().strip().split() for _ in range(4)]
        #print a, b
        z = [ i for i in x[a-1] if i in y[b-1]]
        #print x[a-1],y[b-1],z

        if len(z) == 1:
            print "Case #%d: %s" % (nn+1, z[0])
        elif len(z) > 1:
            print "Case #%d: %s" % (nn+1, "Bad magician!")
        elif len(z) == 0:
            print "Case #%d: %s" % (nn+1, "Volunteer cheated!")


if __name__ == '__main__':
    main()
