__author__ = 'eidanch'

from itertools import combinations


def get_line():
    return raw_input().strip()

formatIntegerList = lambda s: list(map(int, s.split(' ')))


def standard_input():
    T = int(get_line())
    for i in range(T):
        R, C, N = tuple(formatIntegerList(get_line()))
        yield (i+1, (R, C, N))


def handle_case(case):
    R, C, N = case
    lst = [(i,j) for i in xrange(R) for j in xrange(C)]
    best = 4*R*C
    for occupied in combinations(lst, N):
        value = unhappiness(occupied)
        best = min(best, value)
        if best == 0:
            return 0
    return best


def unhappiness(occupied):
    count = 0
    for (i, j) in occupied:
        if (i - 1, j) in occupied:
            count += 1
        if (i, j - 1) in occupied:
            count += 1
        if (i + 1, j) in occupied:
            count += 1
        if (i, j + 1) in occupied:
            count += 1
    return count / 2

def main():
    for i, case in standard_input():
        print "Case #%d: %d" % (i, handle_case(case))

if __name__ == '__main__':
    main()