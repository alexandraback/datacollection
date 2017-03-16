from sys import stdin


_readstr   = lambda: stdin.readline().strip()
_readlist = lambda: stdin.readline().split()
_readint  = lambda: int(_readstr())


for n in range(_readint()):
    i  = _readint()
    xs = [set(_readlist()) for _ in range(4)][i - 1]
    k  = _readint()
    ys = [set(_readlist()) for _ in range(4)][k - 1] & xs
    print('Case #{}: {}'.format(n + 1,
        ys.pop()             if len(ys) == 1 else
        'Bad magician!'      if len(ys) >  1 else
        'Volunteer cheated!'
    ))
