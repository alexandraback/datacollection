from collections import namedtuple
from itertools import count

Test = namedtuple('Test', 'B N ms')
def read(lines):
    B, N = map(int, lines[0].split())
    return Test(B, N, list(map(int, lines[1].split())))

def solve(test):
    cut = lambda t: sum(t // m for m in test.ms)
    free = lambda t: sum(t % m == 0 for m in test.ms)
    cutting = lambda t: sum(t % m > 0 for m in test.ms)

    near = max(0, test.N - test.B) // sum(1 / b for b in test.ms)
    tm = next(t for t in count(near) if cut(t) >= test.N - test.B)
    print('{}\t{}\t{}\t{}\t{}\t{}'.format(test.N - cut(tm), test.N, cut(tm), free(tm), cut(tm - 1), free(tm - 1)))
    print('{}\t{}\t{}'.format(int(near), int(tm), int(cut(near))))
    order = max(0, test.N - 1 - cut(tm) - cutting(tm))

    starts = (i for i, b in enumerate(test.ms, 1) if tm % b == 0)
    return next(i for j, i in enumerate(starts) if j == order)

if __name__ == '__main__':
    infile = 'B-small-attempt2.in'
    rows = 2

    with open(infile) as src: lines = list(src.readlines())
    number = int(lines[0])
    tests = [read(lines[i: i + rows]) for i in range(1, len(lines), rows)]

    with open(infile.replace('.in', '.out'), 'w') as dst:
        for i, test in enumerate(tests, 1):
            print()
            print(i)
            dst.write('Case #{}: {}\n'.format(i, solve(test)))
