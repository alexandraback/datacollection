#!/usr/bin/env python

from __future__ import print_function

def readRow():
    rowNum = int(raw_input())
    for i in xrange(rowNum-1):
        raw_input()
    row = frozenset(map(int, raw_input().split()))
    for i in xrange(rowNum, 4):
        raw_input()
    return row

def main():
    T = int(raw_input())
    for t in xrange(T):
        candidates = readRow() & readRow()
        print("Case #", t+1, ': ', sep='', end='')
        if len(candidates) == 1:
            print(tuple(candidates)[0])
        elif len(candidates) > 1:
            print("Bad magician!")
        else:
            print("Volunteer cheated!")

if __name__ == "__main__":
    main()
