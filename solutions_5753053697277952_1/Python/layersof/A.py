DEBUG=1

def main():
    T = input()
    for i in range(T):
        N = input()
        Ps = map(int, raw_input().split())
        print 'Case #%d: %s' % (i+1, ' '.join(solve(Ps)))

def solve(Ps):
    result = []
    inds = [[p, c] for p, c in zip(Ps, 'ABCDEFGHIJKLMNOPQRSTUVWXYZ')]
    inds = sorted(inds, reverse=True)
    # print inds
    if len(inds) == 1:
        return ['A' for i in range(len(inds))]

    while(inds[0][0] > inds[1][0]):
        result.append(inds[0][1])
        inds[0][0] -= 1

    # print inds


    if len(inds) > 2:
        while(inds[2][0]):
            if inds[2][0] >= 2:
                result.append(inds[2][1]*2)
                inds[2][0] -= 2
                inds[2:] = sorted(inds[2:], reverse=True)
                continue
            if len(inds) > 3 and inds[2][0] and inds[3][0]:
                result.append(inds[2][1] + inds[3][1])
                inds[2][0] -= 1
                inds[3][0] -= 1
                inds[2:] = sorted(inds[2:], reverse=True)
                continue
            result.append(inds[2][1])
            inds[2][0] -= 1
            inds[2:] = sorted(inds[2:], reverse=True)
            continue

    # print inds

    while inds[0][0]:
        result.append(inds[0][1] + inds[1][1])
        inds[0][0] -= 1
        inds[1][0] -= 1

    # print inds

    return result

if __name__ == '__main__':
    main()
