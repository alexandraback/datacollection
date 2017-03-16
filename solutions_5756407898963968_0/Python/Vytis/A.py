#!/usr/bin/env python

SIZE = 4


def read():
    a = int(raw_input().strip())
    lines = [raw_input().strip() for i in xrange(SIZE)]
    line = lines[a-1]
    return set(map(int, line.split()))


def solve():
    a = read()
    b = read()
    c = a & b
    if not c:
        return 'Volunteer cheated!'
    if len(c) > 1:
        return 'Bad magician!'
    return next(iter(c))



def main():
    t = int(raw_input().strip())
    for i in xrange(1, t + 1):
        ret = solve()
        print 'Case #{}:'.format(i), ret

if __name__ == '__main__':
    main()
