#!/usr/bin/python

import sys

def solve_test_case(r1, cards1, r2, cards2):
    res = [ c for c in cards2[r2] if c in cards1[r1] ]
    if len(res) == 0:
        return 'Volunteer cheated!'
    elif len(res) > 1:
        return 'Bad magician!'
    return res[0]

def main():
    f = open(sys.argv[1], 'r')
    n = int(f.readline().strip())
    for i in range(1,n+1):
        r1 = int(f.readline().strip())
        cards1 = []
        for k in range(0,4):
            cards1.append(set(f.readline().strip().split(' ')))
        r2 = int(f.readline().strip())
        cards2 = []
        for k in range(0,4):
            cards2.append(set(f.readline().strip().split(' ')))
        print 'Case #%d: %s' % (i, solve_test_case(r1-1, cards1, r2-1, cards2))

if __name__ == '__main__':
    main()
