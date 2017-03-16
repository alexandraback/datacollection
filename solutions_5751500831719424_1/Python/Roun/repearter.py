#!/usr/bin/env python

from __future__ import print_function
from sys import argv,stdin
import re
import itertools

def rm_dup(s):
    return re.sub(r'(.)\1+',r'\1',s)

def count(s):
    return [len(list(g)) for k, g in itertools.groupby(s)]

def spam(mylist):
    sorts = sorted(mylist)
    length = len(sorts)
    if not length % 2:
        a = sorts[length / 2]
        b = sorts[length / 2 - 1]
        aa = sum(abs(x-a) for x in mylist)
        bb = sum(abs(x-b) for x in mylist)
        if aa < bb:
            return aa
        else:
            return bb
    a = sorts[length / 2]
    return sum(abs(x-a) for x in mylist)

with open(argv[1]) if len(argv)>1 else stdin as f:
    T = int(f.readline())
    for i in xrange(T):
        N = int(f.readline())
        strings = []
        for j in xrange(N):
            strings.append(f.readline().rstrip())
        foo = [rm_dup(s) for s in strings]
        if len(set(foo)) > 1:
            print('Case #%d: Fegla Won'%(i+1,))
            continue
        bar = [count(s) for s in strings]
        bart = zip(*bar)
        sbart = [spam(b) for b in bart]
        v = sum(sbart)
        print('Case #%d: %d'%(i+1,v))
