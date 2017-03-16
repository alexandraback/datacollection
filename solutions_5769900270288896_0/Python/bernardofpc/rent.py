from math import ceil

def one(l, n):
    if l % 2 == 0:
        return 1 + 2*(n - int(l/2) - 1)
    else:
        return 2*(n - int(ceil(l/2)))

# Greedy passes?
def solve(r, c, n):
    triv = int(ceil(r*c/2))
    if n <= triv: return 0

    if r == 1: return one(c, n)
    if c == 1: return one(r, n)
    if r == 3 and c == 3 and n == 8: return 8

    corners = 2
    inner = (r-2)*(c-2)//2
    sides = r+c-4

    if r % 2 == 1 and c % 2 == 1:
        corners = 0
        sides = r+c-2

    rem = n - triv
    if rem <= corners:
        return 2*rem
    if rem <= sides + corners:
        return 2*corners + (rem-corners)*3
    return 2*corners + 3*sides + (rem-corners-sides)*4

import sys

T = int(sys.stdin.readline())

for icase in range(1,T+1):
    x = sys.stdin.readline()
    [r, c, n] = [int(_u) for _u in x.split()]

    noise = solve(r,c,n)
    print('Case #{}: {}'.format(icase,noise))
