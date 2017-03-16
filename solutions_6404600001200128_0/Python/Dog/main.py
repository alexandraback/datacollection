from sys import argv

def solve1(x):
    return sum(max(b - a, 0) for (a, b) in zip(x[1:], x))

def solve2(x):
    m = max((b - a) for (a, b) in zip(x[1:], x))
    return sum(min(m, i) for i in x[:-1])

if __name__ == '__main__':
    with open(argv[1:] and argv[1] or 'sample.in') as inp:
        lines = inp.readlines()
        for (e, i) in enumerate(range(2, len(lines), 2)):
            x = list(map(int, lines[i].split(' ')))
            print('Case #%s: %s %s' % (e + 1, solve1(x), solve2(x)))
