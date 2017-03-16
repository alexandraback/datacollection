#! /usr/bin/env python
import sys, re
import operator as op
import math

""" START TEMPLATE JCHAOISAAC """

# some reading functions
lolfile = open(sys.argv[1]) # open file
getline = lambda: lolfile.readline().strip()
gettoken = lambda: re.split("\s+", getline())
getint = lambda: int(getline())
getints = lambda: map(int, gettoken())

""" END TEMPLATE JCHAOISAAC """

def pp(x):
    return chr(ord('A') + x)
    
[T] = getints()
for cases in xrange(1, T + 1): # loop over cases
    ans = 0
    # main
    N = getint()
    ns = getints()

    ans = '';
    i = 0
    p = False
    while sum(ns) > 0:
        while i < N:
            if ns[i] > 0:
                ans += pp(i)
                ns[i] -= 1
            if p is True:
                ans += ' '
            i += 1
            p = not p
        ans += ' '
        p = False
        i = 0

    ans = ' '.join([x for x in ans[::-1].split(' ') if x != ''])
    
    # main
    print "Case #%d: %s" % (cases, ans) # answer output
