#! /usr/bin/env python
from fractions import gcd

def main():
    num_cases = int(raw_input())
    for case in range(1, num_cases + 1):
        B, N = map(int, (raw_input().split()))
        N -= 1 # index by 0
        M = map(int, raw_input().split())
        X = lcm(M)
        period = sorted([(k*M[i], i) for i in range(len(M))
                         for k in range(X/M[i])])
        N %= len(period)
        answer = period[N][1] + 1 # but count at 1
        print "Case #{}: {}".format(case, answer)


def lcm(M):
    if len(M) == 1:
        return M[0]
    elif len(M) == 2:
        return M[0]*M[1] / gcd(M[0], M[1])
    else:
        return lcm([lcm(M[:2])] + M[2:])

if __name__ == '__main__':
    main()
