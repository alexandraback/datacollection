#!/usr/bin/python2
from math import ceil

def main():
    n = input()
    for t in range(n):
        input()
        li = map(int, raw_input().split())
        print 'Case #{}: {}'.format(t + 1, solve(li))

def solve(li):
    deltas = [li[i] - li[i+1] for i in range(len(li) - 1)]
    first = sum(max(d, 0) for d in deltas)
    max_d = max(deltas)
    second = sum(min(max_d, i) for i in li[:-1])
    return '{} {}'.format(first, second)

main()
