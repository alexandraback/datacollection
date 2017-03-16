from itertools import combinations

def unhappiness(spots, debug=False):
    retval = 0
    def check(r, c):
        if debug:
            print('%d, %d' % (r, c))
        if (r,c) in spots:
            return 1
        return 0
    for r,c in spots:
        for dr in (-1, 1):
            retval += check(r + dr, c)
        for dc in (-1, 1):
            retval += check(r, c + dc)
    return retval // 2

def solve(rows, cols, n):
    board = [(r,c) for r in range(rows) for c in range(cols)]
    best = None
    best_comb = None
    for comb in combinations(board, n):
        comb = set(comb)
        unhap = unhappiness(comb)
        if best is None or unhap < best:
            best = unhap
            best_comb = comb
    return best

t = int(input())
for case in range(1, t+1):
    r, c, n = [int(s) for s in input().split(' ')]
    print('Case #%d: %d' % (case, solve(r, c, n)))
