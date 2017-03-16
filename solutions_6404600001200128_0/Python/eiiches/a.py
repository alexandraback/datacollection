# coding: utf-8

import sys
from collections import deque

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

def solve_a(M):
    s = 0
    for m0, m1 in itertools.window(M, 2):
        s += max(m0 - m1, 0)
    return s

def calc_max_mps(M):
    max_mps = 0
    for m0, m1 in itertools.window(M, 2):
        mps = max(m0 - m1, 0)
        if mps > max_mps:
            max_mps = mps
    return max_mps

def solve_b(M):
    # mushrooms per 10 second
    max_mps = calc_max_mps(M)
    s = 0
    for m0, m1 in itertools.window(M, 2):
        s += m0 - max(m0 - max_mps, 0)
    return s

def solve(M):
    return solve_a(M), solve_b(M)

def main(fp):
    T = int(fp.readline())
    for t in range(T):
        N = int(fp.readline().strip())
        M = tuple(map(int, fp.readline().strip().split(' ')))
        result = solve(M)
        print 'Case #{}: {} {}'.format(t + 1, *result)

if __name__ == '__main__':
    if len(sys.argv) == 1:
        main(sys.stdin)
    elif len(sys.argv) == 2:
        with open(sys.argv[1]) as f:
            main(f)
    else:
        print >> sys.stderr, "Usage: python {} INPUT_FILE".format(sys.argv[0])
        sys.exit(1)
