from collections import Counter

def count(sen):
    c = Counter()
    for i, s in enumerate(sen):
        c[i] += s
    return c

def solve(senators):
    out = []
    if sum(senators) % 2 == 1:
        max_i, max_s = max(enumerate(senators), key=lambda s: s[1])
        senators[max_i] -= 1
        out.append(chr(max_i + 65))
    while any(s > 0 for s in senators):
        max_i1, max_s1 = max(enumerate(senators), key=lambda s: s[1])
        senators[max_i1] -= 1
        max_i2, max_s2 = max(enumerate(senators), key=lambda s: s[1])
        senators[max_i2] -= 1
        out.append(chr(max_i1 + 65) + chr(max_i2 + 65))
    return out

T = int(raw_input())

for case in xrange(1, T + 1):
    N = int(raw_input())
    senators = map(int, raw_input().split())

    print 'Case #{}: {}'.format(case, ' '.join(solve(senators)))
