from sys import argv
import re
from collections import deque

def mmc(x):
    y = list(sorted(set(x)))
    z = list(sorted(set(x)))
    while len(set(y)) > 1:
        (a, i) = min((a, i) for (i, a) in enumerate(y))
        y[i] += z[i]
    return y[0]

def solve(n, x):
    bs = [(i + 1, a) for (i, a) in enumerate(x)]
    mm = mmc(x)
    sched = dict()
    for i in range(mm):
        for (b, t) in bs:
            if i % t == 0:
                if i not in sched:
                    sched[i] = set()
                sched[i].add(b)

    n = n % sum(map(len, sched.values()))
    lst = list()
    for k in sorted(sched.keys()):
        lst.extend(sorted(sched[k]))
    return lst[n - 1]
        
        
        

if __name__ == '__main__':
    with open(argv[1:] and argv[1] or 'sample.in') as inp:
        lines = [list(map(int, l.split(' '))) for l in inp.readlines()]
        lines = list(reversed(lines))
        lines.pop()
        
        i = 1
        while lines:
            (_, n) = lines.pop()
            print('Case #%d: %d' % (i, solve(n, lines.pop())))
            i += 1
