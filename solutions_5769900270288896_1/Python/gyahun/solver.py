from collections import namedtuple
from itertools import product, combinations

Test = namedtuple('Test', 'R C N')
def read(lines):
    return Test(*map(int, lines[0].split()))

def solve(test):
    rows, cols = map(range, (test.R, test.C))
    coords = tuple(product(rows, cols))

    def evaluate(comb):
        rx = sum((r, c) in comb and (n, c) in comb for r, n in zip(rows, rows[1:]) for c in cols)
        cx = sum((r, c) in comb and (r, n) in comb for c, n in zip(cols, cols[1:]) for r in rows)
        return rx + cx

    return min(evaluate(cmb) for cmb in combinations(coords, test.N))

def solve(test):
    R, C = test.R, test.C
    if R == 1 and C == 1: return 0
    elif R == 1 or C == 1:
        capacity = (R // 2 + R % 2) * (C // 2 + C % 2) + (R // 2) * (C // 2)
        corners = 1 if R % 2 == 0 or C % 2 == 0 else 0
        print(test.N, capacity, corners)
        if test.N <= capacity: return 0

        s = 0
        N = test.N - capacity
        cs = min(corners, max(0, N))
        s += cs
        N -= cs
        return s + 2 * N
    elif R % 2 == 0 or C % 2 == 0:
        capacity = (R // 2 + R % 2) * (C // 2 + C % 2) + (R // 2) * (C // 2)
        corners = 2 if R % 2 == 0 or C % 2 == 0 else 0
        edges = max(0, 2 * (R // 2 + C // 2) - (int(R % 2 == 0) + int(C % 2 == 0)) - corners)
        print(test.N, capacity, corners, edges)
        if test.N <= capacity: return 0

        s = 0
        N = test.N - capacity
        cs = min(corners, max(0, N))
        s += 2 * cs
        N -= cs
        es = min(edges, max(0, N))
        s += 3 * es
        N -= es
        return s + 4 * N
    else:
        capacity = (R // 2 + R % 2) * (C // 2 + C % 2) + (R // 2) * (C // 2)
        corners = 2 if R % 2 == 0 or C % 2 == 0 else 0
        edges = max(0, 2 * (R // 2 + C // 2) - (int(R % 2 == 0) + int(C % 2 == 0)) - corners)
        if test.N <= capacity: return 0

        s = 0
        N = test.N - capacity
        cs = min(corners, max(0, N))
        s += 2 * cs
        N -= cs
        es = min(edges, max(0, N))
        s += 3 * es
        N -= es
        a = s + 4 * N        

        capacity = (R // 2) * (C // 2 + C % 2) + (R // 2 + R % 2) * (C // 2)
        corners = 4
        edges = max(0, 2 * (R // 2 + C // 2) - corners)
        print(test.N, capacity, corners, edges)

        s = 0
        N = test.N - capacity
        cs = min(corners, max(0, N))
        s += 2 * cs
        N -= cs
        es = min(edges, max(0, N))
        s += 3 * es
        N -= es
        b = s + 4 * N

        return min(a, b)

if __name__ == '__main__':
    infile = 'B-large.in'
    rows = 1

    with open(infile) as src: lines = list(src.readlines())
    number = int(lines[0])
    tests = [read(lines[i: i + rows]) for i in range(1, len(lines), rows)]

    with open(infile.replace('.in', '.out'), 'w') as dst:
        for i, test in enumerate(tests, 1):
            print()
            print(i)
            print(test)
            dst.write('Case #{}: {}\n'.format(i, solve(test)))
