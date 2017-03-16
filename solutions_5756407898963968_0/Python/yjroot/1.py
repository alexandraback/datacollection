inf = open('./input.txt', 'r')
outf = open('./input.txt', 'r')

T = int(inf.readline())


def readtest():
    LINE = int(inf.readline())
    rows = []
    for i in range(4):
        rows.append(inf.readline())
    row = rows[LINE - 1]
    row = [int(num) for num in row.split(' ')]
    return row


def testcace(t):
    a = readtest()
    b = readtest()
    result = []
    for i in a:
        if i in b:
            result.append(i)
    if len(result) == 0:
        print "Case #%d: Volunteer cheated!" % (t)
    elif len(result) == 1:
        print "Case #%d: %d" % (t, result[0])
    else:
        print "Case #%d: Bad magician!" % (t)

for t in range(T):
    testcace(t + 1)
