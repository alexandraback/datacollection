#!/usr/bin/env python
import sys
from numpy import *

def parse_line(line):
    pattern = line[0]
    counts = [1]
    for i in xrange(1, len(line)):
        if line[i] == "\n":
            break
        if line[i] == pattern[-1]:
            counts[-1] += 1
        else:
            pattern += line[i]
            counts.append(1)
    return pattern, counts

def min_changes(counts):
    s = 0
    counts = array(counts)
    for i in xrange(counts.shape[1]):
        s += min_changes_line(counts[:,i])
    return s
def min_changes_line(line):
    m = Inf
    for i in xrange(len(line)):
        v = sum(abs(line - line[i]))
        if v < m:
            m = v
    return m
if __name__ == "__main__":
    input = open(sys.argv[1])
    T = int(input.readline())
    for ncase in xrange(1, T + 1):
        N = int(input.readline())
        line = input.readline()
        pattern, c = parse_line(line)
        counts = [c]
        fail = False
        for i in xrange(1, N):
            p, c = parse_line(input.readline())
            if p != pattern:
                fail = True
                break
            counts.append(c)
        print "Case #%d:" % ncase,
        if fail:
            print "Fegla Won"
        else:
            print min_changes(counts)

