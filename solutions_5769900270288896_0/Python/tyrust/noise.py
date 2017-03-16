#!/usr/bin/python
'''
Google code jam 2015
Qualification Round
Noisy Neighbors

By Tyrus Tenneson
2015-05-02
'''

import sys

'''
Solution
'''

def re(n, points, occupied):
    if n == 0:
        return 0
    if n > len(points):
        return sys.maxint
    x,y = points[0]
    a = 0
    a += 1 if (x-1,y) in occupied else 0
    a += 1 if (x,y-1) in occupied else 0
    return min(re(n-1, points[1:], occupied.union([(x,y)])) + a,
               re(n, points[1:], occupied))

def eval_case(case):
    '''
    Returns solution to case
    '''
    R, C, N = case
    points = []
    for c in range(C):
        for r in range(R):
            points.append((r,c))
    return re(N, points, set())

'''
I/O
'''
def process_input():
    '''
    Reads stdin
    '''
    with sys.stdin as input:
        num_cases = int(input.readline().rstrip())
        cases = []
        for line in input.readlines():
            cases.append(tuple(map(int, line.split())))
    return tuple(cases)

def solve():
    cases = process_input()
    for idx, val in enumerate(cases):
        sol = eval_case(val)
        write_string = "Case #%i: %s\n" % (idx+1, sol)
        print write_string,

if __name__ == "__main__":
    solve()
