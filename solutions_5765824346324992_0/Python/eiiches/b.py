# coding: utf-8

import sys
from collections import deque
from fractions import gcd

class itertools:
    @staticmethod
    def window(gen, n):
        buf = deque()
        for i in gen:
            buf.append(i)
            while len(buf) > n:
                buf.popleft()
            if len(buf) == n:
                yield buf

def lcm(a, b):
    return (a * b) // gcd(a, b)

def min_with_index(gen):
    minidx = None
    minval = None
    for idx, val in enumerate(gen):
        if minval is None or minval > val:
            minval = val
            minidx = idx
    return minidx, minval

def solve2(Mb, N):
    waits = [0 for i in Mb]
    for i in range(N-1):
        minidx, minval = min_with_index(waits)
        waits[minidx] += Mb[minidx]
    return min_with_index(waits)[0]

def solve(Mb, N):
    term = reduce(lcm, Mb, 1)
    return solve2(Mb, ((N - 1) % sum(term // Mi for Mi in Mb)) + 1)

def main(fp):
    T = int(fp.readline())
    for t in range(T):
        B, N = tuple(map(int, fp.readline().strip().split(' ')))
        Mb = tuple(map(int, fp.readline().strip().split(' ')))
        result = solve(Mb, N)
        print 'Case #{}: {}'.format(t + 1, result + 1)

if __name__ == '__main__':
    if len(sys.argv) == 1:
        main(sys.stdin)
    elif len(sys.argv) == 2:
        with open(sys.argv[1]) as f:
            main(f)
    else:
        print >> sys.stderr, "Usage: python {} INPUT_FILE".format(sys.argv[0])
        sys.exit(1)
