# roll the dice! :)

from random import shuffle

rooms = []


def make_rooms(r, c, n):
    rooms = []

    i = 0

    m = []

    for i in xrange(r * c):
        m.append(0)

    for i in xrange(n):
        m[i] = 1

    shuffle(m)

    i = 0

    for rr in xrange(r):
        row = []

        for cc in xrange(c):
            row.append(m[i])

            i += 1

        rooms.append(row)

    return rooms


def calc_score(r, c):
    score = 0

    for i in xrange(r):
        for j in xrange(1, c):
            if (rooms[i][j - 1] == 1 and rooms[i][j] == 1):
                score += 1

    for i in xrange(c):
        for j in xrange(1, r):
            if (rooms[j - 1][i] == 1 and rooms[j][i] == 1):
                score += 1

    return score

t = int(raw_input())

for x in xrange(t):
    r, c, n = map(int, raw_input().split())

    min_s = c * r * n

    for i in xrange(15000 / (16 / (r * c))):
        rooms = make_rooms(r, c, n)
        s = calc_score(r, c)

        if (s < min_s):
            min_s = s

    print 'Case #%s:' % (x+1), min_s