#!/usr/bin/env python3

import itertools

def cost(L, M):
    result = 0
    n2 = min(M, L[0])
    result += 2 * n2
    M -= n2
    n3 = min(M, L[1])
    result += 3 * n3
    M -= n3
    result += 4 * M
    return result

def solve(R, C, N):
    if N <= (R*C+1) // 2: return 0
    if R == 1 or C == 1:
        return 2*(N-R*C//2)-1-R*C%2
    elif R%2 == 1 and C%2 == 1:
        c1 = cost([0, R+C-2], N-R*C//2-1)
        c2 = cost([4, R+C-6], N-R*C//2)
        return min(c1, c2)
    else:
        return cost([2, R+C-4], N-R*C//2)

tests = int(input())
for test in range(tests):
    R, C, N = map(int, input().split())
    result = solve(R, C, N)
    print("Case #{}: {}".format(1+test, result))
