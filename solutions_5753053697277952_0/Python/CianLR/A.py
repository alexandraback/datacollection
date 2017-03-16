T = int(raw_input())


for case in xrange(1, T+1):
    N = int(raw_input())
    P = map(int, raw_input().split())

    ans = ''
    if sum(P) % 2:
        highest = max(P)
        h_index = P.index(highest)
        P[h_index] -= 1
        ans += ' ' + chr(ord('A') + h_index)

    for _ in xrange(sum(P) / 2):
        highest = max(P)
        h_index = P.index(highest)
        P[h_index] -= 1
        ans += ' ' + chr(ord('A') + h_index)

        highest = max(P)
        h_index = P.index(highest)
        P[h_index] -= 1
        ans += chr(ord('A') + h_index)

    print 'Case #{}: {}'.format(case, ans)
