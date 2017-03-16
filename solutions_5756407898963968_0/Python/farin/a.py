#!/usr/bin/env python
# -*- coding: utf-8 -*-

def intersect(a, b):
     return list(set(a) & set(b))

def solve():
    a = input()
    for i in xrange(1, 5):
        read = raw_input()
        if a == i:
            cards1 = map(int, read.split())
    a = input()
    for i in xrange(1, 5):
        read = raw_input()
        if a == i:
            cards2 = map(int, read.split())
    matching = intersect(cards1, cards2)
    if len(matching) == 0:
        return 'Volunteer cheated!'
    if len(matching) > 1:
        return 'Bad magician!'
    return matching[0]


if __name__ == "__main__":
    testcases = input()
    for case_n in xrange(1, testcases+1):
        #case_data = map(int, raw_input().split())
        print("Case #%i: %s" % (case_n, solve()))
