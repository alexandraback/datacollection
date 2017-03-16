import sys

def check_good(ps):
    s = sum(v for v,_ in ps)
    for v,_ in ps:
        if s - v < v:
            return False
        elif v < 0:
            return False
    return True

def solve(line):
    arr = [int(s) for s in line.split(' ')]
    ps = [[v,i] for i,v in enumerate(arr[1:])]
    acc = []
    while sum(v for v,_ in ps) > 0:
        ps = list(reversed(sorted(ps)))
        first = ps[0][1]
        ps[0][0] -= 2
        if check_good(ps):
            second = first
        else:
            ps[0][0] += 1
            ps[1][0] -= 1
            if check_good(ps):
                second = ps[1][1]
            else:
                ps[1][0] += 1
                second = None
        pair = chr(ord('A') + first)
        if second is not None:
            pair += chr(ord('A') + second)
        acc.append(pair)
    return ' '.join(acc)

case=0
next(sys.stdin)
for line in sys.stdin:
    line = line.strip()
    line += ' ' + next(sys.stdin).strip()
    case += 1
    print('Case #{}: {}'.format(case, solve(line)))
