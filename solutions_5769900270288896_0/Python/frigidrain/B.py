import fileinput
from collections import deque

def compute(N, qty, cost):
    res = 0
    for q, c in zip(qty, cost):
        take = min(N, q)
        res += c*take
        N -= take
        if N == 0:
            break
    return res

def solve(R, C, N):

    if R*C == 1:
        return 0

    if N <= (R*C + 1)/2:
        return 0

    cost = [0, 2, 3, 4]

    if R*C % 2 == 0:
        corners = 2
        centers = (R - 2)*(C - 2)/2
        sides = R*C/2 - corners - centers
        qty = [R*C/2, corners, sides, centers]
    else:
        corners = 0
        centers = (R - 2)*(C - 2)/2
        sides = R*C/2 - corners - centers 
        qty = [(R*C + 1)/2, corners, sides, centers]

    # print qty

    res = compute(N, qty, cost)

    if R*C % 2 == 0:
        return res
    else:
        qty[0] -= 1
        qty[1] += 4
        qty[2] -= 4
        qty[3] += 1
        # print qty
        res = min(res, compute(N, qty, cost))
    return res

f = fileinput.input()
T = int(f.readline())

for t in range(T):
    R, C, N = [int(x) for x in f.readline().split(' ')]
    print "Case #{0}: {1}".format(t + 1, solve(R, C, N))
