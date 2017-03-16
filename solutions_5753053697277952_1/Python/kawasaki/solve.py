CHARS = 'ABCDEFGHIJKLMNOPQRSTUVWXYZ'

T = int(raw_input())
for tc in xrange(1, T + 1):
    N = int(raw_input())
    P = map(int, raw_input().split())
    xs = [[P[i], i] for i in xrange(N)]
    xs.sort(reverse=True)

    answer = []
    n1, i1 = xs[0]
    n2, i2 = xs[1]
    if n1 == n2 + 2:
        answer.append(CHARS[i1] * 2)
        n1 -= 2
    elif n1 == n2 + 1:
        answer.append(CHARS[i1])
        for i in xrange(2, N):
            n, j = xs[i]
            if 0 < n:
                answer[-1] += CHARS[j]
                xs[i][0] -= 1
                break
        n1 -= 1
    else:
        while n1 > n2 + 2:
            answer.append(CHARS[i1] * 2)
            n1 -= 2
        if n1 > n2:
            answer.append(CHARS[i1])
            for i in xrange(2, N):
                n, j = xs[i]
                if 0 < n:
                    answer[-1] += CHARS[j]
                    xs[i][0] -= 1
                    break
            n1 -= 1

    cs = []
    for i in xrange(2, N):
        n, j = xs[i]
        if 0 < n:
            cs.append(CHARS[j] * n)
    cs = ''.join(cs)
    for i in xrange(0, len(cs), 2):
        answer.append(cs[i:i + 2])
    for i in xrange(n1):
        answer.append(CHARS[i1] + CHARS[i2])

    print 'Case #{}: {}'.format(tc, ' '.join(answer))
