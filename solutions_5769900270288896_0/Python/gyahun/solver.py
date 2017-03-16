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

if __name__ == '__main__':
    infile = 'B-small-attempt0.in'
    rows = 1

    with open(infile) as src: lines = list(src.readlines())
    number = int(lines[0])
    tests = [read(lines[i: i + rows]) for i in range(1, len(lines), rows)]

    with open(infile.replace('.in', '.out'), 'w') as dst:
        for i, test in enumerate(tests, 1):
            dst.write('Case #{}: {}\n'.format(i, solve(test)))
