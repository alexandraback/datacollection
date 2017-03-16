import itertools

def f(S):
    G = [
        [
            (a,sum(1 for _ in b))
            for a,b in itertools.groupby(s)
        ]
        for s in S
    ]
    V = [[a for a,b in g] for g in G]
    O = [[b for a,b in g] for g in G]
    for a in V:
        if a != V[0]:
            return "Fegla Won"
    if len(S) == 2:
        return sum(abs(a-b) for a,b in zip(*O))
    s = 0
    for i in range(len(V[0])):
        mi = min(o[i] for o in O)
        ma = max(o[i] for o in O)
        s += min(
            sum(abs(o[i]-n) for o in O)
            for n in range(mi,ma+1)
        )
    return s

T = int(input())
for i in range(T):
    N = int(input())
    S = [input() for a in range(N)]
    print('Case #{}: {}'.format(i+1, f(S)))