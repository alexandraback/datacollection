t = input()

def diffs(m):
    total = []
    for i,j in zip(m, m[1:]):
        total.append(max(0, i - j))
    return total

for case in xrange(1, t+1):
    n = input()
    m = map(int, raw_input().split())
    diff = diffs(m)

    # method 1
    m1 = sum(diff)
    # method 2
    rate = max(diff)
    total = 0
    for num in m[:-1]:
        if num < rate:
            total += num
        else:
            total += rate
    print 'Case #%d: %d %d' % (case, m1, total)

