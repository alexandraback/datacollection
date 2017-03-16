from collections import Counter


t = int(raw_input())
for tt in xrange(1, t + 1):
    n = int(raw_input())
    p = map(int, raw_input().split(' '))
    mp = Counter()
    for idx, value in enumerate(p):
        mp[chr(idx + ord('A'))] = value

    ans = []

    mc = mp.most_common()
    ans += [mc[0][0]] * (mc[0][1] - mc[1][1])

    for val, count in mc[2:]:
        ans += [val] * count

    ans += [mc[0][0] + mc[1][0]] * mc[1][1]

    print 'Case #{}: {}'.format(tt, ' '.join(ans))
