from random import randint
from itertools import combinations

ans = [[[100 for i in range(22)] for j in range(22)] for k in range(22)]

def init():
    for r in range(1, 17):
        for c in range(1, 17):
            if r * c > 16:
                break
            for n in range(0, r * c + 1):
                for it in combinations(range(r * c), n):
                    cur = set(it)
                    val = 0
                    for x in cur:
                        if x % c > 0 and x - 1 in cur:
                            val += 1
                        if x % c < c - 1 and x + 1 in cur:
                            val += 1
                        if (x // c) > 0 and ((x // c) - 1) * c + x % c in cur:
                            val += 1
                        if (x // c) < r - 1 and ((x // c) + 1) * c + x % c in cur:
                            val += 1

                    val //= 2
                    ans[r][c][n] = min(ans[r][c][n], val)


def solve():
    r, c, n = map(int, input().split())
    return ans[r][c][n]

init()
for t in range(1, int(input()) + 1):
    print('Case #%d: %d' % (t, solve()))
