__author__ = 'sunghyo.jung'
import sys
from collections import Counter

sys.setrecursionlimit(10000)

def is_balanced(c):
    if sum(c.values()) == 0:
        return True
    all_sum = sum(c.values())
    for k in c:
        if float(c[k]) / all_sum > 0.5:
            return False
    return True


def back(c, r):
    if sum(c.values()) == 0:
        return r
    # if not is_balanced(c):
    #     return
    for a in c.most_common():
        prefix = a[0]
        c[prefix] -= 1

        if is_balanced(c):
            v = back(c, r + [prefix])
            if v is not None:
                return v

        for b in c.most_common():
            postfix = b[0]
            if c[postfix] >= 0:
                tok = prefix + postfix
                c[postfix] -= 1
                if is_balanced(c):
                    v = back(c, r + [tok])
                    if v is not None:
                        return v
                c[postfix] += 1

        c[prefix] += 1
    return None

for t in range(1, int(input().strip()) + 1):
    n = int(input().strip())    # number of parties
    p = [int(x) for x in input().strip().split()]   # number of senators
    c = Counter()
    for i in range(n):
        c[str(chr(i + ord('A')))] = p[i]

    r = back(c, [])

    print("Case #%d: %s" % (t, " ".join(r)))