def solve(N, m):
    """ solve the problem """

    #print(N, m)
    ans1 = 0
    for i in range(len(m) - 1):
        diff = m[i] - m[i+1]
        if diff > 0:
            ans1 += diff

    ans2 = 0
    maxdiff = 0
    diffs = []
    for i in range(len(m) - 1):
        diff = m[i] - m[i+1]
        if diff > 0:
            diffs.append(diff)
        else:
            diffs.append(0)
    maxdiff = max(diffs)
    for i in range(len(m) - 1):
        if m[i] >= maxdiff: ans2 += maxdiff
        else: ans2 += m[i]
    



    return ans1, ans2


def parse():
    """ parse input """

    N = int(input())
    m = [int(i) for i in input().split()]

    return N, m


def main():
    
    T = int(input())

    # solve
    for t in range(1, T+1):
        params = parse()
        result = solve(*params)
        print('Case #%d: %s %s' % (t, result[0], result[1]))


if __name__ == '__main__':

    main()
