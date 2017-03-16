def solve():
    n = int(input())
    mash = [ int(x) for x in input().split(' ')]
    res1 = 0
    max_diff = 0
    for i in range(1, n):
        if mash[i-1] > mash[i]:
            res1 += mash[i-1] - mash[i]
            max_diff = max(max_diff, mash[i-1] - mash[i])

    res2 = 0
    for i in range(0, n-1):
        res2 += min(max_diff, mash[i])
    return '%d %d' % (res1, res2)

if __name__ == '__main__':
    cases = int(input())
    for case in range(1, cases+1):
        print('Case #%d: %s' % (case, str(solve())))
