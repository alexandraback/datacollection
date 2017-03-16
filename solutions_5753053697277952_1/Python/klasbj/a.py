import sys

alphabet = 'ABCDEFGHIJKLMNOPQRSTUVXYZ'
def solve(ns):
    n = sum(ns)
    zs = [list(x) for x in zip(ns, alphabet)]
    rorder = []
    evacd = 0
    np = []
    while evacd < n:
        print('evacd', evacd, file=sys.stderr)
        print(zs, file=sys.stderr)
        an = False
        for p in zs:
            if p[0] > 0:
                an = True
                np.append(p[1])
                p[0] -= 1
                evacd += 1
                if len(np) > 1:
                    rorder.append(''.join(np))
                    np = []
        if not an:
            break

    if len(np) > 0:
        rorder.append(''.join(np))
    return ' '.join(reversed(rorder))



if __name__ == '__main__':
    lines = [x.strip() for x in sys.stdin.readlines()[1:]]
    for t in range(len(lines)//2):
        ns = [int(x) for x in lines[2*t+1].split()]
        print('Case #{}: {}'.format(t+1, solve(ns)))

