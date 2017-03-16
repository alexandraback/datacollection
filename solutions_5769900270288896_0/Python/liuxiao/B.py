import math
import sys
sys.setrecursionlimit(10010)
max_val = 0
placed  = set()

def place(r, c, remain, now_index, now_val):
    global max_val, placed
    if remain < 1:
        max_val = now_val
        return
    for i in range(now_index, r * c - remain + 1):
        row = i / c
        col = i % c
        val = now_val
        if row and ((row - 1) * c + col) in placed:
            val += 1
        if col and (row * c + col - 1) in placed:
            val += 1
        if val < max_val:
            placed.add(i)
            place(r, c, remain - 1, i + 1, val)
            placed.remove(i)

T = input()
for t in range(T):
    r, c, n = map(int, raw_input().split())
    can_place = int(math.ceil(r * c / 2.0))
    max_val   = 4 * (n - can_place) if n > can_place else 0
    placed.clear()
    place(r, c, n, 0, 0)
    print 'Case #%d: %d' % (t + 1, max_val)
