from sys import stdin

T = int(next(stdin))

alphabet = [chr(ord('A') + i) for i in range(26)]

def f(Ps):
    ret = []
    for x in Ps[2:]:
        for _ in range(x[0]):
            ret.append(x[1])
    ret += [Ps[0][1]+Ps[1][1]] * Ps[0][0]
    return ret

def solve(Ps):
    Ps = sorted(Ps, reverse=True)
    ret = []
    if Ps[0][0] == Ps[1][0]:
        return f(Ps)
    else:
        d = Ps[0][0] - Ps[1][0]
        ret += [Ps[0][1]] * d
        Ps[0][0] -= d
        return ret + f(Ps)

for x in range(1, T+1):
    N = int(next(stdin))
    Ps = [[a, z] for a, z in zip(map(int, next(stdin).strip().split(" ")), alphabet)]
    y = " ".join(solve(Ps))
    print("Case #{0}: {1}".format(x, y))
