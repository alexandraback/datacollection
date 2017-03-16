T = int(raw_input())

for z in xrange(1,T+1):
    r1 = int(raw_input())
    r1 -= 1

    pos1 = []

    for i in xrange(4):
        row = map(int,raw_input().split())
        if i == r1:
            pos1 = row

    r2 = int(raw_input())
    r2 -= 1

    pos2 = []
    for j in xrange(4):
        row = map(int, raw_input().split())
        if j == r2:
            pos2 = row

    pos = (set(pos1) & set(pos2))

    if len(pos) > 1:
        print "Case #%d: Bad magician!" % z

    if len(pos) == 0:
        print "Case #%d: Volunteer cheated!" % z

    if len(pos) == 1:
        print "Case #%d: %d" % (z, list(pos)[0])

