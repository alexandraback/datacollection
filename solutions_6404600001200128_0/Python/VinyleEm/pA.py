def solve(plates):
    n, ret1, min_rate = len(plates), 0, 0
    for i in xrange(1, n):
        if plates[i] < plates[i - 1]:
            ret1 += plates[i - 1] - plates[i]
            min_rate = max(min_rate, plates[i - 1] - plates[i])

    ret2 = 0
    for i in xrange(1, n):
        ret2 += min(min_rate, plates[i - 1])

    return (ret1, ret2)


def main():
    T = int(raw_input())
    for t in xrange(T):
        raw_input()
        plates = map(int, raw_input().split())
        ans1, ans2 = solve(plates)
        print "Case #%d: %d %d" % (t + 1, ans1, ans2)


if __name__ == '__main__':
    main()
