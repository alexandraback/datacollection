r = open('1.test')
T = int(r.readline().rstrip())
for t in range(1, T+1):
    N = int(r.readline().rstrip())
    m = map(int, r.readline().rstrip().split())

    eat_rate = 0
    for index, i in enumerate(m):
        if index < 1:
            continue
        else:
            mer = m[index-1]-m[index]
            if mer > eat_rate:
                eat_rate = mer


    y = sum(eat_rate if i > eat_rate else i for i in m[:-1])

    x = 0
    for index, i in enumerate(m):
        if index < 1:
            continue
        elif m[index] > m[index-1]:
            x += 0
        else:
            x += m[index-1] - m[index]

    print 'Case #%d: %s %s' % (t, x, y)
r.close()
