import itertools
import sys

def calc_unhappiness(p, R, C):
    u = 0
    board = [0] * (R * C)
    for i in p:
        board[i] = 1
    for r in range(R):
        for c in range(C - 1):
            a = r * C + c + 1
            b = r * C + c
            if board[a] == 1 and board[a] == board[b]:
                u += 1
    for r in range(R - 1):
        for c in range(C):
            a = (r + 1) * C + c
            b = r * C + c
            if board[a] == 1 and board[a] == board[b]:
                u += 1
    return u

def lowest(N, R, C):
    poss = itertools.combinations(range(R * C), N)
    s = [calc_unhappiness(p, R, C) for p in poss]
    if len(s) == 0:
        return 0
    else:
        return min(s)

lines = sys.stdin.readlines()
T = int(lines[0].strip())
for i, line in enumerate(lines[1:]):
    R, C, N = map(int, line.strip().split())
    print('Case #{}: {}'.format(i + 1, lowest(N, R, C)))
