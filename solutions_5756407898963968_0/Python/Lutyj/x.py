import sys

def InputIterator():
    for line in sys.stdin:
        for value in line.split(): yield value

inp = InputIterator()
T = int(next(inp))

for t in range(T):
    first = set()
    fr = int(next(inp))

    for r in range(4):
        for c in range(4):
            a = int(next(inp))
            if r == fr-1: first.add(a)

    second = set()
    sr = int(next(inp))

    for r in range(4):
        for c in range(4):
            a = int(next(inp))
            if r == sr-1: second.add(a)

    first = first.intersection(second)

    sys.stdout.write('Case #{0}: '.format(t+1));

    if len(first) == 0:
        print 'Volunteer cheated!'
    elif len(first) > 1:
        print 'Bad magician!'
    else:
        print first.pop()
