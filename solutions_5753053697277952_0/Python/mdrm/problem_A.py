import sys
from random import randint

from collections import Counter,deque
from itertools import combinations

IS_LOCAL = False
try:
    import os
    IS_LOCAL = os.getenv("AGLAE") == "nondual" and os.getenv("SIDONIE") == "improbable"
except:
    pass

def read_ints(inp = sys.stdin):
    return list(map(int,next(inp).strip().split()))


def sol1(ll):
    cc = Counter({i:v for i,v in enumerate(ll)})
    tot = sum(ll)
    res = []
    while tot:
        mc = cc.most_common(1)[0][0]
        cc[mc]-=1
        tot -=1
        if tot==2:
            res.append(chr(65+mc))
            continue
        mc2 = cc.most_common(1)[0][0]
        cc[mc2]-=1
        tot -=1
        res.append(''.join(chr(65+x) for x in (mc,mc2)))

    return " ".join(res)


if IS_LOCAL:
    inp = iter("""4
2
2 2
3
3 2 2
3
1 1 2
3
2 3 1
""".split('\n'))
    # inp = iter(map(str,[6, "2 3 2", "1 1 1", "2 1 1", "2 1 2", "3 2 3", "100 9 50"]))
    # inp = open("A-small-attempt0.in")
    inp = sys.stdin
else:
    inp = sys.stdin

T ,= read_ints(inp)
# T=1
mm = 0
for t in range(T):
    N, =read_ints(inp)
    ll =read_ints(inp)
    x = sol1(ll)
    # if i>=mm:
    #     print(N,i,x)
    #     mm=i
    print("Case #%d: %s" % (t+1,x) )
