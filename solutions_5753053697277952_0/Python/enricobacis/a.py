from collections import Counter
from string import ascii_uppercase

def single(func):
    return func(raw_input())

def row(func):
    return map(func, raw_input().split())

def printcase(case, out, pattern='Case #%d: %s'):
    print pattern % (case, out)

def repeat(func, times):
    return [func() for _ in xrange(times)]


T = single(int)
for test in xrange(1, T + 1):
    N = single(int)
    c = Counter()
    for p, i in zip(ascii_uppercase, row(int)):
        c[p] = i

    c['*'] = c['+'] = 0
    moves = []
    while sum(c.values()):
        (f, fn), (s, sn), (t, tn) = c.most_common(3)
        assert(fn / float(sum(c.values())) <= 0.5)
        if fn > sn:
            moves += f
            c[f] -= 1
        elif tn > 0:
            moves += f
            c[f] -= 1
        else:
            moves.append(f+s)
            c[f] -= 1
            c[s] -= 1
    printcase(test, ' '.join(moves))



