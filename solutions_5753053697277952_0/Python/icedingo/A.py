T = int(input())
letters = 'ABCDEFGHIJKLMNOPQRSTUVWXYZ'

for t in range(1, T+1):
    N = int(input())

    parties = []
    rp = map(int, input().split())
    for n, r in enumerate(rp):
        parties.append((r, letters[n]))

    parties.sort(reverse=True)

    order = []
    diff = parties[0][0] - parties[1][0]
    for i in range(diff):
        order.append(parties[0][1])

    parties[0] = (parties[1][0], parties[0][1])

    while len(parties) > 2:
        p = parties.pop()
        for i in range(p[0]):
            order.append(p[1])

    left = parties[0][0]
    couple = parties[0][1] + parties[1][1]
    for i in range(left):
        order.append(couple)


    print('Case #{}: {}'.format(t, ' '.join(order)))
