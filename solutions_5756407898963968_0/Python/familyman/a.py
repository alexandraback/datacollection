# insight:
#  - if you should buy a new farm, buy it as ASAP as possible

import sys

_input = sys.stdin.read().split()[::-1]
I = lambda: int(_input.pop())
D = lambda: float(_input.pop())


def solve_one():

    S0 = None
    S1 = None

    R0 = I()
    for v in range(1, 4+1):
        xs = set([I(), I(), I(), I()])
        if v == R0:
            S0 = xs

    R1 = I()
    for v in range(1, 4+1):
        xs = set([I(), I(), I(), I()])
        if v == R1:
            S1 = xs

    S = S0 & S1
    if len(S) == 1:
        return str(S.pop())
    elif len(S) > 1:
        return 'Bad magician!'
    else:
        return 'Volunteer cheated!'


for i in range(1, I()+1):
    print 'Case #%d: %s' % (i, solve_one(),)
